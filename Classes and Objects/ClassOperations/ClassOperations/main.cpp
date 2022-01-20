#include <iostream>
#include <string>
#include "Account.h"
#include "Invoice.h"
#include "MotorVehicle.h"
#include "DateClass.h"

using namespace std;

void displayAccount(Account MyAccount) {
	cout << "My read account name is: " << MyAccount.getName() << endl;
	cout << "Account balance is: " << MyAccount.getBalance() << endl;
}

int main() {

	Account MyAccount{"Mahmut Ceylan", 12};          /*MyAccount object created by the definition in Account.h*/
	string theName;                                  /*Name to be set as MyAccount name*/
	int depositAmount{70};                           /*Deposit money to be added to balance account*/

	/*Initial Account Name*/
	cout << "Initial Account Name: " << MyAccount.getName() << endl;

	/*Let's read the account name from commandline*/
	cout << "Please Enter the account name" <<endl;
	getline(cin, theName);			  /*let's read the account name*/
	MyAccount.setName(theName);		  /*let's set the account name (Client) */
	MyAccount.deposit(depositAmount); /*let's add a deposit to the balance (Client) */


	cout << "My read account name is: " << MyAccount.getName() << endl;
	cout << "Account balance is: " << MyAccount.getBalance() << endl;

	/* 3.9 (Modified Account Class) */

	int withdrawalMoney;                    /* Amount of money to be withdrawn from account*/
	/*Let's read the withdrawal amount from commandline*/
	cout << "Please Enter the withdrawal amount" << endl;
	cin >> withdrawalMoney;
	MyAccount.drawMoney(withdrawalMoney);   /*let's withdraw money from our account */

	/* 3.10 (Invoice Class) */

	Invoice myInvoice{ "RN7001TZ"};				    /*MyAccount object created by the definition in Account.h*/

	/*Let's get Part Number*/
	cout << "Your part number is: " << myInvoice.getPartNo() << endl;

	myInvoice.setPartDescription("Screw Driver");   /*let's set the price for each part */
	myInvoice.setPartPrice(13.2);					/*let's set the price for each part */
	myInvoice.setNumberSold(10);					/*let's set number of parts sold */

	/*Let's get the invoice*/
	cout << "Invoice amount is: " << myInvoice.getInvoiceAmount() << endl;
	/*Let's get the invoice*/
	cout << "Price of each part is: " << myInvoice.getPartPrice() << endl;
	/*Let's get the invoice*/
	cout << "Number of parts is: " << myInvoice.getNumberSold() << endl;

	/* 3.11 (Motor Vehicle Class) */

	MotorVehicle myVehicle{ "Mustang" };				    /*MyVehicle object created by the definition in MotorVehicle.h*/

	myVehicle.setVehicleColor("Red");						/*Let's set our cars color*/

	myVehicle.displayCarDetails();

	/* 3.12 (Date Class)*/

	DateClass Today;
	int dummyNumbers;

	cout << "Please enter the month"<< endl;
	cin >> dummyNumbers;			  /*let's read the month*/
	Today.setMonth(dummyNumbers);     /*Let's set the month*/

	cout << "Please enter the day" << endl;
	cin >> dummyNumbers;			  /*let's read the day*/
	Today.setDay(dummyNumbers);     /*Let's set the day*/

	cout << "Please enter the year" << endl;
	cin >> dummyNumbers;			  /*let's read the year*/
	Today.setYear(dummyNumbers);     /*Let's set the year*/

	Today.displayDate();             /*Let'S output the date*/


	/* 3.13 (Removing Duplicated Code in the main function)*/
	displayAccount(MyAccount);

	/* 3.14 (C++ List Initializers)*/

	return 0;
}