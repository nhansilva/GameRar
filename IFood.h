#pragma once
#include "Object.h"
class CFood : public CObject
{
public:
	CFood(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	~CFood();
};