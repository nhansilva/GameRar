#include "Vir_20.h"

CVir_20::CVir_20(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/ground/a.png");
	GSObject = new GSprite(GTObject, 10);
}

CVir_20::~CVir_20()
{

}

