/*
	Inheritance & Polymorphism:
		- Inheritance: Base class and derived classes
		- Polymorphism:
*/


#include <iostream>
#include <string>
#include <vector>
#include "classes.h"

using namespace std;

void printMainMenu();
void printRaceMenu();

Character* createPlayer(string playerName, int typeNum, int raceNum);
void doCleanup(vector<Character*> playerList);

race getRace(int raceNum);
void printAll(vector<Character*> playerList);


int main()
{
	/*
		Inheritance:
			- A form of sotfware reuse
			- Methods and data are inherited from a base class by derive classes
			- The protected access specifier: classes and functions outside the inheritance hierarchy 
			have no access to protetected members
	*/

	/*
		Animal: (UML Class Diagram) UML: Unified Modeling Language
			- name: string
			- weight: double
			+ Animal(name: string, weight: double)
			+ getName(): string
			+ setName(name: string): void
			+ getWeight(): double
			+ setWeight(weight: double): void
			+ makeNoise(): string
	*/

	//Animal myAnimal("Mahmut", 54.6);

	//cout << "Your animal makes " << myAnimal.makeNoise() << endl;

	/*
		Derived Class Dog:
			- breed: string
			+ Dog(name: string, weight: double, breed: string)
			+ getBreed(): string
			+ digHole(): void
	*/

	/*
		Binding: the association of a function definition with a function call
			+ Early Binding: when a function call is bound to a function definition at compile time
	*/

	Dog myDog("Rover", 80, "Greyhound");

	cout << "Dog's name: " << myDog.getName() << endl;
	cout << "Dog's weight: " << myDog.getWeight() << endl;
	cout << "Dog's breed: " << myDog.getBreed() << endl;
	cout << "Your dog makes " << myDog.makeNoise() << endl;

	myDog.digHole();
	myDog.chaseCat();

	/*
		Polymorphism (many forms) & Late Binding: Best demonstrated with pointers and dynamic programming
			+ Animal pointer to point to a dog object, which is a polymorphic reference
			- Early (static) binding: when a function call is bound to a function definition at compile time
			- Late (dynamic) binding: when the function call is bound to the function definition at runtime.
			Requires "virtual" keyword in the base class in C++.
			- You can not create Abstract Classes, which include pure virtual function, but you can create derived class
	*/

	// We could have pointed any of its descendence such as Dog, Cat and other animals we defined
	Animal* dogPtr = new Dog("Fido", 115, "Golden Retreiver"); // It calls the base classes member functions, if it is overrriden

	cout << "Make noise? " << dogPtr->makeNoise() << endl;
	cout << dogPtr->eat() << endl;

	// Here we delete the memory for the dog pointer
	delete dogPtr;
	dogPtr = nullptr;

	/*
		Enumerated Types:
			- Programmer-defined
			- Variables of an enum type represent any of a finite list of named constants
	*/

	enum Direction{UP, DOWN, LEFT, RIGHT, STANDING};

	Direction myDirection = STANDING;

	cout << myDirection << endl; // Here we get assigned ordinal values

	if (myDirection == UP)
		cout << "up!" << endl;
	else if (myDirection == DOWN)
		cout << "down!" << endl;
	else if (myDirection == LEFT)
		cout << "left!" << endl;
	else if (myDirection == RIGHT)
		cout << "right!" << endl;
	else 
		cout << "still standing!" << endl;

	/*
		Mini Project: Derived Cat Class UML Diagram
			+ Cat(name: string, weight: double)
			+ chaseMouse(): void
	*/

	Animal* catPtr = new Cat("Mahmut", 55);

	catPtr->chaseMouse();  // Here we output the pure function from the derived cat class

	// Here we delete the memory for the dog pointer
	delete catPtr;
	catPtr = nullptr;

	/*
		Project: RPG Character Creation
			- Player Base Class (Abstarct class)
				- name: string
				- race: Race
				- hitPoints: int
				- magicPoints: int
				+ Player(name: string, race: Race, hitPoints: int, magicPoints: int)
				+ getName(): string
				+ getRace(): Race
				+ whatRace(): string
				+ getHitPoints(): int
				+ getMagicPoints(): int
				+ setName(name: string): void
				+ setRace(race: Race): void
				+ setHitPoints(hitPoints: int): void
				+ setMagicPoints(magicPoints: int): void
				+ attack(): string = 0 (Pure function)
			- Warrior
				- 200 HP, 0 MP
				- Their attack method returns, "I will destroy you with my sword, foul demon!"
			- Priest
				- 100 HP, 200 MP
				- Their attack method returns, "I will assault you with Holy Wrath!"
			- Mage
				- 150 HP, 150 MP
				- Their attack method returns, "I will crush you with the power of my arcane missiles!"
	*/
	
	int choice;
	int raceNum;
	string characterName;

	vector <Character*> playerList;

	printMainMenu();
	cin >> choice;
	cin.get(); // consume new line

	while (choice != 0)
	{
		cout << "What would you like to name your character?" << endl;
		getline(cin, characterName);

		printRaceMenu();
		cin >> raceNum;
		cin.get();

		Character* tempPlayer = createPlayer(characterName, choice, raceNum);
		playerList.push_back(tempPlayer);

		//---next round?
		printMainMenu();
		cin >> choice;
		cin.get(); // consume new line

	}

	printAll(playerList);
	doCleanup(playerList);

	cout << "Program done!" << endl;

	return 0;

}


void printMainMenu()
{
	cout << endl;
	cout << "Which of the following would you like?" << endl;
	cout << "\t1 - Create a Warrior" << endl;
	cout << "\t2 - Create a Priest" << endl;
	cout << "\t3 - Create a Mage" << endl;
	cout << "\t0 - finish creating player characters" << endl;
}

void printRaceMenu()
{
	cout << "Now, which race do you want?" << endl;
	cout << "\t1 - Human" << endl;
	cout << "\t2 - Elf" << endl;
	cout << "\t3 - Dwarf" << endl;
	cout << "\t4 - Orc" << endl;
	cout << "\t5 - Troll" << endl;
}

Character* createPlayer(string playerName, int typeNum, int raceNum)
{
	race characterRace = getRace(raceNum);

	Character* tempPlayer = nullptr;

	if (typeNum == 1)
		tempPlayer = new Warrior(playerName, characterRace);
	else if (typeNum == 2)
		tempPlayer = new Priest(playerName, characterRace);
	else if (typeNum == 3)
		tempPlayer = new Mage(playerName, characterRace);

	return tempPlayer;

}

void doCleanup(vector<Character*> playerList) 
{
	for (Character* player : playerList)
		delete player;

	playerList.clear();
}

race getRace(int raceNum)
{
	race Race;

	if (raceNum == 1)
		Race = HUMAN;
	else if (raceNum == 2)
		Race = ELF;
	else if (raceNum == 3)
		Race = DWARF;
	else if (raceNum == 4)
		Race = ORC;
	else if (raceNum == 5)
		Race = TROLL;

	return Race;
}
void printAll(vector<Character*> playerList) 
{
	for (Character* player : playerList)
	{
		cout << "I'm a " << player->whatRace() << " and my attack is : "
			<< player->attack() << endl;
	}
		

}