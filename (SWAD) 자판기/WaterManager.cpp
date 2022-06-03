#include "WaterManager.h"
#include <iostream>
#include <Windows.h>
using namespace std;

bool WaterManager::available() {
	return this->numOfWater;
}

bool WaterManager::sendWater(PickUpPlace* pickupPlace) {
	this->numOfWater--;
	Sleep(2000);
	pickupPlace->setState("_|~|_");
	return true;
}