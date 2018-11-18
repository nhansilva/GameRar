#pragma once
#include "Object.h"
class CIFire : public CObject
{
private:
	GTexture *GTObject2;
	GSprite *GSObject2;
	int waitingTime, countTime;
public:
	CIFire(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Draw(GCamera *camera);
	virtual void Fall();
	void setCountTime();
	CIFire();
	~CIFire();
};

