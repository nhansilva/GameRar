#pragma once
#include "Object.h"
class CBrick1 : public CObject
{

public:
	int brickbreak;
	CBrick1(int x, int y, int w, int h);
	virtual void Update(int t);
	virtual Box GetBox(GCamera *camera);
	~CBrick1();
};