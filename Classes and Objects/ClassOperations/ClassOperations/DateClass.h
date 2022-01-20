#pragma once
#pragma once

#include <iostream>

class DateClass {

public:

	/*Member function sets the day*/
	void setDay(int givenDay) {
		if (givenDay > 31)
			day = 1;  // default day
		else
			day = givenDay;
	}

	/*Member function sets the year*/
	void setMonth(int givenMonth) {
		if (givenMonth > 12)
			month = 1;  // default month
		else
			month = givenMonth;
	}

	/*Member function sets the year*/
	void setYear(int givenYear) {
			year = givenYear;  // Store the account name
	}

	void displayDate() {
		if (month < 10 && day <10) {
			std::cout << "Today is: 0" << month <<"/0"<<day<<"/" << year << "\n";
		}
		else if (month < 10 && day > 10) {
			std::cout << "Today is: 0" << month << "/" << day << "/" << year << "\n";
		}
		else if (month > 10 && day < 10) {
			std::cout << "Today is: " << month << "/0" << day << "/" << year << "\n";
		}else
			std::cout << "Today is: " << month << "/" << day << "/" << year << "\n";

	}

private:
	int year{ 2000 };
	int month{ 1 };
	int day{ 1 };

};