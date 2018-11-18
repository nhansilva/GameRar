#ifndef _SWORD_H_
#define _SWORD_H_
#include "Weapon.h"

#define SWORD_IMAGE_FILE "Resources/weapon/1.png"
#define SWORD_VX 8

class CSword : public Weapon
{
public:
	CSword();
	~CSword();
	int dx;//Khoảng cách để kết thúc dao không cho vẽ
	virtual void Update(GCamera *camera, int t);
	virtual void Create(float sm_x, float sm_y, int sm_trend);
};
#endif