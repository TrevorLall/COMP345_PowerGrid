/*
*  Oil.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for Oil Object. Oil is a resource in the game
*/


#include "Oil.h"

// Default constructor
// Assigns player to NULL
Oil::Oil() {
	player = NULL;
}


// Constructor 
// Sets player to a pointer of a Player object
Oil::Oil(Player * player) {
	player = player;
}

//Deconstructor
Oil::~Oil() {

}

//Sets the current owner of the resource to a Player
void Oil::setOwner(Player * newOwner) {
	if (isTaken() == true) {
		cout << "Resource already taken" << endl;
	}
	else {
		player = newOwner;
		player->oil.push_back(resName);
	}
}