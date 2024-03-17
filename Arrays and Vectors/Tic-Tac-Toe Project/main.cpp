/*
		Tic-Tac-Toe Project Design:
			- runGame: the game loop
			- initializeGame: sets the cells of the 2D array to spaces
			- printCurrentBoard: prints whatever is in the current board
			- cellAlreadyOccupied: returns true if a given cel is already occupied
			- getWinner: returns X, O if there is clear winner
*/

#include <iostream>
#include <string>
#include <array>		// Here we import array class
#include <vector>		// Here we import vector class

using namespace std;


const int BOARD_SIZE = 3;

//  Functions
void printCurrentBoard(char board[BOARD_SIZE][BOARD_SIZE]);
char cellAlreadyOccupied(char cell);											 // Checks if a given cell is already X or O
void cellAlreadyOccupied(char board[BOARD_SIZE][BOARD_SIZE], int& i, int& j);    // Checks if a given cell is on the board and empty
void checkChar(char& yourChar, char& opponentChar);								 // Recursive function to check if the player picked X or O
char getWinner(char board[BOARD_SIZE][BOARD_SIZE]);								 // Check if there is a winner

int main() {
	char board[BOARD_SIZE][BOARD_SIZE]; // Here we define our empty board
	int i,j, num_plays = 0;             // Here we initialize indexes and num_plays to proceed the game
	char yourChar,opponentChar;			// First players symbol (X or O)
	

	cout << "Welcome to Tic-Tac-Toe! Please choose X or O!" << endl;
	cin >> yourChar;
	checkChar(yourChar, opponentChar);

	printCurrentBoard(board); // Here we output the empty board to guide the players
	while (num_plays < BOARD_SIZE * BOARD_SIZE && getWinner(board) == ' ')
	{
		
		cout << "Please enter a location for your move on Tic-Tac-Toe board between 1 and 3 both for column and row!" << endl;
		cin >> i >> j;
		cellAlreadyOccupied(board, i, j);
		if (num_plays%2 == 0)
			board[i-1][j-1] = yourChar;
		else
			board[i-1][j-1] = opponentChar;

		printCurrentBoard(board); // Here we output the board to guide the players
		if (getWinner(board) == ' ')
			;
		else
		{
			cout << getWinner(board) << " won the game" << endl;
		}
			
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

void cellAlreadyOccupied(char board[BOARD_SIZE][BOARD_SIZE], int& i, int& j) 
{
	if (cellAlreadyOccupied(board[i-1][j-1]) == ' ' && i <= 3 && j <= 3)
		;
	else
	{
		cout << "Please enter an empty location on the board " << endl;
		cin >> i >> j;
		cellAlreadyOccupied(board, i, j);

	}
}
void checkChar(char& yourChar, char& opponentChar)
{
	if (yourChar == 'X' || yourChar == 'O')
		if (yourChar == 'X')
			opponentChar = 'O';
		else
			opponentChar = 'X';
	else
	{
		cout << "You entered a wrong character, Please enter X or O!" << endl;
		cin >> yourChar;
		checkChar(yourChar, opponentChar);
	}
}

char getWinner(char board[BOARD_SIZE][BOARD_SIZE]) {
	char winner = ' ';
	
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		winner = 'X';
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		winner = 'X';
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		winner = 'X';
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
		winner = 'X';
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
		winner = 'X';
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
		winner = 'X';
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		winner = 'X';
	else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
		winner = 'X';
	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		winner = 'O';
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		winner = 'O';
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		winner = 'O';
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
		winner = 'O';
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
		winner = 'O';
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
		winner = 'O';
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		winner = 'O';
	else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
		winner = 'O';
	
	return winner;
}
