#pragma once
#include "board.h"

class ICordinateValidator
{
public:
	virtual bool isValid(ARRAY<Cordinate> cord, int size)=0;
};

class SnakeCordinateValidator : public ICordinateValidator
{
public:
	bool isValid(ARRAY<Cordinate> cord,int size);
};
