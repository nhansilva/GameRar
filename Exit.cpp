#include "Exit.h"

CExit::CExit()
{
	GTObject = new GTexture("./Resources/Exit.png", 2, 1, 2);
	GSObject = new GSprite(GTObject, 200);
}
CExit::~CExit()
{
}

void CExit::Draw()
{
	GSObject->DrawFromCenter(G_ScreenWidth / 2, 300);
}

void CExit::Update(int t)
{
	GSObject->Update(t);
}

void CExit::Set()
{
	GSObject->SelectIndex(0);
}