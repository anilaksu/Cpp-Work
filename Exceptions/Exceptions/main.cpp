#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip> //for setprecision, etc.
#include "cmath"
#include "Classes.h"

using namespace std;
const int MAX = 2;

template <class Type> 
class Stack {
private:
	Type st[MAX]; //stack: array of any type
	int top; //number of top of stack
public:
	/*class Range //exception class for Stack
	{ //note: empty class body
	};*/

	class Empty {}; // It specifies the empty exception for the stack class
	class Full {};  // It specifies the full exception for the stack class

	Stack(); //constructor
	void push(Type var); //put number on stack
	Type pop(); //take number off stack
};

template<class Type>
Stack<Type>::Stack() //constructor
{
	top = -1;
}
//--------------------------------------------------------------
template<class Type>
void Stack<Type>::push(Type var) //put number on stack
{
	if (top >= MAX - 1) //if stack full,
		throw Full(); //throw exception
	st[++top] = var;
}
//--------------------------------------------------------------
template<class Type>
Type Stack<Type>::pop() //take number off stack
{
	if (top < 0) //if stack empty,
		throw Empty(); //throw exception
	return st[top--];
}

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


	return 0;

}

