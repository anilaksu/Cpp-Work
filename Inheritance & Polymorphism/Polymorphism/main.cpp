#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

int main() {

	cout << "Polymorphism Projects: Commision Employee Derived Classes" << endl;

	CommissionEmployee employee1("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	// Here we define a pointer to employee 1 passed by reference
	CommissionEmployee* commissionEmployeePtr{&employee1}; 
	// Here we define commission employee with pointer from the base abstract class employee
	Employee* commissionPtr = new CommissionEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	BasePlusCommssionEmployee basePlusEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);
	


	cout << "Your commission employee sold " << employee1.getGrossSales() << " units and made $" << employee1.earnings() << endl;
	cout << endl;
	cout << "Pointer output: Your commission employee sold " << commissionEmployeePtr->getGrossSales() 
		<< " units and made $" << commissionEmployeePtr->earnings() << endl;
	cout << endl;

	cout << endl;
	// Dynamic Binding
	cout << "Your commision employee sold " << ((CommissionEmployee*)commissionPtr)->getGrossSales()
		<< " units and made $" << ((CommissionEmployee*)commissionPtr)->earnings() << endl;
	cout << endl;
	// Static Binding
	cout << "Your base plus employee sold " << basePlusEmployee.getGrossSales()
		<< " units and made $" << basePlusEmployee.earnings() << endl;
	cout << "Your base plus employee has $" << basePlusEmployee.getBaseSalary() << " base salary." << endl;
	cout << endl;

	//cout << "Your base plus employee has $" << ((CommissionEmployee*)commissionPtr)->getBaseSalary() << " base salary." << endl;

	//commissionEmployeePtr = &basePlusEmployee; // Here we reassign commission employee pointer to base plus employee 

	//cout << "Pointer output: Your base plus commission employee sold " << ((BasePlusCommssionEmployee*)commissionEmployeePtr)->getGrossSales()
		// << " units and made $" << ((BasePlusCommssionEmployee*)commissionEmployeePtr)->earnings() << endl;

	/*
		delete pointer; does not delete the pointer itself, but the data that the pointer is pointing to.
		In this case, that happens to be memory that's allocated on the stack when the scope of the main() function is entered, 
		and is freed automatically when the scope of main() exits. Your program attempts to free this memory using delete, 
		which is undefined behavior since you're calling delete for memory that wasn't allocated using new.
	*/

	//!!! Create Class Pointer vector with various levels of hierarchy
	
	delete commissionPtr;
	//delete commissionEmployeePtr;
	commissionPtr = nullptr;
	//commissionEmployeePtr = nullptr;

	return 0;
}