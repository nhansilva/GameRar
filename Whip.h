#ifndef _WHIP_H_
#define _WHIP_H_
#define MORNINGSTAR_IMAGE "./Resources/weapon/morningstar.png"
#define MORNINGSTAR_FRAME 70

#include <d3dx9.h>
#include "GSprite.h"
#include "Weapon.h"
#include "Simon.h"
class CWhip :public Weapon
{
	int typeWhip, timeAtk;
protected:

public:
	CWhip();
	~CWhip();
	virtual void Update(GCamera*camera, int t);
	virtual void Create(float MorX, float MorY, int MorTrend);
	virtual void  Draw(GCamera *cam);
	virtual void SetXY(float simon_x, float simon_y);
	virtual Box GetBox(GCamera *camera);
	virtual int getcurentFrame();
	//Tiền updated
	virtual void SetTypeMorningStar(int i = -1);
};

#endif