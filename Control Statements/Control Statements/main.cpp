/*
	C++ Control Statements
*/

#include <iostream>
#include <string>
#include <cstdlib> // Here we use this library to generate random numbers
#include <ctime>
#include <algorithm> // Here we use it to call max() function

using namespace std;

int main()
{
	/*
		- Control Flow:
			+ The order in which instructions are executed in a program
		- Control statements:
			+ Sequential
			+ Selection
			+ Repetition
		- Continue and break statements
		- Random number generators
	*/

	// Sequential control statement works in sequence 
	int age = 15;
	cout << age << endl;

	// Selection statement makes decision before executing any piece of code
	if (age >= 16)
	{
		cout << "You can drive!" << endl;
	}
	else
	{
		cout << "You can not drive yet!" << endl;
	}

	// for loop (repetition)
	for (int i = 1; i <= age; i++)
	{
		cout << "Happy birthday " << i << endl;
	}

	/*
		Selection Control Statements Deeper Dive:
		- if
		- if - else
		- switch
	*/

	cout << "Welcome to the Pub and Grille!" << endl;
	cout << "Please enter your age" << endl;
	cin >> age;

	if (age >= 21) {
		cout << "Here have a beer" << endl;
	}
	else if (age >= 16) {
		cout << "Heve have a coke!" << endl;
		cout << "And, at least you can drive!" << endl;
	}
	else
	{
		cout << "Here have a coke" << endl;
	}

	cout << "Thanks for coming to the Pub and Grille!" << endl;

	// Switch Statement

	char grade;

	cout << "Please enter a letter grade" << endl;
	cin >> grade;

	switch (grade)
	{
		case 'A':
		case 'a':
			cout << "Great job!" << endl;
			break;
		case 'B':
		case 'b':
			cout << "Good job!" << endl;
			break;
		case 'C':
		case 'c':
			cout << "You can do better!" << endl;
			break;
		case 'D':
		case 'd':
			cout << "You are getting close to failing!" << endl;
			break;
		case 'F':
		case 'f':
			cout << "You are failing the course!" << endl;
			break;
		default:
			cout << "You have entered an invalid grade. Try again" << endl;
	}// end switch

	//prompt user for age and gender
	//age is int, gender is character
	//get of f or F and are 60 or over

	char gender;

	cout << "Please enter your gender (F/M)" << endl;
	cin >> gender;

	cout << "Please enter your age" << endl;
	cin >> age;

	if ((gender == 'F' || gender == 'f') && age >= 60) {
		cout << "You are eligible for the discount" << endl;
	}
	else {
		cout << "You are not eligible for the discount" << endl;
	}

	/*
		Repetition Control Statements Deeper Dive:
		- while loops
		- do - while loops
		- for loops
	*/

	int count = 0;

	cout << "While loop" << endl;

	while (count < 10) {

		cout << count << endl;
		count++;
	}

	cout << "Do while loop" << endl;

	// do while executes then checks the condition
	do
	{
		cout << count << endl;
		count--;
	} while (count > 0);

	cout << "For loop" << endl;
	// for loop
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}

	/*
		Break and Continue:
		- Break: early exit from a repetition control statement
		- Continue: causes an iteration of a repetition control statement to be skipped 
	*/

	cout << "Continue statement" << endl;
	while (count < 10)
	{	
		// Here we say skip when count == 5
		if (count == 5) { 
			count++;
			continue;
		}
		cout << count << endl;
		count++;
	}

	cout << "Break statement" << endl;
	for (int i = 0; i < 10; i++)
	{
		// Here we say break the loop when i == 5
		if (i == 5) {
			break;
		}
		cout << i << endl;
	}

	// Print only odd integers using CONTINUE statement from 1 to 10
	cout << "Print only odd numbers" << endl;
	for (int i = 1; i <= 10; i++) {
		// Here we say skip the loop when i is even
		if (i % 2 == 0) {
			continue;
		}
		cout << i << endl;
	}

	/*
		Random Numbers: Technically pseudo-random numbers
	*/

	srand(time(nullptr));		// Here we seed the random number generator

	int val1 = rand() % 10;		// val1 will be >= 0 and < 10

	// shift it
	int val2 = rand() % 10 + 1; // val1 will be >= 1 and <= 10

	cout << "Random numbers between 1 and 10" << endl;
	cout << val1 << endl;
	cout << val2 << endl;

	// Die throw for 10 times
	cout << "Die throm for 10 times" << endl;
	for (int i = 1; i <= 10; i++) {
		val1 = rand() % 6 + 1; // val1 will be >= 1 and <= 6
		cout << val1 << endl;
	}
	
	/*
		Mini Project 1: Jam of the Month Club
		- Users join a club offering jams, jellies, and preserves
		- They get a certain number of there per month, and extras on top of that cost more
		- You should first prompt the user for which package they have from the following:
			+ Package A:
				- $8/month
				- Includes 2 jams per month
				- Each additional jam on the 2 is $5 each
			+ Package B:
				- $12/month
				- Includes 4 jams per month
				- Each additional jam on the 4 is $4 each
			+ Package C:
				- $15/month
				- Includes 6 jams per month
				- Each additional jam on the 6 is $3 each
		- You should secondly prompt the user for how many jams they purchased this month in total
		- Finally, the program should return their total cost
	*/

	char package; // Package that the user picks
	int numJams;  // # of jams the user wants
	int totalCost;// Total cost of the user's selection

	cout << "Mini Project 1: Jam of the Month Club" << endl;

	cout << "Please enter the package you want" << endl;
	cin >> package;
	cout << "Please enter how many jams you want" << endl;
	cin >> numJams;

	switch (package)
	{
	case 'A':
	case 'a':
		totalCost = 8 + max(numJams - 2, 0) * 5;
		cout << "Your total cost is $" << totalCost << endl;
		break;
	case 'B':
	case 'b':
		totalCost = 12 + max(numJams - 4, 0) * 4;
		cout << "Your total cost is $" << totalCost << endl;
		break;
	case 'C':
	case 'c':
		totalCost = 15 + max(numJams - 6, 0) * 3;
		cout << "Your total cost is $" << totalCost << endl;
		break;
	default:
		cout << "You have entered an invalid package. Try again" << endl;
	}

	/*
		Mini Project 2: Odds and Evens
		- Loop through integers 0 to 50 (inclusive)
		- They get a certain number of there per month, and extras on top of that cost more
		- Print out whether each integer is odd or even such as "___ is odd" or "___ is even"
	*/

	cout << "Mini Project 2: Odds and Evens" << endl;

	for (int i = 1; i <= 50; i++) {
		if (i % 2 == 0) {
			cout << i << " is even" << endl;
		}
		else
		{
			cout << i << " is odd" << endl;
		}
	}

	/*
		Mini Project 3: Guess the number
		- The computer will randomly select an integer between 1 and 100 (inclusive)
		- Four possibilities
			+ If the user guesses correctly, print "Congratulations! You guessed the number and the program exits
			+ If the user selects a number too low, print out "Your guess is too low!"
			+ If the user selects a number too high print out "Your guess is too high"
			+ If the user selects a number out of the range, tell to pick between 1 and 100
	*/

	cout << "Mini Project 3: Guess the number" << endl;

	srand(time(nullptr));		// Here we seed the random number generator

	int randomNumber = rand() % 100 +1;		// randomNumber will be >= 1 and <= 100
	int guess;								// User's guess
	int numGuess = 1;					    // Number of guesses
	bool correct = false;					// Here we denote if the guess is correct or not with boolean variable 


	while(!correct)
	{
		cout << "Please choose a number between 1 and 100" << endl;
		cin >> guess;

		if (guess == randomNumber) {
			cout << "Congratulations! You guessed the number in " << numGuess << " trials" << endl;
			correct = true;
		}
		else if (guess < randomNumber) {
			cout << "Your guess is too low! Guess again" << endl;
		}
		else if (guess > randomNumber) {
			cout << "Your guess is too high! Guess again" << endl;
		}
		else
		{
			cout << "Your guess is out of range! Pick a number between 1 and 100" << endl;
		}
		numGuess++; // Here we increment number of guesses for each guess
	}


	return 0;
}