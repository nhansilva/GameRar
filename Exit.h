#ifndef _CExit_H
#define _CExit_H
#pragma once
#include"GSprite.h"
#include "Object.h"

class CExit
{
private:
	GTexture *GTObject;
	GSprite *GSObject;
public:
	CExit();
	~CExit();
	void Draw();
	void Update(int t);
	void Set();
};

#endif