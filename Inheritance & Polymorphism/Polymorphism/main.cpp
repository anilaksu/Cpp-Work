#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "classes.h"

using namespace std;

// Function Protypes used in sales team project
void printMainMenu();

int main() {

	cout << "Polymorphism Projects: Commision Employee Derived Classes" << endl;

	CommissionEmployee employee1("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	// Here we define a pointer to employee 1 passed by reference
	CommissionEmployee* commissionEmployeePtr{&employee1}; 
	// Here we define commission employee with pointer from the base abstract class employee
	Employee* commissionPtr = new CommissionEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	// Here we define base plus commission employee  
	BasePlusCommssionEmployee basePlusEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);
	// Here we define it as a pointer from Commission Employee Class
	Employee* basePlusPtr = new BasePlusCommssionEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);


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

	cout << "Pointer output: Your base commision employee sold " << ((Employee*)basePlusPtr)->getGrossSales()
		<< " units and made $" << ((Employee*)basePlusPtr)->earnings() << endl;
	cout << endl;

	// Static Binding
	cout << "Your base plus employee sold " << basePlusEmployee.getGrossSales()
		<< " units and made $" << basePlusEmployee.earnings() << endl;
	cout << "Your base plus employee has $" << basePlusEmployee.getBaseSalary() << " base salary." << endl;
	cout << endl;

	/*
		delete pointer; does not delete the pointer itself, but the data that the pointer is pointing to.
		In this case, that happens to be memory that's allocated on the stack when the scope of the main() function is entered,
		and is freed automatically when the scope of main() exits. Your program attempts to free this memory using delete,
		which is undefined behavior since you're calling delete for memory that wasn't allocated using new.
	*/

	delete commissionPtr;
	delete basePlusPtr;
	commissionPtr = nullptr;
	basePlusPtr = nullptr;

	/*
		Sales Team: We will create a sales team composed of 
			- Salaried Employee's doing Sales Analytics (2)
			- Commission Employees 2 Free Lancers
			- Base Plus Commission Employees 2 Sales Members
		For given sales and salaries, we will return total sales, revenue and cost and profits

	*/

	string token; // For reading the user input
	string employeeName, employeeLastName; 
	string employeeSocialSecurityNumber;
	double sales, salary, commission;
	int employeeType;
	vector <Employee*> salesTeam;  // Here we create a pointer vector to store all employees

	printMainMenu();
	cin >> employeeType;
	cin.get(); // consume new line

	while (employeeType != 0)
	{
		cout << "What is your employee's name?" << endl;
		getline(cin, employeeName);

		// Turn it into a function
		stringstream ss(employeeName);
		int i = 1;

		while (getline(ss, token, ' ')) {
			// Process each string token 
			if (i == 1)
				employeeName = token;
			else if (i == 2)
				employeeLastName = token;
			else // In case your employee has multiple names
			{
				employeeName = employeeName + " " + employeeLastName; // Here we merge previous names as last name
				employeeLastName = token;                             // Then we assign the last word as the last name
			}
			i++;
		}

		cout << "Your employee name is " << employeeName << " " << employeeLastName << "." << endl;

		/*
		printRaceMenu();
		cin >> raceNum;
		cin.get();

		Character* tempPlayer = createPlayer(characterName, choice, raceNum);
		playerList.push_back(tempPlayer);
		*/

		//---next round?
		printMainMenu();
		cin >> employeeType;
		cin.get(); // consume new line
	}
	//cout << "Your base plus employee has $" << ((CommissionEmployee*)commissionPtr)->getBaseSalary() << " base salary." << endl;

	//commissionEmployeePtr = &basePlusEmployee; // Here we reassign commission employee pointer to base plus employee 

	//cout << "Pointer output: Your base plus commission employee sold " << ((BasePlusCommssionEmployee*)commissionEmployeePtr)->getGrossSales()
		// << " units and made $" << ((BasePlusCommssionEmployee*)commissionEmployeePtr)->earnings() << endl;

	//!!! Create Class Pointer vector with various levels of hierarchy
	
	

	return 0;
}

void printMainMenu()
{
	cout << endl;
	cout << "Which of the following employee would you like to hire?" << endl;
	cout << "\t1 - Hire a salaried employee for sales analytics team" << endl;
	cout << "\t2 - Hire a commssion employee for sales analytics team" << endl;
	cout << "\t3 - Hire a commssion employee for sales analytics team" << endl;
	cout << "\t0 - finish hiring!" << endl;
}

/*
Employee* addEmployee(string playerName, int typeNum, int raceNum)
{
	race characterRace = getRace(raceNum);

	Character* tempPlayer = nullptr;

	if (typeNum == 1)
		tempPlayer = new Warrior(playerName, characterRace);
	else if (typeNum == 2)
		tempPlayer = new Priest(playerName, characterRace);
	else if (typeNum == 3)
		tempPlayer = new Mage(playerName, characterRace);

	return tempPlayer;

}
*/