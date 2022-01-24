#pragma once
#include <iostream>
using namespace std;

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
		part(): modelnumber(), partnumber(), cost() 
			{	}
		~part()
			{	}
		/* Here set part info*/
		void setPart(int mn, int pn, float c) {
			modelnumber = mn;
			partnumber = pn;
			cost = c;
		}

		void getPartInfo() {
			cout << "Part model number is: " << modelnumber << endl;
			cout << "Part part number is: " << partnumber << endl;
			cout << "Part cost is: " << cost << endl;
		}
private:
	/* Part info in private*/
	int modelnumber;
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
