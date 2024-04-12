#include <iostream>
#include <string> 

using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
	public:
		Animal(string name, double weight); // Constructor

		// Getter functions
		string getName() const;
		double getWeight() const;
		virtual string makeNoise() const;
		virtual string eat() const = 0;      // You don't need a definition in the base class for pure virtual functions
		virtual void chaseMouse() const = 0; // You don't need a definition in the base class for pure virtual functions
		// Setter functions
		void setName(string name);
		void setWeight(double weight);


	private:
		string name;
		double weight;
		string noise{"unknown noise"};
};

#endif // End of Animal Class


#ifndef DOG_H
#define DOG_H

class Dog : public Animal
{
	public:
		Dog(string name, double weight, string breed);

		// Getter functions
		string getBreed() const;
		void digHole() const;
		void chaseMouse() const;
		string makeNoise() const; // Here we override makeNoise function in the base class
		string eat() const;		  // Here we add eat function in the derived dog class
		void chaseCat() const;

	private:
		string breed;

};


#endif // End of Dog Class

#ifndef CAT_H
#define CAT_H

class Cat : public Animal
{
public:
	Cat(string name, double weight);

	// Getter functions
	void chaseMouse() const;
	string makeNoise() const; // Here we override makeNoise function in the base class
	string eat() const;		  // Here we add eat function in the derived cat class
};


#endif // End of Cat Class


#ifndef CHARACTER_H
#define CHARACTER_H

enum race { HUMAN, ELF, DWARF, ORC, TROLL };

class Character {
public:
	Character(string name, race Race, int hitPoints, int magicPoints); // Constructor

	// Getter functions
	string getName() const;
	race getRace() const;
	string whatRace() const;
	int getHitPoints() const;
	int getMagicPoints() const;

	virtual string attack() const = 0;      // You don't need a definition in the base class for pure virtual functions
	// Setter functions
	void setName(string name);
	void setRace(race Race);
	void setHitPoints(int hitPoints);
	void setMagicPoints(int magicPoints);


private:
	string name;
	race Race;
	int hitPoints;
	int magicPoints;
};

#endif // End of Character Class

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior : public Character
{
public:
	Warrior(string name, race Race) : Character(name, Race, 200, 0) // Constructor for Warrior Class
	{
	}

	// Getter functions
	string attack() const // It is now a getter function
	{
		return "I will destroy you with my sword, foul demon!";
	}

};

#endif // End of Warrior Class

#ifndef PRIEST_H
#define PRIEST_H

class Priest : public Character
{
public:
	Priest(string name, race Race) : Character(name, Race, 100, 200) // Constructor for Warrior Class
	{
	}

	// Getter functions
	string attack() const // It is now a getter function
	{
		return "I will assault you with Holy Wrath!";
	}

};

#endif // End of Priest Class

#ifndef MAGE_H
#define MAGE_H

class Mage : public Character
{
public:
	Mage(string name, race Race) : Character(name, Race, 150, 150) // Constructor for Warrior Class
	{
	}

	// Getter functions
	string attack() const // It is now a getter function
	{
		return "I will crush you with the power of my arcane missiles!";
	}

};

#endif // End of Mage Class