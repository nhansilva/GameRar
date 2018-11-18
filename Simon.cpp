#include "Simon.h"

CSimon::CSimon(float x1, float y1, int trend)
{
	x = x1;
	y = y1;
   Trend = trend;
   Vx = SIMON_VX_GO;
   Simon_vx = SIMON_VX_GO;
   GTObject = new GTexture("./Resources/simon.png",8,3,24);
   GSObject = new GSprite(GTObject, SIMON_FRAME);
   GTObject2 = new GTexture("./Resources/simondeath.png", 1, 1, 1);
   GSObject2 = new GSprite(GTObject2,10);
   EndHurt = 1;
   isOnBrick9 = false;
}

CSimon::~CSimon()
{

}

void CSimon::Draw() {
	GSObject->DrawFromCenter(x, y);
}
void CSimon::Draw(GCamera * cam)
{
	D3DXVECTOR2 pos = cam->Transform(x, y);	
	if (IsHurting)
	{
		IsHurting--;
		if (!IsDie)
		{
			IsDie = true;
			return;
		}
		else
		{
		  IsDie = false;
		}
	}
	else EndHurt = 1;
	if (Trend == -1)
	{
		if(isSimonDie == true)GSObject2->DrawFromCenter(pos.x, pos.y);
		else GSObject->DrawFromCenter(pos.x, pos.y);
	}
	else {
		if (isSimonDie == true)GSObject2->DrawFlipX(pos.x, pos.y);
		else GSObject->DrawFlipX(pos.x, pos.y);
	} 
}
///////////////////////////
//Thêm vào hàm khi simon di chuyển thì đổi frame

void CSimon::Update(GCamera *camera, int t)
{
		if (IsAttacking == 1) {
			GSObject->Update(t);
			if (IsSitting == 1)					//Tấn công khi đang ngồi
			{
				if (GSObject->_index > 17)
				{
					IsAttacking = 0;
					this->Sit();
				}
			}
			else if (IsJumping == 1) //Tấn công khi đang bay
			{
				Vx *= IsGoing;
				x += Vx * t;
				y += Vy;
				Vy = Vy - SIMON_GRAVITY;
				if (GSObject->_index > 7)
				{
					IsAttacking = 0;
					this->Fall();
				}
			}
			else
				if (GSObject->_index > 7)
				{
					GSObject->SelectIndex(SIMON_STOP_IMAGE);
					IsAttacking = 0;
				}
		}
		else {
			if (IsJumping == 1)
			{
				if (EndHurt) Vx *= IsGoing; else Vx = Vx_Hurt*HTrend*(Prevent == 0);
				y += Vy;
				x += Vx * t;
				Vy = Vy - SIMON_GRAVITY;
				GSObject->SelectIndex(SIMON_SIT_IMAGE);
				if (!EndHurt) GSObject->SelectIndex(SIMON_HURT_IMAGE);
				if (Vy == 0)
				{
					this->Fall();
				}
			}
			else if (IsFalling == 1)
			{
				if (EndHurt) Vx *= IsGoing; else Vx = Vx_Hurt*HTrend*(Prevent == 0);
				x += Vx * t;
				y += Vy;
				Vy = Vy - SIMON_GRAVITY;
				GSObject->SelectIndex(SIMON_STOP_IMAGE);
			}
			else if (IsGoing == 1)
			{
				x += Vx * t;
				//GSObject->_end = 3;
				GSObject->Update(t);
				if (IsFalling == 0 && IsJumping == 0) GSObject->_index = GSObject->_index % 4;
			}
			else if (IsSitting == 1)
			{
				GSObject->SelectIndex(SIMON_SIT_IMAGE);
			}
			else {
				GSObject->SelectIndex(SIMON_STOP_IMAGE);//rơi tự do khi va chạm với gạch thì đổi index frame
			}
		}

	
	//Khi simon ra khỏi đầu cam
	if (x - 15 < camera->viewport.x){
		x = camera->viewport.x + 16;
	}
	//Khi simon ra khỏi cuối cam
	if (x + 15 > camera->viewport.x + G_ScreenWidth){
		x = camera->viewport.x + G_ScreenWidth - 15;
	}
}


void CSimon::setIndexSimon() {
    GSObject->SelectIndex(0);
}

Box CSimon::GetBox(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x - 15, y + GTObject->FrameHeight / 2);
	return Box(pos.x, pos.y, GTObject->FrameWidth - 28, GTObject->FrameHeight, Vx, -Vy);// xem lại
}

