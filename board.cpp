#include "board.h"
#include <iostream>

Fruit::Fruit()
{
	mColor.loadFromFile("images/red.png");
}

Snake::Snake()
{
	mColor.loadFromFile("images/green.png");
	mLength = 3;
}

Board::Board()
{
	mWidth = CELL_SIZE * ROWS;
	mHeight = CELL_SIZE * COLUMBS;

	mCellColor.loadFromFile("images/white.png");
}


