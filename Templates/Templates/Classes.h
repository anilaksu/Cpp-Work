#pragma once
#include <iostream>
#include <cstdlib> //for srand(), rand()
#include <ctime> //for time for srand()
#include <cstring> //for strcpy()
#include <string> //for strcpy()

const int MAX_STR = 10;
const int MAX = 3;

using namespace std;


enum Suit { clubs, diamonds, hearts, spades };
//from 2 to 10 are integers without names
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class Matrix {
	public:
		Matrix()
			{	}
		Matrix(int m, int n) : size1(m), size2(n)
			{	}
		~Matrix()
			{	}
		void putel(int m, int n, float value) {
			values[m - 1][n - 1] = value;
		}
		int getel(int m, int n) {
			return values[m - 1][n - 1];
		}
	private:
		int size1, size2;
		float values[10][10];
};

class Employee {
	public:
		Employee(int n, string Alias)  : number(n), name(Alias)
			{	}
		Employee()
		{	}
		~Employee()
			{	}
		void setEmplyeeInfo(int n, string Alias) {
			number = n;
			name = Alias;
		}
		void getEmployeeInfo() {
			cout << "Employee number and name are: " << number << " " << name << endl;
		}

	private:
		int number;
		string name;
};

class String
{
private:
	enum { SZ = 80 }; //max size of Strings
	char str[SZ]; //array
public:
	String() //constructor, no args
	{
		str[0] = '\0';
	}
	String(char s[]) //constructor, one arg
	{
		strcpy_s(str, s);
	}
	void display() //display string
	{
		cout << str;
	}

	string output() //display string
	{
		return str;
	}

	void concat(String s2) //add arg string to
	{ //this string
		if (strlen(str) + strlen(s2.str) < SZ)
			strcat_s(str, s2.str);
		else
			cout << "\nString too long";
	}
};

////////////////////////////////////////////////////////////////
class card
{
private:
	int number; //2 to 10, jack, queen, king, ace
	Suit suit; //clubs, diamonds, hearts, spades
public:
	card() //constructor
	{ }
	void set(int n, Suit s) //set card
	{
		suit = s; number = n;
	}
	void display(); //display card
};
//--------------------------------------------------------------
void card::display() //display the card
{
	if (number >= 2 && number <= 10)
		cout << number;
	else
		switch (number)
		{
		case jack: cout << "J"; break;
		case queen: cout << "Q"; break;
		case king: cout << "K"; break;
		case ace: cout << "A"; break;
		}
	switch (suit)
	{
	case clubs: cout << static_cast<char>(5); break;
	case diamonds: cout << static_cast<char>(4); break;
	case hearts: cout << static_cast<char>(3); break;
	case spades: cout << static_cast<char>(6); break;
	}
}

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

			string origin; //for name of routine
			float iValue; //for faulty inches value

			InchesEx(string specifier, float in) //2-arg constructor
			{
				origin = specifier; //store string
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





class part {
	public:
		part(): partname(), partnumber(), cost()
			{	}
		~part()
			{	}
		/* Here set part info*/
		void setPart(char pname[], int pn, float c) {
			strcpy_s(partname, pname); //name of widget part;
			partnumber = pn;
			cost = c;
		}

		void getPartInfo() {
			cout << "Part model number is: " << partname << endl;
			cout << "Part part number is: " << partnumber << endl;
			cout << "Part cost is: " << cost << endl;
		}
private:
	/* Part info in private*/
	char partname[30]; //name of widget part
	int partnumber;
	float cost;

};

template<class TYPE> //struct link<TYPE>
struct link //one element of list
//within this struct definition ‘link’ means link<TYPE>
{
	TYPE data; //data item
	link* next; //pointer to next link
};
////////////////////////////////////////////////////////////////
template<class TYPE> //class linklist<TYPE>
class linklist //a list of links
//within this class definition ‘linklist’ means linklist<TYPE>
{
private:
	link<TYPE>* first; //pointer to first link
public:
	linklist() //no-argument constructor
	{
		first = NULL;
	} //no first link
	//note: destructor would be nice; not shown for simplicity
	void additem(TYPE d); //add data item (one link)
	void display(); //display all links
};
////////////////////////////////////////////////////////////////
template<class TYPE>
void linklist<TYPE>::additem(TYPE d) //add data item
{
	link<TYPE>* newlink = new link<TYPE>; //make a new link
	newlink->data = d; //give it data
	newlink->next = first; //it points to next link
	first = newlink; //now first points to this
}
//--------------------------------------------------------------
template<class TYPE>
void linklist<TYPE>::display() //display all links
{
	link<TYPE>* current = first; //set ptr to first link
	while (current != NULL) //quit on last link
	{
		cout << endl << current->data; //print data
		current = current->next; //move to next link
	}
}

class employee //employee class
{
private:
	char name[MAX_STR]; //employee name
	unsigned long number; //employee number
public:
	friend istream& operator >> (istream& s, employee& e);
	friend ostream& operator << (ostream& s, employee& e);
};
//--------------------------------------------------------------
istream& operator >> (istream& s, employee& e)
{
	cout << "\n Enter name : "; cin >> e.name;
	cout << " Enter number : "; cin >> e.number;
	return s;
}
//--------------------------------------------------------------
ostream& operator << (ostream& s, employee& e)
{
	cout << "\n Name : " << e.name;
	cout << "\n Number : " << e.number;
	return s;
}


/* Stack Template */
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



/* Queue Template */
template <class Type>
class Queue {
private:
	Type st[MAX]; //stack: array of any type
	int top; //number of top of stack
	int current;
public:
	/*class Range //exception class for Stack
	{ //note: empty class body
	};*/

	class Empty {}; // It specifies the empty exception for the stack class
	class Full {};  // It specifies the full exception for the stack class

	Queue(); //constructor
	void push(Type var); //put number on stack
	Type pop(); //take number off stack
};

template<class Type>
Queue<Type>::Queue() //constructor
{
	top = -1;
	current = 0;
}
//--------------------------------------------------------------
template<class Type>
void Queue<Type>::push(Type var) //put number on stack
{
	if (top >= MAX - 1) //if stack full,
		throw Full(); //throw exception
	st[++top] = var;
}
//--------------------------------------------------------------
template<class Type>
Type Queue<Type>::pop() //take number off stack
{
	if (top < current || top < 0) //if stack empty,
		throw Empty(); //throw exception
	return st[current++];
}