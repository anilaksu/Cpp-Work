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
		double weight, double costPerOunce); // Constructor for the base class Package

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

#ifndef TWODAY_H
#define TWODAY_H

class TwoDayPackage : public Package
{
public:
	TwoDayPackage(string senderName, string recipientName, string senderAddress, string recipientAddress,
		double weight, double costPerOunce, double flatFee) : Package(senderName, recipientName, senderAddress,
			recipientAddress, weight, costPerOunce)
	{
		this->flatFee = flatFee;
	}// Constructor for the der'ved class Two Day Package

	// Setter functions
	void setFlatFee(double flatFee)
	{
		this->flatFee = flatFee;
	}
	// Getter functions
	double getFlatFee() const
	{
		return this->flatFee;
	}

	// Internal Operations using Class Data 
	double totalCost()
	{
		return this->getCostPerOunce() * this->getWeight() + this->flatFee;
	}

private:
	double flatFee;

};


#endif // End of Two Day Package Class

#ifndef OVERNIGHT_H
#define OVERNIGHT_H

class OvernightPackage : public Package
{
public:
	OvernightPackage(string senderName, string recipientName, string senderAddress, string recipientAddress,
		double weight, double costPerOunce, double additionalFee) : Package(senderName, recipientName, senderAddress,
			recipientAddress, weight, costPerOunce)
	{
		this->additionalFee = additionalFee;
	}// Constructor for the derived class Overnight Package Package

	// Setter functions
	void setAdditionalFee(double additionalFee)
	{
		this->additionalFee = additionalFee;
	}
	// Getter functions
	double getAdditionalFee() const
	{
		return this->additionalFee;
	}

	// Internal Operations using Class Data 
	double totalCost()
	{
		return (this->getCostPerOunce() + this->additionalFee) * this->getWeight();
	}

private:
	double additionalFee;

};

#endif // End of Overnight Package Class

// Question from Chapter 11.10 (Account Inheritance Hierarchy)
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account(double accountBalance)
	{
		try
		{
			processPositive(accountBalance);
			this->accountBalance = accountBalance;
			cout << "Your account has $" << this->accountBalance << " balance." << endl;
		}
		catch (const invalid_argument& err)
		{
			cout << err.what() << endl;
			cin >> accountBalance; // Here we read the new account balance
			setAccountBalance(accountBalance);
		}
		
	}// Constructor for the base class Package

	// Setter functions
	void setAccountBalance(double accountBalance) {
		try
		{
			processPositive(accountBalance);
			this->accountBalance = accountBalance;
			cout << "Your account has $" << this->accountBalance << " balance." << endl;
		}
		catch (const invalid_argument& err)
		{
			cout << err.what() << endl;
			cin >> accountBalance; // Here we read the new account balance
			setAccountBalance(accountBalance);
		}
	}

	void processPositive(double accountBalance) // Throws exceptions
	{
		if (accountBalance >= 0.)
		{
			this->accountBalance = accountBalance;
		}
		else
		{
			throw invalid_argument("Your account can not have a negative balance!\n Please enter a positive balance");
		}
	}

	// Getter functions
	double getAccountBalance() const {
		return this->accountBalance;
	}

	// Internal Operations using Class Data 
	virtual void debit(double debitAmount) {

		double temporaryBalance = this->accountBalance - debitAmount;
		try
		{
			processPositive(temporaryBalance);
			this->accountBalance = temporaryBalance;
		}
		catch (const invalid_argument& err)
		{
			cout << err.what() << endl;
			cin >> debitAmount; // Here we read the new account balance
			debit(debitAmount);
		}
	}

	virtual void credit(double creditAmount) {
		this->accountBalance = this->accountBalance + creditAmount;
	}

private:
	double accountBalance;
};

#endif // !ACCOUNT_H

#ifndef SAVINGS_H
#define SAVINGS_H

class SavingsAccount : public Account
{
public:
	SavingsAccount(double accountBalance, double interestRate) :Account(accountBalance)
	{
		this->interestRate = interestRate;
	}// Constructor for the derived class Overnight Package Package

	// Setter functions
	void setInterestRate(double interestRate)
	{
		this->interestRate = interestRate;
	}
	// Getter functions
	double getInterestRate() const
	{
		return this->interestRate;
	}

	// Internal Operations using Class Data 
	double calculateInterest()
	{
		return  this->interestRate * getAccountBalance();
	}

private:
	double interestRate;

};

#endif // !SAVINGS_H

#ifndef CHECKING_H
#define CHECKING_H

class CheckingAccount : public Account
{
public:
	CheckingAccount(double accountBalance, double transactionFee) :Account(accountBalance)
	{
		this->transactionFee = transactionFee;
	}// Constructor for the derived class Overnight Package Package

	// Setter functions
	void setTransactionFee(double transactionFee)
	{
		this->transactionFee = transactionFee;
	}
	// Getter functions
	double getTransactionFee() const
	{
		return this->transactionFee;
	}

	// Internal Operations using Class Data 
	void debit(double debitAmount) {

		double temporaryBalance = getAccountBalance() - debitAmount - this->transactionFee; // Here we subtract transaction fee
		try
		{
			processPositive(temporaryBalance);
			cout << "We charged $" << this->transactionFee << " for you transaction" << endl;
			setAccountBalance(temporaryBalance);
		}
		catch (const invalid_argument& err)
		{
			cout << err.what() << endl;
			cin >> debitAmount; // Here we read the new account balance
			debit(debitAmount);
		}
	}

	virtual void credit(double creditAmount) {
		double temporaryBalance = getAccountBalance() + creditAmount - this->transactionFee; // Here we subtract transaction fee
		setAccountBalance(temporaryBalance);
		cout << "We charged $" << this->transactionFee << " for you transaction" << endl;
	}

private:
	double transactionFee;

};

#endif // !CHECKING_H