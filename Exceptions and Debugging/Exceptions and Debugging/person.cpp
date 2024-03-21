#include "Person.h"
#include <stdexcept>

using namespace std;

/*
	Person Class Implementation Functions
*/
Person::Person(string name)
{
	setName(name);
}

string Person::getName() const noexcept // noexcept indicates this function does not throw an exception
{
	return name;
}

void Person::setName(string name)
{
	if (name != "John")
		this->name = name;
	else
		throw runtime_error("John? That guy is too ugly for an object!");
}


/*
	Dog Class Implementation Functions
*/
Dog::Dog(string breed)
{
	if (breed != "Poodle")
		this->breed = breed;
	else
		throw runtime_error("Poodle? That's not a real dog!");
}

string Dog::getBreed() const noexcept // noexcept indicates this function does not throw an exception
{
	return breed;
}

