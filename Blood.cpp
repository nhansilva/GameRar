#include "Blood.h"
CBlood::CBlood()
{
	GTObject = new GTexture("./Resources/health.png", 3, 1, 3);
	GSObject = new GSprite(GTObject, 100);
}

void CBlood::DrawBloodSimon(int i)
{
	if (i > 16) i = 16;
	GSObject->SelectIndex(0);
	for (int j = 0; j < i; j++)
	{
		GSObject->DrawFromCenter(120 + j * 12, 45);
	}
}

void CBlood::DrawBloodEnemy(int i)
{
	GSObject->SelectIndex(2);
	for (int j = 0; j < i; j++)
	{
		GSObject->DrawFromCenter(120 + j * 12, 75);
	}
}

void CBlood::DrawBlood()
{
	GSObject->SelectIndex(1);
	for (int j = 0; j < 16; j++)
	{
		GSObject->DrawFromCenter(120 + j * 12, 45);
	}
	for (int j = 0; j < 16; j++)
	{
		GSObject->DrawFromCenter(120 + j * 12, 75);
	}
}

CBlood::~CBlood()
{

}