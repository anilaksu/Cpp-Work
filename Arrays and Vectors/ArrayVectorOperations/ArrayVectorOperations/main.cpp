/*
	Arrays and Vectors in C++
*/

#include <iostream>
#include <string>
#include "Invoice.h"
#include <array>		// Here we import array class
#include <vector>		// Here we import vector class
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <random>

//#include "MotorVehicle.h"

using namespace std;

const size_t arraySize{ 3 };

void staticArrayInit(void) {

	static array<int, arraySize> array1; // Static local array

	// output the array content
	for (size_t i{ 0 }; i < array1.size(); i++)
		cout << "array1[" << i << "] = " << array1[i] << " ";

	cout << "Modified Values"<< endl;

	for (size_t i{ 0 }; i < array1.size(); i++)
		array1[i] +=5;

	// output the modified array content
	for (size_t i{ 0 }; i < array1.size(); i++)
		cout << "array1[" << i << "] = " << array1[i] << " \n";
}

void automaticArrayInit(void) {

	array<int, arraySize> array2{}; // Static local array

	// output the array content
	for (size_t i{ 0 }; i < array2.size(); i++)
		cout << "array2[" << i << "] = " << array2[i] << " ";

	cout << "Modified Values" << endl;

	for (size_t i{ 0 }; i < array2.size(); i++)
		array2[i] += 5;

	// output the modified array content
	for (size_t i{ 0 }; i < array2.size(); i++)
		cout << "array2[" << i << "] = " << array2[i] << " \n";
}

