#ifndef WATERMANAGER_H
#define WATERMANAGER_H
#include <string>
#include "PickUpPlace.h"
using namespace std;

class WaterManager{
private:
	int numOfWater = 340;
public:
	bool available();
	bool sendWater(PickUpPlace* pickupPlace);
};

#endif