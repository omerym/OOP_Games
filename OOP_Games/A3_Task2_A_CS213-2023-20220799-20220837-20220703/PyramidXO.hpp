#ifndef PyramidXOH
#define PyramidXOH
#include "BoardGame_Classes.hpp"
class PyramidXO:public Board {
protected: 
int win;
public:
   PyramidXO ();
   bool update_board (int x, int y, char mark);
   void display_board();
   bool is_winner();
   bool valid_column(int x);
   bool is_winner(int x,int y,char mark);
   bool is_draw();
   bool game_is_over();
   int calc_max_moves();
};
#endif