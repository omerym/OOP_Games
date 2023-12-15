#include "X_O_5x5.hpp"
#include <iostream>
using namespace std;
X_O_5x5_Board::X_O_5x5_Board()
{
	Board::n_rows = 5;
	Board::n_cols = 5;
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
	return board.x_bitBoard | board.o_bitBoard;
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
	unsigned long long& bitBoard = mark == 'x' ? board.x_bitBoard : board.o_bitBoard;
	bitBoard |= 1ll << index;
	board.moves++;
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
			else if (is_set(board.x_bitBoard, get_index(x, y)))
			{
				cout << "X ";
			}
			else if (is_set(board.o_bitBoard, get_index(x, y)))
			{
				cout << "O ";
			}
		}
		cout <<"\n\n";
	}
	cout << "----------------------------------------\n\n";
}
bool X_O_5x5_Board::is_winner()
{
	return false;
}
bool X_O_5x5_Board::is_draw()
{
	return false;
}
int X_O_5x5_Board::evaluate(X_O_5x5_BoardData board)
{
	return evaluate(board.x_bitBoard) - evaluate(board.o_bitBoard);
}
int X_O_5x5_Board::evaluate_row(unsigned long long row, int offset)
{
	int n_in_row = 0;
	unsigned long long r = row;
	for (int i = 1; i < max_in_row; i++)
	{
		r &= (row << (offset * i));
		if (r == 0)
		{
			break;
		}
		n_in_row = i + 1;
	}
	if (n_in_row < 3)
	{
		return 0;
	}
	//3 : 1 (3 in row)
	//4 : 2 (3 in row)
	//5 : 3 (3 in row)
	return n_in_row - 2;
}
int X_O_5x5_Board::evaluate(unsigned long long bitBoard)
{
	return evaluate_cols(bitBoard) + evaluate_rows(bitBoard) + evaluate_diag1(bitBoard) + evaluate_diag2(bitBoard);
}
int X_O_5x5_Board::evaluate_cols(unsigned long long bitBoard)
{
	int c = 0;
	for (int i = 0; i < n_cols; i++)
	{
		c += evaluate_row(bitBoard & (col_mask << (i * (n_rows + 1))), 1);
	}
	return c;
}
int X_O_5x5_Board::evaluate_rows(unsigned long long bitBoard)
{
	int c = 0;
	for (int i = 0; i < n_cols; i++)
	{
		c += evaluate_row(bitBoard & (row_mask << (i)), 6);
	}
	return c;
}
int X_O_5x5_Board::evaluate_diag1(unsigned long long bitBoard)
{
	return 0;
}
int X_O_5x5_Board::evaluate_diag2(unsigned long long bitBoard)
{
	return 0;
}
bool X_O_5x5_Board::game_is_over()
{
	if (moves_available())
	{
		return false;
	}
	end_score = evaluate(board);
	if (end_score > 0)
	{
		cout << "X wins!\n";
	}
	else if(end_score < 0)
	{
		cout << "O wins!\n";
	}
	else
	{
		cout << "Draw!\n";
	}
	return true;
}
bool X_O_5x5_Board::moves_available()
{
	return board.moves < max_moves;
}