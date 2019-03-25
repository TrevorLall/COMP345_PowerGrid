/*
*  Uranium.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Souce file for Uranium Object. Used to represent Uranium resource for the game.
*/

#include"Uranium.h"

// Default constructor
// Assigns player to NULL
Uranium::Uranium() {
	player = NULL;
}

// Constructor 
// Sets player to a pointer of a Player object
Uranium::Uranium(Player * player) {
	player = player;
}

//Sets the current owner of the resource to a Player
void Uranium::setOwner(Player * newOwner){
	if (isTaken() == true) {
		cout << "Resource already taken" << endl;
	}
	else {
		player = newOwner;
		player->uranium.push_back(resName);
	}
}

//Deconstructor
Uranium::~Uranium() {

}