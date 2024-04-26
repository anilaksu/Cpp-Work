#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

int main()
{

	cout << "Inheritance Projects: Commision Employee Derived Classes" << endl;

	CommissionEmployee employee1("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	BasePlusCommssionEmployee basePlusEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);
	CommissionEmployee* basePlusPtr = new BasePlusCommssionEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);

	cout << "Your commission employee sold " << employee1.getGrossSales() << " units and made $" << employee1.earnings() << endl;
	cout << "Your base plus employee sold " << basePlusEmployee.getGrossSales() << " units and made $" << basePlusEmployee.earnings() << endl;
	cout << "Your base plus employee has $" << basePlusEmployee.getBaseSalary() << " base salary." << endl;
	cout << endl;
	cout << "Your base plus employee sold " << ((BasePlusCommssionEmployee*)basePlusPtr)->getGrossSales() 
		<< " units and made $" << ((BasePlusCommssionEmployee*)basePlusPtr)->earnings() << endl;
	cout << "Your base plus employee has $" << ((BasePlusCommssionEmployee*)basePlusPtr)->getBaseSalary() << " base salary." << endl;
	cout << endl;

	delete basePlusPtr;
	basePlusPtr = nullptr;

	OvernightPackage myOvernightPackage("Can Bilir", "Anil Aksu", "Cin Cin", "Seyran", 20.1, 0.1, 0.2);
	TwoDayPackage myTwoDayPackage("Can Bilir", "Anil Aksu", "Cin Cin", "Seyran", 20.1, 0.1, 10.1);

	cout << "If you choose overnight delivery, it costs $" << myOvernightPackage.totalCost() << endl;
	cout << "If you choose two day delivery, it costs $" << myTwoDayPackage.totalCost() << endl;
	cout << endl;


	// Account Hierarchy
	double credit, debit;
	Account myAccount(-100.0);
	SavingsAccount mySavingsAccount(120.0, 0.05);
	CheckingAccount myCheckingAccount(300.5, 2.0);

	cout << "How much would you like to debit from your account?" << endl;
	cin >> debit;
	myAccount.debit(debit);
	cout << "Your account has $" << myAccount.getAccountBalance() << " balance." << endl;

	cout << "How much would you like to credit to your account?" << endl;
	cin >> credit;
	myAccount.credit(credit);
	cout << "Your account has $" << myAccount.getAccountBalance() << " balance." << endl;

	cout << "How much would you like to credit to your savings account?" << endl;
	cin >> credit;
	mySavingsAccount.credit(credit);
	cout << "Your savings account returned $" << mySavingsAccount.calculateInterest() << " interest." << endl;

	cout << "How much would you like to debit to your savings account?" << endl;
	cin >> debit;
	myCheckingAccount.debit(debit);
	cout << "Your account has $" << myCheckingAccount.getAccountBalance() << " balance." << endl;

	return 0;
}