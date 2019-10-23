/*
*  AdjList.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for Adjlist Object. Used to represent a list of adjacency for the game.
*/

#include"AdjList.h"
#include<cstdlib>

//returns the head of city list
AdjListNode *AdjList::getHead() {
	return head;
};

//Sets the head of the list to the city pointer
void AdjList::setHead(AdjListNode *ptr) {
	head = ptr;
};

//null the head of list to clear it
void AdjList::nullHead() {
	head = NULL;
};