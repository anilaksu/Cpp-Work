/*
	Classes and Objects in C++
		- Unified Modeling Language (UML) help us to model our classes during software design
*/

#include <iostream>
#include <string>
#include "Classes.h"

using namespace std;

int main()
{
	/*
		Object-oriented programming encapsulates behaviours and data:
			1) Encapsulation: 
				- Secuirty: Information hiding where data is protected from outside world
				- Portability: A class acts as a blueprint for an object
			2) Inheritance:	 It will be explained in detailed!
			3) Polymorphism: It will be explained in detailed! 
	*/

	House myHouse;
	House yourHouse;

	// Here we set our houses properties using member functions
	myHouse.setNumStories(2);
	myHouse.setNumWindows(6);
	myHouse.setColor("Red");

	yourHouse.setNumStories(3);
	yourHouse.setNumWindows(10);
	yourHouse.setColor("Blue");

	cout << "My house is " << myHouse.getColor() << " and has "
		<< myHouse.getNumStories() << " stories and " << myHouse.getNumWindows()
		<< " windows. " << endl;

	cout << "Your house is " << yourHouse.getColor() << " and has "
		<< yourHouse.getNumStories() << " stories and " << yourHouse.getNumWindows()
		<< " windows. " << endl;

	return 0;
}

