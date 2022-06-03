#include "MoneyManager.h"
#include <iostream>
using namespace std;

void MoneyManager::inputMoney(int cash) {
	// 동전 또는 지폐 하나씩 넣으면서 금액 증가
	this->numOfCash[cash]++;
	this->getCash += cash;
}

int MoneyManager::calcChange(int price) {
	return (this->getCash - price);
}

void MoneyManager::returnChange(int price, map<int, int>& change) {
	int changes = this->calcChange(price);
	this->getCash -= price;

	while (changes > 0) {
		if ((changes >= 1000) && (numOfCash[1000] > 0)) {
			changes -= 1000;
			this->getCash -= 1000;
			this->numOfCash[1000]--;
			change[1000]++;
		}
		else if((changes >= 500) && (numOfCash[500] > 0)){
			changes -= 500;
			this->getCash -= 500;
			this->numOfCash[500]--;
			change[500]++;
		}
		else if ((changes >= 100) && (numOfCash[100] > 0)) {
			changes -= 100;
			this->getCash -= 100;
			this->numOfCash[100]--;
			change[100]++;
		}
		else if ((changes >= 50) && (numOfCash[50] > 0)) {
			changes -= 50;
			this->getCash -= 50;
			this->numOfCash[50]--;
			change[50]++;
		}
		else if(numOfCash[10] > 0) {
			changes -= 10;
			this->getCash -= 10;
			this->numOfCash[10]--;
			change[10]++;
		}
		else {
			std::cout << "\n자판기 내 반환할 화폐가 부족합니다. 관리자에게 문의해주세요. 010-xxxx-xxxx" << endl;
			break;
		}
	}
	std::cout << endl;
}