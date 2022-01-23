#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include "Structures.h"
#include <math.h>

using namespace std;

void callCounter()
{
	static int count = 0; // only once per program
	count++; //increment count
	cout << "You called me " << count << " times" << endl;
}


void swapTimes(Time& t1, Time& t2) {
	Time temp = t1;
	t1 = t2;
	t2 = temp;
}
inline long hms_to_seconds(Time t1) {
	return t1.hour * 3600 + t1.minute * 60 + t1.second;
}

inline long hms_to_seconds(int hour, int minute, int sec) {
	return hour * 3600 + minute * 60 + sec;
}

inline float getInches(Distance dd) {
	return dd.feet * 12 + dd.inch;
}
void printLargerDistance(Distance d1, Distance d2) {
	if (getInches(d1) > getInches(d2))
		cout << "Largest distance is: " << d1.feet << "'' -"
		<< d1.inch << endl;
	else
		cout << "Largest distance is: " << d2.feet << "'' - "
		<< d2.inch << "'" << endl;
}
void zeroSmaller(int& a, int& b) //definition
{
	if (a > b)
		b = 0;
	else
		a = 0;
}


inline float powerFunc(float n, int p)
{
	if (p > 1)
		return n * powerFunc(n, p - 1); //self call
	else
		return n;
}

inline float circarea(float radius) {
	float area = M_PI * (radius * radius);
	return area;
}

float getavg(float newdata)
{
	static float total = 0; //static variables are initialized
	static int count = 0; // only once per program
	count++; //increment count
	total += newdata; //add new data to total
	return total / count; //return the new average
}

void aFunc(int& a, const int& b) //definition
{
	a = 107; //OK
	/* You can modify const variable */
	// b = 111; //error: can’t modify constant argument
}

inline float lbstokg(float pounds)
{
	return 0.453592 * pounds;
}

unsigned long factfunc(unsigned long n)
{
	if (n > 1)
		return n * factfunc(n - 1); //self call
	else
		return 1;
}

void repchar(int n = 45, char ch = '*')
{
	for (int j = 0; j < n; j++) // loops n times
		cout << ch; // prints specified character
	cout << endl;
}
//--------------------------------------------------------------
// repchar()
// displays 45 copies of specified character


void scale(Distance& dd, float factor)
{
	float inches = (dd.feet * 12 + dd.inch) * factor;
	dd.feet = static_cast<int>(inches / 12);
	dd.inch = inches - dd.feet * 12;
}

void order(Distance& dist1, Distance& dist2) //orders two numbers
{
	if (dist1.feet > dist2.feet) //if 1st larger than 2nd,
	{
		Distance temp = dist1; //swap them
		dist1 = dist2;
		dist2 = temp;
	}
}

void intfrac(float n, float& intp, float& fracp)
{
	long temp = static_cast<long>(n); //convert to long,
	cout << "Integer part: " << temp << endl;
	intp = static_cast<float>(temp); //back to float
	fracp = n - intp; //subtract integer part
}

Distance addengl(Distance dd1, Distance dd2)
{
	Distance dd3; //define a new structure for sum
	dd3.inch = dd1.inch + dd2.inch; //add the inches
	dd3.feet = 0; //(for possible carry)
	if (dd3.inch >= 12.0) //if inches >= 12.0,
	{ //then decrease inches
		dd3.inch -= 12.0; //by 12.0 and
		dd3.feet++; //increase feet
	} //by 1
	dd3.feet += dd1.feet + dd2.feet; //add the feet
	return dd3; //return structure
}


void engldisp(Distance dd) //parameter dd of type Distance
{
	cout << dd.feet << "\' - " << dd.inch << endl;
}

void engldisp(float dd) //parameter dd of type float
{
	int feet = static_cast<int>(dd / 12);
	float inches = dd - feet * 12;
	cout << feet << "\' - " << inches << endl;
}

void starline() //function declarator
{
	for (int j = 0; j < 45; j++) //function body
		cout << '*';
	cout << endl;
}

void repchar(char ch, int n) //function declarator
{
	for (int j = 0; j < n; j++) //function body
		cout << ch;
	cout << endl;
}

void getTime(Time ShowStart, string& hour, string& minute, string& second) {

	/*Let's set all times to zero*/
	hour = { "0" };
	minute = { "0" };
	second = { "0" };

	/* Hour conversion */
	if (ShowStart.hour < 10) {
		hour.append(to_string(ShowStart.hour));
	}
	else
		hour = to_string(ShowStart.hour);

	/* Minute conversion */
	if (ShowStart.minute < 10) {
		minute.append(to_string(ShowStart.minute));
	}
	else
		minute = to_string(ShowStart.minute);

	/* Second coversion */

	if (ShowStart.second < 10) {
		second.append(to_string(ShowStart.second));
	}
	else
		second = to_string(ShowStart.second);

}