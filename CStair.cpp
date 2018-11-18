#include "CStair.h"
#define SCANDLE_IMAGE_FILE "./Resources/ground/b.png"
CStair::CStair(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture(SCANDLE_IMAGE_FILE, 1, 1, 1);
	GSObject = new GSprite(GTObject, 0);

}
CStair::~CStair()
{

}

void CStair::Draw(GCamera* cam)
{

}