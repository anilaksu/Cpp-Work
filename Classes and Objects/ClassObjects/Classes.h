#pragma once
#include <iostream>
#include <string>

using namespace std;

class House {
	public:
		// Member functions

		// Setter functions sets fields in private
		void setNumStories(int numStories) {
			this->numStories = numStories;    // this-> shows we want to use data member
		}

		void setNumWindows(int numWindows) {
			this->numWindows = numWindows;
		}

		void setColor(string color) {
			this->color = color;
		}

		// Getter functions access fields in private
		int getNumStories() const // const indicates it accesses the data but can not change it
		{
			return numStories;
		}

		int getNumWindows() const
		{
			return numWindows;
		}

		string getColor() const
		{
			return color;
		}
		
	private: // Private member is only accessible within a function
		// Data Members or Fields
		int numStories;
		int numWindows;
		string color;

}; // end of the class House


