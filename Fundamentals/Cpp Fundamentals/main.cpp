#include <iostream>
#include <string>	 // Here we include string library for built-in string operations
using namespace std; // Here we just say "include standard names"

int main()
{

	cout << "Hello C++" << endl;

	/*
	- Storing different types of data in memory
	- Performing operations on the data
	- Taking our first steps toward helping our programs make decisions
	- Communicating with the users of our programs
	- Projects
		1) Mad Libs clone
		2) Average-of-Three program
	*/

	/*
	Most develop assigne variable names using Camel Case convention
	*/
	int myInt;			       // We declared our integer variable here
	myInt = 15;				   // We assigned a value to it
	double myDouble = 3.14159; // We declared our double and assigned a value to it 
	char singleChar = 'a';	   // We declared our character and assigned a value to it
	string myName = "John";	   // Here we perform basic string operations
	bool isRaining = false;    // Here we assign a boolean value

	cout << myInt << endl;
	cout << myDouble << endl;
	cout << singleChar << endl;
	cout << "Hello " << myName << endl;
	cout << isRaining << endl;				// Here we output integer value of boolean variable 
	// boolapha is also a part of iostream library that enables to output boolean variable as True or False
	cout << boolalpha << isRaining << endl; // Here we output True or False of boolean variable

	// Some Experiment on Boolean operator
	bool isSunny = true;
	bool isWarm = true;

	cout << isSunny << endl;
	cout << isWarm << endl;

	return 0;
}

