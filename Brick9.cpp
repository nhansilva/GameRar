#include "Brick9.h"

CBrick9::CBrick9(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/ground/9.png", 1, 1, 1);
	GSObject = new GSprite(GTObject, 120);
	//IsFalling = 1;
	Trend = -1;
	max = x1 + 48;
	min = x1 - 16;
	//Vx = 3;
}

CBrick9::~CBrick9()
{

}

Box CBrick9::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(this->x - this->w / 2, this->y + this->h / 2);
	return Box(pos.x, pos.y, this->w, this->h, Vx, -Vy);
}

void CBrick9::Update(int t)
{

		CObject::Update(t);
		this->Vx = 0.16 * Trend;
		x += Vx*t;
		/*if (x < min || x > max)
			Trend = -Trend;*/
		if (x < min) Trend = 1;
		if (x > max) Trend = -1;
}

