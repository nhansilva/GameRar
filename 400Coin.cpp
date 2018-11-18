#include "400Coin.h"

C400Coin::C400Coin(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/item/2.png",3,1,3);
	GSObject = new GSprite(GTObject);
	Vy = 0.06;
}

C400Coin::~C400Coin()
{

}
Box C400Coin::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}

void C400Coin::Update(int t)
{
	if (IsFalling == 1)
	{
		Vy = Vy - 0.012;
		y += Vy*t;
	}
}