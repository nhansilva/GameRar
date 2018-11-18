#include "Brick.h"

CBrick::CBrick(int x1, int y1 , int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/ground/g.png");
	GSObject = new GSprite(GTObject);
}

CBrick::~CBrick()
{

}
