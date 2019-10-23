/*
*  Deck.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for Deck Object. Holds vector of card objects for the game
*/

#ifndef DECK_H
#define DECK_H

#include"Cards.h"
#include<iostream>
#include<vector>
using namespace std;

//Class used to create a deck of cards
class Deck {
private:
	vector<Cards>deck; //vector to store cards
public:
	void addCard(Cards powerPlant); //Adds card to deck
	void shuffle(); //Shuffles the vector of cards
	string showDeck(); //Show deck cards order
	Cards peek(); //show card at top of deck
	Cards drawCard(); //draw the card
};



#endif DECK_H
