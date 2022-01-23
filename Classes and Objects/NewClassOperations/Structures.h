#pragma once
#include <iostream>
using namespace std;

enum Word { Nein = 0, Ja = 1, Maybe = 2 }; //NO=0, YES=1
enum Direction { north, south, east, west };
enum Players { B1, B2, SS, B3, RF, CF, LF, P, C };
enum etype { laborer, secretary, manager, accountant, executive, researcher };

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

struct Distance //English distance
{
	float feet;
	float inch;
};

struct Room
{
	Distance length = { 0, 0 };
	Distance width = { 0, 0 };
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
