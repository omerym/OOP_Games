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
#include "FourRow.hpp"
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
    int max_depth = 9;
     PyramidXO* board = new PyramidXO();
    Player* players[2];
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
        players[0] = new RandomPlayer('x', 6);
        break;
    case 3:
            players[0] = new AiPlayer<PyramidXO>('x', board, max_depth);
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
        players[1] = new RandomPlayer('o', 6);
        break;
    case 3:
            players[1] = new AiPlayer<PyramidXO>('o', board, max_depth);
            break;
    
    }
    GameManager x_o_game(board, players);
    x_o_game.run();
    system("pause");
    
}
void game3() {
     int choice;
    Player* players[2];
    string message = "1. human player\n2. random player\n";
    int c;
    cout << "Select player 1 type:\n" << message;
    cin >> c;
    switch (c)
    {
    case 1:
        players[0] = new Player(1, 'x');
        break;
    case 2:
        players[0] = new RandomPlayer('x', 8);
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
        players[1] = new RandomPlayer('o', 8);
        break;
    }
    GameManager x_o_game(new FourRowBoard(), players);
    x_o_game.run();
    system("pause");
    
}
void game4() {
    int max_depth = 5;
    Player* players[2];
    X_O_5x5_Board* board = new X_O_5x5_Board;
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
            players[0] = new AiPlayer<X_O_5x5_BoardData>('x', &(board->board),max_depth);
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
        players[1] = new AiPlayer<X_O_5x5_BoardData>('o',&(board->board), max_depth);
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
    cout << "3. Four in a row Tic Tac Toe\n";
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
    case 3:
        game3();
        break;
    case 4:
        game4();
        break;
    }
}
