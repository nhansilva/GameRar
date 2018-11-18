#include "Trap.h"

CTrap::CTrap(int x1, int y1, int w1, int h1)
{
	Vx = 0;
	Vy = 0;
	x = x1;
	y = y1;
	h = h1;
	w = w1;
	Dy = y1;
	GTObject = new GTexture(TRAP_IMAGE_FILE, 1, 2, 2);
	GSObject = new GSprite(GTObject, 0);
	Waiting = 0;
	sm = x1;
}

void CTrap::Draw(GCamera * camera)
{
	//vẽ cái chông
	D3DXVECTOR2 pos1 = camera->Transform(x, y);
	GSObject->DrawIndex(1, pos1.x, pos1.y);

	//Vẽ cái cây 
	D3DXVECTOR2 pos2 = camera->Transform(x, Dy);
	int k = (pos1.y - pos2.y - GTObject->FrameHeight) / (GTObject->FrameHeight); //Transform nên y2 > y1 => / để lấy số cây cần vẽ
	int Y = pos1.y - GTObject->FrameHeight;

	for (int i = 0; i < k + 1; i++)
	{
		GSObject->DrawIndex(0, pos2.x, Y);
		Y -= GTObject->FrameHeight;
	}
	GSObject->DrawIndex(0, pos2.x, pos2.y);
}

void CTrap::Update(GCamera *camera, int t)
{
	if (Status == 1) // Đi xuống
	{
		y += Vy;
		Vy -= TRAP_GRAVITY;
		if ((y + GTObject->FrameWidth / 2 <= 900 && sm != sm_X) || (sm == sm_X && y + GTObject->FrameWidth / 2 <= 955))
		{
			Status = 2;
			Waiting = 0;
			if (sm != sm_X)
			{
				y += (900 - (y + GTObject->FrameHeight / 2));
			}
			else
			{
				y += (955 - (y + GTObject->FrameHeight / 2));
			}
			Vy = GTObject->FrameHeight;
		}
		return;
	}

	if (Status == 2) // Đi lên
	{
		// lên 1 lần dừng 1 lần
		if (Waiting == 10)
		{
			Vy = 18;
			Waiting = 0;
		}
		else Vy = 0;
		y += Vy;

		if ((y >= Dy - 16 && sm != sm_X) || (sm == sm_X && y >= Dy - 20))
		{
			Status = 1;
			Vy = -TRAP_VY;
			if (sm != sm_X)
			{
				y = Dy - 16;
			}
			else
			{
				y = Dy - 20;
			}
		}
		Waiting++;
		return;
	}
}

void CTrap::Go()
{
	if (IsGoing == 1) return;
	CObject::Go();
	Vy = -TRAP_VY;
	Status = 1;
}

Box CTrap::GetBox(GCamera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - GTObject->FrameWidth / 2 + 15, y + GTObject->FrameHeight / 2);
	return Box(pos.x, pos.y, GTObject->FrameWidth - 30, GTObject->FrameHeight, Vx, -Vy);
}



