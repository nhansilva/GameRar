#pragma once
#include "Object.h"
class CBrick3 : public CObject
{

public:
	int brickbreak;
	CBrick3(int x, int y, int w, int h);
	virtual void Update(int t);
	virtual Box GetBox(GCamera *camera);
	~CBrick3();
};