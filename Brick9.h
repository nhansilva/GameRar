#pragma once
#include "Object.h"
class CBrick9 : public CObject
{
public:
	CBrick9(int x, int y, int w, int h);
	int max, min;
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	~CBrick9();
};