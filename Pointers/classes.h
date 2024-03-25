// Specification File
#define _USE_MATH_DEFINES
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

#ifndef DOG_H
#define DOG_H

class Dog
{
	public:
		Dog(string name, string breed); // Constructor

		// Getter functions
		string getName() const;
		string getBreed() const;

	private:
		string name;
		string breed;

};


#endif // !DOG_H

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:

	// Constructor
	Rectangle();
	Rectangle(double height, double width);
	// Destructor
	~Rectangle();
	// Member functions

	// Setter functions sets fields in private
	void setHeight(double height);
	void setWidth(double width);

	// Getter functions access fields in private
	double getHeight() const;
	double getWidth() const;
	double area() const;
	double perimeter() const;

private: // Private member is only accessible within a function
	// Data Members or Fields
	double height;
	double width;

}; // end of the class Rectangle

#endif 

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:

	// Constructor
	Circle();
	Circle(double radius);

	// Member functions

	// Setter functions
	void setRadius(double radius);

	// Getter functions access fields in private
	double getRadius() const;
	double circumference() const;
	double area() const;


private: // Private member is only accessible within a function
	// Data Members or Fields
	double radius;
}; // end of the class Circle

#endif 