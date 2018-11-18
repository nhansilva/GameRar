#pragma once
#include "Object.h"
#define GHOST_GRAVITY 1
class CGhost : public CObject
{
public:
	CGhost(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	virtual void Draw(GCamera * cam);
	virtual void StopFall(float y);
	virtual void Go();
	~CGhost();
};