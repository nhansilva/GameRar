#ifndef _STAIR_H_
#define _STAIR_H_
#include"GSprite.h"
#include "Object.h"

class CStair : public CObject
{
public:
	void Draw(GCamera * cam);
	CStair(int x1, int y1, int w1, int h1);
	~CStair();
};
#endif