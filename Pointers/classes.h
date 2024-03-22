// Specification File
#include <string>

using namespace std;

#ifndef DOG_H
#define DOG_H

class Dog
{
	public:
		Dog(string name, string breed); // Constructor

		// Getter functions
		string getName() const;
		string getBreed() const;

	private:
		string name;
		string breed;

};


#endif // !DOG_H
