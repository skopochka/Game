#include "GameControl.h"

GameControl::GameControl(GameModel *in_model)
{
	model = in_model;
	gameSpeed = 12;
	endGame = 0;
	gameTime = 0;
	gamePhase = 0;
	score = 0;
};
void GameControl::StartGame()
{
	pauseduration = 0;
	gamePhase = 0;
	model->set_GameScore(0);
	model->set_GameSpeed(6);
	model->set_GameTime(0);
	time1 = clock();
	while (!endGame)
	{
		if (_kbhit())
		{
			switch (GetPressedKey())
			{
			case KEY_UP:
				if (gameSpeed > 2)
					gameSpeed--;
				model->set_GameSpeed(gameSpeed);
				break;
			case KEY_DOWN:
				gameSpeed++;
				model->set_GameSpeed(gameSpeed);
				gamePhase++;
				break;
			case KEY_LEFT:
				endGame = !model->CarUpdate(-1);
				break;
			case KEY_RIGHT:
				endGame = !model->CarUpdate(1);
				break;
			case KEY_ESC:
				ExitGame();
				break;
			case KEY_ENTER:
				pauseduration += PauseGame();
				break;
			default:
				break;
			}
		}
		if (gamePhase >= gameSpeed)
		{
			gamePhase = 0;
			endGame = !model->FieldUpdate();
			score += 5;
			model->set_GameScore(score);
				model->set_GameTime((clock() - time1 - pauseduration) / CLOCKS_PER_SEC);
		}
		else
			gamePhase++;
		Sleep(15);
	}
	ExitGame();

};

GameControl::Keys GameControl::GetPressedKey()
{
	Keys k = static_cast<GameControl::Keys>(_getch());
	if (k == 224|| k == 0)
		 k = static_cast<GameControl::Keys>(_getch());
	while (_kbhit())
		_getch();
	return k;
}
int GameControl::PauseGame()
{
	clock_t pause1, pause2;
	pause1 = clock();
	_getch();
	pause2 = clock();
	return static_cast<int>(pause2 - pause1);
};
void GameControl::ExitGame()
{
	_getch();
	exit(1);
};
GameControl::~GameControl()
{

};

