#pragma once
#include "Object.h"
class CLHeart : public CObject
{
public:
	CLHeart(int x, int y, int w, int h);
	virtual void Update(int t);
	virtual Box GetBox(GCamera *camera);
	~CLHeart();
};