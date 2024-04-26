#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

int main() {

	cout << "Polymorphism Projects: Commision Employee Derived Classes" << endl;

	CommissionEmployee employee1("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	CommissionEmployee* basePlusPtr = new BasePlusCommssionEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);

	cout << "Your commission employee sold " << employee1.getGrossSales() << " units and made $" << employee1.earnings() << endl;
	cout << endl;
	cout << "Your base plus employee sold " << ((BasePlusCommssionEmployee*)basePlusPtr)->getGrossSales()
		<< " units and made $" << ((BasePlusCommssionEmployee*)basePlusPtr)->earnings() << endl;
	cout << "Your base plus employee has $" << ((BasePlusCommssionEmployee*)basePlusPtr)->getBaseSalary() << " base salary." << endl;
	cout << endl;

	delete basePlusPtr;
	basePlusPtr = nullptr;

	return 0;
}