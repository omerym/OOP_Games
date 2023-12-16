// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <cstdlib> 
#include <iostream>
#include"BoardGame_Classes.hpp"
#include"X_O_5x5.hpp"
#include"AiPlayer.hpp"
#include <time.h> 
#include "PyramidXO.hpp"
using namespace std;

void game1() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();
    system ("pause");
    
}
void game2() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new PyramidXO(), players);
    x_o_game.run();
    system ("pause");
    
}
void game4() {
    Player* players[2];
    X_O_5x5_Board* board = new X_O_5x5_Board;
    players[0] = new AiPlayer('x', 2, &(board->board));
    players[1] = new AiPlayer('o', 2, &(board->board));
    string message = "1. human player\n2. random player\n3.AI Player\n";
    int c;
    cout << "Select player 1 type:\n" << message;
    cin >> c;
    switch (c)
    {
    case 1:
        players[0] = new Player(1, 'x');
        break;
    case 2:
        players[0] = new RandomPlayer('x', 5);
        break;
    case 3:
            players[0] = new AiPlayer('x', 3, &(board->board));
            break;
    }
    cout << "Select player 2 type:\n" << message;
    cin >> c;
    switch (c)
    {
    case 1:
        players[1] = new Player(2, 'o');
        break;
    case 2:
        players[1] = new RandomPlayer('o', 5);
        break;
    case 3:
        players[1] = new AiPlayer('o', 3, &(board->board));
        break;
    }
    GameManager x_o_game(board, players);
    x_o_game.run();
    system("pause");

}
int main()
{
    srand(time(0));
    int g;
    cout << "What game to play?\n";
    cout << "1. Tic Tac Toe\n";
    cout << "2. Pyramid Tic Tac Toe\n";
    cout << "4. 5 x 5 Tic Tac Toe\n";
    cin >> g;
    switch (g) 
    {
    case 1:
        game1();
        break;
    case 2:
        game2();
        break;
    case 4:
        game4();
        break;
    }
}
