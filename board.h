#pragma once
#include <SFML/Graphics.hpp>
#include<vector>
using namespace sf;

static const int ROWS = 30;
static const int COLUMBS = 20;
static const int CELL_SIZE = 16;
static const int MAX_SIZE = 50;

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
public:
	Cordinate() { X = 0; Y = 0; }
	Cordinate(int x, int y) { X = x; Y = y; }
	int X, Y;
};

template<class T>
class ARRAY
{
public:
	T a[MAX_SIZE];
	T& operator[](int i) 
	{
		if (i > MAX_SIZE) {
			return a[0];
		}
		return a[i];
	}
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
	Snake mSnake;
	ARRAY<Cordinate> mSnakeCord;
	MovementDirection mSnakeMoveDir;

	Fruit mFruit;
	Cordinate mFruitCord;

	Texture mCellColor;
	int mWidth;
	int mHeight;
	
	Board();
};


