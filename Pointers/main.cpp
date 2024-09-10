/*
	Pointers:
		- Also called pointer variables
		- These are known as raw pointers to distinguish them from C++ 11 smart pointers (managed pointers)
		- Holds a memory address
		- Refer to the data of interest indirectly
*/

#include <iostream>
#include <string>
#include<memory> // Allows us to use smart pointers
#include "classes.h"

using namespace std;

// Function Prototypes
void noConst(); // Non constant pointer to non constant data
void cp2ncd();	// Constant pointer to non constant data
void ncp2ncd();	// Non constant pointer to non constant data
void cp2cd();	// Constant pointer to constant data

void noChange(const double* const parameter);	// Just prints out the value

// Array Size
const int ARRAY_SIZE = 3;

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

	noConst();
	cout << endl;
	cp2ncd();
	cout << endl;
	ncp2ncd();
	cout << endl;
	cp2cd();
	cout << endl;

	double* parameter = new double(2.55);

	noChange(parameter);
	delete parameter;
	parameter = nullptr;

	/*
		Mini Project: Dynamically Create Rectangles
			- Create a regular built-in array of size 3
			- Make the arrary of Rectangle pointers
				+ For each element, you need the new keyword
				+ Create rectangels of different sized ans shapes
				+ Loop through the array and print out the areas and perimentes
	*/

	Rectangle* rectPtrs[ARRAY_SIZE];

	rectPtrs[0] = new Rectangle(2.1, 3.2);
	rectPtrs[1] = new Rectangle(8.1, 6.7);
	rectPtrs[2] = new Rectangle(2.8, 9.2);

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << rectPtrs[i]->perimeter() << endl;
		cout << rectPtrs[i]->area() << endl;
	}
	
	// now, delete
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		delete rectPtrs[i];
		rectPtrs[i] = nullptr;
	}

	/*
		Mini Project: Dynamically Create Circles
			- Ask users for the size of the array
			- Prompt the user for the radius for each circle, then print out all the circumferences and areas
	*/

	double radius;  // Dummy radius for an input
	cout << "Please enter the number of circles you want to create!" << endl;
	cin >> ARR_SIZE;
	
	Circle** circlePtrs = new Circle*[ARR_SIZE]; // Here we use double asteriks to create dynamic array of class

	for (int i = 0; i < ARR_SIZE; i++) {
		cout << "Please enter a radius for your circle " << endl;
		cin >> radius;
		circlePtrs[i] = new Circle(radius);      // Here we initiate each circle pointer with new command
	}

	for (int i = 0; i < ARR_SIZE; i++)
	{
		cout << circlePtrs[i]->circumference() << endl;
		cout << circlePtrs[i]->area() << endl;
	}

	// now, delete
	for (int i = 0; i < ARR_SIZE; i++)
	{
		delete circlePtrs[i];
		circlePtrs[i] = nullptr;
	}

	/*
		Smart Pointers (also called Managed Pointers):
			- Introduced in the C++ 11 Standard
			- Syntactically, they have similarities to raw pointers
			- Manage their own memory! (no delete necessary!)
		* Three types:
			- unique_ptr: sole owner of allocated memort
				+ No two unique_ptrs can point to the same allocated memory
				+ Most common type
			- shared_ptr: shares ownership of allocated memory
				+ Multiple shared_ptrs can point to the same allocated memory
				+ A count is maintained - when it reaches 0, the memory is deallocated
			- weak_ptr: doesn't own memory it points to
				+ Used in some special circumstances
	*/

	unique_ptr<double> myDubPtr = make_unique<double>();
	auto myArray = make_unique<int[]>(ARR_SIZE);

	*myDubPtr = 3.14;
	cout << "pointer value: " << *myDubPtr << endl;


	for (int i = 0; i < ARR_SIZE; i++)
		myArray[i] = i * 2;

	for (int i = 0; i < ARR_SIZE; i++)
		cout << myArray[i] << endl;

	return 0;
}

// neither is a constant
void noConst() {
	cout << "In noConst" << endl;
	int* intPtr = new int(50);

	cout << "\torig value : " << *intPtr << endl;

	*intPtr = 100; 
	cout << "\tchange data : " << *intPtr << endl;

	intPtr = new int(125);
	cout << "\nnew integer entirely : " << *intPtr << endl;

	delete intPtr; // Avoids memory leak
}

// pointer is constant (cannot be changed)
// data is not constant (can be changed)
void cp2ncd() {
	cout << "In cp2ncpd" << endl;

	int* const intPtr = new int(100);
	cout << "\torig value : " << *intPtr << endl;

	*intPtr = 250;
	cout << "\tchange data : " << *intPtr << endl;

	delete intPtr; // Avoids memory leak

	//intPtr = new int(125); //ERROR! ptr is constant
}

// pointer is not constant (can be changed)
// data is constant (can not be changed)
void ncp2ncd() {
	cout << "In ncp2cd" << endl;

	const int*  intPtr = new int(500); // Here we place const before int*
	cout << "\torig value : " << *intPtr << endl;

	//*intPtr = 1500; // ERROR! data is constant

	delete intPtr; // Avoids memory leak

	intPtr = new int(125);
	cout << "\nnew integer entirely : " << *intPtr << endl;
}

// pointer is constant (can not be changed)
// data is constant (can not be changed)
void cp2cd() {
	cout << "In cp2cd" << endl;
	
	const int* const intPtr = new int(500); // Here we place const before int*
	cout << "\torig value : " << *intPtr << endl;
	// no changes allowed
	delete intPtr; // Avoids memory leak
}

// Simply outputs data
void noChange(const double* const parameter)
{
	cout << *parameter << endl;
}