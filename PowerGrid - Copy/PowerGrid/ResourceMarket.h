#pragma once
#pragma once
#include"MarketSpace.h"

class ResourceMarket
{
private:
	

public:
	ResourceMarket();
	~ResourceMarket();
	vector<MarketSpace*> getMarket();
	void reSupply(vector<Player*> players, int player_number);
	void reSupply();
	int buy(int num, string resource);
	string display(vector<MarketSpace*> market);
	vector<MarketSpace*> market;
};