#include <iostream>
#include <string.h>
#include <sstream>
#include "cmath"
#include "Classes.h"

using namespace std;
#include <conio.h> //for getche()
const int NumDir = 4;

//void starline(); //function declaration
// (prototype)

int main()
{
	
	smallobj s1, s2; //define two objects of class smallobj
	part part1;      // define the part
	Distance dist1, dist3; //define two lengths
	Distance dist2(11, 6.25); //define and initialize dist2
	dist1.getdist(); //get dist1 from user
	dist3.add_dist(dist1, dist2); //dist3 = dist1 + dist2
	//display all lengths


	s1.setdata(1066); //call member function to set data
	s2.setdata(1776);

	s1.showdata(); //call member function to display data
	s2.showdata();

	part1.setPart(210, 10, 520.25);
	/* Let's output the part info */
	part1.getPartInfo();

	cout << "\ndist1 = "; dist1.showdist();
	cout << "\ndist2 = "; dist2.showdist();
	cout << "\ndist3 = "; dist3.showdist();
	cout << endl;

	/*for (int i = 0; i < 20; i++)
		callCounter();*/

	return 0;
}

