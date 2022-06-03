#ifndef MONEYMANAGER_H
#define MONEYMANAGER_H
#include <string>
#include <map>
using namespace std;

class MoneyManager{
private:	
	map<int, int> numOfCash = {
		{10, 500}, {50, 500}, {100, 500}, {500, 500}, {1000, 500}
	};
	int getCash = 0;
public:
	void inputMoney(int cash);
	int calcChange(int price);
	void returnChange(int price, map<int, int>& change);
	int getSum() { return this->getCash; }
};

#endif