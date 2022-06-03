#ifndef USERPANEL_H
#define USERPANEL_H

#include <iostream>
#include <string>
using namespace std;

class UserPanel{
public:
	void showState(string state) { cout << "\n[ " << state << " ]\n\n"; };
	int getOrder();
};

#endif