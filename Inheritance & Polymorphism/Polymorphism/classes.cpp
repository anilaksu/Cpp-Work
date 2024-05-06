// Implementation File

#include "classes.h"

// Constructor for Employee Class
Employee::Employee(string firstName, string lastName,
	string socialSecurityNumber, double grossSales)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->socialSecurityNumber = socialSecurityNumber;
	this->grossSales = grossSales;
}

// Setter functions
void Employee::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Employee::setLastName(string lastName) {
	this->lastName = lastName;
}

void Employee::setSocialSecurityNumber(string lastName) {
	this->socialSecurityNumber = socialSecurityNumber;
}

void Employee::setGrossSales(double grossSales) {

	if (grossSales < 0.)
		throw invalid_argument("Gross Sales can not be less than 0!");
	else
		this->grossSales = grossSales;
}

// Getter functions
string Employee::getFirstName() const {
	return this->firstName;
}

string Employee::getLastName() const {
	return this->lastName;
}

string Employee::getSocialSecurityNumber() const {
	return this->socialSecurityNumber;
}

double Employee::getGrossSales() const {
	return this->grossSales;
}

// Commission Employee Setter Functions
void CommissionEmployee::setCommissionRate(double commisionRate) {

	if (commisionRate <= 0. && commisionRate > 1.)
		throw invalid_argument("Commision Rate should be between 0 and 1!");
	else
		this->commissionRate = commissionRate;
}

// Commission Employee Getter Functions
double CommissionEmployee::getCommissionRate() const {
	return this->commissionRate;
}

// Internal Operations using Class Data 
double CommissionEmployee::earnings() const {
	return this->commissionRate * this->grossSales;
}