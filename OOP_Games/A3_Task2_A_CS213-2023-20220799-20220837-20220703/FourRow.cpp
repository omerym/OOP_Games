#include "FourRow.hpp"
#include <iostream>
using namespace std;
FourRowBoard::FourRowBoard()
{
    for (int x = 0; x < n_rows; x++) {
        for (int y = 0; y < n_cols; y++) {
            boardFourRow[x][y] = 0;
        }
    }
    
n_cols = 7;
n_rows = 6;
}
bool FourRowBoard::is_winner()
{
    for (int row = 0; row < 6;row++) {
        for (int col = 0; col < 4; col++) {
            int cell = boardFourRow[row][col];
            if (cell != 0 &&
                boardFourRow[row][col + 1] == cell &&
                boardFourRow[row][col + 2] == cell &&
                boardFourRow[row][col + 3] == cell) {
                return true;
            }
        }
    }

    
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 7; col++) {
            int cell = boardFourRow[row][col];
            if (cell != 0 &&
                boardFourRow[row + 1][col] == cell &&
                boardFourRow[row + 2][col] == cell &&
                boardFourRow[row + 3][col] == cell) {
                return true;
            }
        }
    }

    // Check for a winner diagonally left down 
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 4; col++) {
            int cell = boardFourRow[row][col];
            if (cell != 0 &&
                boardFourRow[row + 1][col + 1] == cell &&
                boardFourRow[row + 2][col + 2] == cell &&
                boardFourRow[row + 3][col + 3] == cell) {
                return true;
            }
        }
    }

    
    for (int row = 3; row < 6; row++) {
        for (int col = 0; col < 4; col++) {
            int cell = boardFourRow[row][col];
            if (cell != 0 &&
                boardFourRow[row - 1][col + 1] == cell &&
                boardFourRow[row - 2][col + 2] == cell &&
                boardFourRow[row - 3][col + 3] == cell) {
                return true;
            }
        }
    }

    return false;
}
bool FourRowBoard::game_is_over()
{
    return (this->moves >= 42) || is_winner();
}
bool FourRowBoard::is_draw()
{
    return (this->moves >= 42) && !is_winner();
}
bool FourRowBoard::update_board (int x, int y, char symbol)
{
    int player = symbol == 'x'? 1 : 2;
    return update_board(x-1,player);
}
bool FourRowBoard::update_board(int inputNumber,int player, int numberIndex)
{
    if (inputNumber < 0 || inputNumber >= n_cols)
    {
        return false;
    }
    for (int y = n_rows - 1; y >= 0; y--)
    {
        if (boardFourRow[inputNumber][y] == 0)
        {
            boardFourRow[inputNumber][y] = player;
            return true;
        }
        
    }
 
        return false;
}
void FourRowBoard::display_board()
{ 
    for (int  i = 1; i <= n_cols; i++)
    {
            cout << " " << i << " ";
    }
    
    cout << endl;
    for (int y = 0; y < n_rows; y++)
    {
        for (int x = 0; x < n_cols; x++)
        {
            int cell = boardFourRow[x][y];
            char mark;
            switch (cell)
            {
            case 0:
            mark = '#';
            break;
            case 1:
            mark = 'X';
            break;
            case 2:
            mark = 'O';
            break;
            }
            cout << " " << mark << " ";
        }
        
        cout << endl;
    }
    cout << "\n\n\n";
}