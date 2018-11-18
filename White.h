#pragma once
#include "Object.h"
class CWhite: public CObject
{
	int a = 0;
public:
	virtual void Update(int x, int y);
	virtual void Draw(GCamera *cam);
	CWhite();
	~CWhite();
};