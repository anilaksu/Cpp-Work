#include "classes.h"

// Constructor for the animal class
Animal::Animal(string name, double weight)
{
	this->name = name;
	this->weight = weight;
}

// Getter functions for Animal Class
string Animal::getName() const
{
	return this->name;
}

double Animal::getWeight() const
{
	return this->weight;
}

string Animal::makeNoise() const
{
	return this->noise;
}

// Setter functions for Animal Class
void Animal::setName(string name)
{
	this->name = name;
}

void Animal::setWeight(double weight)
{
	this->weight = weight;
}

// Constructor for the derived class dog
Dog::Dog(string name, double weight, string breed) : Animal(name, weight) // Here we import base class constructor
{
	this->breed = breed;
}

// Getter functions
string Dog::getBreed() const
{
	return breed;
}
void Dog::digHole() const
{
	cout << "I am digging a hole!" << endl;
}

string Dog::makeNoise() const
{
	return "Whoa Whoa!";
}

string Dog::eat() const
{
	return "I love dog food!";
}

void Dog::chaseCat() const
{
	cout << "Here, kitty kitty!" << endl;
}

void Dog::chaseMouse() const
{
	cout << "I don't chase a mouse, I chase cats!" << endl;
}

// Constructor for the derived class cat
Cat::Cat(string name, double weight) : Animal(name, weight) // Here we import base class constructor
{
}

string Cat::eat() const
{
	return "I love eating mouse!";
}

void Cat::chaseMouse() const
{
	cout << "I am chasing a mouse!" << endl;
}

string Cat::makeNoise() const
{
	return "Meow!";
}
