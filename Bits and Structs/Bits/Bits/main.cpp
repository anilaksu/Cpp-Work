#include <iostream>
#include <string>
#include "DeckOFCards.h"
#include <array>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

//#include "MotorVehicle.h"

using namespace std;

const size_t arraySize{ 3 };

void displayBits(unsigned value) {

	const unsigned SHIFT{8 * sizeof(unsigned)-1};
	const unsigned MASK{static_cast<const unsigned> (1 << SHIFT) };

	for (unsigned i{ 1 }; i <= SHIFT + 1; ++i) {
		cout << (value & MASK ? '1': '0');
		value <<= 1;       // Shift value left by 1

		if (i % 8 == 0) { // Output a space after 8 bits
			cout << ' ';
		}
	}
}



int main() {

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

	DeckOfCards deckOfCards;
	deckOfCards.shuffle();
	deckOfCards.deal();

	unsigned inputValue{ 0 };   // Input value to pring in binary
	cout << "Enter an unsigned integer: ";
	cin >> inputValue;
	displayBits(inputValue);

	cout << "\n"<< targetString << endl;
	// Check if it is an upper case of not
	cout << (isupper(targetString[0]) ? "Upper Case" : "Lower Case") << endl;
	targetString[0] = tolower(targetString[0]);
	cout << "Modified String: \n"<<targetString << endl;

	return 0;
}