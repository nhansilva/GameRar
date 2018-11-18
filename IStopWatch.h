#pragma once
#include "Object.h"
class CIStopWatch : public CObject
{
public:
	CIStopWatch(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	~CIStopWatch();
};