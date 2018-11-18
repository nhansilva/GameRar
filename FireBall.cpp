#include "FireBall.h"

CFireBall::CFireBall()
{
	TypeWeapon = 3;
	GTObject = new GTexture(FIREBALL_IMAGE_FILE);
	GSObject = new GSprite(GTObject, 0);
	Trend = -1;
}

CFireBall::~CFireBall()
{
}

void CFireBall::Update(GCamera *camera, int t)
{
	GSObject->Update(t);
	x += Vx;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (pos.x > G_ScreenWidth - 30 || pos.x < 0) IsFinish = 1;
}

void CFireBall::Create(float sm_x, float sm_y, int sm_trend)
{
	Weapon::Create(sm_x, sm_y + 16, sm_trend);
	Vx = FIREBALL_VX*Trend;
}
