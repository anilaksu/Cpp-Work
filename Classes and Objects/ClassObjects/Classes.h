// Specification file
#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <string>
using namespace std;

class House {
	public:

		// Constructor
		House();
		House(int numStories, int numWindows, string color);
		// Destructor
		~House();
		// Member functions

		// Setter functions sets fields in private
		void setNumStories(int numStories);
		void setNumWindows(int numWindows);
		void setColor(string color);

		// Getter functions access fields in private
		int getNumStories() const;
		int getNumWindows() const;
		string getColor() const;
		void printHouseData() const;
		
	private: // Private member is only accessible within a function
		// Data Members or Fields
		int numStories; 
		int numWindows;
		string color;

}; // end of the class House

#endif 

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
public:

	// Constructor
	Rectangle();
	Rectangle(double height, double width);
	// Destructor
	~Rectangle();
	// Member functions

	// Setter functions sets fields in private
	void setHeight(double height);
	void setWidth(double width);

	// Getter functions access fields in private
	double getHeight() const;
	double getWidth() const;
	double area() const;
	double perimeter() const;

private: // Private member is only accessible within a function
	// Data Members or Fields
	double height;
	double width;

}; // end of the class Rectangle

#endif 


#ifndef BOOK_H
#define BOOK_H

class Book {
public:

	// Constructor
	Book(string author, string title, string genre, int numPages);
	// Destructor
	~Book();
	// Member functions

	// Getter functions access fields in private
	string getAuthor() const;
	string getTitle() const;
	string getGenre() const;
	int getNumPages() const;
	void printBookDetails() const;

private: // Private member is only accessible within a function
	// Data Members or Fields
	string author;
	string title;
	string genre;
	int numPages;

}; // end of the class Book

#endif 

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
public:

	// Constructor
	BankAccount(string owner, int balance);
	BankAccount(string owner);
	// Destructor
	~BankAccount();
	// Member functions

	// Modifier functions
	void deposit(int amount);
	void withdraw(int amount);

	// Getter functions access fields in private
	string getOwner() const;
	int getBalance() const;

private: // Private member is only accessible within a function
	// Data Members or Fields
	string owner;
	int balance;

}; // end of the class Bank Account

#endif 