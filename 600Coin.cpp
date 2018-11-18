#include "600Coin.h"

C600Coin::C600Coin(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/item/2.png", 3, 1, 3);
	GSObject = new GSprite(GTObject);
	Vy = 0.06;
}

C600Coin::~C600Coin()
{

}
Box C600Coin::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}

void C600Coin::Update(int t)
{
	if (IsFalling == 1)
	{
		Vy = Vy - 0.012;
		y += Vy*t;
	}
}