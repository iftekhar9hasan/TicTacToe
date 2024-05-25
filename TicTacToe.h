#pragma once
#include<iostream>

using namespace std;

class TicTacToe {
	private:
		char board[3][3];

	public: 
		TicTacToe();

		void printBoard();
		bool makeMove(int row, int col, char player);
		char checkWinner();
		bool isBoardFull();
};

	
