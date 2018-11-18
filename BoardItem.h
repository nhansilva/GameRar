#pragma once
#include "IDagger.h"
#include "2Up.h"

class CBoardItem
{
private:
	int x1, y1;
	CIDagger *dagger;
	C2Up *_2up;
	int whichItem;
public:
	void Draw();
	void		setwhichObj(int x1) { whichItem = x1; }
	CBoardItem();
	~CBoardItem();

};
