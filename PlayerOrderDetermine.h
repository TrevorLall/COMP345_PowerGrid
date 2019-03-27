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
	
	

private:
	bool firstroundfinished = false;

};

