#include "Brick3.h"

CBrick3::CBrick3(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/ground/29-2.png", 2, 1, 2);
	GSObject = new GSprite(GTObject, 100);
	brickbreak = 0;
}
void CBrick3::Update(int t)
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
CBrick3::~CBrick3()
{

}
Box CBrick3::GetBox(GCamera *camera)
{
	if (this->getIsDie() == 1) return Box(0, 0, 0, 0, 0, 0);
	D3DXVECTOR2 pos = camera->Transform(x - w / 2 -6, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}
