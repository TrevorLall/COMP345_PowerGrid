#include "PowerGrid.h"
#include"City.h"
#include"MapLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include"PlayerOrderDetermine.h"

using namespace std;

PowerGrid::PowerGrid()
{
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
	gameDeck->addCard(Cards(13, "Ecological", 0, 1, "Powerplant"));
	gameDeck->addCard(Cards(14, "Garbage", 2, 2, "Powerplant"));
	gameDeck->addCard(Cards(15, "Coal", 2, 3, "Powerplant"));
	gameDeck->addCard(Cards(16, "Oil", 2, 3, "Powerplant"));
	gameDeck->addCard(Cards(17, "Uranium", 1, 2, "Powerplant"));
	gameDeck->addCard(Cards(18, "Ecological", 0, 2, "Powerplant"));
	gameDeck->addCard(Cards(19, "Garbage", 2, 3, "Powerplant"));
	gameDeck->addCard(Cards(20, "Coal", 3, 5, "Powerplant"));
	gameDeck->addCard(Cards(21, "Hybrid", 2, 4, "Powerplant"));
	gameDeck->addCard(Cards(22, "Ecological", 0, 2, "Powerplant"));
	gameDeck->addCard(Cards(23, "Uranium", 1, 3, "Powerplant"));
	gameDeck->addCard(Cards(24, "Garbage", 2, 4, "powerplant"));
	gameDeck->addCard(Cards(25, "Coal", 2, 5, "powerplant"));
	gameDeck->addCard(Cards(26, "Oil", 2, 5, "powerplant"));
	gameDeck->addCard(Cards(27, "Ecological", 0, 3, "powerplant"));
	gameDeck->addCard(Cards(28, "Uranium", 1, 4, "powerplant"));
	gameDeck->addCard(Cards(29, "Hybrid", 1, 4, "powerplant"));
	gameDeck->addCard(Cards(30, "Garbage", 3, 6, "powerplant"));
	gameDeck->addCard(Cards(31, "Hybrid", 1, 4, "powerplant"));
	gameDeck->addCard(Cards(32, "Oil", 3, 6, "powerplant"));
	gameDeck->addCard(Cards(33, "Ecological", 2, 2, "powerplant"));
	gameDeck->addCard(Cards(34, "Uranium", 1, 6, "powerplant"));
	gameDeck->addCard(Cards(35, "Oil", 1, 5, "powerplant"));
	gameDeck->addCard(Cards(36, "Coal", 3, 7, "powerplant"));
	gameDeck->addCard(Cards(37, "Ecological", 0, 4, "powerplant"));
	gameDeck->addCard(Cards(38, "Garbage", 3, 7, "powerplant"));
	gameDeck->addCard(Cards(39, "Uranium", 1, 6, "powerplant"));
	gameDeck->addCard(Cards(40, "Oil", 2, 6, "powerplant"));
	gameDeck->addCard(Cards(42, "Coal", 2, 6, "powerplant"));
	gameDeck->addCard(Cards(44, "Ecological", 0, 6, "powerplant"));
	gameDeck->addCard(Cards(46, "Hybrid", 3, 7, "powerplant"));
	gameDeck->addCard(Cards(50, "Fusion", 0, 6, "powerplant"));
}

PowerGrid::~PowerGrid()
{
}

void PowerGrid::startGame()
{

	
	market = r.getMarket();
	r.display(market);

	int number;
	vector<string> colors = { "RED","GREEN","BLUE","BLACK","PURPLE","YELLOW" };
	string answer;
	string response;
	string fileName;
	ifstream file;
	City* city1;
	City* city2;
	MapLoader loader = MapLoader();


	// Part 1: Selecting and loading map / connections --------------------------------------------------------------------------------------------------------------------
	do
	{
		cout << "select a map: ";
		cin >> answer;

		fileName = "C:/Users/t_lall/Desktop/PowerGrid/" + answer + ".txt";
		file.open(fileName);

		if (!file)
			cout << "Map doesn't exist! " << endl;

	} while (!file);

	map = loader.loadMap(file);
	cout << answer << " map has been loaded." << endl;
	//fileName = "C:/Users/t_lall/Desktop/PowerGrid/" + answer;
	//file.open(fileName);


	for (int i = 0; i < 6; i++) // assigning each city thier Area color.
	{
		if (i == 0)
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

	} while (number < 2 || number > 6 || cin.fail());

	for (int i = 0; i < number; i++)
	{
		cout << "Player " << i + 1 << " enter your name: ";
		cin >> answer;

		players.push_back(new Player(i + 1, answer, new Elektro(50), colors[i]));

	}

	


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

	PlayerOrderDetermine p;
	players = p.DetermineOrder(players);
	p.display(players);

	//Testing sample for Phase 3, will be deleted once phase 2 is finished
	Cards c = gameDeck->drawCard();
	Cards card2 = gameDeck->drawCard();
	Cards c3 = gameDeck->drawCard();
	Cards card4 = gameDeck->drawCard();
	Cards card5 = gameDeck->drawCard();
	Cards card6 = gameDeck->drawCard();
	Cards card7 = gameDeck->drawCard();


	/*****************************************************************/
	players.at(0)->addCard(&c);
	players.at(0)->addCard(&card2);
	players.at(1)->addCard(&c3);
	players.at(1)->addCard(&card4);
	players.at(1)->addCard(&card5);
	players.at(1)->addCard(&card6);
	players.at(0)->addCard(&card7);
	//End of Test sample for Phase 3, will be deleted once phase 2 is finished

	
	phase3(players);
	phase4(map, players);
	displayPlayer();

	cashResupply(players);
	displayPlayer();

}

