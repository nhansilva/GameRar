#pragma once
#include "Object.h"
class CIWhip : public CObject
{
public:
	CIWhip(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	void Draw2();
	~CIWhip();
};