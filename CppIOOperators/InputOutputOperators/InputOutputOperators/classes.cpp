// Implementation File
#include "classes.h"

// Constructor for Rectangle Class
Rectangle::Rectangle() // It is no argument constructor
{
	this->height = 1; // Here we set data members to their default value in case, they are not set manually
	this->width = 1;
}

Rectangle::Rectangle(double height, double width) // It is with arguments
{
	this->height = height;
	this->width = width;
}

// Destructor for Rectangle Class
Rectangle::~Rectangle()
{
	;
}

// Setter functions sets fields in private
void Rectangle::setHeight(double height) {
	this->height = height;    // this-> shows we want to use data member
}

void Rectangle::setWidth(double width) {
	this->width = width;
}

// Getter functions access fields in private
double Rectangle::getHeight() const // const indicates it accesses the data but can not change it
{
	return height;
}

double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::area() const
{
	return height * width;
}

double Rectangle::perimeter() const
{
	return 2 * (height + width);
}
