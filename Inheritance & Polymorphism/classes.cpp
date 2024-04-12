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

// Constructor for the Character class
Character::Character(string name, race Race, int hitPoints, int magicPoints)
{
	this->name = name;
	this->Race = Race;
	this->hitPoints = hitPoints;
	this->magicPoints = magicPoints;
}

// Setter functions for the Character Class
void Character::setName(string name)
{
	this->name = name;
}

void Character::setRace(race Race)
{
	this->Race = Race;
}

void Character::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}

void Character::setMagicPoints(int magicPoints)
{
	this->magicPoints = magicPoints;
}

// Getter functions for Character Class
string Character::getName() const
{
	return this->name;
}

race Character::getRace() const
{
	return this->Race;
}

string Character::whatRace() const
{

	switch (this->Race)
	{
		case ELF:
			return "ELF";
			break;
		case DWARF:
			return "DWARF";
			break;
		case ORC:
			return "ORC";
			break;
		case TROLL:
			return "TROLL";
			break;
		default:
			return "HUMAN";
	}
}

int Character::getHitPoints() const
{
	return this->hitPoints;
}

int Character::getMagicPoints() const
{
	return this->magicPoints;
}