#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main() {
    TicTacToe game;
    char currentPlayer = 'X';
    int row, col;
    char winner = ' ';

    while (winner == ' ' && !game.isBoardFull()) {
        game.printBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column). " << endl;
        cout << "Row: ";
        cin >> row;
        cout << "COlumn: ";
        cin >> col;

        // Validate input
        if (cin.fail() || row < 0 || row >= 3 || col < 0 || col >= 3) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter numbers between 0 and 2." << endl;
            continue; // prompt the user again
        }


        if (game.makeMove(row, col, currentPlayer)) {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else {
            cout << "Invalid move. Try again." << endl;
        }
        winner = game.checkWinner();
    }
    game.printBoard();
    if (winner != ' ') {
        cout << "Player " << winner << " wins!" << endl;
    }
    else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
