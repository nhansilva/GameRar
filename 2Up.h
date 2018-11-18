#pragma once
#include "Object.h"
class C2Up : public CObject
{
public:
	C2Up(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	~C2Up();
};