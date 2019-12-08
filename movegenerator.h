#pragma once
#include "board.h"
#include<time.h>

class IMoveGenerator
{
public:
	virtual ARRAY<Cordinate> getNextMove(ARRAY<Cordinate> cord,int size = 1,MovementDirection dir = enNone) = 0;
};

class SnakeMoveGenerator : public IMoveGenerator
{
public:
	ARRAY<Cordinate> getNextMove(ARRAY<Cordinate> cord, int size = 1, MovementDirection dir = enNone);
};

class FruitMoveGenerator  : public IMoveGenerator
{
public:
	ARRAY<Cordinate> getNextMove(ARRAY<Cordinate> cord, int size = 1, MovementDirection dir = enNone);
};

