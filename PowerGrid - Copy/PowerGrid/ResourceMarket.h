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
	int buy(int num);
	void buy(MarketSpace m, int num);
	void buy(MarketSpace m);
	void buy();
	string display(vector<MarketSpace*> market);
	vector<MarketSpace*> market;
};