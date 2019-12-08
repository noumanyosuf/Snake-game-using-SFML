#include "gamemanager.h"
#include <iostream>

void GameManager::updateBoard()
{
	updateSnake();
	updateFruit();
	//udpdate snake cord if reaches window's edge
	if (board->mSnakeCord[0].X > ROWS) board->mSnakeCord[0].X = 0;
	if (board->mSnakeCord[0].X < 0) board->mSnakeCord[0].X = ROWS;
	if (board->mSnakeCord[0].Y > COLUMBS) board->mSnakeCord[0].Y = 0;
	if (board->mSnakeCord[0].Y < 0) board->mSnakeCord[0].Y = COLUMBS;
}

void GameManager::updateSnake()
{
	board->mSnakeCord = snakeMoveGenerator->getNextMove(board->mSnakeCord, board->mSnake.mLength, board->mSnakeMoveDir);
	//increment snake body
	for (int i = board->mSnake.mLength; i > 0; --i)
	{
		board->mSnakeCord[i].X = board->mSnakeCord[i - 1].X;
		board->mSnakeCord[i].Y = board->mSnakeCord[i - 1].Y;
	}
	switch (board->mSnakeMoveDir)
	{
	case enDown:
		board->mSnakeCord[0].Y += 1;
		break;
	case enLeft:
		board->mSnakeCord[0].X -= 1;
		break;
	case enRight:
		board->mSnakeCord[0].X += 1;
		break;
	case enUp:
		board->mSnakeCord[0].Y -= 1;
		break;
	default:
		break;
	}
}

void GameManager::updateFruit()
{
	//update fruit cordinate if snake gets the fruit
	if ((board->mSnakeCord[0].X == board->mFruitCord.X) && (board->mSnakeCord[0].Y == board->mFruitCord.Y))
	{
		std::cout << "touched" << std::endl;
		board->mSnake.mLength++;
		ARRAY<Cordinate> t;
		t[0] = board->mFruitCord;
		board->mFruitCord = (fruitMoveGenerator->getNextMove(t))[0];
	}
}

GameManager::GameManager()
{
	mTimer = 0.0; 
	mDelay = 0.5; 
	mbIsClockRunning = false;
	board = std::make_unique<Board>();
	window.create(VideoMode(board->mWidth, board->mHeight), "Snake Game!");
	boardPainter = std::make_unique<BoardPainter>(&window, board->mWidth, board->mHeight, board->mCellColor);
	snakePainter = std::make_unique<SnakePainter>(&window, board->mSnake.mColor);
	fruitPainter = std::make_unique<FruitPainter>(&window, board->mFruit.mColor);
	gameOverPainter = std::make_unique<GameOverPainter>(&window);
	snakeCordinateValidator = std::make_unique<SnakeCordinateValidator>();
	snakeMoveGenerator = std::make_unique<SnakeMoveGenerator>();
	fruitMoveGenerator = std::make_unique<FruitMoveGenerator>();
	
	ARRAY<Cordinate> t;
	t[0] = board->mFruitCord;
	board->mFruitCord = (fruitMoveGenerator->getNextMove(t))[0];
}

void GameManager::start()
{
	srand(time(0));

	while (window.isOpen())
	{
		float time = mClock.getElapsedTime().asSeconds();
		mClock.restart();
		mTimer += time;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed) 
			{
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			board->mSnakeMoveDir = enLeft;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			board->mSnakeMoveDir = enRight;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			board->mSnakeMoveDir = enUp;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			board->mSnakeMoveDir = enDown;
		}

		/*if (snakeCordinateValidator->isValid(board->mSnakeCord, board->mSnake.mLength))
		{
			gameOverPainter->paint();
			window.clear();
			window.display();
			sleep(Time(seconds(2)));
			break;
		}*/
		//draw
		window.clear();

		//paint board
		if (boardPainter)
		{
			boardPainter->paint();
		}
		//paint snake
		if (snakePainter) {
			snakePainter->mCord = board->mSnakeCord;
			snakePainter->mSize = board->mSnake.mLength;
			snakePainter->paint();
		}
		//paint fruit
		if (fruitPainter) {
			fruitPainter->mCord = board->mFruitCord;
			fruitPainter->paint();
		}

		window.display();

		if (mTimer > mDelay) { mTimer = 0; updateBoard(); }

	}
}
