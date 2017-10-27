#include "GameModel.h"
#include<conio.h>
#include<iostream>
#include<random>


GameModel::GameModel(int gameX, int gameY)
{
	for (int i = 0; i < 20;i++)
	for (int j = 0; j < 5; j++)
		field[i][j] = 0;
	Observable::Observable();
	GameX = gameX;
	GameY = gameY;
	carX = 2;
	carY = 19;
	field[19][2] = 2;
	GameSpeed = 6;
	GameTime = 0;
	GameScore = 0;
};
int GameModel::get_GameX() const{ return GameX; };
int GameModel::get_GameY() const{ return GameY; };
int GameModel::get_GameSpeed() const { return GameSpeed; };
void GameModel::set_GameSpeed(int in_GameSpeed) { GameSpeed = in_GameSpeed; };
int GameModel::get_GameTime() const { return GameTime; };
void GameModel::set_GameTime(int in_GameTime) { GameTime = in_GameTime; };
int GameModel::get_GameScore() const { return GameScore; };
void GameModel::set_GameScore(int in_GameScore) { GameScore = in_GameScore; };

 array<array<int,5>,20> GameModel::get_Field() const { return field; };

void GameModel::addObserver(Observer *Obser)
{
	Observable::addObserver(Obser);
};
void GameModel::notifyUpdate(bool endgame)
{
	Observable::notifyUpdate(endgame);
};

bool GameModel::CarUpdate(int direction)
{
	if (carX + direction >= 0 && carX + direction <= 4)
	{
		if (field[carY][carX + direction] != 0)
		{
			notifyUpdate(1);
			return 0;
		}

		field[carY][carX] = 0;
		field[carY][carX + direction] = 2;
		carX += direction;
	}

	notifyUpdate(0);
	return 1;

};
bool GameModel::FieldUpdate()
{
	for (int i = 19; i >= 0; i--)
	for (int j = 0; j < 5; j++)
	{
		if (field[i][j] == 1)
		{
			if (i == 19)
				field[i][j] = 0;
			else
			{
				if (field[i + 1][j] == 2)
				{

					notifyUpdate(1);
					return 0;
				}
				field[i + 1][j] = 1;
				field[i][j] = 0;
			}
		}
	}
	std::random_device rd;
	std::mt19937 mt(rd());
	if ((rd() % 3))
	{
		int sum = 0;
		for (int i = 1; i < 5; i++)
		for (int j = 0; j < 5; j++)
			sum += field[i][j];
		if (sum < 4)
			field[0][rd() % 5] = 1;
	}
	notifyUpdate(0);
	return 1;


};

GameModel::~GameModel()
{};

