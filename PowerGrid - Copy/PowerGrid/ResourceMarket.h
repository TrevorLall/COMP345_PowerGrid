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
	int buy(int num, string resource);
	string display(vector<MarketSpace*> market);
	vector<MarketSpace*> market;
};