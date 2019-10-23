#pragma once
#include<iostream>
#include"Map.h"
#include<vector>

class Phase4 {
public:
	Phase4();
	 string beginPhase4(Map* map);

private:
	int number;
	int id;
	string name;
	std::vector<string> colors;
	vector<Player*> players;
};