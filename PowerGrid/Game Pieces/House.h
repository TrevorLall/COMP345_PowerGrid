/*
*  House.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for House Object. Used to represent Houses in the game
*/

#pragma once
#ifndef House_H
#define House_H
#include<string>
#include"Player.h"
#include"City.h"

using namespace std;

class Player; //Class forwarding of Player

class House {



private:
	string colour;
	Player* player; //player object that owns the house
	bool set;
	int city;

public:
	House(); //Default Constructor
	House(string color);
	House(string color, Player* player); //Constructor that sets the owner
	~House(); //Deconstructor

	void setTrue();
	bool isSet();
	void setOwner(Player* newPlayer); //Setter for owner of a house
	Player* getOwner(); //Getter for owner of a house
	void setColour(string colour); //Setter for house colour
	string getColour(); //Getter for house colour
	void setCity(int city);
	int getCityId();
	
};

#endif House_H