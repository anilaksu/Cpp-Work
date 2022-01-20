#pragma once

#include <iostream>
#include<string>
#include<array>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

struct Card {
	string face;
	string suit;
};

class DeckOfCards {
public:

	static const int numberOfCards{ 52 };
	static const int faces{ 13 };
	static const int suits{ 4 };

	DeckOfCards(); // Constructor

	void shuffle();
	void deal() const;

	/* constructor initializes data member name with parameter accountName */
	/*explicit Invoice(std::string partNumber)
		: partNo{ partNumber } {
		// Empty body
	}*/


	/*void setNumberSold(unsigned int numberSold) {
		if (numberSold < 0) {
			std::cout << "Invalid number of parts requested \n";
		} else
		noSold = numberSold;  // Store the account name
	}

	double getVAT() const {
		return VAT;   // 
	}*/

private:
	
	array<Card, numberOfCards> deck;		// deck including all cards
};

DeckOfCards::DeckOfCards() {
	// Initialize suit array
	static string suit[suits]{"Hearts", "Diamonds", "Clubs", "Spades"};

	// Initialize face array
	static string face[faces]{ "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	// Let's set values for deck of 52 cards
	for (size_t i{ 0 }; i < deck.size(); ++i) {
		deck[i].face = face[i % faces];
		deck[i].suit = suit[i / faces];
	}

	srand(static_cast<size_t>(time(nullptr)));
}

void DeckOfCards::shuffle(){
	// shuffle cards randomly
	for (size_t i{ 0 }; i < deck.size(); ++i) {
		int j{rand() % numberOfCards};
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

void DeckOfCards::deal() const {
	// shuffle cards randomly
	for (size_t i{ 0 }; i < deck.size(); ++i) {
		cout << right << setw(5) << deck[i].face << " of " << left << setw(8) << deck[i].suit << ((i+1)%2 ? '\t' : '\n');
	}
}