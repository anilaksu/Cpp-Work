#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip> //for setprecision, etc.
#include "array_functions.h"
#include "cmath"
#include "Classes.h"

using namespace std;
#include <conio.h> //for getche()
const int SIZE_1 = 2;
const int SIZE_2 = 2;

//void starline(); //function declaration
// (prototype)

int main()
{

	Distance dist1, dist3; //define two lengths
	Distance dist2(11, 6.25); //define and initialize dist2
	Stack s1;
	Distance dist[100]; //array of distances
	card deck[52];
	part part1;
	const int MAX = 80; //max characters in string
	char str[MAX];
	char str1[] = "Tiger ";
	string str2 = "Lion ";
	string str3 = "Tiger ";
	String string1(str1); //uses constructor 2
	String string2(str1); //alternate form of 2
	String string3; //uses constructor 1
	Employee emp[100];

	/* Let's concat str3*/


	int j;
	int n = 0; //count the entries
	char ans; //user response (‘y’ or ‘n’)

	s1.push(11);
	s1.push(22);
	cout << "1: " << s1.pop() << endl; //22
	cout << "2: " << s1.pop() << endl; //11
	dist1.getdist(); //get dist1 from user
	dist3.add_dist(dist1, dist2); //dist3 = dist1 + dist2
	//display all lengths
	float **age;
	double ave_age=0;

	age = new float* [SIZE_1];
	for (int i = 0; i < SIZE_2; i++)
		age[i] = new float[SIZE_2];

	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;

	/*for (int i = 0; i < SIZE_1; i++) {
		for (int j = 0; j < SIZE_2; j++) {
			cin >> age[i][j];
			ave_age += float(age[i][j]);
		}
	}*/
		
	/*ave_age = ave_age / static_cast<__int64>(SIZE_1 * SIZE_2);

	for (int i = 0; i < SIZE_1; i++)
		cout << "Your age group is: " << age[i][0] << endl;

	cout << "Average age is: " << ave_age << endl;
		 
	display_ages( age, SIZE_1, SIZE_2);*/

	do { //get distances from user
		cout << "Enter distance number " << n + 1;
		dist[n++].getdist(); //store distance in array
		cout << "Enter another(y / n) ? : ";
		cin >> ans;
	} while (ans != 'n'); //quit if user types ‘n’

	for (int j = 0; j < n; j++) //display all distances
	{
		cout << "\nDistance number " << j + 1 << " is ";
		dist[j].showdist();
	}
	cout << endl;

	for (j = 0; j < 52; j++) //make an ordered deck
	{
		int num = (j % 13) + 2; //cycles through 2 to 14, 4 times
		Suit su = Suit(j / 13); //cycles through 0 to 3, 13 times
		deck[j].set(num, su); //set card
	}
	cout << "\nOrdered deck : \n";
	for (j = 0; j < 52; j++) //display ordered deck
	{
		deck[j].display();
		cout << " ";
		if (!((j + 1) % 13)) //newline every 13 cards
			cout << endl;
	}
	srand(time(NULL)); //seed random numbers with time
	for (j = 0; j < 52; j++) //for each card in the deck,
	{
		int k = rand() % 52; //pick another card at random
		card temp = deck[j]; //and swap them
		deck[j] = deck[k];
		deck[k] = temp;
	}
	cout << "\nShuffled deck : \n";
	for (j = 0; j < 52; j++) //display shuffled deck
	{
		deck[j].display();
		cout << ", ";
		if (!((j + 1) % 13)) //newline every 13 cards
			cout << endl;
	}

	//cout << "Enter a string : ";
	//cin >> setw(MAX) >> str; //put string in str
	//cin.get(str, MAX, '$'); //terminate with $
	strcpy_s(str, str1);
	//display string from str
	cout << "You entered : " << str1 << endl;

	/* Let's set the part*/
	part1.setPart(str1, 7, 7.8);
	part1.getPartInfo();

	/*Let's play with our string class*/
	string3.concat(string1);
	string3.concat(string1);
	string3.display();
	cout << endl;

	/* Functionalities of the string class */
	str2 += str1;
	str2.append(str2);
	str2.swap(str3);
	cout << "Your famous string is: " << str2 << endl;

	/* Let's enter string 3*/
	cout << "Reenter string 3 with $ in the end" << endl;
	getline(cin, str3, '$');
	cout << "New String" << str3 << endl;

	/* Let's find my lastname*/
	n = str3.find("Aksu");
	cout << "Your last name starts at " << n << endl;

	n = str3.find_first_of("ksl");
	cout << "First of ksnl at " << n << endl;

	str3.erase(0, 6); //remove “Quick! “
	str3.replace(9, 5, "Anil"); //replace “Count” with “Lord”
	str3.replace(0, 1, "s"); //replace ‘S’ with ‘s’
	/*s1.insert(0, s3); //insert “Don’t “ at beginning
	s1.erase(s1.size() - 1, 1); //remove ‘.’ */
	//str3.append(3, '!'); //append “!!!”
	
	int x = str3.find(' '); //find a space
	/* while (x < str3.size()) //loop while spaces remain
	{
		str3.replace(x, 1, " / "); //replace “Count” with “Lord”
		x = str3.find(' '); //find next space
	}*/
	//str3.replace(x, 1, " / "); //replace “Count” with “Lord”
	cout << "New String 3 is " << str3 << endl;
	x = str3.length();
	str3 = reverseit(str3);
	cout << "New String 3 is " << str3 << endl;
	cout << "Length of the final string: " << x << endl;

	emp[0].setEmplyeeInfo(0, "Mahmut");
	emp[0].getEmployeeInfo();

	return 0;

}

