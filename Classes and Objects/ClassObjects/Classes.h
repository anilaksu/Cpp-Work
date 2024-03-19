// Specification file
#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <string>
using namespace std;

class House {
	public:

		// Constructor
		House();
		House(int numStories, int numWindows, string color);
		// Destructor
		~House();
		// Member functions

		// Setter functions sets fields in private
		void setNumStories(int numStories);
		void setNumWindows(int numWindows);
		void setColor(string color);

		// Getter functions access fields in private
		int getNumStories() const;
		int getNumWindows() const;
		string getColor() const;
		void printHouseData() const;
		
	private: // Private member is only accessible within a function
		// Data Members or Fields
		int numStories; 
		int numWindows;
		string color;

}; // end of the class House

#endif 