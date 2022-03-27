#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip> //for setprecision, etc.
#include "array_functions.h"
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

	int int1 = -6, int2 = 2;
	long lon1 = -80000L;
	double dub1 = -10.15;
	Queue<int> s2; //s1 is object of class Queue<float>
	linklist<double> ld; //ld is object of class linklist<double>
	linklist<employee> lemp; //class “linklist<employee>”
	employee emptemp; //temporary employee storage
	char ans; //user’s response (‘y’ or ‘n’)

	char chrArr[] = { 1, 3, 5, 9, 11, 13 }; //array
	char ch = 1; //value to find

	cout << "\nabs(" << int1 << ") = " << abs(int1); //abs(int)
	cout << "\nabs(" << lon1 << ") = " << abs(lon1); //abs(long)
	cout << "\nabs(" << dub1 << ") = " << abs(dub1); //abs(double)

	// Here we find the index of the given character in the array
	cout << "\n 5 in chrArray : index = " << find(chrArr, ch, 6) << endl;
	

	//add three doubles to list ld
	ld.additem(151.5); 
	ld.additem(262.6);
	ld.additem(373.7);
	//display entire list ld
	ld.display(); 


	do
	{
		cin >> emptemp; //get employee data from user
		lemp.additem(emptemp); //add it to linked list ‘lemp’
		cout << "\nAdd another(y / n) ? "<< endl;
		// pause the program until user input
		cin >> ans;
		
	} while (ans == 'y'); //when user is done,
	lemp.display(); //display entire linked list

	// Here we test our template that multiplies every argument by 2
	cout << "\nDoubler template test for float: " << multTwo(2.1) << endl;
	cout << "Doubler template test for integer: " << multTwo(2) << endl;

	int intArr[] = { 1, 3, 15, 9, 11, 13 }; //array
	float fltArr[] = { 1.1, 3.1, 15.1, 9.1, 11.1, 13.1 }; //array

	cout << "Average template test for integer: " << getAverage(intArr, 6) << endl;
	cout << "Average template test for float: " << getAverage(fltArr, 6) << endl;

	try
	{
		//push 3 integers
		s2.push(11);
		s2.push(22);
		s2.push(33);
		// pop 3 floats ! Note that it starts popping from the top
		cout << "1: " << s2.pop() << endl;
		cout << "2: " << s2.pop() << endl;
		cout << "3: " << s2.pop() << endl;
	}

	catch (Queue<int>::Full)
	{
		cout << "Exception: Queue Full" << endl;
	}
	catch (Queue<int>::Empty)
	{
		cout << "Exception: Queue Empty" << endl;
	}

	/* Here we perform a swap operation using template*/
	swaps(int1, int2);        
	/* Let's output the swapped values */
	cout << "int1 value: " << int1 << endl;
	cout << "int2 value: " << int2 << endl;

	/* Here we test the maximum template*/
	cout << "Maximum template test for integer: " << getMax(intArr, 6) << endl;
	cout << "Maximum template test for float: " << getMax(fltArr, 6) << endl;


	safearay<int> sa1;
	safearay<float> sa2;
	fraction<int, int, int, int> frac1(1,2,3,4); // Here we defined all inputs as integer type

	for (int j = 0; j < 3; j++) //insert elements
	{
		sa1[j] = j * 10; //*left* side of equal sign
		sa2[j] = float(j * 10.2); //*left* side of equal sign
	}
		
	for (int j = 0; j < 3; j++) //display elements
	{
		int temp = sa1[j]; //*right* side of equal sign
		float temp1 = sa2[j]; //*right* side of equal sign
		cout << "Element " << j << " is " << temp << endl;
		cout << "Element " << j << " is " << temp1 << endl;
	}

	/* Here we test fraction class template for its member functions and inputs*/
	frac1.getValues();
	cout << "Addition operation with the fraction class: " << frac1.addition() << endl;
	cout << "Subtraction operation with the fraction class: " << frac1.subtraction() << endl;
	cout << "Multiplication operation with the fraction class: " << frac1.multiplication() << endl;
	cout << "Division operation with the fraction class: " << frac1.division() << endl;

	return 0;

}

