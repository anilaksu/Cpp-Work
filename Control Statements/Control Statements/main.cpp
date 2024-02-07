/*
	C++ Control Statements
*/

#include <iostream>
#include <string>
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

	return 0;
}