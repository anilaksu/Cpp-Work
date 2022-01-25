#pragma once
#include <iostream>
#include <cstdlib> //for srand(), rand()
#include <ctime> //for time for srand()
#include <cstring> //for strcpy()
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

class Stack
{
public:
	Stack()
	{
		top = 0;
		bottom = 0;
	}
	void push(int var) {
		st[top] = var;
		top++;
	}
	int pop() {
		bottom++;
		return st[bottom-1];
	}
private:
	enum { MAX = 10 };
	int st[MAX];
	int top;
	int bottom;
};

class Distance //English Distance class
{
private:
	int feet;
	float inches;
public: //constructor (no args)
	Distance() : feet(0), inches(0.0)
	{ }
	//constructor (two args)
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	void getdist() //get length from user
	{
		cout << "\nEnter feet : "; cin >> feet;
		cout << "Enter inches : "; cin >> inches;
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

class smallobj //define a class
{
private:
	int somedata; //class data
public:
	void setdata(int d) //member function to set data
	{
		somedata = d;
	}
	void showdata() //member function to display data
	{
		cout << "Data is " << somedata << endl;
	}
};
