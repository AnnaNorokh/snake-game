#include "GameLogic.h"

#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <ctime>

//simple menu
bool GameLogic::game_menu()
{
	std::cout << "#############################################################" << std::endl;
	std::cout << "_________________________________________ZZZZZZZZZZ__________" << std::endl;
	std::cout << "________________________________________ZZZZZZZZZZZZZ________" << std::endl;
	std::cout << "_____WELCOME __________________________ZZZZZZZZZZZZZZ________" << std::endl;
	std::cout << "____________TO______________________ZZZZZZZZZZZZZZZZZZZ______" << std::endl;
	std::cout << "_______________CONSOLE_____________ZZZZZZZZ__ZZZZZZZZZZZZ____" << std::endl;
	std::cout << "_____PRESS____________SNAKE_______ZZZZZZ_____ZZZZZZZZZZZ_____" << std::endl;
	std::cout << "__________________________________ZZZZZZ________ZZZZZZZZZ____" << std::endl;
	std::cout << "_____1__TO__START__________________ZZZZZ____________ZZZZZZ___" << std::endl;
	std::cout << "___________________________________ZZZZZZ____________ZZ______" << std::endl;
	std::cout << "_____ANY_BUTTON_TO_EXIT____________ZZZZZZZ___________Z_______" << std::endl;
	std::cout << "___________________________________ZZZZZZZZ____________Z_____" << std::endl;
	std::cout << "__________________ZZZZZZZ___________ZZZZZZZZZZ________Z______" << std::endl;
	std::cout << "_________________ZZZZZZZZZZZZ________ZZZZZZZZZZZ_____________" << std::endl;
	std::cout << "________________ZZZZZZZZZZZZZZZ________ZZZZZZZZZZZ___________" << std::endl;
	std::cout << "_ZZZZ___________ZZZZZZZZZZZZZZZZZ_______ZZZZZZZZZZZ__________" << std::endl;
	std::cout << "_Z__ZZ_________ZZZZZZZZZZZZZZZZZZZZ_______ZZZZZZZZZZ_________" << std::endl;
	std::cout << "ZZZ_ZZ_________ZZZZZZZZZZZZZZZZZZZZZ_______ZZZZZZZZZZ________" << std::endl;
	std::cout << "_Z__ZZ_________ZZZZZZZZZZZZZZZZZZZZZZZ_______ZZZZZZZZZ_______" << std::endl;
	std::cout << "___ZZZ_________ZZZZZZZZ_____ZZZZZZZZZZZ_______ZZZZZZZZZ______" << std::endl;
	std::cout << "___ZZZ________ZZZZZZZ_________ZZZZZZZZZZ______ZZZZZZZZZ______" << std::endl;
	std::cout << "___ZZZ________ZZZZZZZ__________ZZZZZZZZZZ_____ZZZZZZZZZ______" << std::endl;
	std::cout << "___ZZZZ______ZZZZZZZ____________ZZZZZZZZZZ_____ZZZZZZZZZ_____" << std::endl;
	std::cout << "____ZZZZZ___ZZZZZZZZ_____________ZZZZZZZZZZZZZZZZZZZZZZ______" << std::endl;
	std::cout << "_____ZZZZZZZZZZZZZZZ_____________ZZZZZZZZZZZZZZZZZZZZZZ______" << std::endl;
	std::cout << "#############################################################" << std::endl;

	//get user choice  
	switch (_getch()) 
	{
		case '1':		return false; break;
		default:		return true; break;
	}
}


void GameLogic::game_logic()
{
	srand(time(NULL));

	//init snake position
	xElem[0] = snakeHead.X;
	yElem[0] = snakeHead.Y;

	//snake move logic
	for (int i = 0; i < snakeSize; i++) {
		supportTail.X = xElem[i];
		supportTail.Y = yElem[i];
		xElem[i] = snakeTail.X;
		yElem[i] = snakeTail.Y;
		snakeTail.X = supportTail.X;
		snakeTail.Y = supportTail.Y;
	}

	//snake move logic 
	switch (direction) 
	{
		case LEFT: snakeHead.Y--; break;
		case UP: snakeHead.X--; break;
		case DOWN: snakeHead.X++; break;
		case RIGHT: snakeHead.Y++; break;
	}//switch

	//tail collision check
	for (int i = 0; i < snakeSize; i++) {
		if (xElem[i] == snakeHead.X && yElem[i] == snakeHead.Y) {
			bGameExit = true;
			break;
		}
	}

	//walls collision check
	if (snakeHead.X == MAP_HEIGHT - 1 || snakeHead.X == 0 || snakeHead.Y == MAP_WIGHT - 1 || snakeHead.Y == 0) {
		bGameExit = true;
	}

	//fruits eating logic 
	if (snakeHead.X == fruit.X && snakeHead.Y == fruit.Y) {                  //if snake ate fruit
		//randomize new fruit position
		fruit.X = rand() % (MAP_HEIGHT - 3) + 3;							// diapason (20-3) to 3 to avoid frut creation in wall
		fruit.Y = rand() % (MAP_WIGHT - 3) + 3;								// diapason (45-3) to 3

		//append score and snake size
		nGameScore += 5;
		++snakeSize;
	}
}

void GameLogic::game_draw()
{
	//clear screen
	system("cls");

	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIGHT; j++) {

			if (snakeHead.X == i && snakeHead.Y == j) {
				std::cout << "S";                                                        //draw snake head
			}
			else if (i == MAP_HEIGHT - 1 || i == 0 || j == MAP_WIGHT - 1 || j == 0) {
				std::cout << "#";                                                        //draw map walls
			}
			else if (i == fruit.X && j == fruit.Y) {
				std::cout << "@";                                                        //draw fruit 
			}
			else {
				bool print = true;
				for (int k = 0; k < snakeSize; k++) {
					if (xElem[k] == i && yElem[k] == j) {
						std::cout << "o";                                                //draw snake body
						print = false;
					}
				}
				if (print) std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "SCORE : " << nGameScore ;
	std::cout << "\t\t      press X to EXIT" << std::endl;

}

void GameLogic::game_input()
{
	//if user input something
	if (_kbhit()) {

		//get input and switch
		switch (_getch()) {

		case 'a':
			direction = LEFT;
			break;
		case 'w':
			direction = UP;
			break;
		case 'd':
			direction = RIGHT;
			break;
		case 's':
			direction = DOWN;
			break;
		case 'x':
			bGameExit = true;
			break;
		case 'A':
			direction = LEFT;
			break;
		case 'W':
			direction = UP;
			break;
		case 'D':
			direction = RIGHT;
			break;
		case 'S':
			direction = DOWN;
			break;
		case 'X':
			bGameExit = true;
			break;
		default:
			break;
		}
	}
}

void GameLogic::game_run()
{
	srand(time(NULL));

	//set game init settings
	direction = STOP;
	nGameScore = 0;
	snakeSize = 0;
	//bRestart = true;

	//set snake start point 
	snakeHead.X = MAP_HEIGHT / 2;
	snakeHead.Y = MAP_WIGHT / 2;

	//set first fruit spawn
	fruit.X = rand() % (MAP_HEIGHT - 3) + 3;
	fruit.Y = rand() % (MAP_WIGHT - 3) + 3;
}

bool GameLogic::restart() {

	std::cout << "\nOOPS! YOU LOSE! :(  WANT TO RESTART? PRESS R " << std::endl << std::endl;

	//get user choice  if R/r - restart, else exit game 
	switch (_getch())
	{
	case 'r':		bGameExit = false;  return true; break;
	case 'R':		bGameExit = false;  return true; break;
	default:		return false; break;
	}
}