void PowerGrid::displayPlayer() {
	for (int i = 0; i < players.size(); i++) {
		players.at(i)->showInformation();
	}
}
//Part 3: placement of players houses -------------------------------------------------------------------------------------------------------------------

//for (int i = 0; i < number; i++)
//{

//	if (i == 0)
//	{
//		do
//		{

//			cout << players[i]->getPlayer() + " choose a city on the map: ";
//			cin.ignore();
//			getline(cin, answer);

//			if (loader.isACity(answer) == false)
//				cout << "city does not exist!" << endl;
//			else
//			{
//				loader.returnCity(answer)->setHouse(houseVector[i][0]);
//				gameArea.push_back(loader.returnCity(answer)->getArea());
//			}

//		} while (loader.isACity(answer) == false);

//	}
//	else
//	{
//		bool isAdj = false; // bool thats true if city is adjacent to other players.

//		do
//		{
//			cout << players[i]->getPlayer() + " choose a city on the map that is in an adjacent area to other player(s): ";
//			getline(cin, answer);

//			if (loader.isACity(answer) == false) // if string entered is not a city, error will displayed.
//				cout << "Area does not exist!" << endl;

//			else
//			{
//				for (int j = 0; j < i; j++)  // checks if the city entered is in an adjacent Area to any other players, if it is the players house is placed.
//				{
//					city1 = loader.returnCity(loader.returnCity(answer)->getArea());
//					city2 = loader.returnCity(loader.returnCity(players[j]->cityOwned[0])->getArea());

//					if (Map::checkAvailability(map, city1, city2) == false && this->isCitySame(answer) == false)
//					{
//						loader.returnCity(answer)->setHouse(houseVector[i][0]);
//						gameArea.push_back(loader.returnCity(answer)->getArea());
//						isAdj = true;
//						break;
//					}



//				}

//				if (isAdj == false)
//					cout << "city entered is not in an adjacent area." << endl;
//			}

//		} while (loader.isACity(answer) == false || isAdj == false);

//	}





	// Part 4 Creation of Deck and Resources -----------------------------------------------------------------------------------------------------------------



	

Deck * PowerGrid::getGameDeck()
{
	return gameDeck;
}

ResourceMarket * PowerGrid::getMarket()
{
	return &r;
}

vector<Player*> PowerGrid::getPlayers()
{
	return players;
}

vector<string> PowerGrid::getGameArea()
{
	return gameArea;
}

bool PowerGrid::isCitySame(string cityName)
{
	for (int i = 0; i < players.size(); i++)
	{
		for (int j = 0; j < players[i]->cityOwned.size(); j++)
		{
			if (cityName == players[i]->cityOwned[j])
				return true;
		}
	}

	return false;
}


