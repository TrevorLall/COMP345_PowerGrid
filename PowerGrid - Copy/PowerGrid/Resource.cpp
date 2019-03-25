/*
*  Resource.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for Resource Object. Used to represent the base resources for the game.
*/

#include "Resource.h"
#include<cstdlib>

//Default constructor
Resource::Resource() {
	player = NULL; //sets resource owner to NULL
}

//Constructor
Resource::Resource( Player* newOwner) {
	player = newOwner;
}

//Deconstructor
Resource::~Resource() {

}

//Sets the owner of a given resouce
void Resource::setOwner(Player* newOwner) {
	player = newOwner;
}

//Checks if house is already taken
bool Resource::isTaken() {
	if (player == NULL) {
		return false;
	}
	else {
		return true;
	}
}

//Gets pointer to player that owns resource object
Player* Resource::getOwner() {
	return player;
}