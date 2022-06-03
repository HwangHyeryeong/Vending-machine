#ifndef PICKUPPLACE_H
#define PICKUPPLACE_H
#include <iostream>
#include <string>
using namespace std;

class PickUpPlace{
private:
	string state;
	bool lock = false;
	bool empty = true; // 픽업대에 음료 존재 여부
public:
	void setLock(bool lock) {
		this->lock = lock;
		if (this->lock)
			cout << "PickUpPlace: <lock>\n";
		else
			cout << "PickUpPlace: <unlock>\n";
	}
	bool isLock() {
		return this->lock;
	}
	void setEmpty(bool empty) {
		this->empty = empty;
		
		if (empty)
			setState("_____");
	}
	bool isEmpty() {
		return this->empty;
	}
	void setState(string newState) { 
		this->state = newState; 
		showState();
	}
	void showState() { cout << "PickUpPlace [" << state << "]\n"; }
};

#endif