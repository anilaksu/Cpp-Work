/*
	Classes and Objects in C++
		- Unified Modeling Language (UML) help us to model our classes 
*/

#define _USE_MATH_DEFINES // This allows us to use Pi number
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Classes.h"

using namespace std;

void printHouseData(const House& theHouse); // Function prototype with Pass by Reference
void printBookDetails(const Book& theBook);

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

	/*
		UML Class Diagrams:
			1) Data in the class (data members/fields)
			2) Behaviours of the class (member functions/methods)
	*/

	// Rectangle using rectangle class
	Rectangle rectangle_1;
	Rectangle rectangle_2(2.0, 5.2);

	cout << "rectangle 1 area is " << rectangle_1.area() << endl;
	cout << "rectangle 2 area is " << rectangle_2.area() << endl;

	rectangle_1.setHeight(22);
	rectangle_1.setWidth(11);

	cout << "rectangle 1 area now is " << rectangle_1.area() << endl;
	cout << "rectangle 1 perimeter now is " << rectangle_1.perimeter() << endl;

	/*
		Book Class:
			- author: string
			- title: string
			- genre: string
			- numPages: int
			+ Book(author: string, title: string,
					genre: string, numPages: int)
			+ getAuthor(): string
			+ getTitle(): string
			+ getGenre(): string
			+ getNumPages(): int
	*/

	Book gameOfThrones("George Martin", "Game of Thrones", "Fantasy", 864);

	printBookDetails(gameOfThrones);
	gameOfThrones.printBookDetails();

	/*
		A Bank Account Class:
			- owner: string
			- balance: int
			+ BankAccount(owner :string)
			+ BankAccount(owner :string, balance: int)
			+ deposit(amount: int): void
			+ widthdraw(amount: int) void
			+ getOwner(): string
			+ getBalance(): int
	*/

	BankAccount myAccount("Anil Aksu", 200);

	myAccount.withdraw(200);

	/*
		A Pizza Class:
			- name: string
			- cost: int
			- diameter: int
			- toppings: vector<string>
			+ Pizza(name :string, cost: int, diameter: int)
			+ addTopping(topping :string): void (Cheese is a default topping)
			+ getCost(): int
			+ printToppings(): void
	*/

	Pizza myPizza("Pepperoni", 20);

	// Here we add our toppings
	myPizza.addTopping("Ham");
	myPizza.addTopping("Jalapeno");

	// Here we output our pizza's cost
	cout << "Your pizza costs $" << myPizza.getCost() << "." << endl;
	// Here we output our toppings
	myPizza.printToppings();

	/*
		A Circle Class:
			- radius: double
			+ Circle()
			+ Circle(radius: double)
			+ getRadius(): double 
			+ setRadius(radius: double): void
			+ circumference(): double
			+ area(): double
	*/

	Circle myCircle;

	cout << "Your circle has " << myCircle.circumference() << " circumference." << endl;
	cout << "Your circle has " << myCircle.area() << " area." << endl;

	// Here we change the radius
	myCircle.setRadius(2.5);

	cout << "Your circle has " << myCircle.circumference() << " circumference." << endl;
	cout << "Your circle has " << myCircle.area() << " area." << endl;


	return 0;
}

void printHouseData(const House& theHouse) // const assures that it does not change the orginal object when we pass it by reference
{
	cout << "The house is " << theHouse.getColor() << " and has "
		<< theHouse.getNumStories() << " stories and " << theHouse.getNumWindows()
		<< " windows. " << endl;
}

void printBookDetails(const Book& theBook) 
{
	cout << "Your book " << theBook.getTitle() << " is written by " << theBook.getAuthor() << " in "
		<< theBook.getGenre() << " with " << theBook.getNumPages() << " pages." << endl;
}