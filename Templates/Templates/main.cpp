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

/* template <class atype> int find(atype* array, atype value, int size)
{
	for (int j = 0; j < size; j++)
		if (array[j] == value)
			return j;
	return -1;
} */

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



int main()
{

	int int1 = -6;
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

	int intArr[] = { 1, 3, 5, 9, 11, 13 }; //array
	float fltArr[] = { 1.1, 3.1, 5.1, 9.1, 11.1, 13.1 }; //array

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


	return 0;

}

