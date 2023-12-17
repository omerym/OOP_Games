#include "X_O_5x5.hpp"
#include <iostream>
using namespace std;
X_O_5x5_Board::X_O_5x5_Board()
{
	Board::n_rows = 5;
	Board::n_cols = 5;
}
bool X_O_5x5_Board::update_board(int x, int y, char mark)
{
	return board.update_board(x, y, mark);
}
void X_O_5x5_Board::display_board()
{
	board.display();
}
bool X_O_5x5_Board::is_winner()
{
	return false;
}
bool X_O_5x5_Board::is_draw()
{
	return false;
}
bool X_O_5x5_Board::game_is_over()
{
	if (moves_available())
	{
		return false;
	}
	end_score = board.evaluate();
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
	return board.moves() < board.max_moves;
}