/*
*  Garbage.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for Garbage Object. Used to represent a resource in the game
*/

#pragma once
#ifndef Garbage_H
#define Garbage_H
#include<string>
#include"Resource.h"

//Class used to represent the coal resource
class Garbage : public Resource {
private:
	const std::string resName = "GARBAGE"; //Name of resource

public:

	Garbage(); //default constructor
	Garbage(Player * newOwner); //Constructor that assigns player to object
	~Garbage(); //Deconstructor
	void setOwner(Player * newOwner); //Getter for name
};


#endif Grabage_H