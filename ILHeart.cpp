#include "ILHeart.h"

CLHeart::CLHeart(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/item/1.png");
	GSObject = new GSprite(GTObject);
	Vy = 0.06;
}

CLHeart::~CLHeart()
{

}
Box CLHeart::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}

void CLHeart::Update(int t)
{
	
}