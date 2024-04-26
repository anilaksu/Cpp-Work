// Implementation File

#include "classes.h"

// Constructor for CommisionEmployee Class
CommissionEmployee::CommissionEmployee(string firstName, string lastName,
	string socialSecurityNumber, double grossSales, double commissionRate)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->socialSecurityNumber = socialSecurityNumber;
	this->grossSales = grossSales;
	this->commissionRate = commissionRate;
}

// Setter functions
void CommissionEmployee::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void CommissionEmployee::setLastName(string lastName) {
	this->lastName = lastName;
}

void CommissionEmployee::setSocialSecurityNumber(string lastName) {
	this->socialSecurityNumber = socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double grossSales) {

	if (grossSales < 0.)
		throw invalid_argument("Gross Sales can not be less than 0!");
	else
		this->grossSales = grossSales;
}

void CommissionEmployee::setCommissionRate(double commisionRate) {

	if (commisionRate <= 0. && commisionRate > 1.)
		throw invalid_argument("Commision Rate should be between 0 and 1!");
	else
		this->commissionRate = commissionRate;
}

// Getter functions
string CommissionEmployee::getFirstName() const {
	return this->firstName;
}

string CommissionEmployee::getLastName() const {
	return this->lastName;
}

string CommissionEmployee::getSocialSecurityNumber() const {
	return this->socialSecurityNumber;
}

double CommissionEmployee::getGrossSales() const {
	return this->grossSales;
}

double CommissionEmployee::getCommissionRate() const {
	return this->commissionRate;
}

// Internal Operations using Class Data 
double CommissionEmployee::earnings() {
	return this->commissionRate * this->grossSales;
}