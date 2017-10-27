#pragma once
#include "Observable.h"
#include<array>
using namespace std;
class GameModel :
	public Observable
{
private: private:
	int GameX, GameY, carX, carY;
	int GameSpeed, GameTime, GameScore;
	array<array<int, 5>, 20> field;
public:
	GameModel(int, int);
	int get_GameX() const;
	int get_GameY() const;
	int get_GameSpeed() const;
	void set_GameSpeed(int);
	int get_GameTime() const;
	void set_GameTime(int);
	int get_GameScore() const;
	void set_GameScore(int);
	bool FieldUpdate();
	bool CarUpdate(int);
	void addObserver(Observer *observer);
	void notifyUpdate(bool);
	array<array<int,5>,20> get_Field() const;
	~GameModel();
};

