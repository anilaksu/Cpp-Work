#pragma once

#include <iostream>

class Invoice {
public:

	/* constructor initializes data member name with parameter accountName */
	explicit Invoice(std::string partNumber)
		: partNo{ partNumber } {
		// Empty body
	}

	/*Describe the part*/
	void setPartDescription(std::string partDescription) {
		partDesc = partDescription;
	}



	/*Member function sets the number of sold parts*/
	void setNumberSold(unsigned int numberSold) {
		if (numberSold < 0) {
			std::cout << "Invalid number of parts requested \n";
		} else
		noSold = numberSold;  // Store the account name
	}

	/*Member function sets the number of sold parts*/
	void setPartPrice(double pricePerPart) {
		if (pricePerPart < 0) {
			std::cout << "Invalid price  \n";
		}
		else
			price = pricePerPart;  // Store the account name
	}

	/*Member function retrieves part number*/
	std::string getPartNo() const {
		return partNo;   // 
	}

	/*Member function retrieves part description*/
	std::string getPartDesc() const {
		return partDesc;   // 
	}

	/*Member function retrieves number of part sold*/
	int getNumberSold() const {
		return noSold;   // 
	}

	/*Member function retrieves part price*/
	double getPartPrice() const {
		return price;   // 
	}

	/*Member function retrieves value added tax*/
	double getVAT() const {
		return VAT;   // 
	}

	/*Member function retrieves discount*/
	double getDiscount() const {
		return discount;   // 
	}

	/* Returns Invoice amount */
	int getInvoiceAmount() const {
		return (float)noSold * price * (1 + VAT) * (1 - discount);
	}

private:
	
	std::string partNo;		// data member containing part number
	std::string partDesc;   // data member containing part description
	int noSold { 0 };		// data member with default initial value for number of parts sold
	int price{ 0 };			// data member with default initial value for price of each number
	double VAT{ 0.2 };		// data member with default initial value for value added tax
	double discount{ 0 };	// data member with default initial value for discount
};