#pragma once
#include "Object.h"
#define PANTHER_STOP_IMAGE 0
#define PANTHER_FALL_IMAGE 3

#define PANTHER_VX 0.43

#define PANTHER_GRAVITY 2
#define PANTHER_FALL 9
class CDog : public CObject
{
public:
	CDog(int x, int y, int h, int w);
	virtual void Fall();
	virtual void Go();
	virtual void Jump();
	virtual void StopFall(float y);
	virtual void Update(int t);
	void Draw(GCamera * cam);
	int timeFall;
	~CDog();
};