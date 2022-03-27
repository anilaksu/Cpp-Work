#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip> //for setprecision, etc.
#include "cmath"
#include "Classes.h"

using namespace std;

int main()
{

	Stack<int> s1; //s1 is object of class Stack<float>

	try
	{
		//push 3 integers
		s1.push(11);
		s1.push(22);
		s1.push(33);
		// pop 3 floats ! Note that it starts popping from the top
		cout << "1: " << s1.pop() << endl;
		cout << "2: " << s1.pop() << endl;
		cout << "3: " << s1.pop() << endl;
		//cout << "4: " << s1.pop() << endl;
	}

	catch (Stack<int>::Full)
	{
		cout << "Exception: Stack Full" << endl;
	}
	catch (Stack<int>::Empty)
	{
		cout << "Exception: Stack Empty" << endl;
	}
	cout << "Arrive here after catch (or normal exit)" << endl;

	/* Here we test the exception handling for the distance function, which controls the entry length is less than the threshold value*/
	try
	{
		Distance dist1(17, 3.5); //2-arg constructor
		Distance dist2; //no-arg constructor
		dist2.getdist(); //get distance from user
		//display distances
		cout << "\ndist1 = "; dist1.showdist();
		cout << "\ndist2 = "; dist2.showdist();
	}

	catch (Distance::InchesEx ix) //catch exceptions 
	{
		cout << "\nInitialization error in " << ix.originValue
			<< ".\n Inches value of " << ix.iValue
			<< " is too large.";
	}
cout << endl;

const unsigned long SIZE = 10000; //memory size
char* ptr; //pointer to memory
try
{
	ptr = new char[SIZE]; //allocate SIZE bytes
}
catch (bad_alloc) //exception handler
{
	cout << "\nbad_alloc exception : can’t allocate memory.\n";
	return(0);
}
delete[] ptr; //deallocate memory
cout << "\nMemory use is successful.\n";

safearay<float> sa2;

/* Here we test bounds error for safe array */
try
{
	//push 3 integers
	for (int j = 0; j < 5; j++) //insert elements
	{
		sa2[j] = float(j * 10.2); //*left* side of equal sign
	}
}
catch (safearay<float>::BoundsError Bound)
{
	cout << "Exception: Input array is out of bounds at: " << Bound.expInd << endl;
}

	return 0;

}

