#pragma once
#pragma once
#include"Coal.h"
#include"Oil.h"
#include"Garbage.h"
#include"Uranium.h"

class Coal;
class Oil;
class Garbage;
class Uranium;

class MarketSpace
{

private:
	int cost;
	vector<Coal*> coal;
	vector<Oil*> oil;
	vector<Garbage*> garbage;
	vector<Uranium*> uranium;

public:
	MarketSpace();
	MarketSpace(int newCost, int newCoal, int newOil, int newGarbage, int newUranium);
	MarketSpace(int newCost, int newUranium);
	~MarketSpace();
	void setCost(int newCost);
	void setCoal(int newCoal);
	void takeCoal(int newCoal);
	void setOil(int newOil);
	void takeOil(int newOil);
	void buyResource(int number, string res);
	void setGarbage(int newGarbage);
	void takeGarbage(int newGarbage);
	void setUranium(int newUranium);
	void takeUranium(int newUranium);
	int getCost();
	vector<Coal*> getCoal();
	vector<Oil*> getOil();
	vector<Garbage*> getGarbage();
	vector<Uranium*> getUranium();

};