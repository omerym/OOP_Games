#ifndef PyramidXOH
#define PyramidXOH
#include "BoardGame_Classes.hpp"
class PyramidXO:public Board {
protected: 
static int odd;
int win;
static int counter;
public:
   PyramidXO ();
   bool update_board (int x, int y, char mark);
   void display_board();
   bool is_winner();
   bool valid_column(int x);
   bool is_winner(int x,int y,char mark,int vert=0,int horiz=0);
   bool is_draw();
   bool game_is_over();
   int calc_max_moves();
};
#endif