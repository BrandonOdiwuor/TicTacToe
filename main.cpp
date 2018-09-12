/*
 * File: main.cpp
 * Author: Brandon Wayne Odiwuor
 * Date: 12th September, 2018
 * -----------------------------
 *  Main for the Tic-Tac-Toe program
 */

#include "tictactoe.h"

int main() {
	// Initialize random seed to random generator
	srand (time(NULL));
	
	// Initialize a new board
	char board[ROWS][COLUMNS] = {'-', '-', '-','-', '-', '-','-', '-', '-'};

	char userSymbol = 'X';
	char computerSymbol = 'O';
	
	int moves = 0; // Keeps track of the total number of turns taken

	// Randomy pick the starting player
	int currentPlayer = startingPlayer();

	while(!gameOver(board, moves)) {
		if(currentPlayer == 0) { // computers turn
			Move next = computersNextMove(board);
			board[next.row][next.column] = computerSymbol;

			currentPlayer = 1; // Change the current player
		} else { // Users turn
			print(board);
			Move next = promptUserForMove(board);
			board[next.row][next.column] = userSymbol;

			currentPlayer = 0; // change the current player
		}
		moves++;
	}

	/* Determining winner */
	if(hasPlayerWon(board, computerSymbol)) {
		cout << "The computer has won" << endl;
	} else if(hasPlayerWon(board, userSymbol)) {
		cout << "You have won" << endl;
	} else {
		cout << "Its a draw" << endl;
	}
	print(board);

	return 0;
}
