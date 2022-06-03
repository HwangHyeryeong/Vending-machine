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

	// ���Ǳ� ��� �Ŵ���
	cout << "\n==================���Ǳ� ��� �Ŵ���==================\n"
		<<"= 1. ���� �Ǵ� 1õ�� ȭ�� ȭ�� ���Ա��� �־��ּ���. =\n"
		<<"= 2. ȭ�� ������ �׸��Ϸ��� '0'�� �Է��Ͽ� �ּ���.    =\n"
		<<"= 3. �ֹ� ������ �޴��� ��ȣ�� �Է��Ͽ� �ּ���.       =\n"
		<<"= 4. \"���� �Ϸ�\" ǥ�ð� ��Ÿ���� ���Ḧ ã�ư�����.   =\n"
		<<"= 5. �Ž������� ȭ�� ���Ա����� ã�ư�����.           =\n"
		<<"=======================================================\n" << endl;

	controller.setState("�Ǹ���");
	while (true) {
		if (controller.getState() == "�Ǹ���" && pickupPlace.isEmpty()) {
			// ���Ǳ⿡ �� �ֱ�
			moneySlot.inputMoney();

			// �ֹ� ������ �޴� ��� �� �ֹ�
			controller.showOrderableMenu(moneySlot.moneyManager.getSum());
			controller.getOrder(moneySlot.moneyManager.getSum());

			// ���� �����
			if(controller.getSelection() != 0) {
				pickupPlace.setLock(true);
				controller.requestManufacture(&pickupPlace);
			}
			else {
				controller.setState("���Ե� �ݾ��� ��ȯ�մϴ�.");
			}

			// �Ž����� ��ȯ
			moneySlot.returnChanges(controller.getPrice());

			// �ƹ� Ű�� �Է��Ͽ� ����ڰ� ���Ḧ ã�ư��� �ٽ� ó�� ���·� ����
			if (controller.getSelection() && _getch()) {
				pickupPlace.setEmpty(true);
				controller.setState("�Ǹ���");
			}
			else {
				controller.setState("�Ǹ���");
			}
		} 
		else {
			controller.setState("���Ұ�");
		}
	}

	return 0;
}