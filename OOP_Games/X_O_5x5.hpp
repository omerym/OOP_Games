#ifndef XO5X5
#define XO5X5
#include "BoardGame_Classes.hpp"
class X_O_5x5_Board :public Board {
public:
	int moves = 0;
	/*
	mapping from index to position in board, 
	adding an extra column and an extra row to help with calculations.
	5  11 17  23  29 35
	4  10 16  22  28 34
	3  9  15  21  27 33
	2  8  14  20  26 32
	1  7  13  19  25 31
	0  6  12  18  24 30 
	*/
	unsigned long long x_bitBoard = 0;
	unsigned long long o_bitBoard = 0;
	unsigned long long board_bitBoard();
	bool is_set(unsigned long long bitBoard, int index);
	int get_index(int x, int y);
public:
	X_O_5x5_Board();
	bool update_board(int x, int y, char mark);
	void display_board();
	bool is_winner();
	bool is_draw();
	bool game_is_over();
};
#endif
