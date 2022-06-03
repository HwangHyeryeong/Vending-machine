#include "MoneySlot.h"
#include <iostream>
#include <map>
using namespace std;

bool MoneySlot::checkVaildCash(int cash) {
	if (cash == 10 || cash == 50 || cash == 100 || cash == 500 || cash == 1000)
		return true;
	else
		return false;
}

void MoneySlot::inputMoney() {
	int cash = 0;

	//사용자가 자판기에 화폐 투입
	while (true) {
		cout << "\n=====화폐 투입구=====\n"; cin >> cash; cout << "===================== " << endl;
		
		// 사용가능한 화폐이면 moneyManager가 관리하도록 함
		if (checkVaildCash(cash)) {
			moneyManager.inputMoney(cash);
		}
		// 사용 불가능한 화폐이면 반환
		else {
			if (cash == 5000 || cash == 10000 || cash == 50000){
				cout << "반환: " << cash << endl;
				cash = 0;
			}
			// 화폐가 아닌 것을 입력했을시 화폐 삽입 멈춤
			else
				return;
		}
		cout << "[ 투입된 금액: " << moneyManager.getSum() << " ]" << endl;
	}
}

void MoneySlot::returnChanges(int price) {
	//화폐별 거스름돈 개수 저장 공간
	map<int, int> change = {
		{10, 0}, {50, 0}, {100, 0}, {500, 0}, {1000, 0}
	};
	moneyManager.returnChange(price, change);

	//moneySlot에 거스름돈 반환
	cout << "\n=====화폐 투입구=====\n";
	while (change[1000]){
		cout << 1000 << " ";
		change[1000]--;
	}
	while (change[500]) {
		cout << 500 << " ";
		change[500]--;
	}
	while (change[100]) {
		cout << 100 << " ";
		change[100]--;
	}
	while (change[50]){
		cout << 50 << " ";
		change[50]--;
	}
	while (change[10]) {
		cout << 10 << " ";
		change[10]--;
	}
	cout << "\n===================== " << endl;
}