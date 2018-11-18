#include "Play.h"

CPlay::CPlay()
{
	GTObject = new GTexture("./Resources/Play.png", 2, 1, 2);
	GSObject = new GSprite(GTObject, 200);
}
CPlay::~CPlay()
{
}

void CPlay::Draw()
{
	GSObject->DrawFromCenter(G_ScreenWidth/2, 250);
}

void CPlay::Update(int t)
{
	GSObject->Update(t);
}

void CPlay::Set()
{
	GSObject->SelectIndex(0);
}