#include <iostream>
#include"BoardGame_Classes.hpp"
#include "PyramidXO.hpp"
#include <cctype>
#include <iomanip>
using namespace std;
    PyramidXO::PyramidXO()
    {
        
        int space=2;
        int rem=0;
        this->n_rows=3;
        this->win=3;
        this->n_cols=5;
        this->n_moves = 0;
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
    PyramidXO::PyramidXO(const PyramidXO & other)
    {
        this->n_rows=other.n_rows;
        this->win=other.win;
        this->n_cols=other.n_cols;
        this->n_moves = other.n_moves;
        board= new char*[n_rows];
        for (int i =0;i<n_rows;i++)
        {
            board[i]=new char[n_cols];
            for(int j=0;j<n_cols;j++)
            {
                    board[i][j]= other.board[i][j]; 
            }
        }
    }
    
   PyramidXO& PyramidXO::operator= (const PyramidXO& other)
   {
        this->n_moves = other.n_moves;
        for (int i = 0; i < n_rows; i++)
        {
            delete [] board[i];
        }
        delete [] board;
       board= new char*[n_rows];
        for (int i =0;i<n_rows;i++)
        {
            board[i]=new char[n_cols];
            for(int j=0;j<n_cols;j++)
            {
                    board[i][j]= other.board[i][j]; 
            }
        }
    return *this;
   }
      bool PyramidXO::update_board(int x, int y, char mark)
      {
        int PlayX,PlayY;
        PlayX=x-1;
        PlayY=y-1;
        if(PlayX>=0&&PlayX<n_rows&&PlayY>=0&&PlayY<n_cols)
        {
            if(board[PlayX][PlayY]=='0')
           {     
            board[PlayX][PlayY]=mark;
                n_moves++;
                return true;
            }
        }
        return false;
      }
      bool PyramidXO::is_winner()
      {
        for (int i=0;i<n_rows;i++)
        {
            for (int j=0;j<n_cols;j++)
            {
                if(board[i][j]==' '||board[i][j]=='0')
                {
                }
                else
                {
                    if(is_winner(i,j,board[i][j]))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
      }
      bool PyramidXO::is_winner(char mark)
      {
        for (int i=0;i<n_rows;i++)
        {
            for (int j=0;j<n_cols;j++)
            {
                if(board[i][j]==' '||board[i][j]=='0')
                {
                }
                else
                {
                    if(is_winner(i,j,mark))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
      }
      bool PyramidXO::is_winner(int x,int y, char mark)
      {
        int tempcounter=1;
        for(int i =-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                tempcounter=1;
                    for (int temp =1;temp<win;temp++)
                    {
                        
                        if(!(i==0&&j==0))
                        {
                        int moveX=i*temp;
                        int moveY=j*temp;
                            
                            if((x+moveX)>=0&&(x+moveX)<n_rows&&(y+moveY)>=0&&(y+moveY)<n_cols)
                            {
                                if(board[x+moveX][y+moveY]==mark)
                                {
                                    tempcounter++;
                                    if(tempcounter>=win)
                                    {
                                        return true;
                                    }
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
            }
        }
        
            return false;
      }
      bool PyramidXO::is_draw()
      {
        if(n_moves>=9&&!is_winner())
        {
            return true;
        }
        return false;
      }
      void PyramidXO::display_board() 
    {
        cout<<endl << endl;
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
        for (int i =0;i<this->n_rows;i++)
        {
            for(int j=0;j<n_cols;j++)
            {
                if(board[i][j]!=' ')
                {
                    cout<<setw(2)<<'('<<i+1<<','<<j+1<<')';
                }
                else
                {
                    cout<<setw(2)<<board[i][j];
                }
                
            }
            cout<<endl;
        }
        cout << endl << endl;
    }
      bool PyramidXO::game_is_over()
      {
        return (n_moves>=9);
      }
    void PyramidXO::generate_moves(vector<PyramidXO>& moves)
    {
        char mark = (n_moves % 2 == 0) ? 'x' : 'o';

        for (int i = 1; i <= n_rows; i++)
        {
            for (int j = 1; j <= n_cols; j++)
            { 
                    PyramidXO x = *this;
                    if ((x.update_board(i,j,mark)))
                    {
                         moves.push_back(x);
                    }
            }
            
        }
        
    }
	void PyramidXO::generate_moves(vector<pair<PyramidXO, Position>>& moves)
    { 
        char mark = (n_moves % 2 == 0) ? 'x' : 'o';
        for (int i = 1; i <= n_rows; i++)
        {
            for (int j = 1; j <= n_cols; j++)
            { 
                    PyramidXO x = *this;
                    if ((x.update_board(i,j,mark)))
                    {
                        moves.push_back({x, Position(i,j)});
                    }
            }
            
        }
    }
	int PyramidXO::evaluate()
    {
        if (this->is_winner())
        {
            return (n_moves % 2 == 0) ? -INT_MAX : INT_MAX;
        }
        return 0;
    }
    PyramidXO::~PyramidXO()
    {
        delete[] this->board;
    }
    char PyramidXO :: sym=0;
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