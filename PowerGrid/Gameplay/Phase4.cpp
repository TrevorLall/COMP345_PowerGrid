#include "Phase4.h"
#include"ResourceMarket.h"
#include<iostream>
#include<vector>
#include"PlayerOrderDetermine.h"
using namespace std;

Phase4::Phase4()
{
}

string Phase4::beginPhase4(Map * map)
{

	ResourceMarket r;
	vector<MarketSpace*> market = r.getMarket();
	r.display(market);



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
	Cards ppc10(12, "Coal", 2, 2, "Powerplant");
	Cards ppc11(13, "Ecological", 0, 1, "Powerplant");
	Cards ppc12(14, "Garbage", 2, 2, "Powerplant");
	Cards ppc13(15, "Coal", 2, 3, "Powerplant");
	Cards ppc14(16, "Oil", 2, 3, "Powerplant");
	Cards ppc15(17, "Uranium", 1, 2, "Powerplant");
	Cards ppc16(18, "Ecological", 0, 2, "Powerplant");
	Cards ppc17(19, "Garbage", 2, 3, "Powerplant");
	Cards ppc18(20, "Coal", 3, 5, "Powerplant");
	Cards ppc19(21, "Hybrid", 2, 4, "Powerplant");
	Cards ppc20(22, "Ecological", 0, 2, "Powerplant");
	Cards ppc21(23, "Uranium", 1, 3, "Powerplant");
	Cards ppc22(24, "Garbage", 2, 4, "Powerplant");
	Cards ppc23(25, "Coal", 2, 5, "Powerplant");
	Cards ppc24(26, "Oil", 2, 5, "Powerplant");
	Cards ppc25(27, "Ecological", 0, 3, "Powerplant");
	Cards ppc26(28, "Uranium", 1, 4, "Powerplant");
	Cards ppc27(29, "Hybrid", 1, 4, "Powerplant");
	Cards ppc28(30, "Garbage", 3, 6, "Powerplant");
	Cards ppc29(31, "Hybrid", 1, 4, "Powerplant");
	Cards ppc30(32, "Oil", 3, 6, "Powerplant");
	Cards ppc31(33, "Ecological", 2, 2, "Powerplant");
	Cards ppc32(34, "Uranium", 1, 6, "Powerplant");
	Cards ppc33(35, "Oil", 1, 5, "Powerplant");
	Cards ppc34(36, "Coal", 3, 7, "Powerplant");
	Cards ppc35(37, "Ecological", 0, 4, "Powerplant");
	Cards ppc36(38, "Garbage", 3, 7, "Powerplant");
	Cards ppc37(39, "Uranium", 1, 6, "Powerplant");
	Cards ppc38(40, "Oil", 2, 6, "Powerplant");
	Cards ppc39(42, "Coal", 2, 6, "Powerplant");
	Cards ppc40(44, "Ecological", 0, 6, "Powerplant");
	Cards ppc41(46, "Hybrid", 3, 7, "Powerplant");
	Cards ppc42(50, "Fusion", 0, 6, "Powerplant");

	/*Creating the deck to store power plant cards, and "step 3 cards"*/
	Deck deck ;

	/*Adding cards to deck*/
	deck.addCard(step3);
	deck.addCard(ppc);
	deck.addCard(ppc2);
	deck.addCard(ppc3);
	deck.addCard(ppc4);
	deck.addCard(ppc5);
	deck.addCard(ppc6);
	deck.addCard(ppc7);
	deck.addCard(ppc8);
	deck.addCard(ppc9);
	deck.addCard(ppc10);
	/*	deck.addCard(ppc11);
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


	colors = { "RED","GREEN","BLUE","BLACK","PURPLE","YELLOW" };

	do {
		cout << "Enter the number of players (2-6): ";
		cin >> number;

		if ((number < 2 || number > 6))
			cout << "Only numbers 2-6 are acceptable!" << endl;

	} while ((number < 2 || number > 6) );

	for (int i = 0; i < number; i++) {
		cout << "Enter your name player " << i + 1 << ": ";
		cin >> name;

		players.push_back(new Player(i, name, new Elektro(50), colors[i]));
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

	cout << "\------------------------------------------------------------------------\n" << endl;
	cout << "!~ PHASE 2 ~!\n" << endl;

	PlayerOrderDetermine p;
	players = p.DetermineOrder(players);
	p.display(players);

	//Testing sample for Phase 3, will be deleted once phase 2 is finished
	Cards c = deck.drawCard();
	Cards card2 = deck.drawCard();
	Cards c3 = deck.drawCard();
	Cards card4 = deck.drawCard();
	Cards card5 = deck.drawCard();
	Cards card6 = deck.drawCard();
	Cards card7 = deck.drawCard();


	/*****************************************************************/
	players.at(0)->addCard(&c);
	players.at(0)->addCard(&card2);
	players.at(1)->addCard(&c3);
	players.at(1)->addCard(&card4);
	players.at(1)->addCard(&card5);
	players.at(1)->addCard(&card6);
	players.at(0)->addCard(&card7);
	//End of Test sample for Phase 3, will be deleted once phase 2 is finished



	//*-------------------------------PHASE 3----------------------------------------*//
							    //Buying Resources

	cout << "\------------------------------------------------------------------------\n" << endl;
	cout << "!~ RESOURCE PHASE ~!\n" << endl;

	//Reverse Player order
	cout << "For this phase player order is: " << endl;
	players = p.reverseOrder(players);
	p.display(players);

	//Buy From Resource Market

	//for loop to initialize how much resources a player can buy
	for (int i = 0; i < players.size(); i++) {
		vector<Cards*> cards = players.at(i)->getCards(); //gets the players current cards
		
														  												  
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
		for (int j = 0; j < cards.size(); j++) {
			//cards of type coal
			if (cards.at(j)->getResType() == "Coal") {
				coal.push_back(cards.at(j));
			}
			//Cards of type oil
			if (cards.at(j)->getResType() == "Oil") {
				oil.push_back(cards.at(j));
			}
			//Cards of type garbage
			if (cards.at(j)->getResType() == "Garbage") {
				garbage.push_back(cards.at(j));
			}
			//Cards of type Uranium
			if (cards.at(j)->getResType() == "Uranium") {
				uranium.push_back(cards.at(j));
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
						if(c <= (2 * coalNum)){
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

	//*-------------------------------PHASE 4----------------------------------------*//
								//Building Phase

	string ans;
	cout << "------------------------------------------------------------------------\n" << endl;
	cout << "!~ BUILDING PHASE ~!\n" << endl;

	//vector<City*> vcity = Map::getCityVector(map);
	//map->displayCityVector(vcity);
	int houseId;
	//Loop to go through each player to ask if they want to build a city
	for (int i = 0; i < players.size(); i++) {
		do{
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
					if (houseVector.at(i).at(j)->isSet()==false) {
						houseId = j;
						//Output to show Last house
						if (j == houseVector.at(i).size()-1) {
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
					City temp = map->returnCityFromId(map, houseVector.at(i).at(houseId-1)->getCityId());
					City temp2 = map->returnCityFromId(map, id);
					int costToConnect = Map::BFS(map, temp, temp2);
					if (players.at(i)->getElektro()->getPlayerMoney() < costToConnect) {
						cout << players.at(i)->getPlayer() << " Doesn't have enough Elektro to pay the "<< costToConnect  <<" Elektro connection fee to " << temp2.getName() <<"! \n\n";
					}
					else {
						map->setHouse(id, players.at(i), houseVector.at(i).at(houseId));
						players.at(i)->getElektro()->subtractElektro(costToConnect);
						cout << players.at(i)->getPlayer() << " Paid " << costToConnect << " Elektro in connection fees \n";
						cout << endl;
					}
					
				}
			}
		}while (ans == "y");
		cout << "Player ends their building phase";
		cout << "\n------------------------------------------------------------------------\n" << endl;
	}
	cout << "\n------------------------------------------------------------------------\n" << endl;
	for (int i = 0; i < players.size(); i++) {
		players.at(i)->showInformation();
	}
	

	//*PHASE 5*//


	//phase5

	//giving money to players 
	cout << "PHASE 5" << endl;
	


	

	
	//Cards card = deck->drawCard();
	//powerMarket.push_back(card);

	// showing players possesion of all the things
	for (int i = 0; i < players.size(); i++)
	{
		players.at(i)->showInformation();;
		cout << endl;
	}
	


	return "";
}




