#include<memory>
#include"board.h"
#include "movemanager.h"
#include "painter.h"
#include "movevalidator.h"

int main()
{
	srand(time(0));
	std::unique_ptr<Board> board = std::make_unique<Board>();
	std::unique_ptr<Snake> snake = std::make_unique<Snake>();
	std::unique_ptr<Fruit> fruit = std::make_unique<Fruit>();
	RenderWindow window(VideoMode(board->mWidth, board->mHeight), "Snake Game!");
	std::unique_ptr<Painter> boardPainter = std::make_unique<BoardPainter>(&window, board.get());
	std::unique_ptr<Painter> snakePainter = std::make_unique<SnakePainter>(&window, snake.get());
	std::unique_ptr<Painter> fruitPainter = std::make_unique<FruitPainter>(&window, fruit.get());
	std::unique_ptr<Painter> gameOverPainter = std::make_unique<GameOverPainter>(&window);
	std::unique_ptr<MoveValidator> snakeMoveValidator = std::make_unique<SnakeMoveValidator>();

	MoveManager::init(snake.get(), fruit.get());
	MoveManager::startProcess();
	
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}
		MoveManager::processMove(e);
		if (snakeMoveValidator->validate(MoveManager::mSnakeCord, MoveManager::mSnake->mLength))
		{
			gameOverPainter->paint();
			window.clear();
			window.display();
			sleep(Time(seconds(1)));
			break;
		}
		//draw
		window.clear();
	    //paint board
		if(boardPainter)
		boardPainter->paint();
		//paint snake
		if(snakePainter)
		snakePainter->paint();
		//paint fruit
		if(fruitPainter)
		fruitPainter->paint();
		
		window.display();
	}
	MoveManager::stopProcess();
	return 0;
}
