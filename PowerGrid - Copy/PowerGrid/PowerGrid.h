#pragma once
#include "MapLoader.h"
#include "Deck.h"
#include "Player.h"
#include "Elektro.h"
#include "ResourceMarket.h"
#include "ConnectionList.h"

class Player;
class Map;
class ResourceMarket;
class ConnectionList;
class Deck;

class PowerGrid {

private:
	Map* map;
	ConnectionList* pipeline;
	ResourceMarket* market;
	Deck* gameDeck;
	vector <Player*> players;
	vector <string> gameArea; // contains the areas being used for the game.
	
	


public:
	PowerGrid();
	~PowerGrid();
	void startGame();
	Deck* getGameDeck();
	ResourceMarket* getMarket();
	vector <Player*> getPlayers();
	vector <string> gameArea();
	bool isCitySame(string cityName);


};
