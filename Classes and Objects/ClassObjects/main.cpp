#include <iostream>
#include <string.h>
#include <sstream>
#include "cmath"
#include "Classes.h"

using namespace std;
#include <conio.h> //for getche()
const int NumDir = 4;
int foo::count = 0; //*definition* of count

//void starline(); //function declaration
// (prototype)

int main()
{
	
	smallobj s1, s2; //define two objects of class smallobj
	part part1;      // define the part
	Distance dist1, dist3; //define two lengths
    const Distance dist2(11, 6.25); //define and initialize dist2
	foo f1, f2, f3;
	Int data1(2), data2(1), data3;
	toolBooth toolbooth1;
	string cartype = { "nonpaying" };
	Time time1(9, 30, 33), time2(10, 35, 40), time3;


	dist1.getdist(); //get dist1 from user
	//dist3.add_dist(dist1, dist2); //dist3 = dist1 + dist2
	dist3 = dist1.add_dist(dist2); //dist3 = dist1 + dist2
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

	cout << "count is " << f1.getcount() << endl; //each object
	cout << "count is " << f2.getcount() << endl; //sees the
	cout << "count is " << f3.getcount() << endl; //same value
	cout << endl;
	/*for (int i = 0; i < 20; i++)
		callCounter();*/

	/* Let's add two data*/
	data3.setData(data2.getData() + data1.getData());
	/* Let's output the data 3 */
	cout << "Third data is: " << data3.getData() << endl;

	while (cartype != "Esc") {
		cout << "Enter Next Car Type" << endl;
		cin >> cartype;
		if (cartype == "paying")
			toolbooth1.payingCar();
		else if (cartype == "nonpaying")
			toolbooth1.nonpayingCar();
	}

	/* Let's output the money we collected */
	toolbooth1.display();

	/*Let's add two time to calculate the last time*/
	time3 = time1.addTime(time2);
	/*Let's display the last time*/
	time3.displayTime();


	return 0;
}

