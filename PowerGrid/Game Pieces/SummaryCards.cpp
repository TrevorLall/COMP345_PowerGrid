/*
*  SummaryCards.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for SummaryCards Object. Used to represent the rules card that each player gets
*/

#include "SummaryCards.h"
#include<iostream>

//Constuctor to set description of summary cards
SummaryCards::SummaryCards()
{
		description = 
		"-------- Summary Card ---------\n"
		"Phase 1: Determine Turn Order\n"
		"Phase 2: Buy Power Plant\n"
		"Phase 3: Buy Raw Material\n"
		"Phase 4: Building\n"
		"Phase 5: Bureacracy";
}

//Gets description of summary cards
string SummaryCards::getDescription()
{
	return description;
}

