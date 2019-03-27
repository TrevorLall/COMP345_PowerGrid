/*
*  Main.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall (40044047), Stephen Smith(40013331), Avnish Patel(40024628), Wenbo Zhong(40023157)
*  Purpose: Driver used to run the game, and utilize the components of recreating the POWERGRID Game
* 
*  Strategy: We tackled the assignment by laying the foundation of the project: Creating the Map. It evolved to creating cities, then being able to have players interact with the cities
*/

#include"AdjList.h"
#include"City.h"
#include"AdjlistNode.h"
#include"Map.h"
#include"Player.h"
#include"House.h"
#include"Deck.h"
#include"Cards.h"
#include "SummaryCards.h"
#include<cstdlib>
#include<iostream>
#include"MapLoader.h"
#include<fstream>
#include"Resource.h"
#include"Uranium.h"
#include"Coal.h"
#include "Garbage.h"
#include"Oil.h"
#include"Elektro.h"
#include"Phase4.h"
#include"ResourceMarket.h"
#include"MarketSpace.h"
#include"PlayerOrderDetermine.h"


int main() {
	
	/*-------------------------------Part 1------------------------------------*/
									//Maps

	cout << "-------------------------------Part 1------------------------------------" << endl;
	/*Creating City Objects*/
	City memphis("Memphis", 10);
	City miami("Miami", 10);
	City ny("New york", 10);
	City philly("Phillidelphia", 10);
	City boston("Boston", 10);

	

	/*create a new graph*/
	int totalVertices = City::cityCount;
	Map *map;
	map = Map::createGraph(totalVertices);

	/*connect edges to the map*/
	Map::addEdge(map, memphis, miami);
	Map::addEdge(map, memphis, ny);
	Map::addEdge(map, memphis, philly);
	Map::addEdge(map, boston, memphis);
	Map::addEdge(map, miami, philly);
	Map::addEdge(map, ny, philly);
	cout << "------------------------------------------------------------------------\n" << endl;
	cout << "!~ GAME MAP ~!\n" << endl;
	/*Add Cities as the head node on the connected map*/
	Map::addCity(map, memphis);
	Map::addCity(map, miami);
	Map::addCity(map, ny);
	Map::addCity(map, philly);
	Map::addCity(map, boston);

	/* print the adjacency list representation of graph */
	Map::printGraph(map);
	cout << "------------------------------------------------------------------------\n" << endl;

//	/*:------------------------------Part 2------------------------------------*/
//								// Map Loader
//
//
//
	////Valid Test Case
	//cout << "-------------------------------Part 2------------------------------------" << endl;
	//string filename = "C:/Users/steve/Desktop/C++ Programming/UsaMap.txt"; //!MAKE SURE IT'S CORRECT PATH!
	//ifstream file;
	//file.open(filename);
	//MapLoader m = MapLoader(); 
	//Map *map;
	//map = m.loadMap(file); //loads the map
	//cout << "\n----------------------------------\n"<< endl;
	//Map::printGraph(m.getMap()); //print map
	//cout << endl;
//
//	 ////Invalid Test Case
//	//filename = "C:/Users/steve/Desktop/C++ Programming/Empty.txt"; //!MAKE SURE IT'S CORRECT PATH!
//	//ifstream file;
//	//file.open(filename);
//	//MapLoader m = MapLoader();
//	//Map *map;
//	//map = m.loadMap(file);
//
//
//	/*:------------------------------Part 3------------------------------------*/
//							//Houses - Resources - Money
//
//	
	/*Create player Wallet*/
	Elektro* wallet1 = new Elektro();
	Elektro* wallet2 = new Elektro();
	Elektro* wallet3 = new Elektro();
	Elektro* wallet4 = new Elektro();
//
//
	/*Initialization of Resource objects */

	//12 Uranium Objects
	vector <Uranium*> uranium;
	for (int i = 0; i < 12; i++)
		uranium.push_back(new Uranium());

	//24 Garbage objects
	vector <Garbage*> garbage;
	for (int i = 0; i < 24; i++)
		garbage.push_back(new Garbage());

	//24 Oil Objects
	vector <Oil*> oil;
	for (int i = 0; i < 24; i++)
		oil.push_back(new Oil());

	//24 Coal objects
	vector <Coal*> coal;
	for (int i = 0; i < 24; i++)
		coal.push_back(new Coal());


	/* Creating Player House Objects*/
	vector <House*> black;
	for (int i = 0; i < 22; i++)
		black.push_back(new House("BLACK"));

	vector <House*> purple;
	for (int i = 0; i < 22; i++)
		purple.push_back(new House("PURPLE"));


//	///*:------------------------------Part 4------------------------------------*/
//	//							//Player Objects
//
	/*Creating Players*/
	Player* player1 = new Player(1, "Trevor", wallet1, "ReD");
	Player* player2 = new Player(2, "Stephen", wallet2, "GREEN");
	Player* player3 = new Player(3, "Avnish", wallet3, "YELLOW");
	Player* player4 = new Player(4, "Wenbo", wallet4, "BLUE");
//
//	/*Shows you can set player to map*/
//	map->setPlayer(miami, player1);
//	map->setPlayer(philly, player2);
//	map->setPlayer(boston, player3);
//	map->setPlayer(memphis, player4);
////
	/*Sets resources to players*/
	uranium[0]->setOwner(player1);
	uranium[1]->setOwner(player2);
	uranium[2]->setOwner(player3);
	garbage[0]->setOwner(player4);

//
	/*Creating the rest of the house Objects*/
	vector <House*> red;
	for (int i = 0; i < 22; i++)
		red.push_back(new House("RED", player1));

	vector <House*> green;
	for (int i = 0; i < 1; i++)
		green.push_back(new House("GREEN", player2));

	vector <House*> yellow;
	for (int i = 0; i < 22; i++)
		yellow.push_back(new House("YELLOW", player3));

	vector <House*> blue;
	for (int i = 0; i < 22; i++)
		blue.push_back(new House("BLUE", player4));

	cout << "-------------------------------Part 3 & 4---------------------------------" << endl;
	//Setting houses on the game map
	map->setHouse(miami, red[0]);
	map->setHouse(ny, green[0]);
	map->setHouse(philly, yellow[0]);
	map->setHouse(memphis, green[0]);
	map->setHouse(boston, blue[0]);

	//Displays Player Information: Cities Controlled, Money, and Resources
	cout << player1->showInformation() << endl;
	cout << player2->showInformation() << endl;
	cout << player3->showInformation() << endl;
	cout << player4->showInformation() << endl;

//	///*:------------------------------Part 5------------------------------------*/
//	//				//PowerPlants - Step 3 - Summary Cards
//
//	//cout << "-------------------------------Part 5------------------------------------" << endl;
//	///*Creating 6 Summary cards*/
//	//SummaryCards sum;
//	//SummaryCards sum2;
//	//SummaryCards sum3;
//	//SummaryCards sum4;
//	//SummaryCards sum5;
//	//SummaryCards sum6;
//
//	////Display a summary card
//	//cout << sum.getDescription() << endl;
//
//
	/* Creating 42 Power Plant Cards + Step 3 Card */
	Cards step3(0, "", 0, 0, "Step3"); //step 2

	//powerplants
	Cards ppc(3, "Oil", 2, 1, "Powerplant");
	Cards ppc2(4, "Coal", 2, 1, "Powerplant");
	Cards ppc3(5, "Hybrid", 2, 1, "Powerplant");
	Cards ppc4(6, "Garbage", 1, 1, "Powerplant");
	Cards ppc5(7, "Oil", 3, 2, "Powerplant");
	Cards ppc6(8, "Coal", 3, 2, "Powerplant");
	Cards ppc7(9, "Oil", 1, 1, "Powerplant");
	Cards ppc8(10, "Coal", 2, 2, "Powerplant");
	Cards ppc9(11, "Uranium", 1, 2, "Powerplant");
	Cards ppc10(12, "Hybrid", 2, 2, "Powerplant");
	Cards ppc11(13,"Ecological", 0, 1, "Powerplant");
	Cards ppc12(14,"Garbage", 2, 2, "Powerplant");
	Cards ppc13(15,"Coal", 2, 3, "Powerplant");
	Cards ppc14(16,"Oil", 2, 3, "Powerplant");
	Cards ppc15(17,"Uranium", 1, 2, "Powerplant");
	Cards ppc16(18,"Ecological", 0, 2, "Powerplant");
	Cards ppc17(19,"Garbage", 2, 3, "Powerplant");
	Cards ppc18(20,"Coal", 3, 5, "Powerplant");
	Cards ppc19(21,"Hybrid", 2, 4, "Powerplant");
	Cards ppc20(22,"Ecological", 0, 2, "Powerplant");
	Cards ppc21(23,"Uranium", 1, 3, "Powerplant");
	Cards ppc22(24,"Garbage", 2, 4, "Powerplant");
	Cards ppc23(25,"Coal", 2, 5, "Powerplant");
	Cards ppc24(26,"Oil", 2, 5, "Powerplant");
	Cards ppc25(27,"Ecological", 0, 3, "Powerplant");
	Cards ppc26(28,"Uranium", 1, 4, "Powerplant");
	Cards ppc27(29,"Hybrid", 1, 4, "Powerplant");
	Cards ppc28(30,"Garbage", 3, 6, "Powerplant");
	Cards ppc29(31,"Hybrid", 1, 4, "Powerplant");
	Cards ppc30(32,"Oil", 3, 6, "Powerplant");
	Cards ppc31(33,"Ecological", 2, 2, "Powerplant");
	Cards ppc32(34,"Uranium", 1, 6, "Powerplant");
	Cards ppc33(35,"Oil", 1, 5, "Powerplant");
	Cards ppc34(36,"Coal", 3, 7, "Powerplant");
	Cards ppc35(37,"Ecological", 0, 4, "Powerplant");
	Cards ppc36(38,"Garbage", 3, 7, "Powerplant");
	Cards ppc37(39,"Uranium", 1, 6, "Powerplant");
	Cards ppc38(40,"Oil", 2, 6, "Powerplant");
	Cards ppc39(42,"Coal", 2, 6, "Powerplant");
	Cards ppc40(44,"Ecological", 0, 6, "Powerplant");
	Cards ppc41(46,"Hybrid", 3, 7, "Powerplant");
	Cards ppc42(50,"Fusion", 0, 6, "Powerplant");

	/*Creating the deck to store power plant cards, and "step 3 cards"*/
	Deck* deck = new Deck();

	/*Adding cards to deck*/
	deck->addCard(step3);
	deck->addCard(ppc);
	deck->addCard(ppc2);
	deck->addCard(ppc3);
	deck->addCard(ppc4);
	deck->addCard(ppc5);
	deck->addCard(ppc6);
	deck->addCard(ppc7);
	deck->addCard(ppc8);
	deck->addCard(ppc9);
	deck->addCard(ppc10);
		/*deck.addCard(ppc11);
		deck.addCard(ppc12);
		deck.addCard(ppc13);
		deck.addCard(ppc14);
		deck.addCard(ppc15);
		deck.addCard(ppc16);
		deck.addCard(ppc17);
		deck.addCard(ppc18);
		deck.addCard(ppc19);
		deck.addCard(ppc20);
		deck.addCard(ppc21);
		deck.addCard(ppc22);
		deck.addCard(ppc23);
		deck.addCard(ppc24);
		deck.addCard(ppc25);
		deck.addCard(ppc26);
		deck.addCard(ppc27);
		deck.addCard(ppc28);
		deck.addCard(ppc29);
		deck.addCard(ppc30);
		deck.addCard(ppc31);
		deck.addCard(ppc32);
		deck.addCard(ppc33);
		deck.addCard(ppc34);
		deck.addCard(ppc35);
		deck.addCard(ppc36);
		deck.addCard(ppc37);
		deck.addCard(ppc38);
		deck.addCard(ppc39);
		deck.addCard(ppc40);
		deck.addCard(ppc41);
		deck.addCard(ppc42);*/


	/*showing Deck Functions*/
	cout << "\nDeck:          ";
	cout << deck->showDeck();
	//invoking shuffle method
	deck->shuffle();
	//showing shufffled deck
	cout << "Shuffled Deck: ";
	cout << deck->showDeck();
	cout << deck->peek().getCardNum() << endl;
	Cards card = deck->drawCard();
	//showing shufffled deck
	cout << "Card Drawn:    " << card.getCardNum() << endl;
	cout << deck->showDeck();


	/*End*/
	for (int i = 0; i < 3; i++) {
cout << "------------------------------------------------------------------------\n" << endl;
cout << "!~ RESOURCE MARKET ~!\n" << endl;
		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 24; j++) {
				if (i == 0)
					cout << " C ";

				else if (i == 1 && j > 8)
					cout << " O ";

				else if (i == 2 && j > 17)
					cout << " G ";
				else
					cout << "   ";

				if ((j + 1) % 3 == 0)
					cout << "  ";
				
			}
			cout << endl;
			
		}
		cout << endl;
	}
	
	/*ResourceMarket r;
	vector<MarketSpace*> market = r.getMarket();
	r.display(market);

	market.at(0)->takeCoal(2);
	cout << endl;
	r.display(market);*/
	cout << "Here"<<endl;
	

	/*Phase4 p4;
	p4.beginPhase4(map);*/

	//player order determine 
	PlayerOrderDetermine od;
	
	vector<Player*> playerr;
	playerr.push_back(player1);
	playerr.push_back(player2);
	playerr.push_back(player3);
	playerr.push_back(player4);

	player1->addCard(&ppc9);
	player2->addCard(&ppc3);
	player3->addCard(&ppc8);
	player4->addCard(&ppc5);
	for (int i = 0; i < playerr.size(); i++) {
		cout << playerr.at(i)->getPlayer() << endl;
	}
	cout << endl;
	//first round random shuffle
	playerr=od.DetermineOrder(playerr);
	for (int i = 0; i < playerr.size(); i++) {
		cout << playerr.at(i)->getCityOwned();
		cout << playerr.at(i)->getMaximumNumofCard()<< endl;
	}
	//second round sort
	playerr=od.DetermineOrder(playerr);

for (int i = 0; i < playerr.size(); i++) {
	cout << playerr.at(i)->getCityOwned();
	cout << playerr.at(i)->getMaximumNumofCard() << endl;
	}

	system("pause");
	return 0;
}