void CSimon::StopFall(float y) {
	if (IsAttacking == 1)return;
	IsAttacking = 0;
	IsFalling = 0;
	if (IsSitting == 0) {
		this->y = y - SIMON_Y_STOP_FALL;//Thay y = y - 8 bằng SIMON_STOP_FALL
	}
	if (SimonFall) this->Sit();
	else
		if (IsGoing == 1) this->Go();
		else this->StandUp();
    Vy = 0;
}
void CSimon::Sit()
{
	if (IsJumping == 1 || IsFalling == 1) return;
	if (IsAttacking == 0)
	{
		GSObject->SelectIndex(SIMON_SIT_IMAGE);
		if (IsSitting == 0) y = y - SIMON_Y_SIT;
		GSObject->SelectIndex(SIMON_SIT_IMAGE);
		CObject::Sit();
	}
}

void CSimon::StandUp()
{
	if (IsSitting == 1) y = y + SIMON_Y_SIT;
	GSObject->SelectIndex(SIMON_STOP_IMAGE);
	CObject::StandUp();
}
void CSimon::Jump()
{
	if (IsAttacking == 0 && IsJumping == 0 && IsFalling == 0)
	{
		if (IsJumping == 0)
		{
			Vy = SIMON_VJUMP;
			GSObject->SelectIndex(SIMON_SIT_IMAGE);
			/*if (EndHurt == 0)
			{
				GSObject->SelectIndex(SIMON_HURT_IMAGE);
				Vx = Vx*HTrend;
			}*/
			CObject::Jump();
		}
	}
}
void CSimon::Fall()
{
	if (IsAttacking == 0 && IsJumping == 1 && IsFalling == 0)
	{
		if (IsFalling == 0)
		{
			Vy = -SIMON_VJUMP;
			GSObject->SelectIndex(SIMON_STOP_IMAGE);
			CObject::Fall();
		}
	}
}

void CSimon::Go()
{
	if (IsJumping == 1 || IsFalling == 1) return;
	if (IsOnStair == 1 && IsAttacking == 0)
	{
		Vx = SIMON_VX_STAIR*Trend;
		Vy = -SIMON_VY_STAIR*Trend*stairTrend;
		CObject::Go();
		return;
	}
	if (IsAttacking == 0)
	{
		if (IsSitting == 1) this->StandUp();
		this->Vx = Simon_vx*Trend;
		CObject::Go();
		//Prevent = 0;
	}
}

void CSimon::Stop()
{
	if (IsAttacking == 0)
	{
		if (IsSitting == 1) {
			this->StandUp();
		}
		CObject::Stop();
		return;
	}
}

/////////////////////////
//Tiền updated
void CSimon::Attack(Weapon * weapon) {
	if (IsFalling == 1) return;

	if (IsSitting == 1)
	{
		GSObject->SelectIndex(SIMON_SITATK_IMAGE);
	}
	else if (IsOnStair == 1) {
		if (Trend * stairTrend == -1) {// di len
			GSObject->SelectIndex(21);
		}
		else {
			GSObject->SelectIndex(18);
		}
	}
	else
		GSObject->SelectIndex(SIMON_ATK_IMAGE);
	CObject::Attack(weapon);
}
void CSimon::Hurt(int HTrend)
{
	if (IsHurting == 0)
	{
		//this->HTrend = HTrend > 0 ? 1 : -1;
		IsHurting = 30;
		EndHurt = 0;
		//SimonFall = 0;
		//Vx_Hurt = Simon_vx;
		//if (IsOnStair == 0)
		//this->Jump();
	}
}

void CSimon::UpStair()
{
	IsSitting = 0;
	IsJumping = 0;
	IsFalling = 0;
	IsOnStair = 1;// cờ nhận biết ở trên cầu thang
}

void CSimon::DownStair()
{
	Trend = stairTrend;
	IsSitting = 0;
	IsJumping = 0;
	IsFalling = 0;
	IsOnStair = 1;
}
void CSimon::OutStair()
{
	Vy = 0;
	Vx = Simon_vx;
	IsOnStair = 0;
	this->GSObject->_timeAni = 70;
}
int CSimon::GetOnStair() {
	return IsOnStair;
}
//stair

void CSimon::AutoGoOnBrick9()
{
	if (isOnBrick9 == true)
	{
		x = x + vOnBrick9;
	}
}
