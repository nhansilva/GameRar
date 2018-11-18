#include "White.h"

CWhite::CWhite()
{
	x = 0;
	y = 0;
	h = 0;
	w = 0;
	GTObject = new GTexture("./Resources/1.png");
	GSObject = new GSprite(GTObject);
}

void CWhite::Update(int x, int y)
{
	this->x = x;
	this->y = y;
}

void CWhite::Draw(GCamera *cam)
{
	a++;
	if (a % 2 == 0)
	{
		D3DXVECTOR2 pos = cam->Transform(cam->viewport.x, cam->viewport.y);
		GSObject->DrawFromTL(pos.x, pos.y);
	}
}
CWhite::~CWhite()
{

}
