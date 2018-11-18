#pragma once
#include "Object.h"
class CBrick2 : public CObject
{

public:
	int brickbreak;
	CBrick2(int x, int y, int w, int h);
	virtual void Update(int t);
	virtual Box GetBox(GCamera *camera);
	~CBrick2();
};