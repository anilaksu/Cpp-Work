#pragma once

#include <iostream>

class Competitor {
public:

	/* constructor initializes data member name with parameter accountName */
	Competitor() {}

	Competitor(std::string compName)
		: Name{ compName } {
		// Empty body
	}


	/*Member function sets the points of a competitor*/
	void setPoints(unsigned int compPoints) {
		if (compPoints < 0) {
			std::cout << "Invalid number of compeptitor points \n";
		} else
		points = compPoints;  // Store the account name
	}

	/*Member function retrieves part number*/
	std::string getName() const {
		return Name;   // 
	}

	/*Member function retrieves number of part sold*/
	int getPoints() const {
		return points;   // 
	}

private:
	
	std::string Name;		// Competitor Name
	int points { 0 };		// data member with default initial value for number of parts sold
};