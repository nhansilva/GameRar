#include "IFire.h"

CIFire::CIFire(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	GTObject = new GTexture("./Resources/other/1.png",3,1,3);
	GSObject = new GSprite(GTObject, 100);
	GTObject2 = new GTexture("./Resources/other/0.png", 1, 1, 1);
	GSObject2 = new GSprite(GTObject2, 100);
	Vy = 0.06;
	countTime = 0;
}

CIFire::~CIFire()
{

}
Box CIFire::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - w / 2, y + h / 2);
	return Box(pos.x, pos.y, w, h, 0, 0);
}

void CIFire::Draw(GCamera * cam)
{
	D3DXVECTOR2 pos = cam->Transform(x, y);
	GSObject->DrawFromCenter(pos.x, pos.y);
	waitingTime++;
	if (waitingTime <1){
		GSObject2->DrawFromCenter(pos.x - 2, pos.y);
	}
	//V? ng?n l?a nhi?u v? trí khi mà dánh ch?t  con boss c?a 2 màn
	if (countTime > 0){
		GSObject->DrawFromCenter(pos.x - GTObject->FrameWidth / 2, pos.y);
		GSObject->DrawFromCenter(pos.x + GTObject->FrameWidth / 2, pos.y);
	}
	if (waitingTime > 10){
		if (countTime > 0){
			if (waitingTime > 40){
				this->setIsDie(1);
				countTime = 0;
			}
		}
		else
			this->setIsDie(1);
	}	
}

void CIFire::Fall(){

}

void CIFire::setCountTime(){
	countTime++;
}
