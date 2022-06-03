#ifndef MANUFACTURE_H
#define MANUFACTURE_H
#include <string>
#include "IngredientManager.h"
#include "CupManager.h"
#include "WaterManager.h"
#include "Manufacture.h"
#include "pickUpPlace.h"
using namespace std;

class Manufacture{
public:
	bool manufacture(PickUpPlace*, const bool*, IngredientManager*, CupManager*, WaterManager*);
};

#endif