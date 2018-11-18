#include"Whip.h"

CWhip::CWhip()
{
	typeWhip = 1;
	GTObject = new GTexture(MORNINGSTAR_IMAGE, 4, 3, 12);
	GSObject = new GSprite(GTObject, MORNINGSTAR_FRAME);
	TypeWeapon = 1;
	timeAtk = 0;
}

CWhip::~CWhip()
{
}
void CWhip::Draw(GCamera *cam)
{
	if (GSObject->_index == 2 || GSObject->_index == 6 || GSObject->_index == 10){
		timeAtk++;
	}
	int color = rand() % 255;
	GSObject->SetARGB(255, rand() % 255, color, color / 2);
	D3DXVECTOR2 pos = cam->Transform(x, y);
	if (Trend == -1) GSObject->DrawFromCenter(pos.x, pos.y);
	else GSObject->DrawFlipX(pos.x, pos.y);
}
void CWhip::Update(GCamera*camera, int t)
{
	GSObject->Update(t);
	IsFinish = (GSObject->_index == 3) + (GSObject->_index == 7) + (GSObject->_index == 11);
	if (IsFinish)
		timeAtk = 0;
}

void CWhip::Create(float MorX, float MorY, int MorTrend)
{
	Weapon::Create(MorX, MorY, MorTrend);
	GSObject->_index = typeWhip * 4 - 4;
}

void CWhip::SetXY(float simon_x, float simon_y){
	x = simon_x + 30 * Trend;
	y = simon_y;
}

int CWhip::getcurentFrame()
{
	return GSObject->_index;
}

Box CWhip::GetBox(GCamera *camera)
{
	if ((GSObject->_index != 2 && GSObject->_index != 6 && GSObject->_index != 10) || timeAtk < 2)
		return Box(0, 0, 0, 0, 0, 0);
	int w1 = 0;
	if (typeWhip == 1)
	{
		w1 = GTObject->FrameWidth - 95;
	}
	else
	{
		if (typeWhip == 2)
		{
			w1 = GTObject->FrameWidth - 100;
		}
		else
		{
			w1 = GTObject->FrameWidth - 70;
		}
	}
	if (Trend == 1)  //  --->
	{
		D3DXVECTOR2 pos = camera->Transform(x - GTObject->FrameWidth / 2 + 64, y + GTObject->FrameHeight / 2 - 16);
		return Box(pos.x, pos.y, w1, GTObject->FrameHeight - 50, Vx, -Vy);
	}
	if (Trend == -1)  //  <---
	{
		D3DXVECTOR2 pos = camera->Transform(x - GTObject->FrameWidth / 2 + 39, y + GTObject->FrameHeight / 2 - 16);
		return Box(pos.x, pos.y, w1, GTObject->FrameHeight - 50, Vx, -Vy);
	}
	return Box(0, 0, 0, 0, 0, 0);
}

void CWhip::SetTypeMorningStar(int i)
{
	if (i == -1)
	{
		if (typeWhip < 3) typeWhip++;
		return;
	}
	typeWhip = i;
}