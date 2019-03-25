/*
*  Elektro.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for Elektro Object. Used to represent money in the game
*/

#pragma once
#include <iostream>
#include <string>

class Elektro {

private:
	int player_money; //The players money count

	int bill50 = 0; //50 Elektro bills in players possesion
	int bill10 = 0;//10 Elektro bills in players possesion
	int bill5 = 0;//5 Elektro bills in players possesion
	int bill1 = 0;//1 Elektro bills in players possesion
public:
	Elektro(); //Default Constructor
	Elektro(int new_amount); //Constructor to set default player money

	void setPlayerMoney(int amount); //Setter for Player_money
	void addElektro(int amount); //Adds moeny to player balance
	void subtractElektro(int amount); //subtracts money from player balance
	int getPlayerMoney(); //Getter for player_money
	void show(); //shows the bill count for player
};






