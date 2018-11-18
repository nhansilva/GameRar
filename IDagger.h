#pragma once
#pragma once
#include "Object.h"
class CIDagger : public CObject
{
public:
	CIDagger(int x, int y, int w, int h);
	virtual Box GetBox(GCamera *camera);
	virtual  void Update(int t);
	void Draw2();
	~CIDagger();
};