#pragma once
#include"GSprite.h"

class CBlood
{
	GTexture* GTObject;
	GSprite* GSObject;
public:
	CBlood();
	~CBlood();
	void DrawBloodSimon(int i);
	void DrawBloodEnemy(int i);
	void DrawBlood();
};