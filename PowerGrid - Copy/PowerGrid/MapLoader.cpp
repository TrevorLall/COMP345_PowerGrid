/*
*  MapLoader.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for MapLoader. Helper class that will read a text file and create a map from it
*/

#include"MapLoader.h"
#include<iostream>
#include<sstream>

//Default Constructor
MapLoader::MapLoader() {
}

// Function used to load a map file from a given text file
Map* MapLoader::loadMap(ifstream& file) {
	string line1 = ""; //stores Original City name
	string line2 = ""; //Stores Original city region color
	string line3 = ""; //Stores string of connections to original city

	vector<string> edges; //Vector to store names of edges to city
	vector<int> iter; //Vector that stores how many edges are for a given city
	iter.push_back(0); 
	
	if (file.is_open()) {
		if (file.peek() == EOF) { // check if file is empty.
			std::cout << "Invald. File is empty!" << endl; //Outputs error
			file.close();
			system("pause");
			exit(0);
		}
		//If file not empty
		else {
			while (!file.eof()) {

				//Gets line in textfile
				//Line 1 searches until ':' is found. Represents city to create
				//Line 2 searches until ',' is found. Represents city's color
				//Line 3 searches until the end of the line. Represents the edges
				while (getline(file, line1, ':')  && getline(file, line2, '\n')) {
					string s; //temp string
					
					city.push_back(new City(line1, 10)); //Create City from Line1 
					std::istringstream iss(line2); //Parse the line2
					while (getline(iss, s, ',')){
						edges.push_back(s); //Add edges to a vector
					}
					iter.push_back(edges.size()); //Store the number of edges are created per loop
					
				}
			}
		}
	}
	else {
		std::cout << "Error.Incorrect file name or file is closed!" << endl; // Output If file isn't open
		system("pause");
		exit(0);

	}

	file.close(); //Close file

	//create a new graph
	Map* graph;
	graph = Map::createGraph(city.size()); //initializes the graph

	//Loop that will cycle through the size of the city vector and add the edges to a given city
	for (int i = 0; i < iter.size() - 1; i++) {
		int length = iter.at(i + 1) - iter.at(i); //Sets length for the amount of edges in a given city

		//Loops through the number of edges per city
		for (int j = 0; j < length; j++) {

			//If the city name is an actual already created city, then add connection to original city
			if (isACity(edges.at(j + iter.at(i)))) {
				City cityId = returnCity(edges.at(j + iter.at(i))); //Gets City Object for the original city
				Map::addEdge(graph, *city.at(i), cityId); //Creates connection
			}
		}
	}

	//Loop to add original cities to the map as head node
	for (int i = 0; i < city.size(); i++)
		Map::addCity(graph, *city[i]);
	
	cout <<  "\n----------------------------------\n";
	Map::printGraph(graph); //Print the Map
	cout << endl;

	this->graph = graph;

	return graph; //Return Map
}

//Returns the map Object
Map* MapLoader::getMap() {
	return graph;
}

vector<City*> MapLoader::getCity()
{
	return city;
}

//Boolean: Returns true if the city exists, false if it does not
bool MapLoader::isACity( string s)
{
	bool isCity = false;

	for (int i = 0; i < city.size(); i++)
	{
		if (city.at(i)->getName() == s)
		{
			isCity = true;
		}
	}

	return isCity;
}

//Returns a city from a given string name
City MapLoader::returnCity(string s)
{
	//loop through city vector to find if the city name exists, and return that city
	for (int i = 0; i < city.size(); i++)
	{
		if (city.at(i)->getName() == s) 
		{
			return *city.at(i);
		}
	}
}