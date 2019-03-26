#include "PowePlantMarket.h"

PowerPlantMarket::PowerPlantMarket()
{
}

PowerPlantMarket::PowerPlantMarket(Deck* deck){
	for (int i = 0; i < 8; i++) {
		Cards card = deck->drawCard();
		powerMarket.push_back(card);
	}
}

vector<Cards> PowerPlantMarket::getPowerPlantMarket() {
	return powerMarket;
}




void PowerPlantMarket::display() {
	cout << "!~ POWER PLANT MARKET ~!\n";
	cout << "(Power Number, Type(Amount), Cities Powered)\n\n";
	cout << "Current Market: ";
	for (int i = 0; i < 4;i++ ) {
		cout << " | [" << powerMarket.at(i).getCardNum()<< ", " << powerMarket.at(i).getResType() << "( "<< powerMarket.at(i).getResourceNum() <<"), " << powerMarket.at(i).getPowerNum() << "] | ";
	}
	cout << "\n\n";
	cout << "Future Market:  ";
	for (int i = 4; i < 8; i++) {
		cout << " | [" << powerMarket.at(i).getCardNum() << ", " << powerMarket.at(i).getResType() << "( " << powerMarket.at(i).getResourceNum() << "), " << powerMarket.at(i).getPowerNum() << "] | ";
	}
}

const int PowerPlantMarket::getSize()
{
	return maxSize;
}
