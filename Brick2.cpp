#include "Brick2.h"

CBrick2::CBrick2(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/ground/29.png", 3, 1, 3);
	GSObject = new GSprite(GTObject, 100);
	brickbreak = 0;
}
void CBrick2::Update(int t)
{
	if (brickbreak == 0)
	{
		GSObject->SelectIndex(0);
	}
	if (brickbreak == 4)
	{
		GSObject->SelectIndex(1);
	}
	if (brickbreak >= 8)
	{
		this->setIsDie(1);
		GSObject->SelectIndex(2);
	}
}
CBrick2::~CBrick2()
{

}
Box CBrick2::GetBox(GCamera *camera)
{
	if (this->getIsDie() == 1) return Box(0, 0, 0, 0, 0, 0);
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}
