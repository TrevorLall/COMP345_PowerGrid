#include "ResourceMarket.h"
#include "Player.h"
#include <iostream>
using namespace std;
//Cost, Coal, Oil, Garbage, Uranium
ResourceMarket::ResourceMarket()
{
	for (int i = 0; i < 12; i++){
		//cout << i << " ";
		if (i < 3) {
			market.push_back(new MarketSpace(i + 1, 3, 0, 0, 0));
		}
		else if (i >= 3 && i < 6) {
			market.push_back(new MarketSpace(i + 1, 3, 3, 0, 0));
		}
		else if (i >= 6 && i < 8) {
			market.push_back(new MarketSpace(i + 1, 3, 3, 3, 0));
		}
		else if (i == 8)
			market.push_back(new MarketSpace(i + 2, 0));
		else if (i == 9)
			market.push_back(new MarketSpace(i + 3, 0));
		else if (i == 10)
			market.push_back(new MarketSpace(i + 4, 1));
		else if (i ==11)
			market.push_back(new MarketSpace(i + 5, 1));
	}
}

ResourceMarket::~ResourceMarket()
{
}

vector<MarketSpace*> ResourceMarket::getMarket()
{
	return market;
}

void ResourceMarket::reSupply(vector<Player*> players, int player_number) {
	int count = 0;
	
	switch (player_number) {
		case 2: {
			for (int i = 0; i < market.size(); i++) {
				int j = 0;
				while (market.at(i)->getCoal().size() < 3 && count < 3 ) {
					market.at(i)->setCoal(1);	
					count++;
				}

				while (market.at(i)->getOil().size() < 3 && count < 3) {
					market.at(i)->setOil(1);
				}

				while (market.at(i)->getGarbage.size() < 3 && count < 3) {
					market.at(i)->setGarbage(1);
				}

				while (market.at(i)->getUranium.size() < 3 && count < 3) {
					market.at(i)->setUranium(1);
				}

				j++;
			}
			break;
		}
		case 3: {
			break;
		}
		case 4: {
			break;
		}
		case 5: {
			break;
		}
		case 6: {
			break;
		}
	}
}

int ResourceMarket::buy(int num, string resource){
	int count = 0;
	int price = 0;
	if (resource == "Coal") {
		for (int i = 0; i < market.size(); i++) {
			int j = 0;
			while (j < market.at(i)->getCoal().size() && count < num) {
				j++;
				count++;
				price += market.at(i)->getCost();
			}
			market.at(i)->takeCoal(j);
		}
	}
	else if (resource == "Oil") {
		for (int i = 0; i < market.size(); i++) {
			int j = 0;
			while (j < market.at(i)->getOil().size() && count < num) {
				j++;
				count++;
				price += market.at(i)->getCost();
			}
			market.at(i)->takeOil(j);
		}
	}

	else if (resource == "Garbage") {
		for (int i = 0; i < market.size(); i++) {
			int j = 0;
			while (j < market.at(i)->getGarbage().size() && count < num) {
				j++;
				count++;
				price += market.at(i)->getCost();
			}
			market.at(i)->takeGarbage(j);
		}
	}

	else if(resource == "Uranium") {
		for (int i = 0; i < market.size(); i++) {
			int j = 0;
			while (j < market.at(i)->getUranium().size() && count < num) {
				j++;
				count++;
				price += market.at(i)->getCost();
			}
			market.at(i)->takeUranium(j);
		}
	}
	else {

	}
	cout << "You bought "<< price << " Elektro worth of " << resource << endl;
	return price;
}

string ResourceMarket::display(vector<MarketSpace*> market){
	cout << "\n------------------------------------------------------------------------\n";
	cout << "RESOURCE MARKET\n";
	for (int i = 0; i < market.size(); i++) {
		
		cout << "Cost " << market.at(i)->getCost() << "|";
		
		//Display Coal Market
		if (market.at(i)->getCoal().size() == 0) {
			for (int j = 0; j < 3; j++) {
				cout << "   ";
			}
		}
		else {
			for (int j = 0; j < market.at(i)->getCoal().size(); j++) {
				cout << " C ";
			
			}
		}
		

		cout << "\t";

		//Display Oil Market
		
		if (market.at(i)->getOil().size() == 0) {
			for (int j = 0; j < 3; j++) {
				cout << "   ";
			}
		}
		else {
			for (int j = 0; j < market.at(i)->getOil().size(); j++) {
				cout << " O ";
			}
		}
		cout << "\t";

		//Display Garbage Market
		if (market.at(i)->getGarbage().size() == 0) {
			for (int j = 0; j < 3; j++) {
				cout << "   ";
			}
		}
		else {
			for (int j = 0; j < market.at(i)->getGarbage().size(); j++) {
				cout << " G ";
			}
		}
		cout << "\t";

		//Display Uranium Market
		if (market.at(i)->getUranium().size() == 0) {
			for (int j = 0; j < 3; j++) {
				cout << "   ";
			}
		}
		else {
			for (int j = 0; j < market.at(i)->getUranium().size(); j++) {
				cout << " U ";
			}
		}
		cout << "\n";
	}
	cout << "------------------------------------------------------------------------\n" << endl;
	return"";
}

bool isFull() {
	return true;
}