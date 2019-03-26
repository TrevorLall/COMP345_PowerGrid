/*
*  Map.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for Map Object. Used to represent maps for the board game
*/

#include "Map.h"
#include "City.h"
#include<cstdlib>
#include"edge.h"
#include<list>
#include<iostream>

//Creates the Graph for the map
Map *Map::createGraph(int V) {
	Map *map = new Map;
	map->V = V;
	//create an array of adjacency list. size of array - V
	map->arr = new AdjList[V];
	//initialize with NULL (e.g root=NULL)
	for (int i = 0; i < V; i++) {
		map->arr[i].nullHead();
	}
	return map;
};

//Add connections between cities
void Map::addEdge(Map *map, City& src, City& dest) {
	City * c1 = &src; // Pointer to src city object
	City * c2 = &dest; // Pointer to dest city object

	//Checks if the connection has already been established. 
	//If available, create edge
	if (Map::checkAvailability(map, c1, c2) == true) {

		//Add an edge from src to dest. A new node added to the adjacency list of src
		//node added at beginning
		AdjListNode *nptr = AdjListNode::newAdjListNode(dest);
		nptr->setNext(map->arr[src.getId()].getHead());
		map->arr[src.getId()].setHead(nptr);

		//connect from dest to src (since undirected)
		nptr = AdjListNode::newAdjListNode(src);
		nptr->setNext(map->arr[dest.getId()].getHead());
		map->arr[dest.getId()].setHead(nptr);

		cout << "edge added between: " << src.getName() << "->" << dest.getName() << "\n";
	}
	else {
		cout << "";
	}
	
};

//Add connections between cities
//void Map::addEdge(Map *map, City& src, City& dest, int cost) {
//	City * c1 = &src; // Pointer to src city object
//	City * c2 = &dest; // Pointer to dest city object
//	int c = cost;
//
//	//Checks if the connection has already been established. 
//	//If available, create edge
//	if (Map::checkAvailability(map, c1, c2) == true) {
//
//		//Add an edge from src to dest. A new node added to the adjacency list of src
//		//node added at beginning
//		AdjListNode *nptr = AdjListNode::newAdjListNode(dest);
//		nptr->setNext(map->arr[src.getId()].getHead());
//		map->arr[src.getId()].setHead(nptr);
//		//connect from dest to src (since undirected)
//		nptr = AdjListNode::newAdjListNode(src);
//		nptr->setNext(map->arr[dest.getId()].getHead());
//		map->arr[dest.getId()].setHead(nptr);
//		cout << "edge added between: " << src.getName() << "->" << dest.getName() << "\n";
//	}
//	else {
//		cout << "";
//	}
//
//};

void Map::BFS(Map* map, City s) {
	int size = map->V;
	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}

	list<City> queue;
	AdjListNode *root = map->arr[s.getId()].getHead();
	// Mark the current node as visited and enqueue it 
	visited[s.getId()] = true;
	queue.push_back(s);

	// 'i' will be used to get all adjacent 
	// vertices of a vertex 

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		s = queue.front();
		cout << s.getName() << " -> ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		
		
		AdjListNode *root = map->arr[s.getId()].getHead();
		////Check if it's the end of the list
		while (root != NULL) {
			int id = root->getData()->getId();
			if (!visited[id]) {
				visited[id] = true;
				queue.push_back(*root->getData());
			}
			root = root->getNext();

		}
	}
}


void Map::BFS(Map* map, City src, City dest) {
	int size = map->V;
	bool* visited = new bool[size];
	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}

	list<City> queue;
	AdjListNode *root = map->arr[src.getId()].getHead();
	// Mark the current node as visited and enqueue it 
	visited[src.getId()] = true;
	queue.push_back(src);

	// 'i' will be used to get all adjacent 
	// vertices of a vertex 

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		src = queue.front();
		cout << src.getName() << " -> ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 


		AdjListNode *root = map->arr[src.getId()].getHead();
		////Check if it's the end of the list
		while (root != NULL) {
			int id = root->getData()->getId();
			if (id == dest.getId()) {
				cout << dest.getName() << endl;
				cout << "Search Complete\n";
				return;
			}
			if (!visited[id]) {
				visited[id] = true;
				queue.push_back(*root->getData());
			}
			root = root->getNext();

		}
	}
}

//Checks if edges have already been created between cities
bool Map::checkAvailability(Map *map, City* city1, City *city2) {


	AdjListNode *root = map->arr[city1->getId()].getHead(); //Get the head of city1
	
	//Cycle through root
	while (root != NULL) {
		bool ans = Map::checkDuplicate(root->getData(), city2); //Checks for duplicates between cities
		
		//If true, the connection is already done
		if (ans == true ) {
			cout << "Edge is already established between: " << city1->getName() << " -> " << city2->getName() <<  endl;
			return false;
		}
		//continue search
		else {
			root = root->getNext(); //cycle through linked list
		}
	}
	return true; //return the connection is available
	
}

//Checks for duplicates in the connections between cities
bool Map::checkDuplicate(City* city1, City *city2) {
	//return true if names are the same
	if (!city1->getName().compare(city2->getName())) {
		return true;
	}
	else {
		return false; //names of cities are different
	}
}


// Function used to print the Cities and it's connections
void Map::printGraph(Map *map) {

	//loop over each adjacent list
	for (int i = 0; i < map->V; i++) {
		AdjListNode *root = map->arr[i].getHead();

		std::cout << "(" << i <<")City:  " << root->getData()->getName() << std::endl;
		//loop over each node in list
		root = root->getNext();

		//Check if it's the end of the list
		while (root != NULL) {
			std::cout << root->getData()->getName() << " -> "; //Gets the name of a given City
			root = root->getNext(); //Cycle to next City on list
		}
		
		std::cout << std::endl << endl; //Used just to produce better output
	}
}

// Gets a vector of all the cities used in the Map
// returns vector of type City* 
vector<City*> Map::getCityVector(Map* map) {
	vector<City*> city; //temp city to store pointers to cities on map

	//Loop through the map
	for (int i = 0; i < map->V; i++) {
			AdjListNode *root = map->arr[i].getHead(); //Gets the City used in node
			city.push_back(root->getData()); //add to vector
	}
	return city; //return vector
}

//Adds a city to the head of list
void Map::addCity(Map * map, City & city) {
	AdjListNode *nptr = AdjListNode::newAdjListNode(city);
	nptr->setNext(map->arr[city.getId()].getHead());
	map->arr[city.getId()].setHead(nptr); 
}

//Sets player to a city on the map
void Map::setPlayer(City & city, Player * player) {
	arr[city.getId()].getHead()->getData()->setPlayer(player);
};


//Set house to a city
void Map::setHouse(int id, Player* player,  House * house) {
	if (house->getOwner() == NULL) {
		cout << "House has no player" << endl;;
	}
	else {
		arr[id].getHead()->getData()->setHouse(house);
		int buy = player->getElektro()->getPlayerMoney();
		buy -= 10;
		player->setElektro(buy);
	}
};


bool Map::isCityFull(int id) {
	if (arr[id].getHead()->getData()->getFull()==true) {
		cout << "City is Full, Try another one!" << endl;
		return true;
	}
	else {
		return false;
	}
};

void Map::getAdjListSize(Map* m, int id) {

}

//Set house to a city
void Map::setHouse(City & city, House * house) {
	if (house->getOwner() == NULL) {
		cout << "House has no player" << endl;;
	}
	else {
		arr[city.getId()].getHead()->getData()->setHouse(house);
	}
};



