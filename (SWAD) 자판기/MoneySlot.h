#ifndef MONEYSLOT_H
#define MONEYSLOT_H
#include <string>
#include "MoneyManager.h"

class MoneySlot{
public:
	MoneyManager moneyManager;
	bool checkVaildCash(int cash); // ��밡���� ȭ������ �˻�
	void inputMoney(); // ����ڰ� ������ ȭ�� 
	void returnChanges(int price); // �Ž����� ��ȯ
};

#endif