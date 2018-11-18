#include "Sword.h"

CSword::CSword()
{
	TypeWeapon = 7;
	GTObject = new GTexture(SWORD_IMAGE_FILE);
	GSObject = new GSprite(GTObject, 0);
	dx = 0;
}

CSword::~CSword()
{
}

void CSword::Update(GCamera *camera, int t)
{
	GSObject->Update(t);
	x += Vx;
	if (IsFinish == 0)
		dx += Vx;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (dx < -300 || dx > 300){
		IsFinish = 1;
		dx = 0;
	}
}

void CSword::Create(float sm_x, float sm_y, int sm_trend)
{
	Weapon::Create(sm_x + 16, sm_y + 10, sm_trend);
	Vx = SWORD_VX*Trend;
}
