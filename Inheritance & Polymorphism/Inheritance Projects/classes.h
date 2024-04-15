// Specification File

#include <iostream>
#include <string>

using namespace std;

#ifndef COMMISSION_H
#define COMMUSION_H

class CommisionEmployee
{
	public:
		CommisionEmployee(string firstName, string lastName, 
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
		double earnings();

	protected:
		string firstName;
		string lastName;
		string socialSecurityNumber;
		double grossSales;
		double commissionRate;


};


#endif // !COMMISSION_H
