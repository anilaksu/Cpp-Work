/*
		Tic-Tac-Toe Project Design:
			- runGame: the game loop
			- initializeGame: sets the cells of the 2D array to spaces
			- printCurrentBoard: prints whatever is in the current board
			- cellAlreadyOccupied: returns true if a given cel is already occupied
			- getWinner: returns X, O if there is clear winner
			- isBoardFull: returns if the board is full or not
*/

#include <iostream>
#include <string>
#include <array>		// Here we import array class
#include <vector>		// Here we import vector class

using namespace std;


const int BOARD_SIZE = 3;

//  Functions
void printCurrentBoard(char board[BOARD_SIZE][BOARD_SIZE]);
char cellAlreadyOccupied(char cell);

int main() {
	char board[BOARD_SIZE][BOARD_SIZE]; // Here we define our empty board
	int i,j, num_plays = 0;             // Here we initialize indexes and num_plays to proceed the game
	while (num_plays < BOARD_SIZE * BOARD_SIZE)
	{
		cout << "Please enter a location for your move on Tic-Tac-Toe board between 1 and 3 both for column and row!" << endl;
		cin >> i >> j;
		if (num_plays%2 == 0)
			board[i-1][j-1] = 'X';
		else
			board[i-1][j-1] = 'O';

		printCurrentBoard(board); // Here we output the board to guide the players
		num_plays++;
	}

	
	return 0;
}

void printCurrentBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
	cout << " Current configuration of the game board! " << endl; // Top Line in the board
	cout << " ------------- " << endl; // Top Line in the board
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << " | " << cellAlreadyOccupied(board[i][0]) << " | " << cellAlreadyOccupied(board[i][1]) << " | "
			<< cellAlreadyOccupied(board[i][2]) << " | "  <<  endl;
		cout << " ------------- " << endl;
	}
}

char cellAlreadyOccupied(char cell)
{
	return (cell == 'X' || cell == 'O') ? cell : ' ';
}