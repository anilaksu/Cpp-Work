#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Rock Paper Scissors Game against
using namespace std;

class RPS_Game //Here we denote Stone Paper Scissor game as RPS_Game
{
private:
	string Player;    // Player's choice
	string Computer;  // Computer's choice
	int result;       // Result of each game

public: 

	static int Wins, Losses, Draws;
	//constructor (no args)
	RPS_Game() : Player(), Computer(), result()
	{ }

	//constructor (two args)
	RPS_Game(string p1) : Player(p1), Computer(p1), result(0)
	{ }

	// Desctructor
	~RPS_Game()
	{	}

	void setPlayerChoice(string); // Here we set Player's choice
	void setComputerChoice(); // Here we set Computer's choice
	void getResult(); 	// Here We define the result function which determine who won the game
	void getGameInfo(); // Here We get the result of each game
	void getSummary(); // Here We get the summary of all games
};


void RPS_Game::setPlayerChoice(string p1) {
	Player = p1;
}

void RPS_Game::setComputerChoice() {
	/* this function randomly assigns stone, paper or scissor to computer*/

	int n; // the random number
	// Chooses a random number for each game
	srand(time(NULL));
	// Let's create a random number between 1 and 3
	n = rand() % 3 + 1;

	// n== 1 is Stone
	if (n == 1)
		Computer.assign("Stone");
	// n== 2 is Paper
	else if (n == 2)
		Computer.assign("Paper");
	// n== 3 is Scissor
	else
		Computer.assign("Scissor");
}

void RPS_Game::getResult()
{
	/* This function determines who wins each game*/

	// If player and computer choose the same thing
	if (Player == Computer)
		result = -1;

	// If player chooses stone and computer chooses paper
	if (Player == "Stone" && Computer == "Paper")
		result = 0;

	// If player chooses paper and computer chooses stone
	else if (Player == "Paper" && Computer == "Stone") 
		result = 1;

	// If player chooses stone and computer chooses scissor
	if (Player == "Stone" && Computer == "Scissor")
		result = 1;

	// If player chooses scissor and computer chooses is stone
	else if (Player == "Scissor" && Computer == "Stone")
		result = 0;

	// If user's choice is paper and computer's choice is scissor
	if (Player == "Paper" && Computer == "Scissor")
		result = 0;

	// If user's choice is scissor and computer's choice is paper
	else if (Player == "Scissor" && Computer == "Paper")
		result = 1;

	if (result == 1)
		++Wins;
	else if (result == 0)
		++Losses;
	else
		++Draws;
}

void RPS_Game::getSummary() {
	cout << "\nThe summary of all games: " << endl;

	/* Winning scenarios*/
	if (Wins > 1)
		cout << "You won " << Wins << " times" << endl;
	else if (Wins == 1)
		cout << "You won " << Wins << " time" << endl;
	else
		cout << "You didn't win any game" << endl;

	/* Losing scenarios*/
	if (Losses > 1)
		cout << "You lost " << Losses << " times" << endl;
	else if (Losses == 1)
		cout << "You lost " << Losses << " time" << endl;
	else
		cout << "You didn't lose any game " << endl;

	/* Draw scenarios*/
	if (Draws > 1)
		cout << "You got " << Draws << " draws" << endl;
	else if (Draws == 1)
		cout << "You got " << Draws << " draw" << endl;
	else
		cout << "You didn't get a draw against computer" << endl;
}

void RPS_Game::getGameInfo() {
	cout << "\nComputer Choice is: " << Computer << endl;

	if (result == -1) {
		cout << "\n\t\tDraw!" << endl;
	}
	else if (result == 1) {
		cout << "\n\t\tYou won the game!" << endl;
	}
	else {
		cout << "\n\t\tYou lost the game!" << endl;
	}
	cout << "You chose " << Player << ", and Computer chose " << Computer << endl;
}

/* Here, we initialize the static variables to keep track of the scoreboard*/
int RPS_Game::Wins = 0;
int RPS_Game::Losses = 0;
int RPS_Game::Draws = 0;

void readRightInput(string &Choice) {
	/* this function checks if the player entered a valid choice*/
	string newChoice;

	if (Choice != "Stone" && Choice != "Paper" && Choice != "Scissor"){
		cout << "\nYou entered an invalid choice, note that your entry is case sensitive" << endl;
		cout << "Please enter Stone, Paper or Scissor" << endl;
		cin >> newChoice;
		Choice.assign(newChoice);
		readRightInput(Choice);
	}

}

/* The main program that allows us to play stone paper scissor against computer*/
int main()
{
	unsigned int n; // Number of Games
	string Player;  // Player's choice in each game
	RPS_Game Game;  // Game Object, which sets the rules and keeps track of summary 

	cout << "Please enter how many time you want to play the game: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "\nEnter Stone, Paper, or Scissor" << endl;
		cin >> Player;
		/* Here we check if the player entered a valid choice*/
		readRightInput(Player);
		/* Here we set Player's choice*/
		Game.setPlayerChoice(Player);
		/* Here we get what computer chooses */
		Game.setComputerChoice();
		/* Here we determine the result */
		Game.getResult();
		/* Here we get the result of each game*/
		Game.getGameInfo();
	}

	/* Here we get the summary of all games we played*/
	Game.getSummary();
	return 0;
}
