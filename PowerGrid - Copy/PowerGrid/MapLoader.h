/*
*  Map.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for MapLoader. Helper class that will read a text file and create a map from it
*/


#pragma once
#ifndef MapLoader_H
#define MapLoader_H
#include"Map.h"
#include"City.h"
#include <iostream>
#include <fstream>
#include<string>
#include <vector>

class MapLoader {

private:
	Map * graph; //Map created from map loader
	std::vector<City*> city; //Vector that stores cities
	string area;

public:
	MapLoader(); //Default constructor
	Map* loadMap(std::ifstream& file); //Loads map into a Map object
	Map* getMap(); //returns the map to driver
	
	bool isACity(string name); //Checks if city has been created
	City* returnCity(string name); //Returns the City object of a given name

	vector<City*> getCity();
	
};
#endif MapLoader_H