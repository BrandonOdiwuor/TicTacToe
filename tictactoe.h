#ifndef _tictactoe_h
#define _tictactoe_h
/*
 * File: TickTackToe.cpp
 * Author: Brandon Wayne Odiwuor
 * Date: September 09, 2018
 * -----------------------------
 *  A console prorgram simulating the TicTackToe game.
 *  The game is played between the computer and  one user via the console.
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Keeps track of the next move to be made
struct Move {int row; int column; };

// The number of columns ans rows in the board
const int ROWS = 3;
const int COLUMNS = 3;

/*
 * Function: startingPlayer
 * Usage: int starter = StartingPlayer();
 * --------------------------------------
 * Returns 0 or 1 used in deciding which player is to start
 * 0 = computer
 * 1 = user
 */

int startingPlayer();

/*
 * Function: print
 * Usage: print(board[ROWS][COLUMNS]);
 * --------------------------
 *  Prints the current state of the board
 */

void print(char board[ROWS][COLUMNS]);

/*
 * Function: hasPlayerWon
 * Usage: bool hasWon = hasPlayerWon(board[ROWS][COLUMNS], "X");
 * ----------------------------------------------------
 * Returns true when the Player whose symbol has been given has won and false otherwise
 */

bool hasPlayerWon(char board[ROWS][COLUMNS], char playerSymbol);

/*
 * Function: gameOver
 * Usage: bool isOver = gameOver(board[ROWS][COLUMNS], moves);
 * --------------------------------------------------
 *  Returns true if a player has won the game or the board is full and false otherwise
 */

bool gameOver(char board[ROWS][COLUMNS], int moves);

/*
 * Function: getInteger
 * Usage: int num = getInteger()
 * -----------------------------
 * Returns an integer input entered by the user from the console
 */

int getInteger();

/*
 * Function: promptUserForMove
 * Usage: Move move = promptUserForMove(char board[ROWS][COLUMNS])
 * -----------------------------------------------------------------
 *  The function prompts user to enter their move and validates the inputs entered
 *  Returns a struct Move cotaining users inputs
 */

Move promptUserForMove(char board[ROWS][COLUMNS]);

/*
 * Function: computersNextMove
 * usage: Move move = computersNextMove(char board[ROWS][COLUMNS]);
 * -----------------------------------------------------------------
 *  The function generates the next move for the computer player
 */

Move computersNextMove(char board[ROWS][COLUMNS]);


int startingPlayer() {
	return rand() % 2;
}

void print(char board[ROWS][COLUMNS]) {
	string line = "-------------";
	cout << line << endl;
	for(int i = 0; i < ROWS; i++) {
		cout << "| ";
		for(int j = 0; j < COLUMNS; j++) {
			cout << board[i][j];
			if(j < COLUMNS - 1) { cout << " | "; }
		}
		cout << " |" << endl << line << endl;
	}
}

bool hasPlayerWon(char board[ROWS][COLUMNS], char symbol) {
	bool rowZeroCheck = ((symbol == board[0][0]) && (symbol == board[0][1])  && (symbol == board[0][2]));
	bool rowOneCheck = ((symbol == board[1][0]) && (symbol == board[1][1]) && (symbol == board[1][2]));
	bool rowTwoCheck = ((symbol == board[2][0]) && (symbol == board[2][1]) && (symbol == board[2][2]));
	bool colZeroCheck = ((symbol == board[0][0]) && (symbol == board[1][0]) && (symbol == board[2][0]));
	bool colOneCheck = ((symbol == board[0][1]) && (symbol == board[1][1]) && (symbol == board[2][1]));
	bool colTwoCheck = ((symbol == board[0][2]) && (symbol == board[1][2]) && (symbol == board[2][2]));
	bool diagOneCheck = ((symbol == board[0][0]) && (symbol == board[1][1]) && (symbol == board[2][2]));
	bool diagTwoCheck = ((symbol == board[0][2]) && (symbol == board[1][1]) && (symbol == board[2][0]));

	if(rowZeroCheck || rowOneCheck || rowTwoCheck || diagOneCheck || diagTwoCheck || colZeroCheck || colOneCheck ||  colTwoCheck) {
		return true;
	}
	return false;
}

bool gameOver(char board[ROWS][COLUMNS], int moves) {
	if(moves == (ROWS * COLUMNS) || hasPlayerWon(board, 'X') || hasPlayerWon(board, 'O')) {
		return true;
	}
	return false;
}

int getInteger() {
	int num;
	bool fail = true;
	do {
		cin >> num;
		fail = cin.fail();
                if (fail) {
                	cin.clear();
                	cin.ignore();
			cout << "Enter a valid input: ";
                }

	} while(fail);
	return num;
}

Move promptUserForMove(char board[ROWS][COLUMNS]) {
        Move move;

	bool invalidInputs = true;
        while(invalidInputs) {
                cout << "Enter Row: ";
                move.row = getInteger();
                cout << "Enter column: ";
                move.column = getInteger();

                bool outOfBoundInputs = (move.column < 0) || (move.column > COLUMNS - 1) || (move.row < 0) || (move.row > ROWS - 1);
                bool slotOccupied = board[move.row][move.column] != '-';

                if(invalidInputs = (outOfBoundInputs || slotOccupied)) {
                        if(outOfBoundInputs)
                                cout << "Column or Row cannot be less than 0 or greater than 2" << endl;
                        if(slotOccupied)
                                cout << "Slot already occupied" << endl;
                }
        }
	return move;

}

Move computersNextMove(char board[ROWS][COLUMNS]) {
	Move move;

	bool invalidInputs = true;
	while(invalidInputs) {
		move.row = rand() % ROWS;
		move.column = rand() % COLUMNS; 
		invalidInputs = (board[move.row][move.column] != '-');
	}
	cout << "Computers move " << move.row << " , " << move.column << endl;
	return move;
}

#endif
