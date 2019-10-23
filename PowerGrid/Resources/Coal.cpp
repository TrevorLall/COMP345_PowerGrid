/*
* Coal.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for Coal Object. Used as a resource for the game
*/

#include"Coal.h"

// Default constructor
// Assigns player to NULL
Coal::Coal() {
	player = NULL;
}

// Constructor 
// Sets player to a pointer of a Player object
Coal::Coal(Player * newOwner) {
	player = newOwner;
}

//Deconstructor
Coal::~Coal() {

}

//Sets the current owner of the resource to a Player
void Coal::setOwner(Player * newOwner) {
	if (isTaken() == true) {
		cout << "Resource already taken" << endl;
	}
	else {
		player = newOwner; //sets player to newOwner
		player->coal.push_back(resName); //Assigns the resource to player
	}
}