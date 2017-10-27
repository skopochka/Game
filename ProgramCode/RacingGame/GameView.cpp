#include "GameView.h"


GameView::GameView(GameModel *in_model)
{
	model = in_model;
	model->addObserver(this);
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	x = model->get_GameX();
	y = model->get_GameY();
}
void  GameView::Update(bool endgame)
{
	system("cls");
	if (!endgame)
	{
		drawBorders();
		drawGame();
		drawMenu();
	}
	else
	{
		drawEndgameMenu();
	}
};
void GameView::drawBorders()
{
	for (int i = 0; i < 6; i++)
	{
		COORD point;
		point.X = x - 1 + i;
		point.Y = y - 1;
		SetConsoleCursorPosition(hConsoleOutput, point);
		putchar('#');
		point.Y = y + 20;
		SetConsoleCursorPosition(hConsoleOutput, point);
		putchar('#');
		for (int i = 0; i < 22; i++)
		{
			point.X = x - 1;
			point.Y = y + i - 1;
			SetConsoleCursorPosition(hConsoleOutput, point);
			putchar('#');
			point.X = x + 5;
			point.Y = y + i - 1;
			SetConsoleCursorPosition(hConsoleOutput, point);
			putchar('#');
		}

	}

};
void GameView::drawGame()
{
	array<array<int,5>,20> arr = model->get_Field();
	COORD point;
	for (int i = 0; i < 20; i++)
	for (int j = 0; j < 5; j++)
	{
		if (arr[i][j] == 1)
		{
			point.X = x + j;
			point.Y = y + i;
			SetConsoleCursorPosition(hConsoleOutput, point);
			putchar('#');
		}
		if (arr[i][j] == 2)
		{
			point.X = x + j;
			point.Y = y + i;
			SetConsoleCursorPosition(hConsoleOutput, point);
			putchar('@');
		}
	}
};
void GameView::drawMenu()
{
	COORD point;
	point.X = model->get_GameX();
	point.Y = model->get_GameY()+23;
	SetConsoleCursorPosition(hConsoleOutput, point);
	string speed = "your speed is ";
	speed += to_string(100 / model->get_GameSpeed());
	printf(speed.c_str());
	point.Y +=2;
	SetConsoleCursorPosition(hConsoleOutput, point);
	string time = "your time is ";
	time += to_string(model->get_GameTime());
	printf(time.c_str());
	point.Y += 2;
	SetConsoleCursorPosition(hConsoleOutput, point);
	string score = "your score is ";
	score += to_string(model->get_GameScore());
	printf(score.c_str());
};
void GameView::drawEndgameMenu()
{
	COORD point;
	point.X = model->get_GameX();
	point.Y = model->get_GameY();
	SetConsoleCursorPosition(hConsoleOutput, point);
	string time = "your time is ";
	time += to_string(model->get_GameTime());
	time += " sec";
	printf(time.c_str());
	point.Y += 2;
	SetConsoleCursorPosition(hConsoleOutput, point);
	string score = "your final score is ";
	score += to_string(model->get_GameScore());
	printf(score.c_str());
	point.Y += 2;
	SetConsoleCursorPosition(hConsoleOutput, point);
};

GameView::~GameView()
{
}
