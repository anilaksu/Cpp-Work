/*
	Pointers:
		- Also called pointer variables
		- These are known as raw pointers to distinguish them from C++ 11 smart pointers (managed pointers)
		- Holds a memory address
		- Refer to the data of interest indirectly
*/

#include <iostream>

using namespace std;

int main()
{
	/*
		Declaring a pointer:
			- int* myIntPtr; // not an integer, it is a pointer to an integer
			- Using ptr or Ptr in the identifier is a common practice
		If you declare multiple variables per line...
			- int *myPtr1, *myPtr2, *myPtr3;
	*/

	int myLovelyInt = 150;
	int* somePtr = &myLovelyInt; // Here we assign the address of myLovelyInt

	cout << "myLovelyInt is originally: " << myLovelyInt << endl;
	cout << "pointer holds value: " << somePtr << endl;
	cout << "pointer dereferenced: " << *somePtr << endl;

	*somePtr = 200; // Here we change the value at myLovelyInt address
	cout << "myLovelyInt is now: " << myLovelyInt << endl;

	return 0;
}