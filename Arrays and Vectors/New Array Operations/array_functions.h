#pragma once
#include <iostream>
#include <iomanip> //for setprecision, etc.
using namespace std;

string reverseit(string phrase) {
	int n = phrase.length();
	char r, temp;

	for (int i = 1; i<= int(n / 2); i++) {
		r = phrase[i];
		temp = phrase[n - i];
		phrase[i] = temp;
		phrase[n +1 - i] = r;
	}

	return phrase;
}

void display_ages(float **age, const int SIZE_1, const int SIZE_2) {
	for (int d = 0; d < SIZE_1; d++)
	{
		cout << "\nDistrict " << d + 1;
		for (int m = 0; m < SIZE_2; m++) //display array values
			cout << setiosflags(ios::fixed) //not exponential
			<< setiosflags(ios::showpoint) //always use point
			<< setprecision(2) //digits to right
			<< setw(10) //field width
			<< age[d][m]; //get number from array
	}
}