#include "Door.h"


CDoor::CDoor(int x1, int y1, int w1, int h1)
{
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	if (State != 3)
		GTObject = new GTexture(DOOR_IMAGE_FILE_1, 2, 1, 2);
	else
		GTObject = new GTexture(DOOR_IMAGE_FILE_2, 2, 1, 2);
	GSObject = new GSprite(GTObject, DOOR_FRAME);
	if (State != 3)
		DoorOpen = new GSprite(new GTexture("Resources/ground/Gate.png", 2, 1, 2), DOOR_FRAME);
	else
		DoorOpen = new GSprite(new GTexture("Resources/ground/Gate2.png", 2, 1, 2), DOOR_FRAME);
	this->x = x;
	this->y = y;
}

CDoor::~CDoor()
{
}

void CDoor::Update(int t)
{
	if (OpeningTheGate && DoorOpen->_index == 1)
		OpeningTheGate = 2;
	if (OpeningTheGate && DoorOpen->_index != 1)
	{
		DoorOpen->Update(t);
	}
	else
		GSObject->SelectIndex(0);
}

void CDoor::Draw(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (OpeningTheGate){
		if (State == 3)
		{
			DoorOpen->DrawFlipX(pos.x - GTObject->FrameWidth - 18, pos.y);
		}
		else
		{
			DoorOpen->DrawFlipX(pos.x + GTObject->FrameWidth, pos.y);
		}
	}
	else GSObject->DrawFromCenter(pos.x, pos.y);
}

Box CDoor::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - GTObject->FrameWidth / 2 - 4, y + GTObject->FrameHeight / 2);
	return Box(pos.x, pos.y, GTObject->FrameWidth / 2 + 15, GTObject->FrameHeight, Vx, -Vy);
}
