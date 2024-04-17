// Specification File

#include <iostream>
#include <string>

using namespace std;

#ifndef COMMISSION_H
#define COMMUSION_H

class CommissionEmployee
{
	public:
		CommissionEmployee(string firstName, string lastName,
			string socialSecurityNumber, double grossSales, double commissionRate); // Constructor for the base class Commision Employee

		// Setter functions
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setSocialSecurityNumber(string lastName);
		void setGrossSales(double grossSales);
		void setCommissionRate(double commisionRate);
		
		// Getter functions
		string getFirstName() const;
		string getLastName() const;
		string getSocialSecurityNumber() const;
		double getGrossSales() const; 
		double getCommissionRate() const;

		// Internal Operations using Class Data 
		virtual  double earnings();

	protected:
		string firstName;
		string lastName;
		string socialSecurityNumber;
		double grossSales;
		double commissionRate;


};

#endif // !COMMISSION_H

#ifndef BASEPLUS_H
#define BASEPLUS_H

class BasePlusCommssionEmployee : public CommissionEmployee
{
	public:
		BasePlusCommssionEmployee(string firstName, string lastName,
			string socialSecurityNumber, double grossSales, double commissionRate, double baseSalary) : CommissionEmployee(firstName, lastName, socialSecurityNumber
				, grossSales, commissionRate)
		{
			this->baseSalary = baseSalary;
		} // Constructor for Base Plus Commission Employee

		// Setter Functions
		void setBaseSalary(double baseSalary)
		{
			this->baseSalary = baseSalary;
		}

		// Getter Functions
		double getBaseSalary() const {
			return this->baseSalary;
		}

		// Modifier Functions
		double earnings() const {
			return this->commissionRate * this->grossSales + this->baseSalary;
		}

	private:
		double baseSalary = 0.;
};

#endif // !BASEPLUS_H

// Question from Chapter 11.9 (Package Inheritance Hierarchy)
#ifndef PACKAGE_H
#define PACKAGE_H

class Package
{
public:
	Package(string senderName, string recipientName, string senderAddress, string recipientAddress,
		double weight, double costPerOunce); // Constructor for the base class Commision Employee

	// Setter functions
	void setSenderName(string senderName);
	void setRecipientName(string recipientName);
	void setSenderAddress(string senderAddress);
	void setRecipientAddress(string recipientAddress);
	void setWeight(double weight);
	void setCostPerOunce(double costPerOunce);

	// Getter functions
	string getSenderName() const;
	string getRecipientName() const;
	string getSenderAddress() const;
	string getRecipientAddress() const;
	double getWeight() const;
	double getCostPerOunce() const;

	// Internal Operations using Class Data 
	virtual  double totalCost();

private:
	string senderName;
	string recipientName;
	string senderAddress; 
	string recipientAddress;
	double weight; 
	double costPerOunce;
};

#endif // !PACKAGE_H