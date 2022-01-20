#include <iostream>
#include <string>
#include "Invoice.h"
#include <array>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <random>

//#include "MotorVehicle.h"

using namespace std;

const size_t arraySize{ 3 };

void staticArrayInit(void) {

	static array<int, arraySize> array1; // Static local array

	// output the array content
	for (size_t i{ 0 }; i < array1.size(); i++)
		cout << "array1[" << i << "] = " << array1[i] << " ";

	cout << "Modified Values"<< endl;

	for (size_t i{ 0 }; i < array1.size(); i++)
		array1[i] +=5;

	// output the modified array content
	for (size_t i{ 0 }; i < array1.size(); i++)
		cout << "array1[" << i << "] = " << array1[i] << " \n";
}

void automaticArrayInit(void) {

	array<int, arraySize> array2{}; // Static local array

	// output the array content
	for (size_t i{ 0 }; i < array2.size(); i++)
		cout << "array2[" << i << "] = " << array2[i] << " ";

	cout << "Modified Values" << endl;

	for (size_t i{ 0 }; i < array2.size(); i++)
		array2[i] += 5;

	// output the modified array content
	for (size_t i{ 0 }; i < array2.size(); i++)
		cout << "array2[" << i << "] = " << array2[i] << " \n";
}

int main() {

	/* Array declaration */
	const int n = 20;
	int Sum{ 0 };         // Sum of array elements
	array<int, n> x{};

	for (size_t i{ 0 }; i < x.size(); i++)
		x[i] = i;

	for (size_t i{ 0 }; i < x.size(); i++) {
		cout << i + 1 << "'th wlement value " << setw(7) << x[i] << endl;
		Sum += x[i];
	}

	cout << "Sum of all elements " << setw(7) << Sum << endl;

	/*default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> randomInt(1, 6);

	const size_t arraySize{ 7 }; //Ignore zeroth element
	array<unsigned int, arraySize> frequency{};

	for (unsigned int roll{ 1 }; roll <= 60'000'00; ++roll)
		++frequency[randomInt(engine)];

	for (size_t face{ 1 }; face < frequency.size(); ++face) {
		cout << setw(4) << face << setw(13) << frequency[face] << endl;
	}*/

	cout << "First call to each function \n" << endl;
	staticArrayInit();
	automaticArrayInit();

	cout << "\nSecond call to each function \n" << endl;
	staticArrayInit();
	automaticArrayInit();

	const size_t m = 7;
	array<string, m> colors{"Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"};

	// Output the unsorted array
	cout << "\nUnsorted colors \n";
	for (string color : colors)
		cout << color << " ";

	sort(colors.begin(), colors.end());  // Sort the colors
	cout << "\nSorted colors \n";
	// Output the sorted array
	for (string color : colors)
		cout << color << " ";

	// let's check out binary search algorithm
	bool found{ binary_search(colors.begin(),colors.end(),"Indigo") };
	cout << "\nIndigo " << (found ? "was" : "was not") << " found in colors" << endl;
	//Invoice myInvoice{ "RN7001TZ"};				    /*MyAccount object created by the definition in Account.h*/

	/* Pointers */
	int* countPtr, count;
	int b[5]{0,1,2,3,4};
	int* bPtr;
	countPtr = &count;
	count = 8;
	cout << "Pointer address: "<< countPtr << endl;
	cout << "Pointer value: " << *countPtr << endl;

	countPtr += 2;
	*countPtr = 10;

	//count = 9;
	cout << "Pointer address: " << countPtr << endl;
	cout << "Pointer address: " << &count << endl;
	cout << "Pointer value: " << count << endl;
	cout << "Pointer value: " << *countPtr << endl;

	bPtr = &b[0];
	cout << "Pointer value: " << *(3+bPtr) << endl;

	/* String Operations*/

	string stringObject, targetString{"Onur Aksu"};
	string stringTrial;
	cin >> stringObject;

	cout << "Size of the string is: " << stringObject[0] << endl;
	//targetString.assign(stringObject, 0, stringObject.size());
	cout << "Copied string is: " << targetString << endl;

	for (char c : targetString)
			cout << c << endl;
	int result;
	result = targetString.compare(5, 8, stringObject, 0, stringObject.size());
	cout << "Difference in strings is: " << result << endl;

	cout << "Location of String object is: " << targetString.find(stringObject) << endl;
	cout << "Target String data is: " << targetString.data() << endl;

	/* Conversion to Pointer-Based char* strings*/

	const char* ptr1{nullptr};      // Initialize ptr1
	size_t length{targetString.size()};

	char* ptr2{ new char[length + 1] }; // Last element is the null pointer
	targetString.copy(ptr2, length, 0);

	cout << "targetString is: " << targetString << "\ntargetString converted to a pointer-based string is " << targetString.c_str()<< endl;

	ptr1 = targetString.data();

	for (size_t i{ 0 }; i < length; i++)
		cout << *(ptr1 + i);
	
	cout << "\nptr2 is " << ptr2 << endl;
	//myInvoice.setPartDescription("Screw Driver");   /*let's set the price for each part */
	//myInvoice.setNumberSold(10);					/*let's set number of parts sold */

	/*Let's get the invoice*/
	//cout << "Number of parts is: " << myInvoice.getNumberSold() << endl;



	return 0;
}