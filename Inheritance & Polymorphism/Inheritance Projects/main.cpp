#include <iostream>
#include <string>
#include "classes.h"

using namespace std;

int main()
{

	cout << "Inheritance Projects: Commision Employee Derived Classes" << endl;

	CommisionEmployee Employee1("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.02);

	cout << "Your commission employeer sold " << Employee1.getGrossSales() << " units and made $" << Employee1.earnings() << endl;

	return 0;
}