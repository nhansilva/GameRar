#pragma once
#include "Object.h"
class C600Coin : public CObject
{
public:
	C600Coin(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	~C600Coin();
};