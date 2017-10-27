#pragma once

#include "GameModel.h"
#include<ctime>
#include <cstdlib>
#include<windows.h>
#include<conio.h>

class GameControl
{
private:
	GameModel *model;
	int gameSpeed, gamePhase;
	bool endGame;
	int gameTime;
	int score;
	clock_t time1, time2, duration, pauseduration;
	enum Keys { KEY_ENTER = 13, KEY_ESC = 27, KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77 };
	Keys GetPressedKey();
	void ClearKeyBuffer();
public:
	GameControl(GameModel*);
	void StartGame();
	void ExitGame();
	int PauseGame(); 
	~GameControl();

};