#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "classes.h"

using namespace std;

// Function Protypes used in sales team project
void printMainMenu();									// This function guides user to choose an employee 
Employee* addEmployee(int employeeType);				// This function adds a new employee
void doCleanup(vector<Employee*> salesTeam);			// This function clears vector of pointers in the end
void returnProfitLoss(vector<Employee*> salesTeam);		// This function calculates revenue, loss, and profit 

int main() {

	cout << "Polymorphism Projects: Commision Employee Derived Classes" << endl;

	CommissionEmployee employee1("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	// Here we define a pointer to employee 1 passed by reference
	CommissionEmployee* commissionEmployeePtr{&employee1}; 
	// Here we define commission employee with pointer from the base abstract class employee
	Employee* commissionPtr = new CommissionEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2);
	// Here we define base plus commission employee  
	BasePlusCommissionEmployee basePlusEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);
	// Here we define it as a pointer from Commission Employee Class
	Employee* basePlusPtr = new BasePlusCommissionEmployee("Mahmut", "Ceylan", "333-33-3333", 2056.9, 0.2, 100.);


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

	vector <Employee*> salesTeam;  // Here we create a pointer vector to store all employees
	int employeeType;

	printMainMenu();
	cin >> employeeType;
	cin.get(); // consume new line

	while (employeeType != 0)
	{

		// Here we add a new employee as many as we want
		Employee* tempEmployee = addEmployee(employeeType);
		salesTeam.push_back(tempEmployee);
		
		cout << "Your employee name is " << salesTeam.back()->getFirstName() << " " << salesTeam.back()->getLastName() << "." << endl;

		//---next round?
		printMainMenu();
		cin >> employeeType;
		cin.get(); // consume new line
	}
	

	returnProfitLoss(salesTeam);  // Here calculate the total profit
	doCleanup(salesTeam);		  // Here we delete vector of pointers

	return 0;
}

void printMainMenu()
{
	cout << endl;
	cout << "Which of the following employee would you like to hire?" << endl;
	cout << "\t1 - Hire a salaried employee for sales analytics team" << endl;
	cout << "\t2 - Hire a freelance commission employee for sales team" << endl;
	cout << "\t3 - Hire a base plus commission employee for sales team" << endl;
	cout << "\t0 - Finish hiring!" << endl;
}


Employee* addEmployee(int employeeType)
{

	Employee* tempEmployee = nullptr;
	string token; // For reading the user input
	string employeeName, employeeLastName;
	string employeeSocialSecurityNumber;
	double sales, salary, commission;

	// Here we ask for the employee name
	cout << "What is your employee's name?" << endl;
	getline(cin, employeeName);

	stringstream ss(employeeName);
	int i = 1;

	// Here we read the employee name
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

	cout << "What is your employee's social security number?" << endl;
	getline(cin, employeeSocialSecurityNumber);

	if (employeeType == 1)
	{
		cout << "What is your employee's sales in last quarter?" << endl;
		cin >> sales;

		cout << "What is your employee's salary?" << endl;
		cin >> salary;

		tempEmployee = new SalariedEmployee(employeeName, employeeLastName,
			employeeSocialSecurityNumber, sales, salary);
	}	
	else if (employeeType == 2)
	{
		cout << "What is your employee's sales in last quarter?" << endl;
		cin >> sales;

		cout << "What is your employee's commission rate?" << endl;
		cin >> commission;

		tempEmployee = new CommissionEmployee(employeeName, employeeLastName,
			employeeSocialSecurityNumber, sales, commission);
	}
	else if (employeeType == 3)
	{
		cout << "What is your employee's sales in last quarter?" << endl;
		cin >> sales;

		cout << "What is your employee's base salary?" << endl;
		cin >> salary;

		cout << "What is your employee's commission rate?" << endl;
		cin >> commission;

		tempEmployee = new BasePlusCommissionEmployee(employeeName, employeeLastName,
			employeeSocialSecurityNumber, sales, commission, salary);
	}

	return tempEmployee;

}

void doCleanup(vector<Employee*> salesTeam)
{
	for (Employee* employee : salesTeam)
		delete employee;

	salesTeam.clear();
}

void returnProfitLoss(vector<Employee*> salesTeam)
{
	double totalRevenue = 0.;
	double totalProfit = 0.;
	double totalSalaries = 0.;

	for (Employee* employee : salesTeam)
	{
		totalProfit += employee->getGrossSales() - employee->earnings(); // Here we add profit per employee
		totalRevenue += employee->getGrossSales();						 // Here we add revene per employee
		totalSalaries += employee->earnings();							 // Here we add salary per employee
	}
		
	cout << "Your sales team made $" << totalRevenue << " and we paid $" << totalSalaries
		<< ".\n In  return, we earned $" << totalProfit << "." << endl;

}