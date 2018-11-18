#include "GCamera.h"
#include "ILHeart.h"
#include "ISHeart.h"
#include "IFood.h"
#include "IDagger.h"
#include "IWhip.h"
#include "400Coin.h"
#include "600Coin.h"
#include "IFire.h"
#include "2Up.h"
#pragma once
class CItems
{
private:
	int whichItem;	 //Phân biệt items
	CLHeart *lheart;
	CSHeart *sheart;
	CFood *food;
	CIDagger *dagger;
	CIWhip *whip;
	C400Coin *_400coin;
	C600Coin *_600coin;
	CIFire *fire;
	C2Up *_2up;

	int timeDie = 0;
public:
	int			getwhichObj() { return whichItem; }
	void		setwhichObj(int x1) { whichItem = x1; }

	void Draw(GCamera * cam);
	Box GetBox(GCamera *camera);
	void Update(int t);
	void StopFall();
	void Fall();
	void setFireDie(int a);
	void setXFire(int a);
	void setYFire(int a);

	CItems(int io, int x1, int y1);

	int			getIsDie();
	void		setIsDie(bool a);
	void		setX(int a);
	void        setY(int a);
	void setCountTime();
	~CItems();

};
