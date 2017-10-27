// RacingGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<ctime>
#include "GameModel.h"
#include "GameControl.h"
#include "GameView.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	setlocale(LC_ALL, "Russian");
	GameModel model(20,1); 
	GameControl controller(&model);
	GameView view(&model);
	cout << "для старта нажмите любую клавишу" << endl;
	int code =_getch();
	view.Update(0);
	controller.StartGame();
	return 0;
}

