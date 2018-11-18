#include "Dog.h"

CDog::CDog(int x1, int y1, int h1, int w1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/enemy/2.png", 4, 1, 4);
	GSObject = new GSprite(GTObject, 120);
	Vx = Vy = 0;
	Trend = -1;
	timeFall = 0;
}

CDog::~CDog()
{

}

void CDog::Fall(){

	if (IsJumping == 1 && IsFalling == 0)
	{
		if (IsFalling == 0)
		{
			Vy = -PANTHER_FALL;
			GSObject->SelectIndex(PANTHER_FALL_IMAGE);
			CObject::Fall();
		}
	}
}
void CDog::Jump(){
	if (IsJumping == 0 && IsFalling == 0)
	{
		if (IsJumping == 0)
		{
			Vy = PANTHER_FALL;
			CObject::Jump();
		}
	}
}

void CDog::Go(){
	CObject::Go();
	Vx = PANTHER_VX*Trend;
}

void CDog::StopFall(float y){
	IsFalling = 0;
	this->y = y + h / 2;
	if (IsGoing == 1) this->Go(); else this->StandUp();
	Vy = 0;
}

void CDog::Update(int t){
	if (IsJumping == 1)
	{
		Vx *= IsGoing;
		y += Vy;
		x += Vx * t;
		Vy = Vy - PANTHER_GRAVITY;
		GSObject->SelectIndex(PANTHER_FALL_IMAGE);
		if (Vy <= 0)
		{
			this->Fall();
		}
	}
	else
	if (IsFalling == 1)
	{
		Vx *= IsGoing;
		x += Vx * t;
		y += Vy;
		Vy = Vy - PANTHER_GRAVITY;
		GSObject->SelectIndex(PANTHER_FALL_IMAGE);
	}
	else
	if (IsGoing == 1)
	{
		x += Vx * t;
		timeFall += Vx * t;
		//GSObject->Update(t);
		if (GSObject->_index == 0) GSObject->_index++;
	}
	else GSObject->SelectIndex(PANTHER_STOP_IMAGE);
}

void CDog::Draw(GCamera * cam)
{
	D3DXVECTOR2 pos = cam->Transform(x, y);
	if (Trend == -1)GSObject->DrawFromCenter(pos.x, pos.y);
	else GSObject->DrawFlipX(pos.x, pos.y);
}