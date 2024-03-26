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