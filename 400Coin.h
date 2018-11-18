#pragma once
#include "Object.h"
class C400Coin : public CObject
{
public:
	C400Coin(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	~C400Coin();
};