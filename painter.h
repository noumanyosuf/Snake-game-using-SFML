#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Snake;
class Fruit;
class Board;

class Painter
{
public:
	virtual void paint() = 0;
};

class BoardPainter : public Painter
{
	Board* mBoard;
	RenderWindow* window;
public:
	BoardPainter(RenderWindow* win, Board* board) { window = win; mBoard = board; }
	void paint();
};


class SnakePainter : public Painter
{
	Snake* mSnake;
	RenderWindow* window;
public:
	SnakePainter(RenderWindow* win, Snake* snake) { window = win; mSnake = snake; }
	void paint();
};


class FruitPainter : public Painter
{
	Fruit* mFruit;
	RenderWindow* window;
public:
	FruitPainter(RenderWindow* win, Fruit* fruit) { window = win; mFruit = fruit; }
	void paint();
};

class GameOverPainter : public Painter
{
	RenderWindow* window;
public:
	GameOverPainter(RenderWindow* win){ window = win; }
	void paint();
};

