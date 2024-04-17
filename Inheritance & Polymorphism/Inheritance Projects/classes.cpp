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

	if (commisionRate <= 0.&& commisionRate >1.)
		throw invalid_argument("Commision Rate should be between 0 and 1!");
	else
		this->commissionRate = commissionRate;
}

// Getter functions
string CommissionEmployee::getFirstName() const{
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


// Constructor for CommisionEmployee Class
Package::Package(string senderName, string recipientName, string senderAddress,
	string recipientAddress, double weight, double costPerOunce)
{
	this->senderName = senderName;
	this->recipientName = recipientName;
	this->senderAddress = senderAddress;
	this->recipientAddress = recipientAddress;
	this->weight = weight;
	this->costPerOunce = costPerOunce;
}

// Setter functions
void Package::setSenderName(string senderName) {
	this->senderName = senderName;
}

void Package::setRecipientName(string recipientName) {
	this->recipientName = recipientName;
}

void Package::setSenderAddress(string senderAddress) {
	this->senderAddress = senderAddress;
}

void Package::setRecipientAddress(string recipientAddress) {
	this->recipientAddress = recipientAddress;
}

void Package::setWeight(double weight) {
	this->weight = weight;
}

void Package::setCostPerOunce(double costPerOunce) {
	this->costPerOunce = costPerOunce;
}

// Getter functions
string Package::getSenderName() const {
	return this->senderName;
}

string Package::getRecipientName() const {
	return this->recipientName;
}

string Package::getSenderAddress() const {
	return this->senderAddress;
}

string Package::getRecipientAddress() const {
	return this->recipientAddress;
}

double Package::getWeight() const {
	return this->weight;
}

double Package::getCostPerOunce() const {
	return this->costPerOunce;
}

// Internal Operations using Class Data 
double Package::totalCost() {
	return this->weight * this->costPerOunce;
}