#include<iostream>
using namespace std;

int boardFourRow[6][7];

int numberIndex = 5;
int player = 1;
bool endGame = false;

void lineInput(int inputNumber) {
    if (numberIndex >= 0) {
        if (boardFourRow[numberIndex][inputNumber] != 0) {
            numberIndex--;
            lineInput(inputNumber);
        } else {
            boardFourRow[numberIndex][inputNumber] = player;
            numberIndex = 5;
        }
    } else {
        cout << "Wrong input, try again\n";
        player = (player == 1) ? 2 : 1;
    }
}

void printrowsandcolumns() {
    for (int y = 0; y < 7; y++) {
        cout << " " << y + 1 << " ";
    }
    cout << "\n";
    for (int x = 0; x < 6; x++) {
        for (int y = 0; y < 7; y++) {
            cout << "|";
            if (boardFourRow[x][y] == 0) {
                cout << " ";
            } else if (boardFourRow[x][y] == 1) {
                cout << "X";
            } else if (boardFourRow[x][y] == 2) {
                cout << "O";
            }
            cout << "|";
        }
        cout << "\n";
    }
}

void checkWinner() {
    // Check for a winner horizontally (row)
    for (int x = 0; x < 6; x++) {
        for (int y = 0; y < 4; y++) {
            if (boardFourRow[x][y] == player && boardFourRow[x][y + 1] == player &&boardFourRow[x][y + 2] == player &&boardFourRow[x][y + 3] == player) {
                endGame = true;

                cout << "\nPlayer " << player << " wins \n";
            } else if (boardFourRow[x][y] == player && x >= 3 && boardFourRow[x - 1][y] == player &&boardFourRow[x - 2][y] == player &&boardFourRow[x - 3][y] == player) {
                endGame = true;
                cout << "\nPlayer " << player << " wins \n";

            } else if (boardFourRow[x][y] == player &&x >= 3 && y >= 3 && boardFourRow[x - 1][y - 1] == player &&boardFourRow[x - 2][y - 2] == player &&boardFourRow[x - 3][y - 3] == player) {
                endGame = true;
                cout << "\nPlayer " << player << " wins\n";
                
            } else if (boardFourRow[x][y] == player&&x >= 3 && y <= 3 && boardFourRow[x - 1][y + 1] == player &&boardFourRow[x - 2][y + 2] == player &&boardFourRow[x - 3][y + 3] == player) {
                endGame = true; 
                cout << "\nPlayer " << player << " wins \n";
            }
        }
    }
};


int main() {
    while (!endGame) {
        printrowsandcolumns();
        cout << "Enter player Number " << player << ": ";
        int inputNumber;
        cin >> inputNumber;
        lineInput(inputNumber - 1); 
        printrowsandcolumns();
        checkWinner();
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
