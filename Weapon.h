#ifndef _WEAPON_H_
#define _WEAPON_H_

#include "GSprite.h"
#include "GCamera.h"
#include "Sweet_AABB.h"

class Weapon
{
protected:
	float Vx;	// Vận tốc theo trục X
	float Vy;	// Vận tốc theo trục Y
	int Trend;		// Phương hướng, trái = -1, phải = 1;
	int IsFinish;
	int TypeWeapon;

public:
	float x;	// Vị trí theo trục X
	float y;	// Vị trí theo trục Y#pragma once
	Weapon();
	~Weapon();							// Hàm hủy Weapon

	GTexture *GTObject;
	GSprite *GSObject;

	int GetTrend();
	void SetTrend(int a);

	virtual void Create(float sm_x, float sm_y, int sm_trend);
	virtual void Update(GCamera*camera, int t);
	virtual Box GetBox(GCamera *camera);
	virtual void Draw(GCamera *camera);
	virtual void SetXY(float x, float y);
	virtual int GetFinish();
	virtual int getcurentFrame();
	virtual void SetTypeMorningStar(int i = -1);
	int IsFalling; //Dùng trong con rắn medusa
	int GetType();
	virtual void Boom();//Dùng để nổ bom khi quăng chai nước
};

#endif
