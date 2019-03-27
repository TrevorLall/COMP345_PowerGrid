#include "PowerGrid.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

PowerGrid::PowerGrid()
{
}

PowerGrid::~PowerGrid()
{
}

void PowerGrid::startGame()
{
	

	int number;
	vector<string> colors = { "RED","GREEN","BLUE","BLACK","PURPLE","YELLOW"};
	string answer;
	string response;
	string fileName;
	ifstream file;
	MapLoader loader = MapLoader();
	

	// Part 1: Selecting and loading map / connections --------------------------------------------------------------------------------------------------------------------
	do
	{
		cout << "select a map: ";
		cin >> answer;

		fileName = "C:/Users/steve/Desktop/Maps/" + answer + ".txt";
		file.open(fileName);

		if (!file)
			cout << "Map doesn't exist! " << endl;

	} 
	while (!file);
	
	map = loader.loadMap(file);
	cout << answer <<" map has been loaded." << endl;
	fileName = "C:/Users/steve/Desktop/Maps/" + answer + "connections.txt";
	file.open(fileName);
	pipeline = new ConnectionList();
	pipeline->loadConnections(loader, file); // load connections for map.
	

	for(int i = 0; i < 6; i++) // assigning each city thier Area color.
	{
	  if(i == 0)
	  {
		  for (int a = 0; a < 7; a++)
			 loader.getCity()[a]->setArea(loader.getCity()[i + 42]->getName());
	  }

	  else if (i == 1)
	  {
		  for (int a = 7; a < 14; a++)
			  loader.getCity()[a]->setArea(loader.getCity()[i + 42]->getName());
	  }

	  else if (i == 2)
	  {
		  for (int a = 14; a < 21; a++)
			  loader.getCity()[a]->setArea(loader.getCity()[i + 42]->getName());
	  }

	  else if (i == 3)
	  {
		  for (int a = 21; a < 28; a++)
			  loader.getCity()[a]->setArea(loader.getCity()[i + 42]->getName());
	  }

	  else if (i == 4)
	  {
		  for (int a = 28; a < 35; a++)
			  loader.getCity()[a]->setArea(loader.getCity()[i + 42]->getName());
	  }

	  else 
	  {
		  for (int a = 35; a < 42; a++)
			  loader.getCity()[a]->setArea(loader.getCity()[i + 42]->getName());
	  }

	}

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	// Part 2: the creation of players ----------------------------------------------------------------------------------------------------------------------
	do 
	{
		cout << "Enter the number of players (2-6): ";
		cin >> number;

		if (number < 2 || number > 6 || cin.fail())
		{
			cout << "Only numbers 2-6 are acceptable!" << endl;
			cin.clear();
			cin.ignore(200, '\n');
		}
				
	} 
	while (number < 2 || number > 6 || cin.fail()); 
	
	for (int i = 0; i < number; i++) 
	{
		cout << "Player " << i+1 << " enter your name: ";
		cin >> answer;
		
		players.push_back(new Player(i+1, answer, new Elektro(50), colors[i]));

	}

	vector <House*> red;
	vector <House*> green;
	vector <House*> blue;
	vector <House*> black;
	vector <House*> purple;
	vector <House*> yellow;
	vector<vector<House*>> houseVector;


	if (players.size() >= 1) {
		for (int i = 0; i < 22; i++)
			red.push_back(new House("RED", players.at(0)));

		houseVector.push_back(red);
	}
	if (players.size() >= 2) {
		for (int i = 0; i < 22; i++)
			green.push_back(new House("GREEN", players.at(1)));

		houseVector.push_back(green);
	}

	if (players.size() >= 3) {
		for (int i = 0; i < 22; i++)
			blue.push_back(new House("BLUE", players.at(2)));

		houseVector.push_back(blue);
	}
	if (players.size() >= 4) {
		for (int i = 0; i < 22; i++)
			black.push_back(new House("BLACK", players.at(3)));

		houseVector.push_back(black);
	}
	if (players.size() >= 5) {
		for (int i = 0; i < 22; i++)
			purple.push_back(new House("PURPLE", players.at(4)));

		houseVector.push_back(purple);
	}
	if (players.size() >= 6) {
		for (int i = 0; i < 22; i++)
			yellow.push_back(new House("YELLOW", players.at(5)));

		houseVector.push_back(yellow);
	}


	//Part 3: placement of players houses -------------------------------------------------------------------------------------------------------------------
	
	for (int i = 0; i < number; i++) 
	{

		if(i == 0)
		{
			do
			{
				
				cout << players[i]->getPlayer() + " choose a city on the map: ";
				cin.ignore();
				getline(cin , answer);

				if (loader.isACity(answer) == false)
					cout << "city does not exist!" << endl;
				else 
				{
					loader.returnCity(answer).setHouse(houseVector[i][0]);
					gameArea.push_back(loader.returnCity(answer).getArea());
				}
					
			} 
			while (loader.isACity(answer) == false);
			
		}
		else 
		{
			bool isAdj = false; // bool thats true if city is adjacent to other players.
			
				do
				{
					cout << players[i]->getPlayer() + " choose a city on the map that is in an adjacent area to other player(s): ";
					getline(cin, answer);

					if (loader.isACity(answer) == false) // if string entered is not a city, error will displayed.
						cout << "Area does not exist!" << endl;

					else 
					{
						for (int j = 0; j < i; j++)  // checks if the city entered is in an adjacent Area to any other players, if it is the players house is placed.
						{
							
								if (Map::checkAvailability(map, &loader.returnCity(loader.returnCity(answer).getArea()), &loader.returnCity(loader.returnCity(players[j]->cityOwned[0]).getArea())) == false)
								{
									loader.returnCity(answer).setHouse(houseVector[i][0]);
									gameArea.push_back(loader.returnCity(answer).getArea());
									isAdj = true;
									break;
								}
			
						}

						if (isAdj == false)
							cout << "city entered is not in an adjacent area." << endl;
					} 
					
				} while (loader.isACity(answer) == false || isAdj == false);
			
		}



	}
	
	// Part 4 Creation of Deck and Resources -----------------------------------------------------------------------------------------------------------------


	//market = new ResourceMarket(); // creation of market.

	//	//powerplants
	gameDeck = new Deck();
	gameDeck->addCard(Cards(3, "Oil", 2, 1, "Powerplant"));
	gameDeck->addCard(Cards(4, "Coal", 2, 1, "Powerplant"));
	gameDeck->addCard(Cards(5, "Hybrid", 2, 1, "Powerplant"));
	gameDeck->addCard(Cards(6, "Garbage", 1, 1, "Powerplant"));
	gameDeck->addCard(Cards(7, "Oil", 3, 2, "Powerplant"));
	gameDeck->addCard(Cards(8, "Coal", 3, 2, "Powerplant"));
	gameDeck->addCard(Cards(9, "Oil", 1, 1, "Powerplant"));
	gameDeck->addCard(Cards(10, "Coal", 2, 2, "Powerplant"));
	gameDeck->addCard(Cards(11, "Uranium", 1, 2, "Powerplant"));
	gameDeck->addCard(Cards(12, "Hybrid", 2, 2, "Powerplant"));
	gameDeck->addCard(Cards(13,"Ecological", 0, 1, "Powerplant"));
	gameDeck->addCard(Cards(14,"Garbage", 2, 2, "Powerplant"));
	gameDeck->addCard(Cards(15,"Coal", 2, 3, "Powerplant"));
	gameDeck->addCard(Cards(16,"Oil", 2, 3, "Powerplant"));
	gameDeck->addCard(Cards(17,"Uranium", 1, 2, "Powerplant"));
	gameDeck->addCard(Cards(18,"Ecological", 0, 2, "Powerplant"));
	gameDeck->addCard(Cards(19,"Garbage", 2, 3, "Powerplant"));
	gameDeck->addCard(Cards(20,"Coal", 3, 5, "Powerplant"));
	gameDeck->addCard(Cards(21,"Hybrid", 2, 4, "Powerplant"));
	gameDeck->addCard(Cards(22,"Ecological", 0, 2, "Powerplant"));
	gameDeck->addCard(Cards(23,"Uranium", 1, 3, "Powerplant"));
	gameDeck->addCard(Cards(24,"Garbage", 2, 4, "powerplant"));
	gameDeck->addCard(Cards(25,"Coal", 2, 5, "powerplant"));
	gameDeck->addCard(Cards(26,"Oil", 2, 5, "powerplant"));
	gameDeck->addCard(Cards(27,"Ecological", 0, 3, "powerplant"));
	gameDeck->addCard(Cards(28,"Uranium", 1, 4, "powerplant"));
	gameDeck->addCard(Cards(29,"Hybrid", 1, 4, "powerplant"));
	gameDeck->addCard(Cards(30,"Garbage", 3, 6, "powerplant"));
	gameDeck->addCard(Cards(31,"Hybrid", 1, 4, "powerplant"));
	gameDeck->addCard(Cards(32,"Oil", 3, 6, "powerplant"));
	gameDeck->addCard(Cards(33,"Ecological", 2, 2, "powerplant"));
	gameDeck->addCard(Cards(34,"Uranium", 1, 6, "powerplant"));
	gameDeck->addCard(Cards(35,"Oil", 1, 5, "powerplant"));
	gameDeck->addCard(Cards(36,"Coal", 3, 7, "powerplant"));
	gameDeck->addCard(Cards(37,"Ecological", 0, 4, "powerplant"));
	gameDeck->addCard(Cards(38,"Garbage", 3, 7, "powerplant"));
	gameDeck->addCard(Cards(39,"Uranium", 1, 6, "powerplant"));
	gameDeck->addCard(Cards(40,"Oil", 2, 6, "powerplant"));
	gameDeck->addCard(Cards(42,"Coal", 2, 6, "powerplant"));
	gameDeck->addCard(Cards(44,"Ecological", 0, 6, "powerplant"));
	gameDeck->addCard(Cards(46,"Hybrid", 3, 7, "powerplant"));
	gameDeck->addCard(Cards(50,"Fusion", 0, 6, "powerplant"));

}
