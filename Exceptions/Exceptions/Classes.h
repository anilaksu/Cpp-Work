#pragma once
#include <iostream>
#include <cstdlib> //for srand(), rand()
#include <ctime> //for time for srand()
#include <string> //for strcpy()


using namespace std;

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
