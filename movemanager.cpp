#include "movemanager.h"
#include <iostream>

Clock MoveManager::mClock;
float MoveManager::mTimer = 0.0;
float MoveManager::mDelay = 0.1;
bool MoveManager::mbIsClockRunning = false;

MovementDirection MoveManager::mSnakeMoveDir;
Snake* MoveManager::mSnake = nullptr;
Fruit* MoveManager::mFruit = nullptr;
Cordinate MoveManager::mSnakeCord[100];
Cordinate MoveManager::mFruitCord;

void MoveManager::updateSnakeCord()
{
	//increment snake body
	for (int i = mSnake->mLength; i > 0; --i)
	{
		mSnakeCord[i].X = mSnakeCord[i - 1].X;
		mSnakeCord[i].Y = mSnakeCord[i - 1].Y;
	}
	switch (mSnakeMoveDir)
	{
	case enDown:
		mSnakeCord[0].Y += 1;
		break;
	case enLeft:
		mSnakeCord[0].X -= 1;
		break;
	case enRight:
		mSnakeCord[0].X += 1;
		break;
	case enUp:
		mSnakeCord[0].Y -= 1;
		break;
	default:
		break;
	}
}

void MoveManager::updateFruitCord()
{
	//update fruit cordinate if snake gets the fruit
	if ((mSnakeCord[0].X == mFruitCord.X) && (mSnakeCord[0].Y == mFruitCord.Y))
	{
		mSnake->mLength++;
		mFruitCord.X = rand() % ROWS;
		mFruitCord.Y = rand() % COLUMBS;
	}
}

void MoveManager::init(Snake* snake, Fruit* fruit)
{
	mFruit = fruit;
	mSnake = snake;
	mFruitCord.X = rand() % ROWS;
	mFruitCord.Y = rand() % COLUMBS;
	mSnakeMoveDir = enRight;
}

void MoveManager::startProcess()
{
	mbIsClockRunning = true;
}

void MoveManager::stopProcess()
{
	mbIsClockRunning = false;
}

void MoveManager::processMovement()
{
	updateSnakeCord();
	updateFruitCord();
	//udpdate snake cord if reaches window's edge
	if (mSnakeCord[0].X > ROWS) mSnakeCord[0].X = 0;
	if (mSnakeCord[0].X < 0) mSnakeCord[0].X = ROWS;
	if (mSnakeCord[0].Y > COLUMBS) mSnakeCord[0].Y = 0;
	if (mSnakeCord[0].Y < 0) mSnakeCord[0].Y = COLUMBS;
}

void MoveManager::processMove(Event& e)
{
	if (mbIsClockRunning)
	{
		float time = mClock.getElapsedTime().asSeconds();
		mClock.restart();
		mTimer += time;
	}

	//increment snake head
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		mSnakeMoveDir = enLeft;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		mSnakeMoveDir = enRight;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		mSnakeMoveDir = enUp;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		mSnakeMoveDir = enDown;
	}

	if (mbIsClockRunning && mTimer > mDelay) { mTimer = 0; MoveManager::processMovement(); }
}
