/*
*  SummaryCards.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for SummaryCards Object. Used to represent the rules card that each player gets
*/

#pragma once
#include<string>
using namespace std;

// Class to display summary card
class SummaryCards {

private:
	string description; // description

public:
	//Constructor
	SummaryCards();
	string getDescription(); //gets description of summary card
};
