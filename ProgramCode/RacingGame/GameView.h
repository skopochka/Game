#pragma once
#include "GameModel.h"
#include "Observer.h"
#include<windows.h>
#include<iostream>
#include<string>
class GameView :
	public Observer
{
private:
	HANDLE hConsoleOutput;
	void drawBorders();
	void drawGame();
	void drawMenu();
	void drawEndgameMenu();
	GameModel *model;
	int x, y;
public:
	GameView(GameModel*);
	void  Observer::Update(bool) override;
	~GameView();
};

