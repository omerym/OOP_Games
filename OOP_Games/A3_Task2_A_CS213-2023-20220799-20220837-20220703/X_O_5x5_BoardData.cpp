#include "X_O_5x5.hpp"
#include <iostream>
using namespace std;

int X_O_5x5_BoardData::moves() const
{
	return _moves;
}
int X_O_5x5_BoardData::evaluate() const
{
	return evaluate(x_bitBoard) - evaluate(o_bitBoard);
}
int X_O_5x5_BoardData::evaluate_row(unsigned long long row, int offset) const
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
int X_O_5x5_BoardData::evaluate(unsigned long long bitBoard) const
{
	return evaluate_cols(bitBoard) + evaluate_rows(bitBoard) + evaluate_diag1(bitBoard) + evaluate_diag2(bitBoard);
}
int X_O_5x5_BoardData::evaluate_cols(unsigned long long bitBoard) const
{
	int c = 0;
	for (int i = 0; i < n_cols; i++)
	{
		c += evaluate_row(bitBoard & (col_mask << (i * (n_rows + 1))), 1);
	}
	return c;
}
int X_O_5x5_BoardData::evaluate_rows(unsigned long long bitBoard) const
{
	int c = 0;
	for (int i = 0; i < n_cols; i++)
	{
		c += evaluate_row(bitBoard & (row_mask << (i)), 6);
	}
	return c;
}
int X_O_5x5_BoardData::evaluate_diag1(unsigned long long bitBoard) const
{
	return 0;
}
int X_O_5x5_BoardData::evaluate_diag2(unsigned long long bitBoard) const
{
	return 0;
}

unsigned long long X_O_5x5_BoardData::board_bitBoard() const
{
	return x_bitBoard | o_bitBoard;
}

int X_O_5x5_BoardData::get_index(int x, int y)
{
	return (x * (n_rows + 1) + y);
}
bool X_O_5x5_BoardData::is_set(unsigned long long bitBoard, int index)
{
	return (bitBoard & (1ll << index)) != 0;
}
bool X_O_5x5_BoardData::update_board(int x, int y, char mark)
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
	_moves++;
	return true;
}
void X_O_5x5_BoardData::display() const
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
		cout << "\n\n";
	}
	cout << "----------------------------------------\n\n";
}