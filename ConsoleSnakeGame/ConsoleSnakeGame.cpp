#include <iostream>
#include "GameLogic.h"

int main()
{
	GameLogic game;

	//open menu and get user choise
	game.bGameExit = game.game_menu();

	//if user selected to EXIT game
	if (game.bGameExit) {
		std::cout << "GOODBYE" << std::endl;
		return 0;
	}

	while (game.bRestart) {
		//set game start parametrs
		game.game_run();

		while (!game.bGameExit) {
			game.game_input();
			game.game_logic();
			game.game_draw();
		}

		game.bRestart = game.restart();
	}

	//_getch();

	std::cout << "GAME OVER! Your Scoure : " << game.nGameScore << std::endl;
	return 0;
}