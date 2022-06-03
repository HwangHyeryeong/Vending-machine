#ifndef INGREDIENTMANAGER_H
#define INGREDIENTMANAGER_H
#include <string>
#include "PickUpPlace.h"
using namespace std;

class IngredientManager{
private:
	int numOfPremiumCoffee = 565;
	int numOfNormalCoffee = 600;
	int numOfSugar = 618;
	int numOfCream = 350;
	int numOfTea = 175;

public:
	bool available(const bool ingredient[5]);
	bool sendIngredient(const bool ingredient[5], PickUpPlace* pickupPlace);
};

#endif