#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip> //for setprecision, etc.
#include "cmath"
#include "Classes.h"

using namespace std;

template <class T> //function template
T abs(T n)
{
	return (n < 0) ? -n : n;
}

template <class T> //function template
T multTwo(T n)
{
	return (2 * n);
}

template <class T>
void swaps(T& x, T& y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}


template <class atype, class btype>
btype find(atype* array, atype value, btype size)
{
	for (btype j = 0; j < size; j++) //note use of btype
		if (array[j] == value)
			return j;
	return static_cast<btype>(-1);
}

template <class atype, class btype>
atype getAverage(atype* array, btype size)
{
	atype average = 0; // Here define the average variable

	for (btype j = 0; j < size; j++) //note use of btype
		average += array[j];
	/* Here we return the sum divided by the number of elements*/
	/* Also, we specify that the function returns it in atype*/
	return static_cast<atype>(average/size);
}

template <class atype, class btype>
atype getMax(atype* array, btype size)
{
	atype Max = array[0]; // Here define the average variable

	for (btype j = 1; j < size; j++) //note use of btype
		if(array[j] > Max)
			Max = array[j];
	/* Here we return the maximum element in array */
	return Max;
}


int main()
{
	CountDn c1(5); //c1 of class CountDn
	Stack2 s1;

	DistSign alpha; //no-arg constructor
	DistSign beta(11, 6.25); //2-arg constructor
	DistSign gamma(100, 5.5, neg); //3-arg constructor

	cout << "\nc1 = " << c1.get_count(); //display c1
	++c1; ++c1; ++c1; //increment c1, 3 times
	cout << "\nc1 = " << c1.get_count(); //display it
	--c1; --c1; //decrement c1, twice
	cout << "\nc1 = " << c1.get_count(); //display it
	cout << endl;

	s1.push(11); //push some values onto stack
	s1.push(22);
	s1.push(33);
	cout << endl << s1.pop(); //pop some values from stack
	cout << endl << s1.pop();
	cout << endl << s1.pop();
	cout << endl;

	// Here we play with the class DistSign derived from the distance class with a sign
	alpha.getdist(); //get alpha from user
	cout << " Ther distance from the derived class" << endl;

	//display all distances
	cout << "\nalpha = "; alpha.showdist();
	cout << "\nbeta = "; beta.showdist();
	cout << "\ngamma = "; gamma.showdist();
	cout << endl;

	return 0;

}

