// Implementation File
#include "classes.h"

Dog::Dog(string name, string breed)
{
	this->name = name;
	this->breed = breed;
}

string Dog::getName() const
{
	return name;
}

string Dog::getBreed() const
{
	return breed;
}

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
	cout << "The rectangle is " << height << " by " << width << "." << endl;
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


// Constructor for Circle Class
Circle::Circle() // It is without arguments
{
	this->radius = 1.;
}

Circle::Circle(double radius) // It is with arguments
{
	this->radius = radius;
}


// Setter functions access fields in private
void Circle::setRadius(double radius)
{
	this->radius = radius;
}

// Getter functions access fields in private
double Circle::getRadius() const
{
	return radius;
}

double Circle::circumference() const
{
	return 2. * M_PI * radius;
}

double Circle::area() const
{
	return  M_PI * pow(radius, 2.);
}