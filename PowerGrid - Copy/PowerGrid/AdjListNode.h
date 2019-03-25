/*
*  AdjListNode.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for BlueHouse Object
*/

#pragma once
#ifndef AdjListNode_H
#define AdjListNode_H
#include"City.h"

//class for an City adjacency
class AdjListNode
{
private:
	City* data; // store City pointer as data
	AdjListNode *next; // pointer to next city

public:
	static AdjListNode* newAdjListNode(City& data); //Create new node for city
	void setNext(AdjListNode *head); //sets the next City to head of the list
	AdjListNode* getNext(); // gets next city
	City* getData(); // get city data


};

#endif AdjListNode_H
