/*
	Functions in C++
*/

#include <iostream>
#include <string>
#include <cmath>
#include <array>		// Here we import array class

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

// Global Variables ( Accessible in all functions and main)

double myGlobalDouble = 3.14159;
unsigned int counter = 0;
const int ARRAY_SIZE = 5;											// Here we declare our array size

int giveMe10();
int addThese(int num1, int num2);
int square(int num1);
void valueChanged1(int someNum);			// It changes pass-by-value
void valueChanged2(int& someNum);			// It changes pass-by-reference
void threeTimesN(int input, int& output);	// It uses both pass-by-value and pass-by-reference
void outputVariableTypes(int aParam);		// It exemplifies several variable types
void modifyGlobal();            


// Function prototyes for overloaded functions
int getResult(int num1, int num2);
string getResult(string str1, string str2);

// Recursive functions
void countDownFrom(int num);
int sumValues(int num);
int factorial(int num);

// Project Functions
int multiply(int num1, int num2, int num3);					  // Product of Three Project
int sumArray(int array[], int size);						  // Sum of a given array project
int sumArrayObject(array<int, ARRAY_SIZE> array);			  // Sum of a given array object project
void sumArrayObject(array<int, ARRAY_SIZE> array, int& sum);  // Sum of a given array object project



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
		Function Overloading: the process of creating multiple functions with the same name but different signatures
			- Function signatures consists of thhe name and parameter list of a function
	*/

	cout << " Function Overloading " << endl;
	int resultNum = getResult(num1, num2);
	string nameResult = getResult("Anil", "Aksu");

	cout << "result num is " << resultNum << endl;
	cout << "name num is " << nameResult << endl;

	/*
		The <cmath> Library: contains many mathematical functions such as:
			- sqrt for finding the square root
			- pow for finding a base taken to a power
			- ceil for rounding a value up to the nearest integer
			- floor for rounding a value down to the nearest integer
	*/

	cout << " cmath library " << endl;
	int powResult = pow(2, 3);
	int sqrtResult = sqrt(25);
	int ceilResult = ceil(4.2);
	int floorResult = floor(4.2);
	int log2Result = log2(512);

	cout << "2^3 is " << powResult << endl;
	cout << "sqrt of 25 is " << sqrtResult << endl;
	cout << "ceiling of 4.2 is " << ceilResult << endl;
	cout << "floor of 4.2 is " << floorResult << endl;
	cout << "logarithm 2 of 512 is " << log2Result << endl;

	/*
		Recursion: When a function calls itself, this is called recursion, which requires:
			- At least one base case (no recursion in this case)
			- At least one recursive case (this is whre recursion occurs)
	*/

	cout << " Recursive Functions " << endl;
	countDownFrom(5);
	cout << "Sum up to 10 is " << sumValues(10) << endl;

	/*
		Factorial via recursion
	*/

	cout << "10 factorial is " << factorial(5) << endl;

	/*
		Mini Project 1: Return the Product of Three Parameters
	*/

	int myInt1 = 2, myInt2 = 3, myInt3 = 27;

	cout << "Product of your three integers is " << multiply(myInt1, myInt2, myInt3) << endl;

	/*
		Mini Project 2: Sum of Built-in Array Elements
			- Write a function called sumArray:
				+ Two parameters: An array of integers, the size of the array
				+ Iterate through the array summing the integers in the array
	*/

	int myArray[ARRAY_SIZE]{ 13, 3, 98, 27, 11};						// String array

	cout << "Sum of your array is " << sumArray(myArray, ARRAY_SIZE) << endl;

	/*
		Mini Project 3: Sum of Array Objects Elements
			- Write a function called sumArray:
				+ Two parameters: An array of integers, the size of the array
				+ Iterate through the array summing the integers in the array
	*/

	array<int, ARRAY_SIZE> myIntArray{ 13, 3, 98, 27, 11 }; //Here we initialize our array class

	cout << "Sum of your array object is " << sumArrayObject(myIntArray) << endl;


	/*
		Mini Project 4: Sum of Array Objects Elements by Reference
	*/
	int sum = 0; // Sum of array

	sumArrayObject(myIntArray, sum); // Here we sum the array by reference to sum
	cout << "Sum of your array object is " << sum << endl;

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

// Overloaded functions
int getResult(int num1, int num2)
{
	return num1 * num2;
}

string getResult(string str1, string str2)
{
	return str1 + " " + str2;
}

// Recursive functions
void countDownFrom(int num)
{
	if (num >= 0)
	{
		cout << num << endl;
		countDownFrom(num - 1);
	}
}

int sumValues(int num)
{
	if (num > 0)
	{
		return num + sumValues(num - 1);
	}
	else
		return 0;
}

int factorial(int num)
{
	if (num > 1)
	{
		return num * factorial(num - 1);
	}
}

int multiply(int num1, int num2, int num3 )
{
	return num1 * num2 * num3;
}

int sumArray(int array[], int size)
{
	int sum = 0;
	for (int i = 0; i < size ; i++)
		sum += array[i];

	return sum;
}

int sumArrayObject(array<int, ARRAY_SIZE> array)
{
	int sum = 0;
	for (int item : array)
		sum += item;

	return sum;
}

void sumArrayObject(array<int, ARRAY_SIZE> array, int& sum)
{
	for (int item : array)
		sum += item;
}