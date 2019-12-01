#pragma once
#include "board.h"
#include<time.h>

class MoveManager
{
	static Clock mClock;
	static float mTimer;
	static float mDelay;
	static bool mbIsClockRunning;

	static void updateSnakeCord();
	static void updateFruitCord();
	static void processMovement();
public:
	static Cordinate mSnakeCord[100];
	static Cordinate mFruitCord;
	static Snake* mSnake;
	static Fruit* mFruit;
	static MovementDirection mSnakeMoveDir;

	static void init(Snake* snake, Fruit* fruit);
	static void startProcess();
	static void stopProcess();
	static void processMove(Event& e);
};


