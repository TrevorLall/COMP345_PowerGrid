/*
*  Uranium.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for Uranium Object. Used to represent Uranium resource for the game.
*/

#pragma once
#ifndef Uranium_H
#define Uranium_H
#include<string>
#include"Resource.h"

//Class used to represent the coal resource
class Uranium : public Resource {

private:

	const std::string resName = "URANIUM"; //Name of resource

public:

	Uranium(); //default constructor
	Uranium(Player * player); //Constructor that assigns player to object
	void setOwner(Player * newOwner); //setter for owner
	~Uranium(); //Deconstructor


};
#endif Uranium_H
