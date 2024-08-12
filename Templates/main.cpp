/*
	- Templates: Function and class templates
	- Standard Template Library (STL): Tons of helpful data structures and algorithms
	- Smart Pointes: Pointers that manage their own memory
	- Friend functions and friend classes
	- Operator overloading
*/

#include<iostream>
#include<string>

using namespace std;

template <class T>
T getBigger(T a, T b);

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

	cout << biggerDouble << " " << biggerInt << " " << biggerStr << endl;

	/*
		Class Templates:
			- Allows the entire class to handle different types
			- You must keep the full implementation inside heaer file
	*/
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