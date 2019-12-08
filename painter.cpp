#include "painter.h"

void BoardPainter::paint()
{
	if (window)
	{
		Sprite sprite(mtexture);
		for (int i = 0; i < mWidth; i++)
		{
			for (int j = 0; j < mHeight; j++)
			{
				sprite.setPosition(i * CELL_SIZE, j * CELL_SIZE);
				window->draw(sprite);
			}
		}
	}
}

void SnakePainter::paint()
{
	if (window)
	{
		Sprite sprite(mtexture);
		for (int i = 0; i <mSize; i++)
		{
			sprite.setPosition(mCord[i].X * CELL_SIZE,mCord[i].Y * CELL_SIZE);
			window->draw(sprite);
		}
	}
}

void FruitPainter::paint()
{
	if (window)
	{
		Sprite sprite(mtexture);
		sprite.setPosition(mCord.X * CELL_SIZE, mCord.Y * CELL_SIZE);
		window->draw(sprite);
	}
}

void GameOverPainter::paint()
{
	Sprite sprite;
	Font font;
	if (font.loadFromFile("Windsong.ttf"))
	{
		Text text;
		text.setFont(font);
		text.setString("Game over!");
		text.setFillColor(Color::Red);
		text.setCharacterSize(80);
		FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
		text.setPosition(Vector2f(ROWS*CELL_SIZE / 2.0f, COLUMBS * CELL_SIZE / 2.0f));
		window->draw(text);
	}
}
