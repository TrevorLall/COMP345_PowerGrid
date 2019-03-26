/*
*  Map.h
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Header file for Map Object. Used to represent maps for the board game
*/

#pragma once
#ifndef Map_H
#define Map_H
#include "AdjList.h"
#include "City.h"

//Class for a Map. A Map as an array of adjacency lists
//Size of array will be V (total vertices)
class Map {

private:
	AdjList *arr; //array that will display adjacency of cities
	int V; //number of cities on a map


public:
	static Map *createGraph(int V); //Initializes map to size V
	static void addEdge(Map *Map, City& src, City& dest); //Connects cities to eachother on a graph
	//void addEdge(Map * map, City & src, City & dest, int cost);
	static void BFS(Map * map, City s);
	static void BFS(Map * map, City src, City dest);
	void BFS(Map * map, int s);
	void BFS(Map * map);
	static void printGraph(Map *Map); //Displays the Cities along with their adjacency lists

	static bool checkAvailability(Map * map, City * city1, City * city2); //Checks if a city is available to be connected
	static bool checkDuplicate(City* city1, City* city2); //checks if a connection has been established already


	static vector<City*> getCityVector(Map* map); //Vector that stores city Objects of all the cities created for the game
	//void getAdjlist(Map* map,int id);
	static void addCity(Map *Map, City& city);  //Adds City to the head of list. Denotes the actual city on the map
	void setHouse(int id, Player* player,House * house);
	bool isCityFull(int id);
	void getAdjListSize(Map * m, int id);
	void setPlayer(City& city, Player* player); //Sets player to be on map
	void setHouse(City& city, House* player); //Sets House to be on a map

};

#endif Map_H
