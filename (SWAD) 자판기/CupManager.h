#ifndef CUPMANAGER_H
#define CUPMANAGER_H
#include <string>
#include "PickUpPlace.h"
using namespace std;

class CupManager{
private:
	int numOfCup = 350;
public:
	bool available();
	bool sendCup(PickUpPlace*);
};

#endif