#include "Board.h"

CBoard::CBoard()
{
	GTObject = new GTexture("./Resources/blackboard.png");
	GSObject = new GSprite(GTObject, 100);
}

CBoard::~CBoard()
{
	delete GTObject;
	delete GSObject;
}

void CBoard::Draw()
{
	GSObject->DrawFromTL(2, 10);
}