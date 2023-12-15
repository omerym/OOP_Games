#ifndef FOURROW
#define FOURROW
#include "BoardGame_Classes.hpp"
class FourRowBoard : public Board
{
private:

public:  
 // Return true  if move is valid and put it on board
   // within board boundaries in empty cell
   // Return false otherwise
   virtual bool update_board (int x, int y, char symbol);
   // Returns true if there is any winner
   // either X or O
   virtual bool is_winner();
   // Return true if all moves are done and no winner
   virtual bool is_draw();
   // Display the board and the pieces on it
   virtual void display_board();
   // Return true if game is over
   virtual bool game_is_over();
};

#endif