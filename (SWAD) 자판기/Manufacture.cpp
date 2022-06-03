#include "Manufacture.h"
#include <iostream>
#include <Windows.h>
using namespace std;

bool Manufacture::manufacture(PickUpPlace* pickupPlace, const bool* recipe, IngredientManager* ingrediendtManager, CupManager* cupManager, WaterManager* waterManager) {
	if (cupManager->sendCup(pickupPlace) && waterManager->sendWater(pickupPlace) && ingrediendtManager->sendIngredient(recipe, pickupPlace)) {
		pickupPlace->setState("_|¡×|_"); //mix
		Sleep(2000);
		return true;
	}
	else false;
}