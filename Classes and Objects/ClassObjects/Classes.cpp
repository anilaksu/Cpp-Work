// Implementation File
#include "Classes.h"

// Constructor for House class
House::House() // It is no argument constructor
{
	this->numStories = 2; // Here we set data members to their default value in case, they are not set manually
	this->numWindows = 10;
	this->color = "Grey";
}

House::House(int numStories, int numWindows, string color) // It is with arguments
{
	this->numStories = numStories; 
	this->numWindows = numWindows;
	this->color = color;
}

// Destructor
House::~House()
{
	cout << "The " << color << " house with " << numStories << " stories "
		<< " and " << numWindows << " windows is being destroyed!" << endl;
}

// Setter functions sets fields in private
void House::setNumStories(int numStories) {
	this->numStories = numStories;    // this-> shows we want to use data member
}

void House::setNumWindows(int numWindows) {
	this->numWindows = numWindows;
}

void House::setColor(string color) {
	this->color = color;
}

// Getter functions access fields in private
int House::getNumStories() const // const indicates it accesses the data but can not change it
{
	return numStories;
}

int House::getNumWindows() const
{
	return numWindows;
}

string House::getColor() const
{
	return color;
}

void House::printHouseData() const
{
	cout << "The house is " << this->color << " and has "
		<< this->numStories << " stories and " << this->numWindows
		<< " windows. " << endl;
}