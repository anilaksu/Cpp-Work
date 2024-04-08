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
		string makeNoise() const;
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
		string makeNoise() const; // Here we override makeNoise function in the base class
		void chaseCat() const;

	private:
		string breed;

};


#endif // End of Dog Class