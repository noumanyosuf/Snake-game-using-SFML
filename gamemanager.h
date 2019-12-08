#pragma once

#include<memory>
#include"board.h"
#include "cordinatevalidator.h"
#include"painter.h"
#include "movegenerator.h"

class GameManager
{
	Clock mClock;
	float mTimer;
	float mDelay;
	bool mbIsClockRunning;

	std::unique_ptr<Board> board;
	RenderWindow window;
	std::unique_ptr<IPainter> boardPainter;
	std::unique_ptr<SnakePainter> snakePainter;
	std::unique_ptr<FruitPainter> fruitPainter;
	std::unique_ptr<IPainter> gameOverPainter;
	std::unique_ptr<ICordinateValidator> snakeCordinateValidator;
	std::unique_ptr<IMoveGenerator> snakeMoveGenerator;
	std::unique_ptr<IMoveGenerator> fruitMoveGenerator;
	void updateBoard();
	void updateSnake();
	void updateFruit();
public:
	GameManager();
	void start();
};

