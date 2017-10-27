#pragma once
#include "Observer.h"
#include<vector>

class Observable
{
private:
	std::vector<Observer*> observers;
public:
	Observable();
	void addObserver(Observer *observer);
	void notifyUpdate(bool);
	~Observable();

};

