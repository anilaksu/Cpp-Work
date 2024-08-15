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
#include<stack> // Differing from deque, you can only access the element in the front
#include<queue> // It allows us to use queue data structure
#include<map>   // It allows to use dictionaries 
#include "swapper.h"

using namespace std;

template <class T>
T getBigger(T a, T b);
template <class T>
T getSmaller(T a, T b);

void printDeque(deque<int> deck);
// Palindrome functions
void storeReverse(string origString, stack<char>& reverseStack);
bool isPalindrome(string origString);
void printResult(string origString);

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

	/*
		Stack Function: Differing from deque, you can only access the element in the front
		We check if a stack is a palindrome
	*/

	string myPalindrome;

	cout << "Please enter a palindrome" << endl;
	cin >> myPalindrome;

	printResult(myPalindrome); // Here we check if it is a palindrome

	/*
		Queue project:
			- Use the <queue> library
			- Queues are first-in, first-out
			- Use "push" and "pop" methods for adding and removing
			- Use front to obtain the next element to deque from the queue (Hint: use empty() method)
	*/

	queue<string> myQueue;
	string myName;
	bool add = true;
	char doContinue = 'Y';

	cout << "Queue project: Queue of Names" << endl;

	// Here we input our names
	while (add)
	{
		cout << "Please enter a name" << endl;
		cin >> myName;

		myQueue.push(myName);

		cout << "Do you wanna continue? (Y/N)" << endl;
		cin >> doContinue;
		add = (doContinue == 'Y') ? true : false;

	}

	// Here we output our names
	while (!myQueue.empty())
	{
		cout << myQueue.front() << endl; // Here we output the name
		myQueue.pop();				     // Here we clear the element on the top
	}
		
	/*
		Maps:
			- Also known as dictionaries
			- Data struncture representing key/value pairs
	*/

	map<string, string> contacts; // Here we create our phone book

	contacts["Mahmut Ceylan"] = 313 - 555 - 5555;

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

// This function stores the reverse string
void storeReverse(string origString, stack<char>& reverseStack)
{
	for (auto character : origString)
		reverseStack.push(character);
}

// This function checks if a given string is a palindrom or not
bool isPalindrome(string origString) 
{
	stack<char> reverseStack;
	bool result = true;

	storeReverse(origString, reverseStack);

	for (auto character : origString)
	{
		if (character != reverseStack.top())
		{
			result = false;
			break;
		}

		reverseStack.pop(); // Here we remove the top element in the reversed stack
	}
		

	return result;
}

// This function returns the check of palindrome
void printResult(string origString) {

	if (isPalindrome(origString))
		cout << "Yes, it is a palindrome.\n" << endl;
	else
		cout << "No, it is not a palindrome.\n" << endl;
}