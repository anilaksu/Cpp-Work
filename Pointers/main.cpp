/*
	Pointers:
		- Also called pointer variables
		- These are known as raw pointers to distinguish them from C++ 11 smart pointers (managed pointers)
		- Holds a memory address
		- Refer to the data of interest indirectly
*/

#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

// Function Prototypes
void noConst(); // Non constant pointer to non constant data
void cp2ncd();	// Constant pointer to non constant data
void ncp2ncd();	// Non constant pointer to non constant data
void cp2cd();	// Constant pointer to constant data

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
	double myDouble = 3.14;
	int* somePtr = &myLovelyInt; // Here we assign the address of myLovelyInt
	double* doublePtr = &myDouble;// Here we assign the address of myDouble

	cout << "myLovelyInt is originally: " << myLovelyInt << endl;
	cout << "pointer holds value: " << somePtr << endl;
	cout << "pointer dereferenced: " << *somePtr << endl;

	*somePtr = 200; // Here we change the value at myLovelyInt address
	cout << "myLovelyInt is now: " << myLovelyInt << endl;

	cout << "doublePtr holds value: " << doublePtr << endl;
	cout << "doublePtr dereferenced: " << *doublePtr << endl;

	/*
		Dynamic Memory:
			- Allocated at runtime instead of being set at complie time
			- Useful because often we don't know how many of certain variables we will need
		C++ syntax for dynamic memory
			- The new keyword allows us to reserve memory on the free store, more commonly called the heap
			- The delete keyword is for returning dynamically allocated memory when we are using it
	*/

	int* myIntPtr = new int(123);		// We dynamically initialize to the address  with new operator
	bool* myBoolPtr = new bool(true);   // Here we do it for a boolean variable
	*myIntPtr = 123;					// Here we assigned a value similar to data members

	cout << *myIntPtr << endl;
	cout << boolalpha <<  *myBoolPtr << endl; // boolalpha allows us to output true or false

	delete myIntPtr;					// Here we free up dynamically allocated memory
	delete myBoolPtr;
	myIntPtr = nullptr;					// Here we set it to nullptr to make sure it has a valid address and prevent memory leak
	myBoolPtr = nullptr;

	/*
		Pointers on Class
	*/

	Dog* myDogPtr = new Dog("Alfred", "Pitbull");

	cout << "using arrow member access " << endl;
	cout << "My dog's name is " << myDogPtr->getName() << endl;
	cout << "My dog's breed is " << myDogPtr->getBreed() << endl;
	cout << endl;

	cout << "using dereferencing and the dot operator " << endl;
	cout << "My dog's name is " << (*myDogPtr).getName() << endl;
	cout << "My dog's breed is " << (*myDogPtr).getBreed() << endl;

	delete myDogPtr;    // Here we free up allocated memory
	myDogPtr = nullptr; // Here we make sure it has a valid address and prevent memory leak

	/*
		Pointers on Dynamic Arrays
	*/

	int ARR_SIZE = 5;    // Here we assign array size dynamically so it does not have to be constant anymore

	cout << "Please enter an array size!" << endl;
	cin >> ARR_SIZE;          

	int* myArray = new int[ARR_SIZE]; 

	for (int i = 0; i < ARR_SIZE; i++)
		myArray[i] = i * 2;

	for (int i = 0; i < ARR_SIZE; i++)
		cout << myArray[i] << endl;

	delete[] myArray; // Here we free up with brackets
	myArray = nullptr;

	/*
		Const Correctness: refers to how to use the const keyword correctly in different circumstances
			- Non-constant pointer to non-constant data
			- Constant pointer to non-constant data
			- Non-constant pointer to constant data
			- Constant pointer to constant data
	*/


	return 0;
}


void noConst() {

}

void cp2ncd() {

}


void ncp2ncd() {

}

void cp2cd() {

}
