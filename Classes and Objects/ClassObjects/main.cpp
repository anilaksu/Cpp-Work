/*
	Classes and Objects in C++
		- Unified Modeling Language (UML) help us to model our classes 
*/

#include <iostream>
#include <string>
#include "Classes.h"

using namespace std;

void printHouseData(const House& theHouse); // Function prototype with Pass by Reference

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

	House myHouse(2, 6, "Red");
	House yourHouse;

	/*
		Constructors and Destructors:
			1) Constructors:
				- Must have the same name as the class itself
				- Are functions
				- Can be overloaded
				- Have no return type - not even void
				- Are called when an object is created
			2) Destructors:
				- There can only be one
				- Does cleanup when the object is removed from memory

	*/
	
	// Here we print before setting data members manually
	myHouse.printHouseData();
	yourHouse.printHouseData();

	// Here we set our houses properties using member functions
	yourHouse.setNumStories(3);
	yourHouse.setNumWindows(10);
	yourHouse.setColor("Blue");

	printHouseData(myHouse);
	printHouseData(yourHouse);

	myHouse.printHouseData();
	yourHouse.printHouseData();

	return 0;
}

void printHouseData(const House& theHouse) // const assures that it does not change the orginal object
{
	cout << "The house is " << theHouse.getColor() << " and has "
		<< theHouse.getNumStories() << " stories and " << theHouse.getNumWindows()
		<< " windows. " << endl;
}