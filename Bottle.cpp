//#include "Bottle.h"
//
//CBottle::CBottle()
//{
//	TypeWeapon = 6;
//	GTObject = new GTexture(BOTTLE_IMAGE_FILE, 3, 1, 3);
//	GSObject = new GSprite(GTObject, BOTTLE_FRAME);
//	Trend = 1;
//}
//
//CBottle::~CBottle()
//{
//}
//
//void CBottle::Update(GCamera *camera, int t)
//{
//	x += Vx;
//	y += Vy;
//	Vy -= BOTTLE_GRAVITY;
//	if (IsBoom == 0)
//	{
//		GSObject->SelectIndex(0);
//	}
//	else
//	{
//		Vy = 0;
//		Vx = 0;
//		WaitingTime += t;
//		if (WaitingTime > 100)
//		{
//			GSObject->Update(t);
//			if (GSObject->_index == 0) GSObject->SelectIndex(1);//Khi nổ thì bỏ qua frame đầu tiên
//			if (WaitingTime > 700) IsFinish = 1;
//		}
//	}
//}
//
//void CBottle::Create(float sm_x, float sm_y, int sm_trend)
//{
//	Weapon::Create(sm_x, sm_y, sm_trend);
//	Vx = BOTTLE_VX*Trend;
//	Vy = BOTTLE_VY;
//	IsBoom = 0;
//	WaitingTime = 0;
//}
//
//void CBottle::Boom()
//{
//	if (Vy < 0) IsBoom = 1;
//}
//
//
//void CBottle::Draw(GCamera *camera)
//{
//	D3DXVECTOR2 pos = camera->Transform(x, y);
//	if (Trend == 1) GSObject->DrawFromCenter(pos.x, pos.y);
//	else GSObject->DrawFlipX(pos.x, pos.y);
//
//	if (GSObject->_index > 0)
//	{
//		GSObject->DrawFromCenter(pos.x - GTObject->FrameWidth / 2, pos.y);
//		GSObject->DrawFromCenter(pos.x + GTObject->FrameWidth / 2, pos.y);
//	}
//}
