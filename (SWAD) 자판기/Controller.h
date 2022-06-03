#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "IngredientManager.h"
#include "WaterManager.h"
#include "CupManager.h"
#include "Manufacture.h"
#include "UserPanel.h"
#include "PickUpPlace.h"
using namespace std;

const int NUMOFMENU = 13;

typedef struct Menu {
	const int menuID;
	const string menuName;
	const int price;
	const bool ingredient[5];//�����̾�Ŀ��, �Ϲ�Ŀ��, ����, ũ��, �츮�� ��� ����
	bool available;
}Menu;

class Controller{
private:
	UserPanel userPanel;
	IngredientManager ingredientManager;
	WaterManager waterManager;
	CupManager cupManager;
	Manufacture manufacture;
	string state;
	int selection = 100;

public:
	Menu menu[NUMOFMENU] = {
		{0, "", 0},
		{1, "���Ŀ��", 700, {true, false, true, true, false}},
		{2, "���Ŀ��", 700, {true, false, true, true, false}},
		{3, "���Ŀ��", 700, {true, false, true, true, false}},
		{4, "Ư��Ŀ��", 600, {false, true, true, true, false}},
		{5, "Ư��Ŀ��", 600, {false, true, true, true, false}},
		{6, "Ư��Ŀ��", 600, {false, true, true, true, false}},
		{7, "�Ϲ�Ŀ��", 500, {false, true, false, false, false}},
		{8, "�Ϲ�Ŀ��", 500, {false, true, false, false, false}},
		{9, "�Ϲ�Ŀ��", 500, {false, true, false, false, false}},
		{10, "�츮��", 500, {false, false, true, false, true}},
		{11, "�츮��", 500, {false, false, true, false, true}},
		{12, "�츮��", 500, {false, false, true, false, true}}
	};
	void showOrderableMenu(int cash);
	void setState(string state);
	int getPrice() { return menu[this->selection].price; };
	int getSelection() { return selection; };
	string getState() { return this->state; }
	void checkAvailability();
	void getOrder(int cash);
	void requestManufacture(PickUpPlace* pickupPlace);
};

#endif