/*
	Arrays and Vectors in C++
*/

#include <iostream>
#include <string>
#include <array>		// Here we import array class
#include <vector>		// Here we import vector class

using namespace std;


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

	//vector<string> entourage;
	//string name;

	//cout << "Please enter " << ARRAY_SIZE << " favorite people" << endl;

	//for (int i = 0; i < ARRAY_SIZE; i++)
	//{
	//	getline(cin, name);
	//	entourage.push_back(name);
	//}

	//entourage.insert(entourage.begin() + 2, "John Baugh"); // Here add John Baugh to third element
	//entourage.pop_back();                                  // Here we remove the last element

	//cout << " Modified Names Vector " << endl;

	//for (auto names : entourage) 
	//{
	//	cout << names << endl;
	//}

	/*
		Multi-dimensional Arrays:
		- First index represents the row
		- Second index represents the column
	*/

	cout << " Multi-dimensional arrays " << endl;

	int myNums[2][3]{ {1, 2, 3}, {4, 5, 6} }; // 2D array that is 2 x 3

	cout << myNums[0][2] << endl;

	myNums[1][0] = 14;					     // Here we access and individual element and change it

	cout << myNums[1][0] << endl;

	for (int row = 0; row < 2; row++)
	{ 
		for (int col = 0; col < 3; col++)
		{
			cout << myNums[row][col] << " ";
		}
		cout << endl;
	}

	/*
		Mini-Project 1: Array Data
		- Read five integers into the array
		- Loop through the array of integers, and print twice
	*/


	cout << " Mini Project: Array Data " << endl;

	array<int, ARRAY_SIZE> arrayData{ 3, 8, 0, 13, 7 }; //Here we initialize our array class

	// Here we can access each element of array using Range-based for loop
	for (int a : arrayData)
		cout << 2 * a << endl;

	/*
		Mini-Project 2: Vector Data
		- Read five integers into the array
		- Loop through the array of integers, and print twice
	*/

	return 0;
}