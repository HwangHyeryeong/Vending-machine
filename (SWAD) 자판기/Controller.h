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
	const bool ingredient[5];//프리미엄커피, 일반커피, 설탕, 크림, 우리차 사용 여부
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
		{1, "고급커피", 700, {true, false, true, true, false}},
		{2, "고급커피", 700, {true, false, true, true, false}},
		{3, "고급커피", 700, {true, false, true, true, false}},
		{4, "특수커피", 600, {false, true, true, true, false}},
		{5, "특수커피", 600, {false, true, true, true, false}},
		{6, "특수커피", 600, {false, true, true, true, false}},
		{7, "일반커피", 500, {false, true, false, false, false}},
		{8, "일반커피", 500, {false, true, false, false, false}},
		{9, "일반커피", 500, {false, true, false, false, false}},
		{10, "우리차", 500, {false, false, true, false, true}},
		{11, "우리차", 500, {false, false, true, false, true}},
		{12, "우리차", 500, {false, false, true, false, true}}
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