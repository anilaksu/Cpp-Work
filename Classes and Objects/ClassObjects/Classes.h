#pragma once
#include <iostream>
using namespace std;

class Time {
	public:
		Time() : hour(0), minute(0), second(0)
		{	}

		Time(int h, int m, int s) : hour(h), minute(m), second(s)
		{	}

		~Time()
		{	}

		void setTime(int h, int m, int s) {
			hour = h;
			minute = m;
			second = s;
		}

		void displayTime() {
			cout << "Time is: " << hour << ":" << minute << ":" << second << endl;
		}

		Time addTime(Time t) {
			Time temp;
			int seconds = second + t.second;
			int minutes = minute + t.minute;
			int hours = hour + t.hour;

			/* let's add any extra minute by summation*/
			minutes = minutes + int(seconds / 60);
			seconds = seconds % 60;
			/* let's add any extra hour by summation*/
			hours = hours + int(minutes / 60);
			minutes = minutes % 60;
			/*Let's set our final time*/
			temp.setTime(hours, minutes, seconds);
			return temp;
		}
	private:
		int hour, minute, second;
};



class toolBooth {

	public:
		toolBooth() : carnumber(0), money(0)
		{}

		void payingCar() {
			carnumber++;
			money = money + 0.5;
		}

		void nonpayingCar() {
			carnumber++;
		}

		void display() {
			cout << "Total number of cars is " << carnumber << endl;
			cout << "Total money collected is " << money << endl;
		}
	private:
		int carnumber;
		float money;
};
class Int {

	public:
		Int(): data(0)
			{	}
		Int(int d): data(d)
			{	}
		void setData(int d) {
			data = d;
		}

		int getData() const {
			return data;
		}
	private:
		int data;
};
class foo {
	private:
		static int count;

	public:
		foo()
		{ count++; }
		int getcount()
		{
			return count;
		}
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
	void showdist() const //display distance
	{
		cout << feet << "\' - " << inches << "\'";
	}
	void add_dist(Distance, Distance); //declaration
	Distance add_dist(Distance); //declaration

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

Distance Distance::add_dist(Distance d2)
{
	Distance temp; //temporary variable
	temp.inches = inches + d2.inches; //add the inches
	if (temp.inches >= 12.0) //if total exceeds 12.0,
	{ //then decrease inches
		temp.inches -= 12.0; //by 12.0 and
		temp.feet = 1; //increase feet
	} //by 1
	temp.feet += feet + d2.feet; //add the feet
	return temp;
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

		void getPartInfo() const {
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
