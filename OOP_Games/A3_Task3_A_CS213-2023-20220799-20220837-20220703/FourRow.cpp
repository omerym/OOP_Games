#include "FourRow.hpp"
#include <iostream>

using namespace std;

FourRowBoard::FourRowBoard() {
    n_cols = 7;
    n_rows = 6;

    for (int x = 0; x < n_rows; x++) {
        for (int y = 0; y < n_cols; y++) {
            boardFourRow[x][y] = 0;
        }
    }
}

bool FourRowBoard::is_winner() {
    // Check horizontally
    for (int row = 0; row < n_rows; row++) {
        for (int col = 0; col < n_cols - 3; col++) {
            int cell = boardFourRow[row][col];
            if (cell != 0 &&
                boardFourRow[row][col + 1] == cell &&
                boardFourRow[row][col + 2] == cell &&
                boardFourRow[row][col + 3] == cell) {
                return true;
            }
        }
    }

    // Check vertically
    for (int row = 0; row < n_rows - 3; row++) {
        for (int col = 0; col < n_cols; col++) {
            int cell = boardFourRow[row][col];
            if (cell != 0 &&
                boardFourRow[row + 1][col] == cell &&
                boardFourRow[row + 2][col] == cell &&
                boardFourRow[row + 3][col] == cell) {
                return true;
            }
        }
    }

    // Check diagonally (left-down)
    for (int row = 0; row < n_rows - 3; row++) {
        for (int col = 0; col < n_cols - 3; col++) {
            int cell = boardFourRow[row][col];
            if (cell != 0 &&
                boardFourRow[row + 1][col + 1] == cell &&
                boardFourRow[row + 2][col + 2] == cell &&
                boardFourRow[row + 3][col + 3] == cell) {
                return true;
            }
        }
    }

    // Check diagonally (left-up)
    for (int row = 3; row < n_rows; row++) {
        for (int col = 0; col < n_cols - 3; col++) {
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

bool FourRowBoard::game_is_over() {
    return (moves >= n_cols * n_rows) || is_winner();
}

bool FourRowBoard::is_draw() {
    return (moves >= n_cols * n_rows) && !is_winner();
}

bool FourRowBoard::update_board (int x, int y, char symbol)
{
    int player = symbol == 'x'? 1 : 2;
    return update_board(x-1,player);
}



bool FourRowBoard::update_board(int col, int player, int numberIndex) {
    if (col < 0 || col >= n_cols) {
        return false;
    }

    for (int row = n_rows - 1; row >= 0; row--) {
        if (boardFourRow[row][col] == 0) {
            boardFourRow[row][col] = player;
            moves++;
            return true;
        }
    }

    return false;
}

void FourRowBoard::display_board() {
    for (int i = 1; i <= n_cols; i++) {
        cout << " " << i << " ";
    }

    cout << endl;

    for (int row = 0; row < n_rows; row++) {
        for (int col = 0; col < n_cols; col++) {
            int cell = boardFourRow[row][col];
            char mark;

            switch (cell) {
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