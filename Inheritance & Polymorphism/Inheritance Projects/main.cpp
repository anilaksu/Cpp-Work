#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

int main()
{

	cout << "Inheritance Projects: Commision Employee Derived Classes" << endl;

	CommissionEmployee employee1("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	BasePlusCommssionEmployee basePlusEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.1, 100.);
	//CommissionEmployee* basePlusPtr = new BasePlusCommssionEmployee("Mahmut", "Ceylan", "333-33-3333", 1056.9, 0.2, 100.);

	cout << "Your commission employee sold " << employee1.getGrossSales() << " units and made $" << employee1.earnings() << endl;
	cout << "Your base plus employee sold " << basePlusEmployee.getGrossSales() << " units and made $" << basePlusEmployee.earnings() << endl;
	cout << "Your base plus employee has $" << basePlusEmployee.getBaseSalary() << " base salary." << endl;


	return 0;
}