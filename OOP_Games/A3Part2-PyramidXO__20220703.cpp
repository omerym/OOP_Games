#include <iostream>
#include"BoardGame_Classes.hpp"
#include <cctype>
#include <iomanip>
using namespace std;
    int PyramidXO::odd=0;
    int PyramidXO::counter=0;
    PyramidXO::PyramidXO()
    {
        int space=2;
        int rem=0;
        this->n_rows=3;
        this->win=3;
        this->n_cols=5;
        this->odd=1;

        board= new char*[n_rows];
        for (int i =0;i<n_rows;i++)
        {
            rem=(n_cols-space);
            board[i]=new char[n_cols];
            for(int j=0;j<n_cols;j++)
            {
                
                if(j>=0&&j<space)
                {
                    board[i][j]=' ';
                }
                else if(j>=rem&&j<n_cols)
                {
                    board[i][j]=' ';
                }
                else
                {
                    board[i][j]='0';
                }
                
                    
            }
            space-=1;
        }
    }
      bool PyramidXO::update_board(int x, int y, char mark)
      {
        if(board[x][y]=='0'&&x>=0&&x<n_rows&&y>=0&&y<n_cols)
        {
            board[x][y]=mark;
            n_moves++;
            display_board();
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
                if(board[i][j]!=' '||board[i][j]!=0)
                {
                return is_winner(i,j,board[i][j]);
                }
            }
        }
        return false;
      }
      bool PyramidXO::is_winner(int x,int y, char mark,int vert,int horiz)
      {
        if(x>=0&&x<n_rows&&y>=0&&y<n_cols&&x+vert<n_rows&&x+vert>=0&&y+horiz<n_cols&&y+horiz>=0&&board[x][y]!=' ')
        {    board[x][y]='~';
            counter++;
            display_board();
            if(counter==this->win)
            {
                counter=0;
                return true;
            }
            if(vert==0&&horiz==0)
            {
                    for(int i =-1;i<2;i++)
                    {
                        for(int j =-1;j<2;j++)
                        {
                            if(x+i>=0&&x+i<n_rows&&x+j>=0&&x+j<n_cols)
                            {    if(board[x+i][y+j]==mark)
                                {
                                    is_winner((x+i),(y+j),mark,i,j);
                                }
                                
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
            counter--;
        }
            return false;
      }
      bool PyramidXO::is_draw()
      {
        if(n_moves>=10&&!is_winner())
        {
            return true;
        };
        return false;
      }
      void PyramidXO::display_board() 
    {
        cout<<endl;
        int space=2;
        int rem=0;
        for (int i =0;i<this->n_rows;i++)
        {
            for(int j=0;j<n_cols;j++)
            {
                
                cout<<setw(2)<<board[i][j];
            }
            cout<<endl;
        }
        cout << endl;
    }
      bool PyramidXO::game_is_over()
      {
        return (n_moves>=10);
      }
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