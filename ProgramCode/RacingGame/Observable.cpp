#include "Observable.h"


Observable::Observable()
{
	observers = std::vector<Observer*>();
};
void Observable::addObserver(Observer *observer)
{
	observers.push_back(observer);
};
void Observable::notifyUpdate(bool endgame)
{
	int size = observers.size();
	for (int i = 0; i < size; i++)
	{
		observers[i]->Update(endgame);
	}
}

Observable::~Observable()
{
}
