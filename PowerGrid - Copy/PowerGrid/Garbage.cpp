/*
*  Garbage.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for Garbage Object. Used to represent a resource in the game
*/


#include "Garbage.h"

// Default constructor
// Assigns player to NULL
Garbage::Garbage() {
	player = NULL;
}

// Constructor 
// Sets player to a pointer of a Player object
Garbage::Garbage(Player* newOwner) {
	player = newOwner;
}

//Deconstructor
Garbage::~Garbage() {

}

//Sets the current owner of the resource to a Player
void Garbage::setOwner(Player * newOwner) {
	if (isTaken() == true) {
		cout << "Resource already taken" << endl;
	}
	else {
		player = newOwner;
		player->garbage.push_back(resName);
	}
}