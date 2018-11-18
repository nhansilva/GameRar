#include "Object.h"
#include "Sweet_AABB.h"
#pragma once

#define SIMON_TREND 1
#define SIMON_FRAME 70
#define SIMON_STOP_IMAGE 0
#define SIMON_SIT_IMAGE 4
#define SIMON_ATK_IMAGE 5
#define SIMON_SITATK_IMAGE 15
#define SIMON_HURT_IMAGE 8

#define SIMON_VX_STAIR 0.13
#define SIMON_VY_STAIR 0.13
#define SIMON_VJUMP 12
#define SIMON_GRAVITY 1
#define SIMON_FALL 180
/////////////////////
//Thay thế số 8 trong hàm StopFall( y = y -8)
#define SIMON_Y_STOP_FALL 8
#define SIMON_Y_SIT 15
#define SIMON_VX_GO 0.33

class CSimon: public CObject
{
private:
	float Simon_vx;
	int HTrend;
	bool isOnBrick9;
	float vOnBrick9;
	GTexture *GTObject2;
	GSprite *GSObject2;
	bool isSimonDie= false;
public:
	//Stair
	int IsOnStair;
	int Auto;
	int stairTrend;
	int xStairUp;
	int yStairUp;
	int xStairDown;
	int yStairDown;
	int isUpStair;
	int isDownStair;
	void UpStair();
	int GetOnStair();
	void OutStair();
	void DownStair();
	//stair
	//Tiền updated
	float Vx_Hurt;
	int Prevent;
	int SimonFall = 0;
	void setIndexSimon();
	void Update(GCamera *camera, int t);
	void Draw(GCamera * cam);
	void Draw();
	CSimon(){}
	CSimon(float x, float y, int trend);
	~CSimon();
	virtual Box GetBox(GCamera *camera);
	virtual void StopFall(float y);
	virtual void Stop();
	virtual void Sit();
    virtual void StandUp();
	virtual void Fall();
	virtual void Jump();
	virtual void Go();
	void AutoGoOnBrick9();
	/////////////////(Tiền updated)
	virtual void Attack(Weapon * weapon);
	void Hurt(int HTrend);
	void setSimonDie(bool isdie) { isSimonDie = isdie; };
	bool getisOnbrick9() { return isOnBrick9; };
	void setisOnBrick9(bool a) { isOnBrick9 = a; }
	//int getvOnBrick9() { return vOnBrick9; };
	void setvOnBrick9(float a) { vOnBrick9 = a; };
	//void setxOnBrick9(int a) { xonBrick = a; }
};
