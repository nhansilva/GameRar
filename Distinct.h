#include "Brick.h"
#include "LCandle.h"
#include "Dog.h"
#include "Ghost.h"
#include "MCandle.h"
#include "Sweet_AABB.h"
#include "Vir_20.h"
#include "Door.h"
#include "CStair.h"
#include "Brick2.h"
#include "Brick1.h"
#include "Brick9.h"
#include "Trap.h"
#include "Simon.h"
#include "Brick3.h"
#pragma once
class CDistinct
{
private:
	int whichObj;	 //Phân biệt obj
public:
	int			getwhichObj() { return whichObj; }
	void		setwhichObj(int x1) { whichObj = x1; }
	CBrick * brick;
	CLCandle *lcandle;
	CMCandle *mcandle;
	CDog *dog;
	CGhost *ghost;
	CVir_20 *vir_20;
	CDoor * door;
	CStair *stair;
	CBrick2 *brick2;
	CBrick9 *brick9;
	CTrap *trap;
	CBrick1 *brick1;
	CBrick3 *brick3;
	//Tiền updated
	bool coliDog;
	bool coliBrick;
	bool endEffect;
	bool enemyDie;
	////////////////////
	CDistinct(int io, int x1, int y1, int w1, int h1);
	void Draw(GCamera * cam);
	void Update(GCamera *camera, int t);
	~CDistinct();
	int			getObjX();
	int			getObjY();
	int			getObjW();
	int			getObjH();
	int			getIsDie();

	void		setX(int a);

	void		setIsDie(bool a);

	virtual void Fall();
	virtual void StopFall(float a);
	virtual void Jump();
	virtual void Go();

	virtual Box GetBox(GCamera *camera);
	////////////////////////(Tiền update)
	void  moveRigh();
	int getIsGoing();
	int getTimeFall();
	int getIsJumping();
	int getIsFalling();
	//dùng cho cầu thang.
	void		settrend(int trend);
	int         gettrend();

	//Hàm mang tính cá nhân
	void		breakBrick();
	int getBreakBrick();
	void GetSMPositionForBoss(float x);
	void GetSMPositionForBoss(float x, float y, int Trend);

	void SetHurt(int i);
	int GetHurt();

	float getVx();
};
