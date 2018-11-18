#include "Object.h"

CObject::CObject()
{
	
}
CObject::CObject(float x1, float y1, int w1, int h1)
{
	this->x = x1;
	this->y = y1;
	this->w = w1;
	this->h = h1;
}
CObject::~CObject()
{

}

void CObject::Draw(GCamera * cam)
{
	D3DXVECTOR2 pos = cam->Transform(x, y);
	GSObject->DrawFromCenter(pos.x, pos.y);
}


void CObject::Update(int t)
{
	GSObject->Update(t);
}

void CObject::StopFall(float y)
{
	IsFalling = 0;
}
Box CObject::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - GTObject->FrameWidth / 2, y + GTObject->FrameHeight / 2);
	return Box(pos.x, pos.y, GTObject->FrameWidth, GTObject->FrameHeight, Vx, -Vy);
}

void CObject::MoveLeft()
{
	if (IsFalling || IsJumping) return;
	if (IsAttacking == 1) return;
	Trend = -1;
}

void CObject::MoveRigh()
{
	if (IsFalling || IsJumping) return;
	if (IsAttacking == 1) return;
	Trend = 1;
}

void CObject::Stop()
{
	IsGoing = 0;
	Vx = 0;
}

void CObject::Sit()
{
	IsSitting = 1;
	IsFalling = 0;
	IsJumping = 0;
	IsGoing = 0;
}

void CObject::StandUp()
{
	IsSitting = 0;
	IsFalling = 0;
	IsJumping = 0;
	IsGoing = 0;
}

void CObject::Fall()
{
	IsFalling = 1;
	IsJumping = 0;
	IsSitting = 0;
	EndHurt = 1;
}
void CObject::Jump()
{
	IsJumping = 1;
	IsFalling = 0;
	IsSitting = 0;
}
void CObject::Go()
{
	IsSitting = 0;
	IsFalling = 0;
	IsJumping = 0;
	IsGoing = 1;
}

float CObject::GetVx()
{
	if (IsAttacking == 1) return 0;
	if (IsGoing == 1) return Vx;
	return 0;
}

float CObject::GetVy()
{
	if (IsAttacking == 1) return 0;
	if (IsFalling == 1 || IsJumping == 1) return Vy;
	return 0;
}
//////////////////////////////////
//Tiền updated
void CObject::Attack(Weapon *weapon)
{
	IsAttacking = 1;
	if (weapon) weapon->Create(x, y, Trend);
}
int CObject::GetHurt()
{
	if (IsHurting) return 1;
	return 0;
}

void CObject::SetAnimation(float Vx, float Vy, int Frame)
{
	this->Vx = Vx*Trend;
	this->Vy = Vy;
	this->GSObject->_timeAni = Frame;
}
void CObject::SetHurt(int i)
{
	IsHurting = i;
}
int CObject::CreateWeapon(){
	return 0;
}
void CObject::GetSMPositionForBoss(float x, float y, int Trend)
{
}