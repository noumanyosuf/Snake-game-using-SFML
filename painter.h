#pragma once
#include <SFML/Graphics.hpp>
#include "board.h"

class IPainter
{
public:
	virtual void paint() = 0;
};

class BoardPainter : public IPainter
{
	RenderWindow* window;
	Texture mtexture;
	int mWidth;
	int mHeight;
public:
	BoardPainter(RenderWindow* win,int width,int height,Texture texture) 
	{
		window = win; mtexture = texture; mWidth = width; mHeight = height;
	}
	void paint();
};

class SnakePainter : public IPainter
{
	RenderWindow* window;
	Texture mtexture;
public:
	ARRAY<Cordinate> mCord;
	int mSize;
	SnakePainter(RenderWindow* win, Texture texture)
	{
		window = win;  mtexture = texture; mSize = 0;
	}
	void paint();
};

class FruitPainter : public IPainter
{
	RenderWindow* window;
	Texture mtexture;
public:
	Cordinate mCord;
	FruitPainter(RenderWindow* win, Texture texture)
	{
		window = win; mtexture = texture;
	}
	void paint();
};

class GameOverPainter : public IPainter
{
	RenderWindow* window;
public:
	GameOverPainter(RenderWindow* win)
	{
		window = win;
	}
	void paint();
};