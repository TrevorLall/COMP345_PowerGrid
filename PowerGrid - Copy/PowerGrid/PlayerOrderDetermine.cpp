#include "PlayerOrderDetermine.h"
#include <vector>
#include <iostream>
#include"Player.h"
#include "City.h"
#include <algorithm> 
#include <random>

using namespace std;

bool comparePlayer(Player* p1, Player* p2)
{
	return p1->getCityOwned() > p2->getCityOwned();
}

PlayerOrderDetermine::PlayerOrderDetermine()
{
	firstroundfinished = false;
}


PlayerOrderDetermine::~PlayerOrderDetermine()
{
}
//to use this method, create a object of this class and call this function with a vector<Player*> type vector
vector<Player*> PlayerOrderDetermine::DetermineOrder(vector<Player*> player)
{
	//for first round just random shuffle
	auto rng = std::default_random_engine{};
	if (!firstroundfinished) {
		shuffle(player.begin(), player.end(), rng);
		firstroundfinished = true;
	}
	//after first round, sort by citynum than cardnum
	else
	{
		//sort by citynum
		sort(player.begin(), player.end(), comparePlayer);

		bool testpass = false;
		int k = 0;
		while (true) {
			//swap when cardnum is less than the next player
			for (int i = 0; i < player.size() - 1; i++) {
				if (player.at(i)->getCityOwned() == player.at(i + 1)->getCityOwned()) {
					if (player.at(i)->getMaximumNumofCard() < player.at(i + 1)->getMaximumNumofCard()) {
						swap(player.at(i), player.at(i + 1));
					}
				}
			}
			//check if is been sorted
			for (int i = 0; i < player.size() - 1; i++) {
				if (player.at(i)->getCityOwned() == player.at(i + 1)->getCityOwned()) {
					if (player.at(i)->getMaximumNumofCard() < player.at(i + 1)->getMaximumNumofCard()) {
						testpass = false;
					}
					else
					{
						testpass = true;
					}
					if (!testpass)
						break;

				}

			}
			if (testpass) {
				break;
			}
		}
	}
	
	return player;
}

vector<Player*> PlayerOrderDetermine::reverseOrder(vector<Player*> player){
	std::reverse(player.begin(), player.end());
	return player;
}

vector<vector<House*>> PlayerOrderDetermine::reverseOrder(vector<vector<House*>>house) {
	std::reverse(house.begin(), house.end());
	return house;
}

void PlayerOrderDetermine::display(vector<Player*> player)
{
	//output order of player
	cout << "\n------------------------------------------------------------------------\n";
	cout << "PLAYER ORDER: ";
	for (int i = 0; i < player.size(); i++) {
		cout << player.at(i)->getPlayer() << " -> ";
	}
	cout << endl;
}


