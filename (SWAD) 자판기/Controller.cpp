#include <iostream>
#include "Controller.h"
using namespace std;

void Controller::setState(string state) {
	this->state = state; 
	userPanel.showState(this->state);
}

void Controller::checkAvailability() {
	for (int i = 0; i < NUMOFMENU; i++)
		menu[i].available = ingredientManager.available(menu[i].ingredient);
}

void Controller::showOrderableMenu(int cash) {
	cout << "\n************MENU************\n";

	// �� �Ǵ� ���� ���� ��� ��� �޴� �ֹ� �Ұ���
	if(waterManager.available() && cupManager.available()){
		checkAvailability(); // ��� �ִ��� Ȯ��
		for (int i = 1; i < NUMOFMENU; i++) {
			// �ֹ� ������ �޴�: ��, �Ұ����� �޴�: �� �� ǥ��
			if ((menu[i].price <= cash) && (menu[i].available)) {
				cout << "(" << (menu[i].menuID) << ") " << menu[i].menuName << " " << menu[i].price << " �� " << endl;
			}
			else {
				cout << "(" << (menu[i].menuID) << ") " << menu[i].menuName << " " << menu[i].price <<  " �� " << endl;
			}
		}
	}
	else {
		for (int i = 1; i < NUMOFMENU; i++){
			cout << "(" << (menu[i].menuID) << ") " << menu[i].menuName << " " << menu[i].price << " �� " << endl;
			this->selection = 0;
		}
	}
	cout << "****************************\n";
}

void Controller::getOrder(int cash) {
	setState("�޴� ����");
	
	// ��� �޴� �Ұ����� ��� selection�� �̹� 0�̹Ƿ� �������� ����
	while (selection) {
		selection = userPanel.getOrder();
		
		// ���Ե� �ݾ׺��� ������ �޴��� ������ ���ų� ��Ȱ��ȭ�� ��ư�� ���� ��� �ٽ� �����ϵ��� ��
		if (menu[selection].price <= cash || (selection >= NUMOFMENU))
			break;
	}
}

void Controller::requestManufacture(PickUpPlace* pickupPlace) {
	setState(menu[this->selection].menuName + " ���� ��");
	pickupPlace->setEmpty(false);
	
	if (manufacture.manufacture(pickupPlace, menu[this->selection].ingredient, &ingredientManager, &cupManager, &waterManager)) {
		setState("���� �Ϸ�. ���Ḧ ã�ư�����.");
		pickupPlace->setLock(false);
		pickupPlace->setState("_|=|_");
	}
	else{
		setState("�����ڿ��� �����Ͻÿ�.");
		this->selection = 0; // �Ž����� ��ȯ�� ���� �޴� ���� ���� ��ó�� ó��
	}
}