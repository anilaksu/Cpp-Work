#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace  std;

class Person {
	public:
		// Constructor
		Person(string name);
		// Setter functions
		void setName(string name);
		// Getter functions
		string getName() const noexcept; // noexcept indicates this function does not throw an exception
	private:
		string name;
	
};

#endif

#ifndef DOG_H
#define DOG_H

class Dog {
public:
	// Constructor
	Dog(string breed);
	// Getter functions
	string getBreed() const noexcept; // noexcept indicates this function does not throw an exception
private:
	string breed;
};

#endif