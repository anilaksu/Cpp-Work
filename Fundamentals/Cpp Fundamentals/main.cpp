/*
	Fundamentals of C++ version 17
*/


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
		Most develop assign variable names using Camel Case convention
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
	bool isSunny = false;
	bool isWarm = true;

	cout << isSunny << endl;
	cout << isWarm << endl;

	/*
		Arithmetic Operators:
		- Operators: Special symbols used to perform operations
		- Operands: The variables or literals that the opertors act upon
		- Arithmetic operators: Used to perform arithmetic
	*/
	 
	int a = 10;
	int b = 3;

	/*
		Here are some built - in arithmetic operators, 
		however more complex operations are also available in cmath library, which we will cover later
	*/ 

	int sum = a + b;
	int difference = a - b;
	int product = a * b;
	int quotient = a / b;
	int remainder = a % b;
	// Compound operators 
	int result = 10;
	int myInteger = 5;

	result += 5; // Here we add 5 to the existing value in result variable
	result *= 2; // Here we multiply the existing value in result variable with 2

	cout << "Sum = " << sum << endl;
	cout << "Difference = " << difference << endl;
	cout << "Product = " << product << endl;
	cout << "Quotient = " << quotient << endl;
	cout << "Remainder = " << remainder << endl;
	cout << "Result = " << result << endl;

	myInteger++;     // We increment myInt by 1
	cout << myInteger << endl;
	myInteger--;     // We decrement myInt by 1
	cout << myInteger << endl;

	/*
		Relational Operators: Retunrs Boolean values and help us make decisions
		>	greater than
		>=  greater than or equal to
		<	less than
		<=  less than or equal to
		==  equal to
		!=  not equal to 
	*/

	cout << boolalpha; // Here we set boolean operators as True or False instead of 1 or 0

	int c = 15;
	int d = 20;
	bool areEqual = c == d;
	int age = 21;
	bool olderThan21 = age >= 21;

	cout << (c < d) << endl;
	cout << areEqual << endl;
	cout << olderThan21 << endl;

	/*
		Logical Operators: Use to combine or change boolean variables
		Logical AND: p && q (binary operator)
		Logical OR : p || q (binary operator)
		Logical NOT: !p		(unary  operator)
	*/

	// Here we use boolean variables we defined before
	isRaining = true;
	isWarm = false;

	cout << "And: " << (isRaining && isWarm) << endl;
	cout << "Or: " << (isRaining || isWarm) << endl;
	cout << "Not: " << (!isRaining) << endl;

	/*
		Symbolic Constants and Naming Conventions
		Symbolic Constants: Similar to variables, but we can't change their values once they are initialized
		Naming Convention: Constants are written in capital letters with underscore seperating words such as MY_RATE (Snake Casing)
	*/

	const double MY_PI = 3.14159;
	const string MY_NAME = "Anil Aksu";

	cout << MY_NAME << endl;


	
	/*
		User Input
		Symbolic Constants: Similar to variables, but we can't change their values once they are initialized
	*/

	return 0;
}

