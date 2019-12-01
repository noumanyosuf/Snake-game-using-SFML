#include "movevalidator.h"
#include "board.h"

bool SnakeMoveValidator::validate(Cordinate* cord, int size)
{
	bool bStatus = false;
	if (size >= 1)
	{
		for (int i = 1; i < size; i++)
		{

			if (cord[0].X == cord[i].X && cord[0].Y == cord[i].Y)
			{
				bStatus = true;
				break;
			}
		}
	}
	else
	{
		bStatus = true;
	}
	return bStatus;
}
