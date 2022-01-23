#include <iostream>
#include <string.h>
#include <sstream>
#include "TestFunctions.h"
#include "Structures.h"
#include "cmath"

using namespace std;
#include <conio.h> //for getche()
const int NumDir = 4;

//void starline(); //function declaration
// (prototype)

int main()
{
	Direction home = north;  // Home direction 
	Players player1 = B3;    // Player round
	string PossibleWays[NumDir] = { "north",  "south",  "east",  "west" };
	Phone HomeNumber = { 312, 432, 5722 }; // Home number
	Time ShowStart = {9, 30, 0}, ShowEnd = { 12, 30, 0 };           // Show start time
	int hour = 10, minute = 40, second = 32;
	Point point1, point2, point3;
	Distance d1, d2;
	Room room1;
	Employee employee1, employee2, employee3;
	char EmployeeInitial;
	float kgs;
	float number, intpart, fracpart; //float variables
	float data = 1, avg;
	unsigned long fact;
	int a = 5, b = 2;

	starline();
	cout << float(361) / float(9) << endl;
	repchar('c', 10);
	starline();

	cout << "Enter the width: ";
	cin >> d1.feet;
	cin >> d1.inch;

	

	/* Convert my weight to kgs*/
	kgs = lbstokg(144.5);
	cout << "Your weight is :" << kgs << endl;
	cout << "Your weight is :" << lbstokg(144.5) << endl;
	/* Let's play with Structure function*/
	d2 = addengl(d1, d1);
	/*engldisp(d2);

	cout << "\nEnter a real number : "; //number from user
	cin >> number;
	intfrac(number, intpart, fracpart); //find int and frac

	cout << "Integer part is " << intpart //print them
		<< ", fraction part is " << fracpart << endl;*/

	/*order(d2, d1);
	engldisp(d1);
	engldisp(d2);

	scale(d2, 1.5);
	engldisp(d2);
	engldisp(14.5);

	repchar(34, 'y');*/

	/* Factorial Function*/
	/*fact = factfunc(5);
	cout << "Factorial is: " << float(fact) << endl;


	while (data != 0)
	{
		cout << "Enter a number : ";
		cin >> data;
		avg = getavg(data);
		cout << "New average is " << avg << endl;
	}*/

	cout << "The area of the circle is: " << circarea(3.5) << endl;
	cout << "Power function test: " << powerFunc(2.4, 5) << endl;

	zeroSmaller(a, b);
	cout << "Smaller one: " << b << endl;

	/* Let's print out the largest distance */
	printLargerDistance(d1, d2);
	/* Conversion to seconds*/
	cout << "Number of seconds: " << hms_to_seconds(hour, minute, second) << endl;
	cout << "Number of seconds: " << hms_to_seconds(ShowStart) << endl;

	swapTimes(ShowStart, ShowEnd);
	cout << "Number of seconds: " << hms_to_seconds(ShowStart) << endl;

	for (int i = 0; i < 20; i++)
		callCounter();

	return 0;
}