void PowerGrid::cashResupply(vector<Player*> players) {
	int amount = 0;
	for (int i = 0; i < players.size(); i++)
	{
		int j = players.at(i)->getCityOwned();
		cout << "Original Amount for " << players.at(i)->getPlayer() << " : " << players.at(i)->getElektro()->getPlayerMoney() << endl;
		cout << "Number of cities of player " << players.at(i)->getPlayer() << " : " << j << endl;
		switch (j) {
		case 0: {
			players.at(i)->getElektro()->addElektro(10);
			break;
		}
		case 1: {
			players.at(i)->getElektro()->addElektro(22);
			break;
		}
		case 2: {
			players.at(i)->getElektro()->addElektro(33);
			break;
		}
		case 3: {
			players.at(i)->getElektro()->addElektro(44);
			break;
		}
		case 4: {
			players.at(i)->getElektro()->addElektro(54);
			break;
		}
		case 5: {
			players.at(i)->getElektro()->addElektro(64);
			break;
		}
		case 6: {
			players.at(i)->getElektro()->addElektro(73);
			break;
		}
		case 7: {
			players.at(i)->getElektro()->addElektro(82);
			break;
		}
		case 8: {
			players.at(i)->getElektro()->addElektro(90);
			break;
		}
		case 9: {
			players.at(i)->getElektro()->addElektro(98);
			break;
		}
		case 10: {
			players.at(i)->getElektro()->addElektro(105);
			break;
		}

		case 11: {
			players.at(i)->getElektro()->addElektro(112);
			break;
		}
		case 12: {
			players.at(i)->getElektro()->addElektro(118);
			break;
		}
		case 13: {
			players.at(i)->getElektro()->addElektro(124);
			break;
		}
		case 14: {
			players.at(i)->getElektro()->addElektro(129);
			break;
		}
		case 15: {
			players.at(i)->getElektro()->addElektro(134);
			break;
		}
		case 16: {
			players.at(i)->getElektro()->addElektro(138);
			break;
		}
		case 17: {
			players.at(i)->getElektro()->addElektro(142);
			break;
		}
		case 18: {
			players.at(i)->getElektro()->addElektro(145);
			break;
		}
		case 19: {
			players.at(i)->getElektro()->addElektro(148);
			break;
		}
		case 20: {
			players.at(i)->getElektro()->addElektro(150);
			break;
		}
		}
	}
}


void PowerGrid::phase3(vector <Player*> players) {
	//*-------------------------------PHASE 3----------------------------------------*//
	//Buying Resources

	cout << "\------------------------------------------------------------------------\n" << endl;
	cout << "!~ RESOURCE PHASE ~!\n" << endl;

	//Reverse Player order
	cout << "For this phase player order is: " << endl;
	PlayerOrderDetermine p;
	players = p.reverseOrder(players);
	p.display(players);

	//Buy From Resource Market

	//for loop to initialize how much resources a player can buy
	for (int i = 0; i < players.size(); i++) {
		vector<Cards*> player_cards = players.at(i)->getCards(); //gets the players current cards


	//Init Resource Vector
		vector<Cards*> coal;
		vector<Cards*> oil;
		vector<Cards*> uranium;
		vector<Cards*> garbage;

		//Init the number of resources a player can buy
		int coalNum = 0;
		int oilNum = 0;
		int uraniumNum = 0;
		int garbageNum = 0;

		//String for yes/no input
		string yn;

		//adds cards of certain resource to correct vector
		for (int j = 0; j < player_cards.size(); j++) {
			//cards of type coal
			if (player_cards.at(j)->getResType() == "Coal") {
				coal.push_back(player_cards.at(j));
			}
			//Cards of type oil
			if (player_cards.at(j)->getResType() == "Oil") {
				oil.push_back(player_cards.at(j));
			}
			//Cards of type garbage
			if (player_cards.at(j)->getResType() == "Garbage") {
				garbage.push_back(player_cards.at(j));
			}
			//Cards of type Uranium
			if (player_cards.at(j)->getResType() == "Uranium") {
				uranium.push_back(player_cards.at(j));
			}
		}
		cout << "\------------------------------------------------------------------------\n" << endl;

		//Displaying the players current cards
		cout << "\n" << players.at(i)->getPlayer() << " You have these " << players.at(i)->showCards();

		//
		cout << "\nWhich means you may store up to this amount of resources: \n";

		//Display The amount of coal you can buy from Resource market
		if (coal.size() > 0) {
			for (int i = 0; i < coal.size(); i++) {
				coalNum += coal.at(i)->getResourceNum();
			}
			cout << "Coal: " << 2 * coalNum << "\n";
		}
		else { cout << "Coal: 0\n"; } //If no coal cards, display 0


									  //Display The amount of oil you can buy from Resource market
		if (oil.size() > 0) {
			for (int i = 0; i < oil.size(); i++) {
				oilNum += oil.at(i)->getResourceNum();
			}
			cout << "Oil: " << 2 * oilNum << "\n";
		}
		else { cout << "Oil: 0\n"; } //If no coal cards, display 0

									 //Display The amount of garbage you can buy from Resource market
		if (garbage.size() > 0) {
			for (int i = 0; i < garbage.size(); i++) {
				garbageNum += garbage.at(i)->getResourceNum();
			}
			cout << "Garbage: " << 2 * garbageNum << "\n";
		}
		else { cout << "Garbage: 0\n"; } //If no Garbage cards, display 0

										 //Display The amount of uranium you can buy from Resource market
		if (uranium.size() > 0) {
			for (int i = 0; i < uranium.size(); i++) {
				uraniumNum += uranium.at(i)->getResourceNum();
			}
			cout << "Uranium: " << 2 * uraniumNum << "\n";
		}
		else { cout << "Uranium: 0\n"; } //If no uranium, display 0
		cout << "------------------------------------------------------------------------\n" << endl;

		//Init how much resources player wants to buy
		int buyCoal = 0;
		int buyOil = 0;
		int buyGarbage = 0;
		int buyUranium = 0;

		//Init cost of purchases
		int cost = 0;
		do {
			cout << "Would you like to buy more resources? (y/n)";
			cin >> yn;

			if (yn == "y") {
				if (coalNum > 0) {
					do {
						int input = 0;
						cout << "How much coal would you like to buy? (#) ";
						cin >> input;
						int c = buyCoal + input;
						if (c <= (2 * coalNum)) {
							buyCoal += input;
							cost += r.buy(input, "Coal");
							players.at(i)->addResource("Coal", input);
							//r.display(market);
						}
						else {
							cout << "You Can't Store That Much Coal! \n";
						}
					} while (buyCoal > (2 * coalNum));
				}
				if (oilNum > 0) {
					do {
						int input = 0;
						cout << "How much oil would you like to buy? (#) ";
						cin >> input;
						int c = buyOil + input;

						if (c <= (2 * oilNum)) {
							cost += r.buy(input, "Oil");
							players.at(i)->addResource("Oil", input);

							//	r.display(market);
						}
						else {
							cout << "You Can't Store That Much Oil! \n";
						}
					} while (buyOil > (2 * oilNum));
				}
				if (garbageNum > 0) {
					do {
						int input = 0;
						cout << "How much garbage would you like to buy? (#) ";
						cin >> input;
						int c = buyGarbage + input;

						if (c <= (2 * garbageNum)) {
							cost += r.buy(input, "Garbage");
							players.at(i)->addResource("Garbage", input);
							//r.display(market);
						}
						else {
							cout << "You Can't Store That Much Garbage! \n";
						}
					} while (buyGarbage > (2 * garbageNum));
				}
				if (uraniumNum > 0) {
					do {
						int input = 0;
						cout << "How much uranium you like to buy? (#) ";
						cin >> input;
						int c = buyUranium + input;

						if (c <= (2 * uraniumNum)) {
							cost += r.buy(input, "Uranium");
							players.at(i)->addResource("Uranium", input);

							//r.display(market);
						}
						else {
							cout << "You Can't Store That Much Uranium! \n";
						}
					} while (buyUranium > (2 * uraniumNum));
				}
				r.display(market);
				players.at(i)->getElektro()->subtractElektro(cost);
				cost = 0;
			}
		} while (yn == "y");
	}
}

