
#define _USE_MATH_DEFINES

#include<cmath>
#include <iostream>

using namespace std;

void swapInt(int *t_1, int *t_2) {
	/*This function performs swapping operations for integers*/
	int temp;

	temp = *t_1;
	*t_1 = *t_2;
	*t_2 = temp;

}

void swapFloat(float* t_1, float* t_2) {
	/*This function performs swapping operations for floats*/
	float temp;

	temp = *t_1;
	*t_1 = *t_2;
	*t_2 = temp;

}

void getOrder(int Numbers[], int Order[], size_t Nsize) {
	// this function sorts Numbers[] Array by Bubble Sort
	for ( int i = 0; i < Nsize; i++) {  
		Order[i] = i + 1;              // the order 
	}

	// Bubble Sort starts here
	for (int i = 0; i < (Nsize-1); i++)
	{
		for (int j = 0; j < (Nsize-i-1); j++)
		{
			//Swapping element in if statement    
			if (Numbers[j] > Numbers[j + 1])
			{
				swap(Order[j], Order[j+1]);             // Let's swap orders
				swap(Numbers[j], Numbers[j + 1]);       // Let's swap numbers
			}
		}
	}	
}


int main() {

	const int Nsize = 5;
	int number1{ 0 }, number2{ 0 }, number3{ 0 }, sum{ 0 };  /* Three integers and their sum */
	int difference{ 0 }, product{ 0 };		                 /* difference and prodcut */
	float quotient{ 0 }, average{ 0 };					     /* Average and Quotient of Three integers */
	int Numbers[Nsize], Order[Nsize];                        /* Array of integers and their order */
	int Largest{ 0 }, Smallest{ 0 };                         /* Smallest and Largest Integer */
	char SampleChar;                                         /* Sample character to test ASCII character set */
	float r{ 0 }, dia{ 0 }, area{ 0 }, circumference{ 0 };   /* Radius, diameter, area and circumference of a circle */

    // int *Order = new int(Nsize);              // Order of integers array
	cout << "Enter first integer \n";
	cin >> number1;
	cout << "Enter second integer \n";
	cin >> number2;
	cout << "Enter third integer \n";
	cin >> number3;

	sum = number1 + number2;
	difference = number1- number2;
	product = number1 * number2;
	quotient = (float) number1 / number2 ;  /* As a result of this operation floating integer will be obtained
											It should be stated in the beginning of RHS of the statement first.*/

	cout << "your sum is equal to " << sum << "\n" << endl ;
	cout << "your difference is equal to " << difference << "\n" << endl;
	cout << "your product is equal to " << product << "\n" << endl;
	cout << "your quotient is equal to " << quotient << "\n" << endl;

	cout << "Welcome\t";
	cout << "to C++ \n";

	/*2.18 a)*/
	cout << "VX " << "YZ" << "\n" << endl;
	/*2.18 b)*/
	cout << "V" << "X " << "Y" << "Z" << "\n" << endl;
	/*2.18 c)*/
	cout << "VX ";
	cout <<  "YZ\n" << endl;

	/*2.19 */

	sum = number1 + number2 + number3;
	average = (float ) sum/3;              /* As a result of this operation floating integer will be obtained
											It should be stated in the beginning of RHS of the statement first.*/
	product = number1 * number2 * number3;
	quotient = (float) number1 / number2;  /* As a result of this operation floating integer will be obtained
											It should be stated in the beginning of RHS of the statement first.*/

	//swapInt(&number1, &number2);

	// cout << "Number 1: " << number1 << endl;
	// cout << "Number 2: " << number2 << endl;

	/* Write a bubble sort function here*/

	Numbers[0] = number1;			   /*First number in Array*/
	Numbers[1] = number2;			   /*Second number in Array*/
	Numbers[2] = number3;			   /*Third number in Array*/
	Numbers[3] = number2 * number2;    /*Forth number in Array*/
	Numbers[4] = number3 * number3;    /*Fifth number in Array*/

	getOrder(Numbers, Order, Nsize); /*Let's sort our numbers*/
	// cout << "Order is: " << Order[0] << " " << Order[1] << " " << Order[2] << endl;

	cout << "Input three different integers: " << number1 << " " << number2 << " " << number3 << endl;
	cout << "Sum is: " << sum << endl;
	cout << "Average is: " << average << endl;
	cout << "Product is: " << product << endl;
	cout << "Smallest is: " << Numbers[0] << endl;
	cout << "Largest is: " << Numbers[4] << endl;

	/*2.20 (Diameter, Circumference and Area of a Circle)*/

	// cout << "Pi number is: " << M_PI << endl;
	cout << "Please Enter the raduis of the circle \n";
	cin >> r;

	dia = 2. * r;                    /* Diameter of a circle */
	circumference = 2. * M_PI * r;   /* Circumference of a circle */
	area = M_PI * r * r;             /* Area of a circle */

	cout << "Diameter is: " << dia << endl;
	cout << "Circumference is: " << circumference << endl;
	cout << "Area is: " << area << endl;

	/*2.21 (Displaying Large Letters)*/

	cout << "   CCC\t" << "  +    " << "  +  " << endl;
	cout << " C    \t" << "  +    " << "  +  " << endl;
	cout << "C     \t" << "+++++  " << "+++++" << endl;
	cout << " C    \t" << "  +    " << "  +  " << endl;
	cout << "   CCC\t" << "  +    " << "  +  " << endl;

	/*2.23 (Largest and Smallest Integers) */

	/* Let's set largest and smallest number as the first number */
	Largest = number1;
	Smallest = number1;
	/* Let's check the second number */
	if (number2 > Largest)
		Largest = number2;
	if (number2 < Smallest)
		Smallest = number2;
	/* Let's check the third number */
	if (number3 > Largest)
		Largest = number3;
	if (number3 < Smallest)
		Smallest = number3;
	/* Let's check the forth number */
	if (Numbers[3] > Largest)
		Largest = Numbers[3];
	if (Numbers[3] < Smallest)
		Smallest = Numbers[3];
	/* Let's check the fifth number */
	if (Numbers[4] > Largest)
		Largest = Numbers[4];
	if (Numbers[4] < Smallest)
		Smallest = Numbers[4];

	cout << "Largest is: " << Largest << endl;
	cout << "Smallest is: " << Smallest << endl;

	/*2.24 (Odd or Even) */

	if (number1%2 == 0)
		cout << "First number is even integer " << endl;
	else
		cout << "First number is odd integer"  << endl;

	/*2.25 (Factors) */

	if (number1 % number2 == 0 && number1 % number3 == 0)
		cout << "First number is the factor of second and third numbers" << endl;
	else
		cout << "First number is not the factor of second and third numbers" << endl;

	/*2.26 (Checkerboard) */

	cout << "* * * * * * * *" << endl;
	cout << " * * * * * * * *" << endl;
	cout << "* * * * * * * *" << endl;
	cout << " * * * * * * * *" << endl;
	cout << "* * * * * * * *" << endl;
	cout << " * * * * * * * *" << endl;
	cout << "* * * * * * * *" << endl;
	cout << " * * * * * * * *" << endl;

	/*2.27 (Integer Equivalent of a Character) */

	cout << "A sample character \n";
	cin >> SampleChar;
	cout << "ASCII Character Set is: " << static_cast<int>(SampleChar) << endl;  /* This command converts a charater 
																					into its corresponding ASCII character set */
	/*2.28 (Digits of an Integer) */

	Numbers[0] = number1 % 10;                    /*Ones digit*/
	Numbers[1] = ((int) (number1 / 10)) % 10;     /*Tens digit*/
	Numbers[2] = ((int) (number1 / 100)) % 10;    /*Hundreds digit*/
	Numbers[3] = ((int)(number1 / 1000)) % 10;    /*Thousands digit*/

	cout << " Digits of first integer " << endl;
	cout << Numbers[0] << " " << Numbers[1] << " " << Numbers[2] << " " << Numbers[3] << endl;

	/*2.29 (Table) */

	Numbers[0] = 0;          /*Length 1*/
	Numbers[1] = 1;          /*Length 2*/
	Numbers[2] = 2;          /*Length 3*/
	Numbers[3] = 3;          /*Length 4*/

	cout << "Face length\t" << "Surface area\t"  << "Volume" << endl;
	cout << "of cube (cm)\t" << "of cube (cm^2)\t" << "of cube (cm^3)" << endl;
	cout << Numbers[0] << "\t\t" << Numbers[0] * Numbers[0] << "\t\t" << Numbers[0] * Numbers[0] * Numbers[0]<< endl;
	cout << Numbers[1] << "\t\t" << Numbers[1] * Numbers[1] << "\t\t" << Numbers[1] * Numbers[1] * Numbers[1] << endl;
	cout << Numbers[2] << "\t\t" << Numbers[2] * Numbers[2] << "\t\t" << Numbers[2] * Numbers[2] * Numbers[2] << endl;
	cout << Numbers[3] << "\t\t" << Numbers[3] * Numbers[3] << "\t\t" << Numbers[3] * Numbers[3] * Numbers[3] << endl;

	/*2.30 (Body Mass Index Calculator) */

	cout << "Please Enter Your Weight in Kilograms \n";
	cin >> Numbers[0];
	cout << "Please Enter Your Height in Meters \n";
	cin >> r;

	area = (float)(Numbers[0]) / (r * r); /*Body Mass Index (BMI)*/

	if (area < 18.5)
		cout << "Underweight" << endl;
	else if(area >= 18.5 && area < 24.9)
		cout << "Normal" << endl;
	else if (area >= 24.9 && area < 29.9)
		cout << "Overweight" << endl;
	else if (area >= 29.9)
		cout << "Obese" << endl;

	/*2.31 (Car-Pool Savings Calculator) */

	return 0;


}