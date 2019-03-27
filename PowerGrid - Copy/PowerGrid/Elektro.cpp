/*
*  Elektro.cpp
*
*  Created  on: Feb 25, 2019
*  Authors: Trevor Lall, Stephen Smith, Avnish Patel, Wenbo Zhong
*  Purpose: Source file for Elektro Object. Used to represent money in the game
*/

#include"Elektro.h"
#include<iostream>
using namespace std;

//default constructor
Elektro::Elektro(){
	player_money = 50; //default player money to 50
}

//Constructor
Elektro::Elektro(int new_amount){
	player_money = new_amount;
}

//Sets the players money
void Elektro::setPlayerMoney(int amount) {
	player_money = amount;
}

//Add money to player amount
void Elektro::addElektro(int amount) {
	player_money += amount;
	cout << "Player added " << amount << " to their wallet!\n";
}

//Subtract money from player amount
void Elektro::subtractElektro(int amount) {
	if (player_money < amount) {
		cout << "Player Doesn't have that much money! Player's current balance is : " << player_money << endl;
	}
	else {
		player_money -= amount;
	}
}

//Get player money
int Elektro::getPlayerMoney() {
	return player_money;
}

//Shows the players money in terms of Elektro bills
void Elektro::show(){
	
		int change_money = 0;	
		change_money = player_money;
		if (change_money >= 50) {
			bill50 = change_money / 50;  //Sets the number of 50 Elektro bills the player has
			change_money = change_money - (50*bill50); 
		}
		if (change_money >= bill10) {
			bill10 = change_money / 10; //Sets the number of 10 Elektro bills the player has
			change_money = change_money - (10*bill10);
		}
		if (change_money >= bill5) {
			bill5 = change_money / 5; //Sets the number of 5 Elektro bills the player has
			change_money = change_money - (5*bill5);

		}
		if (change_money >= 1) {
			bill1 = change_money / 1; //Sets the number of 1 Elektro bills the player has
			change_money = change_money - (1*bill1);
		}
		
		//Output
		cout << "-----------------\nAmount returned \n" << "50 Elektro Bills: " << bill50 << "\n" 
										"10 Elektro Bills: " << bill10 << "\n"
										"5  Elektro Bills: " << bill5 << "\n"
										"1  Elektro Bills: " << bill1 << "\n"
										 "Total = " << player_money  << endl;
}