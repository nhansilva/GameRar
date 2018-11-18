#include "Ghost.h"

CGhost::CGhost(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/enemy/1.png", 2, 1, 2);
	GSObject = new GSprite(GTObject, 120);
	IsFalling = 1;
	Trend = -1;
}

CGhost::~CGhost()
{

}

Box CGhost::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(this->x - this->w / 2, this->y + this->h / 2);
	return Box(pos.x, pos.y, this->w, this->h, Vx, -Vy);
}

void CGhost::Update(int t)
{
	if (IsFalling == 1)
	{	
		y += Vy;
		Vy = Vy - GHOST_GRAVITY;
	}
	else
	{
		//CObject::Update(t);
		this->Vx = 0.18 * Trend;
		x += Vx * t;
		if (x < 0|| x > 3072 && x < 4112)
			Trend = 1;
	}
}

void CGhost::Draw(GCamera * cam)
{
	D3DXVECTOR2 pos = cam->Transform(x, y);
	if(Trend == -1) GSObject->DrawFromCenter(pos.x, pos.y);
	if (Trend == 1) GSObject ->DrawFlipX(pos.x, pos.y);
}

void CGhost::Go(){
	if (IsJumping == 1 || IsFalling == 1) return;
	CObject::Go();
}

void CGhost::StopFall(float y) {
	IsFalling = 0;
	this->Go();
	Vy = -1;
}