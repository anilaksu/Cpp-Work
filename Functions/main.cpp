/*
	Functions in C++
*/

#include <iostream>
#include <string>
using namespace std;

void printSomething() // Function itself
{
	cout << "Hey! Look I am here!" << endl;
}

/*
	We need to refer to function prototype before call it in main
*/

void printMyName(string yourName); // Function Protype

/*
	Here we define functions with int return type
*/

int giveMe10();
int addThese(int num1, int num2);
int square(int num1);
void valueChanged1(int someNum);			// It changes pass-by-value
void valueChanged2(int& someNum);			// It changes pass-by-reference
void threeTimesN(int input, int& output);	// It uses both pass-by-value and pass-by-reference
void outputVariableTypes(int aParam);		// It exemplifies several variable types
void modifyGlobal();

// Global Variables ( Accessible in all functions and main)

double myGlobalDouble = 3.14159;    
unsigned int counter = 0;

int main() {

	string myName;
	int num1 = 21, num2 = 22;
	printSomething(); // Here call the function here

	cout << "Please enter your name" << endl;
	getline(cin, myName);

	printMyName(myName);
	cout << giveMe10() << endl;
	cout << "Your sum is " << addThese(num1, num2) << endl;
	cout << "Your square is " << square(num1) << endl;

	/*
		Parameter Passing: Pass-by-Value and Pass-by-Reference
			- Pass-by-value
				+ The default parameter passing scheme
				+ Think of it as "pass-by-copy"
			- Pass-by-reference
				+ Allows us to give more control to the function
				+ The parameter acts as an aliase for the variable from the calling function
				+ Values of parameters passed by reference that are changed reflect 
				the change in the change in the argument that was passed to them
	*/

	int myNumber = 20;

	/*
		When we pass-by-value, it does not change the number
	*/
	cout << " Pass-by-value " << endl;
	cout << "Before valueChange1 call, my number is " << myNumber << endl;
	valueChanged1(myNumber);
	cout << "After valueChange1 call, my number is " << myNumber << endl;

	/*
		When we pass-by-reference, it does change the number
	*/

	cout << " Pass-by-reference " << endl;
	cout << "Before valueChange2 call, my number is " << myNumber << endl;
	valueChanged2(myNumber);
	cout << "After valueChange2 call, my number is " << myNumber << endl;


	/*
		Parameter Passing Challenge:
			- Add a function called threeTimesN
			- The function is a void function takes two integer parameters
			- Parameters:
				+ First paramenter, input is an integer passed by value
				+ Second parameter, output is an integer passed by reference
			- Store the input multiplied by 3 intothe output variable
	*/

	cout << "Please enter an input for threeTimesN function" << endl;
	cin >> num1;

	threeTimesN(num1, num2); // Here we expect to change num2
	 
	cout << "Your output by threeTimesN function is " << num2 << endl;

	/*
		Variable Scope and Lifetime:
			- Variable Scope: which parts of the program is a variable accessible?
			- Lifetime: How long does a specific variable live?
			- Some variable categories by scope and lifetime
				+ Global variables: Accessible throughout entire program
				+ Local variables: Defined and used within the functions, not accessible by main or any other function
				+ Static local variables: It is only accessible via a function but it is updated not created each time we call the function
	*/

	cout << " Variable Scope Output " << endl;
	outputVariableTypes(num2);
	outputVariableTypes(num2); // Changing the global variable remains permanently

	/*
		Scope Challenge:
			- Create a function called modifyGlobal: void and parameterless
			- Create a global variable counter, and initialize it to 0
			- Inside modifyGlobal, increment counter by 1
			- Inside mainb, call modifyGlobal inside a for loop iterate 100 times
			- Print out the value of counter before and after the for loop
	*/

	cout << " Scope Challenge " << endl;
	
	cout << "Your counter is: " << counter << endl;

	for (int i = 0; i < 100; i++)
		modifyGlobal();

	cout << "Your counter is: " << counter << endl;

	/*
		Function Overloading:
	*/

	return 0;
}

/*
	We can place functions underneath main, then call it before main
*/

void printMyName(string yourName)
{
	cout << "Your name is " << yourName << endl;
}

/*
	Here we define functions with return
*/

int giveMe10()
{
	return 10;
}

int addThese(int num1, int num2)
{
	return num1 + num2;
}

int square(int num1)
{
	return num1 * num1;
}

// Pass-by-value value change function
void valueChanged1(int someNum)
{
	someNum = 100;
}

// Pass-by-reference value change function
void valueChanged2(int& someNum)
{
	someNum = 100;
}

// Both Pass-by-value and Pass-by-reference function
void threeTimesN(int input, int& output)
{
	output = 3 * input;
}

// Both Pass-by-value and Pass-by-reference function
void outputVariableTypes(int aParam)
{
	int myLocalNum = 100;
	static int myStatic = 500;
	myStatic++;
	myLocalNum++;
	myGlobalDouble++; 

	cout << "My local number is " << myLocalNum << endl;
	cout << "The parameter is " << aParam << endl;
	cout << "My global double is " << myGlobalDouble << endl;
	cout << "My static variable: " << myStatic << endl;
}

// Scope Challenge Function
void modifyGlobal()
{
	counter++;
}