#pragma once

#include <Windows.h>

#define MAP_HEIGHT  20
#define MAP_WIGHT  45

class GameLogic
{	   	  
	private:
		int snakeSize;                                                      //snake size
		COORD snakeHead;                                                    //head cordinats
		COORD fruit;														//fruit cordinats
		int xElem[100], yElem[100];                                         //snake size capacity
		COORD snakeTail{ 0,0 };												//snake tail cordinats
		COORD supportTail;													//coordinats of in front of the tail element 

		enum Directions { STOP = 0, LEFT, RIGHT, DOWN, UP };				//directions set
		Directions direction;

	public:
		bool bRestart;
		bool bGameExit;
		int nGameScore;

		bool game_menu();													//simple menu
		void game_logic();													//game behavior logic
		void game_draw();                                                   //draw all game elements logic
		void game_input();                                                  //user input processing
		void game_run();                                                    //init game settings
		bool restart();                                                     //restart logic

};

