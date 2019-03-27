/*
*  Map.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for MapLoader. Helper class that will read a text file and create a map from it
*/


#pragma once
#include"Map.h"
#include"City.h"
#include <iostream>
#include <fstream>
#include<string>
#include <vector>

using namespace std;

class MapLoader {

private:
	Map * graph; //Map created from map loader
	vector<City*> city; //Vector that stores cities


public:
	MapLoader(); //Default constructor
	Map* loadMap(ifstream& file); //Loads map into a Map object
	Map* getMap(); //returns the map to driver
	vector<City*> getCity();
	
	bool isACity(string name); //Checks if city has been created
	City returnCity(string name); //Returns the City object of a given name
};