int main() {

	const int ARRAY_SIZE = 5;											// Here we declare our array size
	int myArray[ARRAY_SIZE];											// Here we declare our array
	string names[ARRAY_SIZE]{ "Bob", "Sally", "John", "Ed", "Mahmut" }; // String array

	// Array starts with 0 index
	myArray[0] = 15;
	myArray[1] = 25;
	myArray[2] = 22;
	myArray[3] = 13;
	myArray[4] = 6;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << myArray[i] << endl;
		cout << names[i] << endl;
	}

	// Range-based for loop
	for (string name : names)
	{
		cout << name << endl;
	}

	// Using auto allows C++ find out the data type of array
	for (auto name : names)
	{
		cout << name << endl;
	}

	/*
		Array Class: Similar to built-in arrays but is object-oriented
		- STL (Standard Template Library)
			+ Contains many things, including container class
			+ Arrays are sequence containers
	
	*/

	cout << "Array Class" << endl;

	array<int, ARRAY_SIZE> myIntArray{ 0, 0, 0, 0, 0 }; //Here we initialize our array class

	// Here we can access myIntArray size via member function .size()
	for (int i = 0; i < myIntArray.size(); i++)
		myIntArray[i] = 2 * i;

	// Here we can access each element of array using Range-based for loop
	for (int a : myIntArray)
		cout << a << endl;

	/*
		Vector Class: Sequential container just like the array class
		- Consists of contiguous memory just like arrays
		- Are not limited to fixed sizes, but instead can dynamically resize as needed to accomodate more elements
		- You don't need to specify an initial capacity
	*/

	cout << "Vector Class" << endl;

	vector<int> someVec;			// Here we initialize an integer vector
	vector<string> anotherVec(3);   // Here we initialize string vector with an intial size

	// Here we add elements to our integer vector using member function .push_back()
	someVec.push_back(1);
	someVec.push_back(2);
	someVec.push_back(3);

	cout << "someVec size: " << someVec.size() << endl;

	// Here we change the existing element in a vector similar to built-in arrays
	anotherVec[0] = "John";
	anotherVec[1] = "Bob";
	anotherVec[2] = "Sally";

	// Here we both increase the size and add a new element to our string vector
	anotherVec.push_back("Shannon");

	for (int a : someVec)
	{
		cout << a << endl;
	}

	for (string name : anotherVec) 
	{
		cout << name << endl;
	}

	cout << "Front and back:" << endl;
	cout << "front: " << anotherVec.front() << endl;
	cout << "back: " << anotherVec.back() << endl;

	anotherVec.pop_back();							// Removes the last element 
	anotherVec.insert(anotherVec.begin(), "Don");   // Inserts to the first element

	cout << "now ,front is " << anotherVec.front() << endl;
	cout << "now, back is " << anotherVec.back() << endl;

	/*
		Vector Practice Challenge:
		- Create a vector and add to it the names of five friends, family mements
		- After adding those five, insert my name as the third element in the vector
		- Remove the last element and print the elements 
	*/

	vector<string> entourage;
	string name;

	cout << "Please enter " << ARRAY_SIZE << " favorite people" << endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		getline(cin, name);
		entourage.push_back(name);
	}

	entourage.insert(entourage.begin() + 2, "John Baugh"); // Here add John Baugh to third element
	entourage.pop_back();                                  // Here we remove the last element

	for (auto names : entourage) 
	{
		cout << names << endl;
	}

	///* Array declaration */
	//const int n = 20;
	//int Sum{ 0 };         // Sum of array elements
	//array<int, n> x{};

	//for (size_t i{ 0 }; i < x.size(); i++)
	//	x[i] = i;

	//for (size_t i{ 0 }; i < x.size(); i++) {
	//	cout << i + 1 << "'th wlement value " << setw(7) << x[i] << endl;
	//	Sum += x[i];
	//}

	//cout << "Sum of all elements " << setw(7) << Sum << endl;


	//cout << "First call to each function \n" << endl;
	//staticArrayInit();
	//automaticArrayInit();

	//cout << "\nSecond call to each function \n" << endl;
	//staticArrayInit();
	//automaticArrayInit();

	//const size_t m = 7;
	//array<string, m> colors{"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};

	//// Output the unsorted array
	//cout << "\nUnsorted colors \n";
	//for (string color : colors)
	//	cout << color << " ";

	//sort(colors.begin(), colors.end());  // Sort the colors
	//cout << "\nSorted colors \n";
	//// Output the sorted array
	//for (string color : colors)
	//	cout << color << " ";

	//// let's check out binary search algorithm
	//bool found{ binary_search(colors.begin(),colors.end(),"Indigo") };
	//cout << "\nIndigo " << (found ? "was" : "was not") << " found in colors" << endl;
	////Invoice myInvoice{ "RN7001TZ"};				    /*MyAccount object created by the definition in Account.h*/

	///* Pointers */
	//int* countPtr, count;
	//int b[5]{0,1,2,3,4};
	//int* bPtr;
	//countPtr = &count;
	//count = 8;
	//cout << "Pointer address: "<< countPtr << endl;
	//cout << "Pointer value: " << *countPtr << endl;

	//countPtr += 2;
	//*countPtr = 10;

	////count = 9;
	//cout << "Pointer address: " << countPtr << endl;
	//cout << "Pointer address: " << &count << endl;
	//cout << "Pointer value: " << count << endl;
	//cout << "Pointer value: " << *countPtr << endl;

	//bPtr = &b[0];
	//cout << "Pointer value: " << *(3+bPtr) << endl;

	///* String Operations*/

	//string stringObject, targetString{"Onur Aksu"};
	//string stringTrial;
	//cin >> stringObject;

	//cout << "Size of the string is: " << stringObject[0] << endl;
	////targetString.assign(stringObject, 0, stringObject.size());
	//cout << "Copied string is: " << targetString << endl;

	//for (char c : targetString)
	//		cout << c << endl;
	//int result;
	//result = targetString.compare(5, 8, stringObject, 0, stringObject.size());
	//cout << "Difference in strings is: " << result << endl;

	//cout << "Location of String object is: " << targetString.find(stringObject) << endl;
	//cout << "Target String data is: " << targetString.data() << endl;

	///* Conversion to Pointer-Based char* strings*/

	//const char* ptr1{nullptr};      // Initialize ptr1
	//size_t length{targetString.size()};

	//char* ptr2{ new char[length + 1] }; // Last element is the null pointer
	//targetString.copy(ptr2, length, 0);

	//cout << "targetString is: " << targetString << "\ntargetString converted to a pointer-based string is " << targetString.c_str()<< endl;

	//ptr1 = targetString.data();

	//for (size_t i{ 0 }; i < length; i++)
	//	cout << *(ptr1 + i);
	//
	//cout << "\nptr2 is " << ptr2 << endl;
	////myInvoice.setPartDescription("Screw Driver");   /*let's set the price for each part */
	////myInvoice.setNumberSold(10);					/*let's set number of parts sold */

	///*Let's get the invoice*/
	////cout << "Number of parts is: " << myInvoice.getNumberSold() << endl;



	return 0;
}