#include "movegenerator.h"
#include<iostream>
ARRAY<Cordinate> SnakeMoveGenerator::getNextMove(ARRAY<Cordinate> cord, int size, MovementDirection dir)
{
	for (int i = 0; i < size; i++)
		std::cout << "(" << cord[i].X << ", " << cord[i].Y << ") ";
	std::cout << std::endl;

	//	//increment snake body
	for (int i = size; i > 0; --i)
	{
		cord[i].X = cord[i - 1].X;
		cord[i].Y = cord[i - 1].Y;
	}
	switch (dir)
	{
	case enDown: {
		cord[0].Y += 1;
		break;
	}
	case enLeft: {
		cord[0].X -= 1;
		break;
	}
	case enRight: {
		cord[0].X += 1;
		break;
	}
	case enUp: {
		cord[0].Y -= 1;
		break;
	}
	default:
		break;
	}
	return cord;
}

ARRAY<Cordinate> FruitMoveGenerator::getNextMove(ARRAY<Cordinate> cord, int size, MovementDirection dir)
{
	cord[0].X = rand() % ROWS;
	cord[0].Y = rand() % COLUMBS;
	return cord;
}
