#pragma once
#include "Cards.h"
#include "Deck.h"
#include<iostream>
#include <vector>

using namespace std;

class PowerPlantMarket {
public:
	PowerPlantMarket();

	PowerPlantMarket(Deck* deck);

	vector<Cards> getPowerPlantMarket();

	void populate(Deck deck);

	void display();

	const int getSize();

private:
	vector<Cards> powerMarket; 
	const int maxSize = 8;
};