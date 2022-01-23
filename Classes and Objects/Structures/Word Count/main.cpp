#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
#include <conio.h> //for getche()
const int NumDir = 4;
enum Word { Nein = 0, Ja = 1, Maybe = 2 }; //NO=0, YES=1
enum Direction { north, south, east, west };
enum Players { B1, B2,SS, B3, RF, CF, LF, P, C};
enum etype { laborer, secretary, manager, accountant, executive, researcher};

struct Time
{
	int hour;
	int minute;
	int second;
};

struct Phone
{
	int Area;
	int Exhange;
	int Number;
};

struct Point
{
	int x_coordinate;
	int y_coordinate;
};

void getTime(Time ShowStart, string &hour, string &minute, string &second) {
	
	/*Let's set all times to zero*/
	hour = { "0" };
	minute = { "0" };
	second = { "0" };

	/* Hour conversion */
	if (ShowStart.hour < 10) {
		hour.append(to_string(ShowStart.hour));
	}
	else
		hour = to_string(ShowStart.hour);

	/* Minute conversion */
	if (ShowStart.minute < 10) {
		minute.append(to_string(ShowStart.minute));
	}
	else
		minute = to_string(ShowStart.minute);

	/* Second coversion */

	if (ShowStart.second < 10) {
		second.append(to_string(ShowStart.second));
	}
	else
		second = to_string(ShowStart.second);

}struct Distance //English distance
{
	float feet;
	float inch;
};

struct Room
{
	Distance length = {0, 0};
	Distance width = {0, 0};
	float volume = (length.feet + length.inch / 12) * (width.feet + width.inch / 12);
};


struct Employee //English distance
{
int number;
float salary;
etype employment_type;
Time employment_date;
string Employment;
};

int main()
{
	Direction home = north;  // Home direction 
	Players player1 = B3;    // Player round
	string PossibleWays[NumDir] = { "north",  "south",  "east",  "west" };
	Phone HomeNumber = { 312, 432, 5722 }; // Home number
	Time ShowStart = {9, 30, 0};           // Show start time
	string hour = {"0"}, minute = { "0" }, second = { "0" };
	Point point1, point2, point3;
	Room room1;
	Employee employee1, employee2, employee3;
	char EmployeeInitial;
	/*cout << "Our direction home is " << PossibleWays[home] << "\n";
	cout << "player 1 order is: " << player1 << endl;
	cout << "Please enter your phone number in area code, exchange code, and number form";
	cin >> HomeNumber.Area;
	cin >> HomeNumber.Exhange;
	cin >> HomeNumber.Number;

	cout << "Your home number is: (" << HomeNumber.Area << ") " << HomeNumber.Exhange << " " << HomeNumber.Number << endl;*/
	/*Let's convert to more handsome format*/
	// getTime(ShowStart, hour, minute, second);
	/* Let's output the time in handsome format*/
	// cout << "We make home by " << hour << ":" << minute << ":" << second << endl;

	/* Set show start hour */
	// ShowStart.hour = 11;
	/*Let's convert to more handsome format*/
	// getTime(ShowStart, hour, minute, second);
	/* Let's output the time in handsome format*/
	// cout << "We make home by " << hour << ":" << minute << ":" << second << endl; 

	/*cout << "Enter coordinates for point 1 ";
	cin >> point1.x_coordinate;
	cin >> point1.y_coordinate;

	cout << "Enter coordinates for point 2 ";
	cin >> point2.x_coordinate;
	cin >> point2.y_coordinate;

	/* Let's calculate point3 coordinates */
	/* point3.x_coordinate = point1.x_coordinate + point2.x_coordinate; */
	/* point3.y_coordinate = point1.y_coordinate + point2.y_coordinate;

	cout << "Coordinates of point 3 are: " << point3.x_coordinate << " " << point3.y_coordinate << endl; */

	/* Initial volume of room 1*/
	/* cout << "Initial volume of the room: " << room1.volume << endl;

	/* Let's set dimensions for room 1*/
	/* cout << "Enter the length: ";
	cin >> room1.length.feet;
	cin >> room1.length.inch; 

	cout << "Enter the width: ";
	cin >> room1.width.feet;
	cin >> room1.width.inch;

	/* Let's recalculate the volume */
	/*room1.volume = (room1.length.feet + room1.length.inch / 12) * (room1.width.feet + room1.width.inch / 12);
	/* Final volume of room 1*/
	// cout << "Final volume of the room: " << room1.volume << endl;

	/*cout << "Please enter employee 1 salary ";
	employee1.number = 1;
	cin >> employee1.salary;
	cout << "\nPlease enter employee 2 salary ";
	employee2.number = 2;
	cin >> employee2.salary;
	cout << "\nPlease enter employee 3 salary ";
	employee3.number = 3;
	cin >> employee3.salary;

	cout << "Employee ID: " << employee1.number << " Employee Salary: " << employee1.salary << endl;
	cout << "Employee ID: " << employee2.number << " Employee Salary: " << employee2.salary << endl;
	cout << "Employee ID: " << employee3.number << " Employee Salary: " << employee3.salary << endl;*/

	/*cout << "Please enter employee 1 salary  and start date ";
	employee1.number = 1;
	cin >> employee1.salary;
	employee1.employment_type = laborer;
	cin >> employee1.employment_date.hour;
	cin >> employee1.employment_date.minute;
	cin >> employee1.employment_date.second;

	switch(employee1.employment_type) {
		case 0: employee1.Employment = "laborer"; break;
		case 1: employee1.Employment = "secretary"; break;
		case 2: employee1.Employment = "manager"; break;
		case 3: employee1.Employment = "accountant"; break;
		case 4: employee1.Employment = "executive"; break;
		case 5: employee1.Employment = "researcher"; break;
	}

	cout << "Employee Type: " << employee1.Employment << endl;*/

	cout << float(361) / float(9) << endl;
	return 0;
}