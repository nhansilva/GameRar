#ifndef _FIREBALL_H_
#define _FIREBALL_H_

#include "Weapon.h"

#define FIREBALL_IMAGE_FILE "Resources/fireball.png"
#define FIREBALL_VX 8

class CFireBall : public Weapon
{
public:
	CFireBall();
	~CFireBall();
	virtual void Update(GCamera *camera, int t);
	virtual void Create(float fm_x, float fm_y, int fm_trend);
};
#endif

