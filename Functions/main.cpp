/*
	Functions in C++
*/

#include <iostream>
#include <string>
using namespace std;

void printSomething() // Function itself
{
	cout << "Hey! Look I am here!" << endl;
}

/*
	We need to refer to function prototype before call it in main
*/

void printMyName(string yourName); // Function Protype

/*
	Here we define functions with int return type
*/

int giveMe10();
int addThese(int num1, int num2);

int main() {

	string myName;
	int num1 = 21, num2 = 22;
	printSomething(); // Here call the function here

	cout << "Please enter your name" << endl;
	getline(cin, myName);

	printMyName(myName);

	cout << giveMe10() << endl;
	cout << "Your sum is " << addThese(num1, num2) << endl;


	/*
		Parameter Passing: Pass-by-Value and Pass-by-Reference
	*/

	return 0;
}

/*
	We can place functions underneath main, then call it before main
*/

void printMyName(string yourName)
{
	cout << "Your name is " << yourName << endl;
}

/*
	Here we define functions with return
*/

int giveMe10()
{
	return 10;
}

int addThese(int num1, int num2)
{
	return num1 + num2;
}