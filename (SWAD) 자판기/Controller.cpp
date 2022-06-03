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

	// 물 또는 컵이 없는 경우 모든 메뉴 주문 불가능
	if(waterManager.available() && cupManager.available()){
		checkAvailability(); // 재료 있는지 확인
		for (int i = 1; i < NUMOFMENU; i++) {
			// 주문 가능한 메뉴: ●, 불가능한 메뉴: ○ 로 표시
			if ((menu[i].price <= cash) && (menu[i].available)) {
				cout << "(" << (menu[i].menuID) << ") " << menu[i].menuName << " " << menu[i].price << " ● " << endl;
			}
			else {
				cout << "(" << (menu[i].menuID) << ") " << menu[i].menuName << " " << menu[i].price <<  " ○ " << endl;
			}
		}
	}
	else {
		for (int i = 1; i < NUMOFMENU; i++){
			cout << "(" << (menu[i].menuID) << ") " << menu[i].menuName << " " << menu[i].price << " ○ " << endl;
			this->selection = 0;
		}
	}
	cout << "****************************\n";
}

void Controller::getOrder(int cash) {
	setState("메뉴 선택");
	
	// 모든 메뉴 불가능할 경우 selection은 이미 0이므로 선택하지 않음
	while (selection) {
		selection = userPanel.getOrder();
		
		// 삽입된 금액보다 선택한 메뉴의 가격이 높거나 비활성화된 버튼을 누른 경우 다시 선택하도록 함
		if (menu[selection].price <= cash || (selection >= NUMOFMENU))
			break;
	}
}

void Controller::requestManufacture(PickUpPlace* pickupPlace) {
	setState(menu[this->selection].menuName + " 제조 중");
	pickupPlace->setEmpty(false);
	
	if (manufacture.manufacture(pickupPlace, menu[this->selection].ingredient, &ingredientManager, &cupManager, &waterManager)) {
		setState("제조 완료. 음료를 찾아가세요.");
		pickupPlace->setLock(false);
		pickupPlace->setState("_|=|_");
	}
	else{
		setState("관리자에게 문의하시오.");
		this->selection = 0; // 거스름돈 반환을 위해 메뉴 선택 안한 것처럼 처리
	}
}