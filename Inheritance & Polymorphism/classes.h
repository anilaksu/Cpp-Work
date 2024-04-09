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
	void setHitPoints();
	void setMagicPoints();


private:
	string name;
	double weight;
	string noise{ "unknown noise" };
};

#endif // End of Character Class