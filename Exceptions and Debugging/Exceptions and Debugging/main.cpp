/*
	Exceptions and Debugging:
		- Objects representing exceptional situations
		- Usually mean there is a problem with your code
		- Built-in exceptions and custom exceptions
		- Crucial to know how to handle exceptions for industry-level software development
		- Makes our code more robust and fault-tolerant
	Testing and debugging
		- Help us to find bugs and remove them as early as possible
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "exceptions.h"

using namespace std;

// Function Prototype
void processPositive(int num);
void doSomething(int num);
void feedKitty(int numTreats);
int imBroken(int num1, int num2);

int main()
{
	/*
		Exceptions and Exception Hierarchy:
			- Exceptions objects are created from classes, just like any objects are
		C++ Exception Hierarchy
			- The top of the hierarchy is a class named exception
			- Other classes are derived from the exception class
			- logic_error and runtime_error are some of the most common exceptions in C++
	*/

	vector<string> names(5);

	names.at(0) = "John";
	names.at(1) = "Bob";
	names.at(2) = "Sally";
	names.at(3) = "Karen";
	names.at(4) = "Smitty";

	for (string name : names)
		cout << name << endl;

	try
	{
		names.at(5) = "Tyler"; // exceptions? 
	}
	catch (const out_of_range& err)
	{
		cout << err.what() << endl;
	}

	/*
		Logic Errors:
			- results from a fault in logic in our code (out of range error i.e.)
	*/

	vector<int> myNums;

	try
	{
		myNums.resize(myNums.max_size() + 1);
	}
	catch (const length_error& err)
	{
		cerr << err.what() << endl; // we can use cerr instead of cout, which specifically refers to an error
	}
	
	cout << "Yay it is a big vector!" << endl;


	/*
		Runtime Errors and Throwing Exceptions:
			- Typically external errors - originate outside the program
			- often outside our control
			- We write defensive code that responds to unusual situations outside our control
		We can throw exceptions ourselves:
			- This sends out the signal that an exception occured
		Here we create a Person Class to demonstrate with UML:
			- name: string
			+ Person(name: string)
			+ getName(): string
			+ setName(name: string): void
	*/

	try
	{
		Person person1("Bob");
		Person person2("John");

		cout << person1.getName() << endl;
		cout << person2.getName() << endl;
	}
	catch (const runtime_error& err)
	{
		cerr << err.what() << endl;
	}

	/*
		Dog Class:
			-breed: string
			+ Dog(breed: string)
			+ getBreed(): string
		If the dog is a poodle, the constructor throws a runtime_error with the message
		: "Poodle? That's not a real dog!"
	*/

	try
	{
		Dog myDog("Pitbull");
		Dog yourDog("Poodle");

		cout << myDog.getBreed() << endl;
		cout << yourDog.getBreed() << endl;
	}
	catch (const runtime_error& err)
	{
		cerr << err.what() << endl;
	}

	/*
		Rethrowing Exceptions:
			- Allows it to be caught again by a different segment of code to do its own processing
	*/

	int input;

	try
	{
		cout << "Enter a number to process!" << endl;
		cin >> input;
		doSomething(input);
		cout << "Yay! main was able to completely "
			<< "process the num!" << endl;
	}
	catch (const invalid_argument& err)
	{
		cout << "main says there is an error!" << endl;
		cout << err.what() << endl;
	}
	catch (const out_of_range& err)
	{
		cout << "main says the number is too big!" << endl;
		cout << err.what() << endl;
	}

	/*
		Custom Exceptions:
			- we can use inheritance - by making a custom exception inherit from either the exception class 
			  or one of its descendants
	*/

	int numTreats = 0;

	cout << "How many treats do you want to feed kitty?" << endl;
	cin >> numTreats;

	try
	{
		feedKitty(numTreats);
	}
	catch (const AngryCatException& err)
	{
		cerr << err.what() << endl;
	}

	/*
		Basic Testing and Debugging:
			- Bug: a problem in our code
				+ Could be a compile-time error such as a syntax error, preventing compilation
				+ Could be a fatal runtime error - causing program to crash
				+ Could be logic error - we get the wrong behaviour or result
			- Testing - running the program trying to expose bugs
			- Debugging - removing the bugs
	*/

	int a;

	try
	{
		a = imBroken(10, 5);
		cout << a << endl;
	}
	catch (const invalid_argument& err)
	{
		cout << err.what() << endl;
	}

	try
	{
		a = imBroken(10, 0);
		cout << a << endl;
	}
	catch (const invalid_argument& err)
	{
		cout << err.what() << endl;
	}

	a = imBroken(10, 0);
	cout << a << endl;

	return 0;
}

void processPositive(int num) // Throws exceptions
{
	cout << "Welcome to the positive integer processor!" << endl;
	if (num > 100)
	{
		throw out_of_range("Number can not be greater than 100");
	}
	else if (num >= 0 )
	{
		cout << "Good job! You passed in a positive num to processPositive" << endl;
	}
	else 
	{
		throw invalid_argument("Negative number passed in!");
	}
}

void doSomething(int num)	 // Rethrows exceptions
{
	try
	{
		processPositive(num);
		cout << "Yay! doSomething could process that num!" << endl;
	}
	catch (const invalid_argument& err)
	{
		cout << "doSomething says there is a problem!" << endl;
		throw; // Rethrow
	}
	catch (const out_of_range& err)
	{
		cout << "doSomething says the number is too big" << endl;
		throw; // Rethrow
	}
}

void feedKitty(int numTreats)
{
	if (numTreats < 3)
	{
		throw AngryCatException();
	}
	else if (numTreats < 6)
	{
		throw AngryCatException("I am still not happy!");
	}
	else
		cout << "Kitty is happy with " << numTreats << " treats." << endl;
}

int imBroken(int num1, int num2)
{
	int result = 0;

	if (num2 != 0)
		result = num1 / num2;
	else
		throw invalid_argument("Cannot divide by 0");

	return result;
}