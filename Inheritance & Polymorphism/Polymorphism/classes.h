// Specification File

#include <iostream>
#include <string>

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

enum employeeType { Salaried, Commission, BasePlus};

class Employee
{
public:
	Employee(string firstName, string lastName, 
		string socialSecurityNumber, double grossSales); // Constructor for the base abstract class Employee

	// Setter functions
	virtual void setFirstName(string firstName) final;			// This is the final version of the set first name function
	virtual void setLastName(string lastName) final;			// This is the final version of the set last name function
	virtual void setSocialSecurityNumber(string lastName) final; // This is the final version of the set social security function
	virtual void setGrossSales(double grossSales) final;

	// Getter functions
	virtual string getFirstName() const final;               // This is the final version of the get first name function
	virtual string getLastName() const final;				 // This is the final version of the get last name function
	virtual string getSocialSecurityNumber() const;          // This is the final version of the get social security function
	virtual double getGrossSales() const;                    // This is the final version of the get gross sales function    

	// Internal Operations using Class Data 
	virtual  double earnings() const = 0;            // This is the pure virtual function to be defined in every level of the hierarchy

protected:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	double grossSales;

};

#endif // !EMPLOYEE_H

#ifndef COMMISSION_H
#define COMMUSION_H

class CommissionEmployee : public Employee
{
public:
	CommissionEmployee(string firstName, string lastName,
		string socialSecurityNumber, double grossSales, double commissionRate) : Employee(firstName, lastName, socialSecurityNumber
			, grossSales)
	{
		this->commissionRate = commissionRate;
	} // Constructor for Commission Employee

	// Setter functions
	void setCommissionRate(double commisionRate);

	// Getter functions
	double getCommissionRate() const;

	// Internal Operations using Class Data 
	virtual  double earnings() const;

protected:
	double commissionRate;
};

#endif // !COMMISSION_H

#ifndef SALARIED_H
#define SALARIED_H

class SalariedEmployee : public Employee
{
public:
	SalariedEmployee(string firstName, string lastName,
		string socialSecurityNumber, double grossSales, double salary) : Employee(firstName, lastName, socialSecurityNumber
			, grossSales)
	{
		this->salary = salary;
	} // Constructor for Commission Employee

	// Setter functions
	void setSalary(double salary) {
		this->salary = salary;
	}

	// Getter functions
	double getSalary() const {
		return this->salary;
	}

	// Internal Operations using Class Data 
	virtual  double earnings() const override {
		return this->salary;
	}

protected:
	double salary;
};

#endif // !SALARIED_H

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
	virtual double earnings() const override final {  // Here we override earnings function and declare it as final
		return this->commissionRate * this->grossSales + this->baseSalary;
	}

private:
	double baseSalary = 0.;
};

#endif // !BASEPLUS_H