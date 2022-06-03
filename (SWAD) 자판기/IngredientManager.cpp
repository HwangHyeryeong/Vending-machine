#include "IngredientManager.h"
#include <iostream>
#include <Windows.h>
using namespace std;

bool IngredientManager::available(const bool ingredient[5]) {
	bool isAvailable = false;

	if (ingredient[0]){
		if (numOfPremiumCoffee > 0)
			isAvailable = true;
		else
			return false;
	}
	if (ingredient[1]) {
		if (numOfNormalCoffee > 0)
			isAvailable = true;
		else
			return false;
	}
	if (ingredient[2]) {
		if (numOfSugar > 0)
			isAvailable = true;
		else
			return false;
	}
	if (ingredient[3]) {
		if (numOfCream > 0)
			isAvailable = true;
		else
			return false;
	}
	if (ingredient[4]) {
		if (numOfTea > 0)
			isAvailable = true;
		else
			return false;
	}
	return isAvailable;
}
bool IngredientManager::sendIngredient(const bool ingredient[5], PickUpPlace* pickupPlace) {
	if (ingredient[0]){
		numOfPremiumCoffee--;
		Sleep(1000);
		pickupPlace->setState("_|¡Ú|_");
	}
	if (ingredient[1]){
		numOfNormalCoffee--;
		Sleep(1000);
		pickupPlace->setState("_|¡Ù|_");
	}
	if (ingredient[2]){
		numOfSugar--;
		Sleep(1000);
		pickupPlace->setState("_|¡à|_");
	}
	if (ingredient[3]){
		numOfCream--;
		Sleep(1000);
		pickupPlace->setState("_|¢Æ|_");
	}
	if (ingredient[4]){
		numOfTea--;
		Sleep(1000);
		pickupPlace->setState("_|¡â|_");
	}
	return true;
}