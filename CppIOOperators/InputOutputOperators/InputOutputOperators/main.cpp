/*
	File I/O:
		- Main memory:
			+ Memory or RAM
			+ This is where data (variables) and instructions (statements, functions) live
			+ Main memory is fast, but volatile
		- Secondary storage
			+ Slow, but persistent
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "classes.h"

using namespace std;

// Function prototypes
void printFormatted(ofstream& outfile, int highNum);

int main() {

	ofstream outfile;
	char SampleChar;  // Sample character to test ASCII character set 
	int highNum;      // the length of the output

	/* Integer Equivalent of a Character */

	cout << "A sample character \n";
	cin >> SampleChar;
	cout << "ASCII Character Set is: " << static_cast<int>(SampleChar) << endl;  /* This command converts a charater 
																					into its corresponding ASCII character set */
	/*
		File Output:
			- setw function sets the spacing		
			- setprecision function sets the number of digits
	*/

	cout << "Writing to file" << endl;
	cout << "Please enter the length of the output" << endl;
	cin >> highNum;
	outfile.open("output.txt");          // Here we open the output file 
	outfile << fixed << showpoint;
	cout << fixed << showpoint;
	printFormatted(outfile, highNum);	 // Here we call the function for output
		
	outfile.close();				     // Here we close the file
	cout << "Done!" << endl;

	/*
		File Input
	*/

	ifstream infile;
	infile.open("input.txt");

	vector<int> inputVector; // Here we create a vector to store the numbers in the input file
	int  inputNum; // Here we create a vector to store the numbers in the input file
	int sum = 0;

	while (!infile.eof())
	{
		infile >> inputNum;
		inputVector.push_back(inputNum);
		sum += inputNum;
	}

	// Here we output the input on the console before showing the sum 
	cout << "Your input:" << endl;
	for (int num : inputVector)
		cout << setw(12) << 2 * num << endl;

	cout << "Sum of numbers is: " << sum << endl;
	infile.close();

	/*
		Read data from two files and combine their data into a single output file
	*/

	ifstream nameFile;		// For reading name file
	ifstream ageFile;		// For reading age file
	ofstream nameAgeFile;	// For outputting name and age


	vector<string> names; // Here we create a vector to store names in the name file
	vector<int> ages;     // Here we create a vector to store names in the name file

	string name;          // Temporary variable to store the name
	int age;			  // Temporary variable to store the age
		
	nameFile.open("names.txt"); // Here we open the name file
	ageFile.open("ages.txt");   // Here we open the name file

	cout << "We are reading name and age files!" << endl;

	// Here we check if these files exists
	if (!nameFile || !ageFile)
	{
		cout << "Problem opening one of the input files!" << endl;
		return 1;
	}

	while (!nameFile.eof() || !ageFile.eof())
	{
		getline(nameFile, name); // get line help us to read entire line 
		names.push_back(name);
		cout << name << endl;
		ageFile >> age;
		ages.push_back(age);
	}

	cout << "Writing to file" << endl;
	nameAgeFile.open("name&age.txt");          // Here we open the output file 

	for (int i = 0; i < names.size(); i++)
	{
		nameAgeFile << setw(12) << names[i] << setw(12) << ages[i] << endl; // Here we write to the output file
		cout << setw(12) << names[i] << setw(12) << ages[i] << endl;		// Here we write to the console
	}

	nameAgeFile.close();				     // Here we close the file
	cout << "Done!" << endl;

	/*
		Mini Project: Read Data from File and Print Statistics
			- Data should be 0 through 100
			- From the data, write to console:
				+ Mininmum Score
				+ Maximum Score
				+ Average Score
			- Program ignores/rejects invalid input (not in 0 to 100)
	*/

	ifstream scoreFile;		// For reading score file

	vector<int> scores;     // Here we create a vector to store scores in the score file
	int score;              // Dummy variable to keep scores we read from the file
	int counter = 0;		// Which keeps track of number of scores
	int maxScore = 0, minScore = 100; // Here we start maxScore from 0 to compare and replace
	double avgScore = 0;    

	scoreFile.open("scores.txt"); // Here we open the name file

	cout << "We are reading scores file!" << endl;

	// Here we check if these files exists
	if (!scoreFile )
	{
		cout << "Problem opening score file!" << endl;
		return 1;
	}

	while (!scoreFile.eof())
	{
		scoreFile >> score; // read each score until EOF
		if (score >= 0 && score <= 100)
		{
			scores.push_back(score);
			avgScore += score;				 // Here we sum all valid scores then divide them to the count
			minScore = min(minScore, score); // Here we update the minimum score
			maxScore = max(maxScore, score); // Here we update the maximum score
			counter++;
		}
		else
			continue;
	}

	avgScore = double(avgScore / counter); // Here we divide it to the total score count
	cout << "Minimum Score is: " << minScore << endl;
	cout << "Maximum Score is: " << maxScore << endl;
	cout << "Average Score is: " << avgScore << endl;

	/*
		Mini Project: Dynamically create rectangles from file
			- Use the same Rectangle class
			- Use the rectangles.txt file, in which each line contains length and width
			- Read data from file and dynamically create Rectangle objects and store their pointers
			- Print perimeters and areas to an output file
	*/

	ifstream rectangleFile;				// For reading rectangle file
	ofstream rectangleCalculationFile;	// For outputting rectangle calculations
	vector<Rectangle> Rectangles;      // Here we create a vector to store scores in the rectangle file
	Rectangle rectPtr;                 // Rectangle pointer to for dummy variable

	double height = 0.0, length = 0.0; // Dummy height and width variable for rectangles 
	string rectSummary;                // Here we read each line as a message then process it

	//rectPtr = new Rectangle(2.1, 3.2);

	rectangleFile.open("rectangles.txt");								  // Here we open the rectangle file
	rectangleCalculationFile.open("rectangle_calculations.txt");          // Here we open the output file 

	// Here we check if these files exists
	if (!rectangleFile)
	{
		cout << "Problem opening rectangle file!" << endl;
		return 1;
	}

	cout << "We are reading rectangles file!" << endl;
	while (!rectangleFile.eof())
	{

		rectangleFile >> length;  // Here we convert the first element into height
		rectangleFile >> height;  // Here we convert the second element into height
			
		rectPtr.setHeight(length);   // Here we store it in Rectangle Pointer
		rectPtr.setHeight(height);   // Here we store it in Rectangle Pointer
		Rectangles.push_back(rectPtr);             // Here we add it to rectangles vector

		cout << "Rectangle Area is " << Rectangles.back().area() <<
			" and Rectangle Perimeter is " << Rectangles.back().perimeter() << endl;
	
	}

	// We output the calculation data
	for (int i = 0; i < Rectangles.size(); i++)
	{
		rectangleCalculationFile << "Rectangle Area is " << Rectangles[i].area() <<
			" and Rectangle Perimeter is " << Rectangles[i].perimeter() << endl;
	}

	return 0;
}

void printFormatted(ofstream& outfile, int highNum)
{
	for (int i = 0; i <= highNum; i++)
	{
		outfile << setw(12) << setprecision(2) << (i * 5.7575)
			<< setw(12) << setprecision(3) << (i * 3.14159) << endl; // Here we write to the output file
		cout << setw(12) << setprecision(2) << (i * 5.7575)
			<< setw(12) << setprecision(3) << (i * 3.14159) << endl; // Here we write to the console
	}
}
