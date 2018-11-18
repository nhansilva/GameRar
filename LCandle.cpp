#include "LCandle.h"

CLCandle::CLCandle(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/ground/0.png", 2, 1, 2);
	GSObject = new GSprite(GTObject, 100);
}

CLCandle::~CLCandle()
{

}

