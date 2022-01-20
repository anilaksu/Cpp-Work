#pragma once

#include <iostream>

class MotorVehicle {

public:
	/* constructor initializes data member name with parameter accountName */
	explicit MotorVehicle(std::string model)
		: make{ model } {
	}

	/*let's get the vehicle color*/
	void setVehicleColor(std::string vehicleColor) {
		color = vehicleColor;
	}



	/*Member function sets the number of sold parts*/
	void setManufactureYear(int year) {
		if (year < 1980) {
			std::cout << "Invalid year requested \n";
		}
		else
			yearOfManufacture = year;  // Store the account name
	}

	void displayCarDetails() {
		std::cout << "Car model: "<< make << "\n";
		std::cout << "Car color: " << color << "\n";
		std::cout << "Car Manufacture Year: " << yearOfManufacture << "\n";
	}

private:
	std::string make;
	std::string fuelType{"nitrin"};
	int yearOfManufacture{2000};
	std::string color;
	int engineCapacity;

};
