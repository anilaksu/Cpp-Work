// Implementation File

#include "classes.h"

// 
CommisionEmployee::CommisionEmployee(string firstName, string lastName,
	string socialSecurityNumber, double grossSales, double commissionRate)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->socialSecurityNumber = socialSecurityNumber;
	this->grossSales = grossSales;
	this->commissionRate = commissionRate;
}

// Setter functions
void CommisionEmployee::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void CommisionEmployee::setLastName(string lastName) {
	this->lastName = lastName;
}

void CommisionEmployee::setSocialSecurityNumber(string lastName) {
	this->socialSecurityNumber = socialSecurityNumber;
}

void CommisionEmployee::setGrossSales(double grossSales) {

	if (grossSales < 0.)
		throw invalid_argument("Gross Sales can not be less than 0!");
	else
		this->grossSales = grossSales;
}

void CommisionEmployee::setCommissionRate(double commisionRate) {

	if (commisionRate < 0.)
		throw invalid_argument("Commision Rate can not be less than 0!");
	else
		this->commissionRate = commissionRate;
}

// Getter functions
string CommisionEmployee::getFirstName() const{
	return this->firstName;
}

string CommisionEmployee::getLastName() const {
	return this->lastName;
}

string CommisionEmployee::getSocialSecurityNumber() const {
	return this->socialSecurityNumber;
}

double CommisionEmployee::getGrossSales() const {
	return this->grossSales;
}

double CommisionEmployee::getCommissionRate() const {
	return this->commissionRate;
}

// Internal Operations using Class Data 
double CommisionEmployee::earnings() {
	return this->commissionRate * this->grossSales;
}