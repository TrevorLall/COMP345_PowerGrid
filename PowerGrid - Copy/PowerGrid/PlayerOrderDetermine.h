#pragma once
#include <vector>
#include <iostream>
#include"Player.h"
#include "City.h"


using namespace std;

class PlayerOrderDetermine
{
public:
	PlayerOrderDetermine();
	~PlayerOrderDetermine();
	std::vector<Player*> DetermineOrder(vector<Player*> player);
	vector<Player*> reverseOrder(vector<Player*> player);
	vector<vector<House*>> reverseOrder(vector<vector<House*>> house);

	void display(vector<Player*> player);

private:
	bool firstroundfinished = false;

};

