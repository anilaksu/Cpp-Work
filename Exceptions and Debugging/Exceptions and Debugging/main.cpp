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
#include "Person.h"

using namespace std;

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
			- results from a fault in logic in our code (out of range error i.e.)
	*/

	return 0;
}