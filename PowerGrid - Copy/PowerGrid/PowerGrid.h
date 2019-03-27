#pragma once
#pragma once
#include "MapLoader.h"
#include "Deck.h"
#include "Player.h"
#include "Elektro.h"
#include "ResourceMarket.h"

class Player;
class Map;
class ResourceMarket;
class ConnectionList;
class Deck;

class PowerGrid {

private:
	Map * map;
	
	vector <Player*> players;
	vector <string> gameArea; // contains the areas being used for the game.




public:
	PowerGrid();
	~PowerGrid();
	void startGame();
	void displayPlayer();
	Deck* getGameDeck();
	ResourceMarket* getMarket();
	vector <Player*> getPlayers();
	vector<string> getGameArea();
	bool isCitySame(string cityName);

	void cashResupply(vector<Player*> players);

	void phase3(vector<Player*> players);

	void phase4(Map * map, vector<Player*> players);

	vector <House*> red;
	vector <House*> green;
	vector <House*> blue;
	vector <House*> black;
	vector <House*> purple;
	vector <House*> yellow;

	vector<vector<House*>> houseVector;
	vector<MarketSpace*> market;
	ResourceMarket r;
	Deck* gameDeck;
	


};