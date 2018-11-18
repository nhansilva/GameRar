#include "Brick1.h"

CBrick1::CBrick1(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/ground/29-1.png", 2, 1, 2);
	GSObject = new GSprite(GTObject, 100);
	brickbreak = 0;
}
void CBrick1::Update(int t)
{
	if (brickbreak == 0)
	{
		GSObject->SelectIndex(0);
	}
	if (brickbreak == 4)
	{
		this->setIsDie(1);
		GSObject->SelectIndex(1);
	}
}
CBrick1::~CBrick1()
{

}
Box CBrick1::GetBox(GCamera *camera)
{
	if (this->getIsDie() == 1) return Box(0, 0, 0, 0, 0, 0);
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}
