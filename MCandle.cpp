#include "MCandle.h"

CMCandle::CMCandle(int x1, int y1, int h1, int w1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/ground/1.png", 2, 1, 2);
	GSObject = new GSprite(GTObject, 100);
}

CMCandle::~CMCandle()
{

}

