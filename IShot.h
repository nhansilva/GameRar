#pragma once
#include "Object.h"
class CIShot : public CObject
{
public:
	CIShot(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	~CIShot();
};