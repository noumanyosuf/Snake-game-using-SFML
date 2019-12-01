#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

static const int ROWS = 30;
static const int COLUMBS = 20;
static const int CELL_SIZE = 16;

enum MovementDirection
{
	enNone =0,
	enUp,
	enDown,
	enRight,
	enLeft
};


class Cordinate
{
	int mx;
	int my;
public:
	int X, Y;
};


class Fruit
{
public :
	Texture mColor;
	Fruit();
};


class Snake
{
public:
	int mLength;
	Texture mColor;
	Snake();
};


class Board
{
public:
	Texture mCellColor;
	int mWidth;
	int mHeight;
	Snake mSnake;
	Fruit mFruit;
	Board();
};


