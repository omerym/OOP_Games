#include "X_O_5x5.hpp"
#include <iostream>
using namespace std;
X_O_5x5_Board::X_O_5x5_Board()
{
	n_rows = 5;
	n_cols = 5;
}
bool X_O_5x5_Board::is_set(unsigned long long bitBoard, int index)
{
	return (bitBoard & (1ll << index)) != 0;
}
int X_O_5x5_Board::get_index(int x, int y)
{
	return (x * (n_rows + 1) + y);
}
unsigned long long X_O_5x5_Board::board_bitBoard()
{
	return x_bitBoard | o_bitBoard;
}
bool X_O_5x5_Board::update_board(int x, int y, char mark)
{
	if (x < 0 || x >= n_cols || y < 0 || y >= n_rows || (mark != 'x' && mark != 'o'))
	{
		return false;
	}
	int index = get_index(x, y);
	if (is_set(board_bitBoard(), index))
	{
		return false;
	}
	unsigned long long& bitBoard = mark == 'x' ? x_bitBoard : o_bitBoard;
	bitBoard |= 1ll << index;
	moves++;
	return true;
}
void X_O_5x5_Board::display_board()
{
	for (int y = n_rows - 1; y >= 0; y--)
	{
		for (int x = 0; x < n_cols; x++)
		{
			cout << "|(" << x << ',' << y << ") ";
			if (!is_set(board_bitBoard(), get_index(x, y)))
			{
				cout << "_ ";
			}
			else if (is_set(x_bitBoard, get_index(x, y)))
			{
				cout << "X ";
			}
			else if (is_set(o_bitBoard, get_index(x, y)))
			{
				cout << "O ";
			}
		}
		cout <<"\n\n";
	}
	cout << "----------------------------------------\n";
}
bool X_O_5x5_Board::is_winner()
{
	return game_is_over() && false;
}
bool X_O_5x5_Board::is_draw()
{
	return game_is_over() && !is_winner();
}
bool X_O_5x5_Board::game_is_over()
{
	return moves >= 24;
}