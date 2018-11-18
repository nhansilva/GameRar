#pragma once
#include "Object.h"
class CIGoldPotion : public CObject
{
public:
	CIGoldPotion(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual void Update(int t);
	~CIGoldPotion();
};