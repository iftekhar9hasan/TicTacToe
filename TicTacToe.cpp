#include "TicTacToe.h"

TicTacToe::TicTacToe() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void TicTacToe::printBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << board[i][j];
			if (j < 2) {
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 2) {
			cout << "---------" << endl;
		}
	}
}

bool TicTacToe::makeMove(int row, int col, char player) {
	if (row < 0 || row >= 3 || col >= 3 || board[row][col] != ' ') {
		return false;
	}
	board[row][col] = player;
	return true;
}

char TicTacToe::checkWinner() {
	// Check rows and columns
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
			return board[0][i];
		}
	}
	// Check diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
		return board[0][2];
	}
	return ' '; // No winner
}

bool TicTacToe::isBoardFull() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}