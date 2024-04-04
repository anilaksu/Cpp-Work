#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

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

#ifndef ITEMFREQUENCIES_H
#define ITEMFREQUENCIES_H

class ItemFrequencies {
public:

	// Member functions

	// Setter functions sets fields in private
	void getItem(string item);

	// Getter functions access fields in private
	void getItemFrequncyList() const;


private: // Private member is only accessible within a function
	// Data Members or Fields
	vector<string> itemList;
	vector<int> itemFrequency;

}; // end of the class Rectangle

#endif 