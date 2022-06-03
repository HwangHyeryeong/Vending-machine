#ifndef MONEYSLOT_H
#define MONEYSLOT_H
#include <string>
#include "MoneyManager.h"

class MoneySlot{
public:
	MoneyManager moneyManager;
	bool checkVaildCash(int cash); // 사용가능한 화폐인지 검사
	void inputMoney(); // 사용자가 삽입한 화폐 
	void returnChanges(int price); // 거스름돈 반환
};

#endif