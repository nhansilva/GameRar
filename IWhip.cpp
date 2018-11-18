#include "IWhip.h"

CIWhip::CIWhip(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/item/3.png");
	GSObject = new GSprite(GTObject);
	Vy = 0.06;
}

CIWhip::~CIWhip()
{

}
Box CIWhip::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}

void CIWhip::Update(int t)
{

}


void CIWhip::Draw2()
{
	GSObject->DrawFromTL(x, y);
}