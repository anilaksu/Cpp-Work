// Implementation File
#include "Classes.h"

// Constructor for House class
House::House() // It is no argument constructor
{
	this->numStories = 2; // Here we set data members to their default value in case, they are not set manually
	this->numWindows = 10;
	this->color = "Grey";
}

House::House(int numStories, int numWindows, string color) // It is with arguments
{
	this->numStories = numStories; 
	this->numWindows = numWindows;
	this->color = color;
}

// Destructor
House::~House()
{
	cout << "The " << color << " house with " << numStories << " stories "
		<< " and " << numWindows << " windows is being destroyed!" << endl;
}

// Setter functions sets fields in private
void House::setNumStories(int numStories) {
	this->numStories = numStories;    // this-> shows we want to use data member
}

void House::setNumWindows(int numWindows) {
	this->numWindows = numWindows;
}

void House::setColor(string color) {
	this->color = color;
}

// Getter functions access fields in private
int House::getNumStories() const // const indicates it accesses the data but can not change it
{
	return numStories;
}

int House::getNumWindows() const
{
	return numWindows;
}

string House::getColor() const
{
	return color;
}

void House::printHouseData() const
{
	cout << "The house is " << this->color << " and has "
		<< this->numStories << " stories and " << this->numWindows
		<< " windows. " << endl;
}



// Constructor for Rectangle Class
Rectangle::Rectangle() // It is no argument constructor
{
	this->height = 1; // Here we set data members to their default value in case, they are not set manually
	this->width = 1;
}

Rectangle::Rectangle(double height, double width) // It is with arguments
{
	this->height = height;
	this->width = width;
}

// Destructor for Rectangle Class
Rectangle::~Rectangle()
{
	cout << "The rectangle is " << height << " by " << width << "." << endl;
}

// Setter functions sets fields in private
void Rectangle::setHeight(double height) {
	this->height = height;    // this-> shows we want to use data member
}

void Rectangle::setWidth(double width) {
	this->width = width;
}

// Getter functions access fields in private
double Rectangle::getHeight() const // const indicates it accesses the data but can not change it
{
	return height;
}

double Rectangle::getWidth() const 
{
	return width;
}

double Rectangle::area() const 
{
	return height * width;
}

double Rectangle::perimeter() const
{
	return 2 * ( height + width);
}

// Constructor for Book Class
Book::Book(string author, string title, string genre, int numPages) // It is with arguments
{
	this->author = author;
	this->title = title;
	this->genre = genre;
	this->numPages = numPages;
}

// Destructor for Book Class
Book::~Book()
{
	cout << "Your book " << title << " is written by " << author << " in "
		<< genre << " with " << numPages << " pages." << endl;
}


// Getter functions access fields in private
string Book::getAuthor() const 
{
	return author;
}

string Book::getTitle() const 
{
	return title;
}

string Book::getGenre() const 
{
	return genre;
}

int Book::getNumPages() const
{
	return numPages;
}

void Book::printBookDetails() const
{
	cout << "Your book " << title << " is written by " << author << " in "
		<< genre << " with " << numPages << " pages." << endl;
}


// Constructor for Bank Account Class
BankAccount::BankAccount(string owner, int balance) // It is with arguments
{
	this->owner = owner;
	this->balance = balance;
}

BankAccount::BankAccount(string owner) // It is with arguments
{
	this->owner = owner;
}


// Destructor for Bank Account Class
BankAccount::~BankAccount()
{
	cout << "The acccount owned by " << owner << " has " << balance << "." << endl;
}


// Modifier functions access fields in private
void BankAccount::deposit(int amount) 
{
	this->balance += amount;
}

void BankAccount::withdraw(int amount)
{
	if (amount > this->balance)
		cout << "Please withdraw less than " << this->balance << endl;
	else
		this->balance -= amount;
}

// Getter functions access fields in private
string BankAccount::getOwner() const
{
	return owner;
}

int BankAccount::getBalance() const
{
	return balance;
}
