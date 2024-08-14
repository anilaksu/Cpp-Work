/*
	- Templates: Function and class templates
	- Standard Template Library (STL): Tons of helpful data structures and algorithms
	- Smart Pointes: Pointers that manage their own memory
	- Friend functions and friend classes
	- Operator overloading
*/

#include<iostream>
#include<string>
#include<deque> // It allows us to use STL and containers
#include "swapper.h"

using namespace std;

template <class T>
T getBigger(T a, T b);
template <class T>
T getSmaller(T a, T b);

void printDeque(deque<int> deck);

int main() {

	/*
		Function templates: (Avoids duplication of code and increases reusability of a code)
			- Generic functions that can work with many different types of data
			- Developer writes a placeholder, and the compiler generates the specific version needed
	*/

	
	string name1 = "John";
	string name2 = "Alice";

	double biggerDouble = getBigger(3.14, 5.55);
	int biggerInt = getBigger(9, 11);
	string biggerStr = getBigger(name1, name2);

	double smallerDouble = getSmaller(3.14, 5.55);
	int smallerInt = getSmaller(9, 11);
	string smallerStr = getSmaller(name1, name2);

	cout << biggerDouble << " " << biggerInt << " " << biggerStr << endl;
	cout << smallerDouble << " " << smallerInt << " " << smallerStr << "\n" << endl;

	/*
		Class Templates:
			- Allows the entire class to handle different types
			- You must keep the full implementation inside heaer file:
				+ It can be in the class declaration
				+ It could also use scope resolution syntax below the class declaration as an alternative
	*/

	Swapper<int> mySwap(3, 4);
	Swapper<string> myStringSwap(name1, name2);

	// Here we output our swapper results
	cout << "Your first number is " << mySwap.getFirst() 
		<< " and your second number is " << mySwap.getSecond() << endl;

	mySwap.swap(); // Here we swap

	// Here we output our swapper results
	cout << "After swap, your first number is " << mySwap.getFirst()
		<< " and your second number is " << mySwap.getSecond() << "\n" << endl;

	// Here we output our swapper results
	cout << "Your first name is " << myStringSwap.getFirst()
		<< " and your second name is " << myStringSwap.getSecond() << endl;

	myStringSwap.swap(); // Here we swap

	// Here we output our swapper results
	cout << "After swap, your first name is " << myStringSwap.getFirst()
		<< " and your second name is " << myStringSwap.getSecond() << "\n" << endl;
	
	/*
		- The Standard Template Library (STL): Also sometimes just called C++ Standard Library
		- Three broad categories of data and functionality:
			+ Containers: For storage and organization of data, majority of these are sequence containers or associative containers
			+ Iterators: help move through the containers and find elements
			+ Algorithms: function templates - a wider variety to perform operations on the containers
	*/

	deque<int> myDeck; // Integer Deque container

	// Here we add integers to our deque in the end
	myDeck.push_back(1); 
	myDeck.push_back(5);
	myDeck.push_back(10);

	printDeque(myDeck);

	// Here we add integers to our deque in the front
	myDeck.push_front(21);
	myDeck.push_front(35);
	myDeck.push_front(19);

	printDeque(myDeck);


	return 0;
}

/*
	Function Template
*/
template <class T> // It can accept any data type which denote by type T
T getBigger(T a, T b) {

	if (a > b)
		return a;
	else
		return b;
}

template <class T> // It can accept any data type which denote by type T
T getSmaller(T a, T b) {

	if (a < b)
		return a;
	else
		return b;
}

// This function outputs a deque
void printDeque(deque<int> deck) {

	for (int num : deck)
	{
		cout << num << endl;
	}
	cout << endl;
}