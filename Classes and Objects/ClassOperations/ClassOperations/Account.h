#pragma once

#include <iostream>

class Account {
public:

	/* constructor initializes data member name with parameter accountName */
	Account(std::string accountName, int initialBalance)
		: name{ accountName } {
		//validate that initial balance is greater than 0; if not data member stay 0 
		if (initialBalance > 0)
			balance = initialBalance; // assign it to data member balance

	/*Account(unsigned int no, std::string accountName, std::string lastName, int initialBalance){
		//validate that initial balance is greater than 0; if not data member stay 0 
		firstName = accountName;
		surname = lastName;
		accountNo = no;

		if (initialBalance > 0)
			balance = initialBalance; // assign it to data member balance
	}*/
}

	explicit Account(std::string accountName)
		: name{ accountName } {
		// Empty body
	}
	/*Add valid deposit amount to balance*/
	void deposit(int depositAmount) {
		if (depositAmount > 0) {
			balance = balance + depositAmount; // add it to the balance
		}
	}
	/* Returns how much money the account have in balance */
	int getBalance() const {
		return balance; 
	}

	/*Member function sets the account name*/
	void setName(std::string accountName) {
		name = accountName;  // Store the account name
	}

	/*Member function retrieves the account name*/
	std::string getName() const {
		return name;   // 
	}

	/* Returns how much money the account have in balance */
	void drawMoney(int withdrawalAmount) {
		if (withdrawalAmount > balance) {
			std::cout << "Withdrawal amount exceeded account balance\n" ; // return error message if the amount requested exceeds the balance
		}
		else {
			balance = balance - withdrawalAmount;
			std::cout << "Remaining account balance is " << balance << "\n";
		}
	}

	/* Returns how much money the account have in balance */
	/*void getAccountDetails() {
		std::cout << "Account Number is " << accountNo << "\n"; 
		std::cout << "Full name of account holder is " << firstName << " " << surname << "\n";
		std::cout << "Account Balance is " << balance << "\n";
	}*/

private:

	/*unsigned int accountNo{ 1 };  // Initial account number
	std::string firstName;		// data member containing first name
	std::string surname;		// data member containing surname */
	std::string name;		// data member containing account name
	int balance{ 0 };	// data member with default initial value
};