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

	//����ڰ� ���Ǳ⿡ ȭ�� ����
	while (true) {
		cout << "\n=====ȭ�� ���Ա�=====\n"; cin >> cash; cout << "===================== " << endl;
		
		// ��밡���� ȭ���̸� moneyManager�� �����ϵ��� ��
		if (checkVaildCash(cash)) {
			moneyManager.inputMoney(cash);
		}
		// ��� �Ұ����� ȭ���̸� ��ȯ
		else {
			if (cash == 5000 || cash == 10000 || cash == 50000){
				cout << "��ȯ: " << cash << endl;
				cash = 0;
			}
			// ȭ�� �ƴ� ���� �Է������� ȭ�� ���� ����
			else
				return;
		}
		cout << "[ ���Ե� �ݾ�: " << moneyManager.getSum() << " ]" << endl;
	}
}

void MoneySlot::returnChanges(int price) {
	//ȭ�� �Ž����� ���� ���� ����
	map<int, int> change = {
		{10, 0}, {50, 0}, {100, 0}, {500, 0}, {1000, 0}
	};
	moneyManager.returnChange(price, change);

	//moneySlot�� �Ž����� ��ȯ
	cout << "\n=====ȭ�� ���Ա�=====\n";
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