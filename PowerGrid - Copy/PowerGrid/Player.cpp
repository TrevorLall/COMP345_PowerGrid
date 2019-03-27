/*
*  Player.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for Player Object. Used to represent players for the game.
*/


#include "Player.h"
#include "City.h"
#include "House.h"
using namespace std;

//Default Constructor
Player::Player() {
	name = "";
	player_num = 0;
	elektro = 0;
	colour = "";
}

//Constructor to create new Player
Player::Player(int p_num, string player_name, Elektro* player_money, string player_colour) {
	name = player_name;
	player_num = p_num;
	elektro = player_money;
	colour = player_colour;
}

void Player::setPlayer(string Pname){
	name = Pname;
}

//set the players money
void Player::setElektro(int money_spent) {
	elektro->setPlayerMoney(money_spent);
}

void Player::setColour(string colours){
	colour = colours;
}

void Player::setPlayerNum(int p_num){
	player_num = p_num;
}

void Player::setPlayerHouses(vector<House*> house) {
	houses = house;
}

void Player::addCard(Cards* card) {
	cards.push_back(card);
}

//show a list of the cities the player owns
string Player::showCityOwned() {
	cout << "Controlled Cities: ";
	for (int i = 0; i < (int)cityOwned.size(); i++) {
		cout << cityOwned.at(i) << ", ";
	}
	return "\n";

}

int Player::getCityOwnSize() {
	return  (int)cityOwned.size();
}



//show a list of the cities the player owns
string Player::showCards() {
	for (int i = 0; i < cards.size(); i++) {
		cout << " | [" << cards.at(i)->getCardNum() << ", " << cards.at(i)->getResType() << "(" << cards.at(i)->getResourceNum() << "), " << cards.at(i)->getPowerNum() << "] | -> ";
	}
	return "\n";

}

//Show Player information. Displays Player name, money, cities owned, and resources
string Player::showInformation() {
	//Player Name
	cout << "\n----------\n" << getPlayer() << "\n----------\n" << endl;

	//Output for cities owned
	showCityOwned();
	cout << endl;
	cout << "Cards: ";
	//Output for cities owned
	showCards();

	//output for Money
	cout << "\nElektro: " << getElektro()->getPlayerMoney() << endl ;
	
	//Outout for Resources
	cout << 
		"\nResources\n"
		"----------\n"
		"Coal:    " << coal.size() << "\n"
		"Garbage: " << garbage.size() << "\n"
		"Oil:     " << oil.size() << "\n"
		"Uranium: " << uranium.size() << endl;

	return "\n";
}

void Player::addResource(string res, int num) {
	if (res=="Coal") {
		for (int i = 0; i < num; i++) {
			coal.push_back(res);
		}
	}

	if (res == "Oil") {
		for (int i = 0; i < num; i++) {
			oil.push_back(res);
		}
	}

	if (res == "Garbage") {
		for (int i = 0; i < num; i++) {
			garbage.push_back(res);
		}
	}

	if (res == "Uranium") {
		for (int i = 0; i < num; i++) {
			uranium.push_back(res);
		}
	}
}

//Getters
string Player::getPlayer() { return name; } //gets player name
int Player::getPlayerNum() { return player_num; } //gets player number
Elektro* Player::getElektro() { return elektro; } //gets Money
vector<House*> Player:: getHouse() { return houses; }
vector<Cards*> Player::getCards() { return cards; }

string Player::getPlayerColour(){
	return colour;
}


int	Player::getCityOwned() { return (int)cityOwned.size(); }
int	Player::getMaximumNumofCard(){
	int k = 0;
	for (int i = 0; i < cards.size(); i++) {
		if (cards.at(i)->getCardNum() > k)
			k = cards.at(i)->getCardNum();
	}
	return k;
}
