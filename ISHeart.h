#pragma once
#include "Object.h"
class CSHeart : public CObject
{
	int x2;
public:
	CSHeart(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	virtual void setx(float x1) { x = x1; x2 = x1; }
	~CSHeart();
};