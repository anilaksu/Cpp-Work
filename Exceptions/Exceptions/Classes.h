#pragma once
#include <iostream>
#include <cstdlib> //for srand(), rand()
#include <ctime> //for time for srand()
#include <string> //for strcpy()

using namespace std;

const int MAX = 5;
/*
	Here, we create the distance class, which we regularly update by adding new features
*/

class Distance //English Distance class
{
private:
	int feet;
	float inches;
public: //constructor (no args)

	class InchesEx { 
		public:

			float iValue; //for faulty inches value
			string originValue; //for name of routine

			InchesEx(string specifier, float in) //2-arg constructor
			{
				originValue = specifier; //store string
				iValue = in; //store inches
			}
	
	}; //exception class

	Distance() : feet(0), inches(0.0)
	{ }
	//constructor (two args)
	Distance(int ft, float in) 
	{ 
		if (in >= 12.0) //if inches too big,
			throw InchesEx("2 - arg constructor", in);
			//throw InchesEx(); //throw exception
		feet = ft;
		inches = in;
	}
	void getdist() //get length from user
	{
		cout << "\nEnter feet : "; cin >> feet;
		cout << "Enter inches : "; cin >> inches;
		if (inches >= 12.0) //if inches too big,
			throw InchesEx("getdist() function", inches);
			//throw InchesEx(); //throw exception
	}
	void showdist() //display distance
	{
		cout << feet << "\' - " << inches << "\'";
	}
	void add_dist(Distance, Distance); //declaration
};

void Distance::add_dist(Distance d2, Distance d3)
{
	inches = d2.inches + d3.inches; //add the inches
	feet = 0; //(for possible carry)
	if (inches >= 12.0) //if total exceeds 12.0,
	{ //then decrease inches
		inches -= 12.0; //by 12.0 and
		feet++; //increase feet
	} //by 1
	feet += d2.feet + d3.feet; //add the feet
}

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

////////////////////////////////////////////////////////////////
/* Safearay Template */
template <class Type>
class safearay
{
private:
	Type arr[MAX];
public:

	class BoundsError {
	public:
		int expInd;

		/* Constructor showing the index */
		BoundsError(int j) : expInd(j)
		{	}

	};

	Type& operator [](int n) //note: return by reference
	{
		if (n < 0 || n >= MAX)
		{
			//cout << "\nIndex out of bounds"; exit(1);
			throw BoundsError(n);
		}
		return arr[n];
	}
};