void PowerGrid::phase4(Map* map, vector<Player*>players) {
	//*-------------------------------PHASE 4----------------------------------------*//
	//Building Phase

	string ans;
	int id;

	cout << "------------------------------------------------------------------------\n" << endl;
	cout << "!~ BUILDING PHASE ~!\n" << endl;



	//vector<City*> vcity = Map::getCityVector(map);
	//map->displayCityVector(vcity);
	int houseId;
	//Loop to go through each player to ask if they want to build a city
	for (int i = 0; i < players.size(); i++) {
		do {
			cout << players.at(i)->getPlayer() << " Do you want to place a house? (y/n)";
			cin >> ans;
			if (ans == "y") {
				do {
					cout << players.at(i)->getPlayer() << " Where do you want to place a house? (City #)";
					cin >> id;
				} while (map->isCityFull(id) != false);

				//loop through houseVector
				for (int j = 0; j < houseVector.at(i).size(); j++) {

					//Check for empty house to use
					if (houseVector.at(i).at(j)->isSet() == false) {
						houseId = j;
						//Output to show Last house
						if (j == houseVector.at(i).size() - 1) {
							cout << "Getting to last house\n";
						}
						break;
					}
				}
				//Set house in the desired city
				if (houseId == 0) {
					map->setHouse(id, players.at(i), houseVector.at(i).at(houseId));
					cout << endl;
				}
				else {
					City temp = map->returnCityFromId(map, houseVector.at(i).at(houseId - 1)->getCityId());
					City temp2 = map->returnCityFromId(map, id);
					int costToConnect = Map::BFS(map, temp, temp2);
					if (players.at(i)->getElektro()->getPlayerMoney() < costToConnect) {
						cout << players.at(i)->getPlayer() << " Doesn't have enough Elektro to pay the " << costToConnect << " Elektro connection fee to " << temp2.getName() << "! \n\n";
					}
					else {
						map->setHouse(id, players.at(i), houseVector.at(i).at(houseId));
						players.at(i)->getElektro()->subtractElektro(costToConnect);
						cout << players.at(i)->getPlayer() << " Paid " << costToConnect << " Elektro in connection fees \n";
						cout << endl;
					}

				}
			}
		} while (ans == "y");
		cout << "Player ends their building phase";
		cout << "\n------------------------------------------------------------------------\n" << endl;
	}
	cout << "\n------------------------------------------------------------------------\n" << endl;
}
