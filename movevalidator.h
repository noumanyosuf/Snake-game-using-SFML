#pragma once
class Cordinate;

class MoveValidator
{
public:
	virtual bool validate(Cordinate* cord, int size)=0;
};

class SnakeMoveValidator : public MoveValidator
{
public:
	bool validate(Cordinate *cord,int size);
};
