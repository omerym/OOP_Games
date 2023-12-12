#include <iostream>
#include"BoardGame_Classes.hpp"
#include <cctype>
#include <iomanip>
using namespace std;
    PyramidXO::PyramidXO()
    {
        
        this->n_rows=3;
        this->win=3;
        this->n_cols=5;
        this->odd=1;

        board= new char*[n_rows];
        for (int i =0;i<n_rows;i++)
        {
            board[i]=new char[odd];
            for(int j=0;j<odd;j++)
            {
                board[i][j]=0;
            }
            odd+=2;
        }
    }
      bool PyramidXO::valid_row(int x)
      {
        int value=0;
        for(int i=0;i<x;i++)
        {
            value+=odd;
            odd+=2;
        }
        if(value>=x||value<x)
        {
            return true;
        }
        return false;
      }
      bool PyramidXO::update_board(int x, int y, char mark)
      {
        if(y>=0||y<n_cols||this->valid_row(x))
        {
            board[x][y]=toupper(mark);
            n_moves++;
            return true;
        }
        return false;
      }
      bool PyramidXO::is_winner()
      {
        for (int i=0;i<n_rows;i++)
        {
            for (int j=0;j<n_cols;j++)
            {
                return is_winner(i,j,board[i][j]);
            }
        }
        return false;
      }
      bool PyramidXO::is_winner(int x,int y, char mark,int vert,int horiz)
      {
        board[x][y]='~';
        counter++;
        if(counter==this->win)
        {
            return true;
        }
        if(vert==0&&horiz==0)
        {
            for(int i =-1;i<2;i++)
            {
                for(int j =-1;j<2;j++)
                {
                    if(board[x+i][j+j]==mark)
                    {
                        is_winner((x+i),(y+j),mark,vert=i,horiz=j);
                    }
                }
            }
        }
        else
        {
            if(board[x+vert][y+horiz]==mark)
            {
                is_winner(x,y,mark,vert,horiz);
            }
        }
        board[x][y]=mark;
        return false;
      }
      bool PyramidXO::is_draw()
      {
        if(n_moves>calc_max_moves()&&!is_winner())
        {
            return true;
        };
        return false;
      }
      void PyramidXO::display_board() 
    {
        for (int i=0;i<n_rows;i++) {
            cout << "\n| ";
            for (int j=0;j<n_cols;j++) {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board [i][j] << " |";
            }
            cout << "\n-----------------------------";
        }
        cout << endl;
    }
      bool PyramidXO::game_is_over()
      {
        return (n_moves>=calc_max_moves());
      }
      int PyramidXO::calc_max_moves()
      {
        int size;
        for(int i=0;i<this->n_rows;i++)
        {
            size+=odd;
            odd+=2;
            size+=size;
        }
        return size;
      }
      int PyramidXO::counter=0;
// class Board {
// protected:
//    int n_rows, n_cols;
//    char** board;
//    int  n_moves = 0;

// public:
//    // Return true  if move is valid and put it on board
//    // within board boundaries in empty cell
//    // Return false otherwise
//    virtual bool update_board (int x, int y, char symbol) = 0;
//    // Returns true if there is any winner
//    // either X or O
//    // Written in a complex way. DO NOT DO LIKE THIS.
//    virtual bool is_winner() = 0;
//    // Return true if all moves are done and no winner
//    virtual bool is_draw() = 0;
//    // Display the board and the pieces on it
//    virtual void display_board() = 0;
//    // Return true if game is over
//    virtual bool game_is_over() = 0;
// };