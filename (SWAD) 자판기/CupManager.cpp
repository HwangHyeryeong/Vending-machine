#include "CupManager.h"
#include <iostream>
#include <Windows.h>
using namespace std;

bool CupManager::available() {
	return numOfCup;
}

bool CupManager::sendCup(PickUpPlace* pickupPlace) {
	this->numOfCup--;
	Sleep(1000);
	pickupPlace->setState("_|_|_");
	return true;
}