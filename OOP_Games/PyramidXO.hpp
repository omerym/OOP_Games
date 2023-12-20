#ifndef PyramidXOH
#define PyramidXOH
#include "BoardGame_Classes.hpp"
#include "Position.hpp"
#include <vector>
#include <limits.h> 
class PyramidXO:public Board {
protected: 
int win;
static char sym;
public:
const int MIN_WIN = INT_MAX;
   PyramidXO ();
   PyramidXO (const PyramidXO & other);
   bool update_board (int x, int y, char mark);
   void display_board();
   bool is_winner();
   bool valid_column(int x);
   bool is_winner(int x,int y,char mark);
   bool is_winner(char mark);
   bool is_draw();
   bool game_is_over();
   int calc_max_moves();
   void generate_moves(vector<PyramidXO>& moves);
	void generate_moves(vector<pair<PyramidXO, Position>>& moves);
	int evaluate();
   PyramidXO& operator= (const PyramidXO& other);
   ~PyramidXO();
};
#endif