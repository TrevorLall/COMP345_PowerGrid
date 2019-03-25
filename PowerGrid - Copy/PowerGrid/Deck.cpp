/*
*  Deck.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for the Deck Object. Holds vector of card objects for the game
*/

#include"Deck.h"
#include<algorithm>
#include<iostream>
#include <cstdlib>

using namespace std;

//Add card to deck
void Deck::addCard(Cards power_card) {
	deck.push_back(power_card);
}

//Shuffle the deck of cards
void Deck::shuffle() {
	int n = 1;
	n = n + (rand() % 10) + 1;
	for (int i = 0; i < n; i++) {
		random_shuffle(deck.begin(), deck.end());
	}
}

//Shows deck of cards
string Deck::showDeck() {
	for (int i = 0; i < (int)deck.size(); i++) {
		cout << deck.at(i).getCardNum() << ", "; //displays number of the card
	}
	return "\n";
}

//Shows top card of the deck
Cards Deck::peek() {
	Cards card = deck.back();
	return card;
}

//Draws card from deck
Cards Deck::drawCard() {
	Cards card = deck.back();
	deck.pop_back();
	return card;
}
