#ifndef XO5X5
#define XO5X5
#include "BoardGame_Classes.hpp"
class X_O_5x5_BoardData
{
	unsigned long long x_bitBoard = 0;
	unsigned long long o_bitBoard = 0;
	unsigned int _moves = 0;
	int evaluate_cols(unsigned long long bitBoard) const;
	int evaluate_rows(unsigned long long row) const;
	int evaluate_diag1(unsigned long long bitBoard) const;
	int evaluate_diag2(unsigned long long bitBoard) const;
	int evaluate(unsigned long long bitBoard) const;
	int evaluate_row(unsigned long long row, int offset) const;
	static int get_index(int x, int y);
	static const unsigned long long col_mask = 0b11111;
	static const unsigned long long row_mask = ((1 << 0) | (1 << 6) | (1 << 12) | (1 << 18) | (1 << 24));
	static const unsigned long long diag1_mask = ((1 << 4) | (1 << 9) | (1 << 14) | (1 << 19) | (1 << 24)); // diag \;
	static const unsigned long long diag2_mask = ((1 << 0) | (1 << 7) | (1 << 14) | (1 << 21) | (1 << 28)); // dig /;
	unsigned long long board_bitBoard() const;
public:
	void display() const;
	int moves() const;
	static const int max_moves = 24;
	static const int max_in_row = 5;
	static const int n_cols = 5;
	static const int n_rows = 5;
	static bool is_set(unsigned long long bitBoard, int index);
	bool update_board(int x, int y, char mark);
	int evaluate() const;
};
class X_O_5x5_Board :public Board {
public:
	/*
	mapping from index to position in board, 
	adding an extra column and an extra row to help with calculations.
	5  11 17  23  29	35

	4  10 16  22  28	34
	3  9  15  21  27	33
	2  8  14  20  26	32
	1  7  13  19  25	31
	0  6  12  18  24	30 
	*/
	X_O_5x5_BoardData board;
	int end_score = 0;
	bool moves_available();
public:
	X_O_5x5_Board();
	bool update_board(int x, int y, char mark);
	void display_board();
	bool is_winner();
	bool is_draw();
	bool game_is_over();
};
#endif
