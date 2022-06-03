#include <iostream>
#include <conio.h>
#include "MoneySlot.h"
#include "Controller.h"
#include "PickUpPlace.h"
using namespace std;

int main() {
	MoneySlot moneySlot;
	Controller controller;
	PickUpPlace pickupPlace;

	// 자판기 사용 매뉴얼
	cout << "\n==================자판기 사용 매뉴얼==================\n"
		<<"= 1. 동전 또는 1천원 화폐를 화폐 투입구에 넣어주세요. =\n"
		<<"= 2. 화폐 삽입을 그만하려면 '0'을 입력하여 주세요.    =\n"
		<<"= 3. 주문 가능한 메뉴의 번호를 입력하여 주세요.       =\n"
		<<"= 4. \"제조 완료\" 표시가 나타나면 음료를 찾아가세요.   =\n"
		<<"= 5. 거스름돈을 화폐 투입구에서 찾아가세요.           =\n"
		<<"=======================================================\n" << endl;

	controller.setState("판매중");
	while (true) {
		if (controller.getState() == "판매중" && pickupPlace.isEmpty()) {
			// 자판기에 돈 넣기
			moneySlot.inputMoney();

			// 주문 가능한 메뉴 출력 후 주문
			controller.showOrderableMenu(moneySlot.moneyManager.getSum());
			controller.getOrder(moneySlot.moneyManager.getSum());

			// 음료 만들기
			if(controller.getSelection() != 0) {
				pickupPlace.setLock(true);
				controller.requestManufacture(&pickupPlace);
			}
			else {
				controller.setState("투입된 금액을 반환합니다.");
			}

			// 거스름돈 반환
			moneySlot.returnChanges(controller.getPrice());

			// 아무 키를 입력하여 사용자가 음료를 찾아가면 다시 처음 상태로 세팅
			if (controller.getSelection() && _getch()) {
				pickupPlace.setEmpty(true);
				controller.setState("판매중");
			}
			else {
				controller.setState("판매중");
			}
		} 
		else {
			controller.setState("사용불가");
		}
	}

	return 0;
}