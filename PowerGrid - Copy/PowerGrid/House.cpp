/*
*  House.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for House Object. Used to represent base House for the game.
*/

#include "House.h"
#include<string>
#include<algorithm>

namespace upper
{

	static string& to_upper(string& str)
	{

		transform(str.begin(), str.end(), str.begin(), static_cast<int(*)(int)>(::toupper));
		return str;
	}

}

using namespace upper;



//Default Constructor
House::House() {
	colour = "";
	player = NULL;
	set == false;
}

//House Constructor
House::House(string color) {
	colour = color;
	player = NULL;
}

//House Constructor
House::House(string color, Player* newPlayer) {
	string s = newPlayer->getPlayerColour();

	if ( to_upper(color) == to_upper(s)) {
		colour = color;
		player = newPlayer;
	}
	else {
		cout << "Error in creating house. Player Doesn't match house colour" << endl;
	}
}

//Deconstructor
House::~House() {

}

//Sets the owner of the house to player pointer
void House::setOwner(Player* newPlayer) {
	player = newPlayer;
}

void House::setTrue() {
	set = true;
}

bool House::isSet() {
	return set;
}

//Get pointer to house owner
Player* House::getOwner() {
	return player;
}

void House::setColour(string color){
	colour = color;
}

string House::getColour(){
	return colour;
}


