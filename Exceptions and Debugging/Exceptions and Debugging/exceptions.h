#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <stdexcept>

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

#ifndef ANGRY_CAT_EXCEPTION_H
#define ANGRY_CAT_EXCEPTION_H

class AngryCatException : public runtime_error {
	public:
		// Constructor
		AngryCatException() : runtime_error("Made kitty angry")
		{

		}
		AngryCatException(const string& err) : runtime_error(err)
		{

		}
};

#endif