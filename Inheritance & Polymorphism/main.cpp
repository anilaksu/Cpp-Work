/*
	Inheritance & Polymorphism:
		- Inheritance: Base class and derived classes
		- Polymorphism:
*/


#include <iostream>
#include <string>
#include "classes.h"

using namespace std;



int main()
{
	/*
		Inheritance:
			- A form of sotfware reuse
			- Methods and data are inherited from a base class by derive classes
			- The protected access specifier: classes and functions outside the inheritance hierarchy 
			have no access to protetected members
	*/

	/*
		Animal: (UML Class Diagram) UML: Unified Modeling Language
			- name: string
			- weight: double
			+ Animal(name: string, weight: double)
			+ getName(): string
			+ setName(name: string): void
			+ getWeight(): double
			+ setWeight(weight: double): void
			+ makeNoise(): string
	*/

	Animal myAnimal("Mahmut", 54.6);

	cout << "Your animal makes " << myAnimal.makeNoise() << endl;

	/*
		Derived Class Dog:
			- breed: string
			+ Dog(name: string, weight: double, breed: string)
			+ getBreed(): string
			+ digHole(): void
	*/

	/*
		Binding: the association of a function definition with a function call
			+ Early Binding: when a function call is bound to a function definition at compile time
	*/

	Dog myDog("Rover", 80, "Greyhound");
	Animal* dogPtr = new Dog("Fido", 115, "Golden Retreiver"); // It calls the base classes member functions, if it is overrriden

	cout << "Dog's name: " << myDog.getName() << endl;
	cout << "Dog's weight: " << myDog.getWeight() << endl;
	cout << "Dog's breed: " << myDog.getBreed() << endl;
	cout << "Your dog makes " << myDog.makeNoise() << endl;

	myDog.digHole();
	myDog.chaseCat();

	cout << "Make noise? " << dogPtr->makeNoise() << endl;



	// Here we delete the memory for the dog pointer
	delete dogPtr;
	dogPtr = nullptr;

	/*
		Polymorphism & Late Binding: Best demonstrated with pointers and dynamic programming
			+ Animal pointer to point to a dog object, which is a polymorphic reference
	*/

	return 0;

}