#include <iostream>
using namespace std;

/* Days of week in order*/
enum Weekdays { Sun, Mon, Tue, Wed, Thu, Fri, Sat };
/* Word check enumeration */
enum itsaWord { NO, YES };
////////////////////////////////////////////////////////////////
struct Distance //English distance
{
	int feet;
	float inches;
};
////////////////////////////////////////////////////////////////
struct Room //rectangular area
{
	Distance length; //length of rectangle
	Distance width; //width of rectangle
};

int main()
{
	Room Bedroom;
	Distance d1, d3; //define two lengths
	Weekdays day1;   // Day of the week 
	Bedroom.length = { 11, 6.25 }; //define & initialize one length
	//get length d1 from user
	cout << "\nEnter feet : "; 
	cin >> d1.feet;
	cout << "Enter inches : "; 
	cin >> d1.inches;
	//add lengths d1 and d2 to get d3
	d3.inches = d1.inches + Bedroom.length.inches; //add the inches
	d3.feet = 0; //(for possible carry)
	if (d3.inches >= 12.0) //if total exceeds 12.0,
	{ //then decrease inches by 12.0
		d3.inches -= 12.0; //and
		d3.feet++; //increase feet by 1
	}
	d3.feet += d1.feet + Bedroom.length.feet; //add the feet
	//display all lengths
	cout << d1.feet << "\' - " << d1.inches << "\" + ";
	cout << Bedroom.length.feet << "\' - " << Bedroom.length.feet << "\" = ";
	cout << d3.feet << "\' - " << d3.inches << "\"\n";

	day1 = Mon;
	cout << day1 << endl;
	return 0;
}