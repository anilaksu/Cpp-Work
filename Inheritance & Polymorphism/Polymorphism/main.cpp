#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

int main() {

	cout << "Polymorphism Projects: Commision Employee Derived Classes" << endl;

	CommissionEmployee employee1("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	// Here we define a pointer to employee 1 passed by reference
	CommissionEmployee* commissionEmployeePtr{&employee1}; 
	// Here we define base plus employee with pointer then assign it
	CommissionEmployee* basePlusPtr = new BasePlusCommssionEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);
	BasePlusCommssionEmployee basePlusEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);
	


	cout << "Your commission employee sold " << employee1.getGrossSales() << " units and made $" << employee1.earnings() << endl;
	cout << endl;
	cout << "Pointer output: Your commission employee sold " << commissionEmployeePtr->getGrossSales() 
		<< " units and made $" << commissionEmployeePtr->earnings() << endl;
	cout << endl;

	cout << endl;
	// Dynamic Binding
	cout << "Your base plus employee sold " << ((BasePlusCommssionEmployee*)basePlusPtr)->getGrossSales()
		<< " units and made $" << ((BasePlusCommssionEmployee*)basePlusPtr)->earnings() << endl;
	cout << "Your base plus employee has $" << ((BasePlusCommssionEmployee*)basePlusPtr)->getBaseSalary() << " base salary." << endl;
	cout << endl;
	// Static Binding
	cout << "Your base plus employee sold " << basePlusEmployee.getGrossSales()
		<< " units and made $" << basePlusEmployee.earnings() << endl;
	cout << "Your base plus employee has $" << basePlusEmployee.getBaseSalary() << " base salary." << endl;
	cout << endl;

	commissionEmployeePtr = &basePlusEmployee; // Here we reassign commission employee pointer to base plus employee 

	cout << "Pointer output: Your base plus commission employee sold " << ((BasePlusCommssionEmployee*)commissionEmployeePtr)->getGrossSales()
		<< " units and made $" << ((BasePlusCommssionEmployee*)commissionEmployeePtr)->earnings() << endl;

	delete basePlusPtr;
	basePlusPtr = nullptr;


	return 0;
}