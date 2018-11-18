#include "Distinct.h"
//NHỚ XÓA CASE 20,0 UPDATE
CDistinct::CDistinct(int io, int x1, int y1, int w1, int h1)
{
	this->whichObj = io;
	switch (whichObj)
	{
	case 0: //Cục gạch ảo, Simon đứng trên cục này
	{
				brick = new CBrick(x1, y1 + AutoFit, w1, h1);
	}break;
	case 1: //Cầu Thang
	{
				stair = new CStair(x1, y1 + AutoFit, w1, h1);
	}break;
	case 2: //Cầu Thang
	{
				stair = new CStair(x1, y1 + AutoFit, w1, h1);
	}break;
	case 3: //Cầu thang
	{
				stair = new CStair(x1, y1 + AutoFit, w1, h1);
	}break;
	case 4: //Cầu thang
	{
				stair = new CStair(x1, y1 + AutoFit, w1, h1);
	}break;
	case 5: //Đèn cầy lớn
	{
				lcandle = new CLCandle(x1, y1 + AutoFit, w1, h1);
	}break;
	case 6: //Đèn cầy nhỏ
	{
				mcandle = new CMCandle(x1, y1 + AutoFit, w1, h1);
	}break;
	case 7: //Con chó
	{
				dog = new CDog(x1, y1 + AutoFit, w1, h1);
	}break;

	case 10: //Con ma
	{
				 ghost = new CGhost(x1, y1 + AutoFit, w1, h1);
	}break;
	case 12: //Cái đầu (Số 06) bay bay
	{

	}break;

	case 20: //CHuyển màn 1
	{
				 vir_20 = new CVir_20(x1, y1 + AutoFit, w1, h1);
	}break;
	case 22:
	{
			   door = new CDoor(x1, y1 + AutoFit, w1, h1);
	}break;

	case 29:
	{
			   brick2 = new CBrick2(x1, y1 + AutoFit, w1, h1);
	}break;
	case 30:
	{
			   brick1 = new CBrick1(x1, y1 + AutoFit, w1, h1);
	}break;
	case 31:
	{
			   brick3 = new CBrick3(x1, y1 + AutoFit, w1, h1);
	}break;
	default:
	{

	}break;
	}

}

CDistinct::~CDistinct()
{

}

void CDistinct::Draw(GCamera * cam)
{
	switch (whichObj)
	{
	case 0: //Cục gạch ảo, Simon đứng trên cục này
		//brick->Draw(cam);
		break;
	case 1:
		//stair->Draw(cam);
		break;
	case 2:
		stair->Draw(cam);
		break;
	case 3:
		//stair->Draw(cam);
		break;
	case 4:
		stair->Draw(cam);
		break;
	case 5:
	{
			  if (lcandle->getIsDie() == 0) lcandle->Draw(cam);
	}break;
	case 6:
	{
			  if (mcandle->getIsDie() == 0)mcandle->Draw(cam);
	}break;
	case 7:
	{
			  if (dog->getIsDie() == 0)dog->Draw(cam);
	}break;
	case 10:
	{
			   if (ghost->getIsDie() == 0)ghost->Draw(cam);
	}break;
	case 12:
	{

	}break;
	case 14:
	{

	}break;
	case 15:
	{

	}break;
	case 16:
	{
			   if (brick9->getIsDie() == 0)brick9->Draw(cam);
	}break;
	case 17:
	{
			   if (trap->getIsDie() == 0)trap->Draw(cam);
	}break;
	case 22:
	{
			   if (door->getIsDie() == 0)
				   door->Draw(cam);
	}break;
	case 29:
	{
			   //if (brick2->getIsDie() == 0)
			   brick2->Draw(cam);
	}break;
	case 30:
	{
			   //if (brick2->getIsDie() == 0)
			   brick1->Draw(cam);
	}break;
	case 31:
	{
			   //if (brick2->getIsDie() == 0)
			   brick3->Draw(cam);
	}break;
	default:
	{

	}break;
	}
}

void CDistinct::Update(GCamera *camera, int t)
{
	switch (whichObj)
	{
	case 5: //Cục gạch ảo, Simon đứng trên cục này
	{
				//if (lcandle->getIsDie() == 0) lcandle->Update(t);
	}break;
	case 6: //Đèn cầy
	{
				//if (mcandle->getIsDie() == 0) mcandle->Update(t);
	}break;
	case 7: //Con 
	{
				if (dog->getIsDie() == 0) dog->Update(t);
	}break;

	case 10: //Con ma
	{
				 if (ghost->getIsDie() == 0) ghost->Update(t);
	}break;

	case 16: //
	{
				 if (brick9->getIsDie() == 0) brick9->Update(t);
	}break;
	case 17:
	{
			   if (trap->getIsDie() == 0) trap->Update(camera, t);
	}break;
	case 22:
	{
			   if (door->getIsDie() == 0) door->Update(t);
	}break;
	case 29:
	{
			   if (brick2->getIsDie() == 0)
			   {
				   brick2->Update(t);
			   }
	}break;
	case 30:
	{
			   if (brick1->getIsDie() == 0)
			   {
				   brick1->Update(t);
			   }
	}break;
	case 31:
	{
			   if (brick3->getIsDie() == 0)
			   {
				   brick3->Update(t);
			   }
	}break;
	default:
	{

	}break;
	}
}

Box CDistinct::GetBox(GCamera *camera) {
	switch (whichObj) {
	case 0:
	{
			  D3DXVECTOR2 pos = camera->Transform(brick->getx() - brick->getw() / 2, brick->gety() + brick->geth() / 2);
			  return Box(pos.x, pos.y, brick->getw(), brick->geth(), 0, 0);
	}break;
	case 1: {
				D3DXVECTOR2 pos = camera->Transform(stair->getx() - stair->getw() / 2, stair->gety() + stair->geth() / 2);
				return Box(pos.x, pos.y, stair->getw(), stair->geth(), 0, 0);
	}break;
	case 2: {
				D3DXVECTOR2 pos = camera->Transform(stair->getx() - stair->getw() / 2, stair->gety() + stair->geth() / 2);
				return Box(pos.x, pos.y, stair->getw(), stair->geth(), 0, 0);
	}break;
	case 3: {
				D3DXVECTOR2 pos = camera->Transform(stair->getx() - stair->getw() / 2, stair->gety() + stair->geth() / 2);
				return Box(pos.x, pos.y, stair->getw(), stair->geth(), 0, 0);
	}break;
	case 4: {
				D3DXVECTOR2 pos = camera->Transform(stair->getx() - stair->getw() / 2, stair->gety() + stair->geth() / 2);
				return Box(pos.x, pos.y, stair->getw(), stair->geth(), 0, 0);
	}break;
	case 5:
	{
			  D3DXVECTOR2 pos = camera->Transform(lcandle->getx() - lcandle->getw() / 2, lcandle->gety() + lcandle->geth() / 2);
			  return Box(pos.x, pos.y, lcandle->getw(), lcandle->geth(), 0, 0);
	}break;
	case 6:
	{
			  return mcandle->GetBox(camera);
	}break;
	case 7:
	{
			  D3DXVECTOR2 pos = camera->Transform(dog->getx() - dog->getw() / 2, dog->gety() + dog->geth() / 2);
			  return Box(pos.x, pos.y, dog->getw(), dog->geth(), dog->getVx(), -dog->GetVy());
	}break;
	case 10:
	{
			   return ghost->GetBox(camera);
	}break;
	case 16:
	{
			   return brick9->GetBox(camera);
	}break;
	case 17:
	{
			   return trap->GetBox(camera);
	}break;
	case 20:
	{
			   //return vir_20->GetBox(camera);
			   D3DXVECTOR2 pos = camera->Transform(vir_20->getx() - vir_20->getw() / 2, vir_20->gety() + vir_20->geth() / 2);
			   return Box(pos.x, pos.y, vir_20->getw(), vir_20->geth(), 0, 0);
	}break;
	case 22:
	{
			   return door->GetBox(camera);
	}break;
	case 29:
	{
			   return brick2->GetBox(camera);
	}break;
	case 30:
	{
			   return brick1->GetBox(camera);
	}break;
	case 31:
	{
			   return brick3->GetBox(camera);
	}break;
	default:
	{
			   return Box(0, 0, 0, 0, 0, 0);
	}break;
	}
}
int CDistinct::getObjX() {
	switch (whichObj) {
	case 0:return brick->getx();
		break;
	case 1:return stair->getx();
		break;
	case 2:return stair->getx();
		break;
	case 3: return stair->getx();
		break;
	case 4: return stair->getx();
		break;
	case 5:
		return lcandle->getx();
		break;
	case 6:
		return mcandle->getx();
		break;
	case 7:
		return dog->getx();
		break;
	case 10:
		return ghost->getx();
		break;
	case 16:
		return brick9->getx();
		break;
	case 17:
		return trap->getx();
		break;
	case 22:
		return door->getx();
		break;
	case 29:
		return brick2->getx();
		break;
	case 30:
		return brick1->getx();
		break;
	case 31:
		return brick3->getx();
		break;
	}
}
int CDistinct::getObjY() {
	switch (whichObj) {
	case 0:
		return brick->gety();
		break;
	case 1: return stair->gety();
		break;
	case 2: return stair->gety();
		break;
	case 3: return stair->gety();
		break;
	case 4: return stair->gety();
		break;
	case 7:
		return dog->gety();
		break;
	case 10:
		return ghost->gety();
		break;
	case 16:
		return brick9->gety();
		break;
	case 17:
		return  trap->gety();
		break;
	case 29:
		return  brick2->gety();
		break;
	case 30:
		return  brick1->gety();
		break;
	case 31:
		return  brick3->gety();
		break;
	}
}
int CDistinct::getObjH() {
	switch (whichObj) {
	case 0:
		return brick->geth();
		break;
	case 7:
		return dog->geth();
		break;
	case 16:
		return brick9->geth();
		break;
	case 17:
		return trap->geth();
		break;
	case 29:
		return brick2->geth();
		break;
	case 30:
		return brick1->geth();
		break;
	case 31:
		return brick3->geth();
		break;
	}
}

int CDistinct::getObjW() {
	switch (whichObj) {
	case 0:
		return brick->getw();
		break;
	case 7:
		return dog->getw();
		break;
	case 14:

		break;
	case 16:
		return brick9->getw();
		break;
	case 17:
		return trap->getw();
		break;
	}
}

int	CDistinct::getIsDie()
{
	switch (whichObj)
	{
	case 5:
	{
			  return lcandle->getIsDie();
	}break;
	case 6:
	{
			  return mcandle->getIsDie();
	}break;
	case 7:
	{
			  return dog->getIsDie();
	}break;
	case 10:
	{
			   return ghost->getIsDie();
	}break;
	case 17:
	{
			   return trap->getIsDie();
	}break;
	case 29:
	{
			   return brick2->getIsDie();
	}break;
	case 30:
	{
			   return brick1->getIsDie();
	}break;
	case 31:
	{
			   return brick3->getIsDie();
	}break;
	default:
	{

	}break;
	}
}


void CDistinct::setIsDie(bool a)
{
	switch (whichObj)
	{

	case 5:
	{
			  return lcandle->setIsDie(a);
	}break;
	case 6:
	{
			  return mcandle->setIsDie(a);
	}break;
	case 7:
	{
			  return dog->setIsDie(a);
	}break;
	case 10:
	{
			   return ghost->setIsDie(a);
	}break;
	{
			   return trap->setIsDie(a);
	}break;
	case 20: //NHỚ PHẢI XÓA THẰNG NÀY
	{
				 return vir_20->setIsDie(a);
	}break;

	default:
	{

	}break;
	}
}

void  CDistinct::Fall() {
	switch (whichObj) {
	case 7:
	{
			  return dog->Fall();
			  break;
	}
	case 10:
	{
			   return ghost->Fall();
	}break;
	}
}

void CDistinct::Jump() {
	switch (whichObj) {
	case 7:
		return dog->Jump();
		break;
	}
}
void CDistinct::Go() {
	switch (whichObj) {
	case 7:
		return dog->Go();
		break;
	case 17:
		return trap->Go();
		break;
	}
}

void CDistinct::StopFall(float y)
{
	switch (whichObj) {
	case 10:
		return ghost->StopFall(y);
		break;
	case 7:
		return dog->StopFall(y);
		break;
	}
}

void CDistinct::moveRigh() {
	switch (whichObj) {
	case 7:
		return dog->MoveRigh();
		break;
	}
}

int CDistinct::getIsGoing() {
	switch (whichObj)
	{
	case 7:
		return dog->getIsGoing();
		break;
	case 10:
		return ghost->getIsGoing();
		break;

	}
}
int CDistinct::getIsFalling() {
	switch (whichObj)
	{
	case 7:
		return dog->getIsFalling();
		break;
	default:
		return 0;
		break;
	}
}

void CDistinct::setX(int a)
{
	switch (whichObj)
	{
	case 0:
	{
			  brick->setx(a);
	}break;
	case 10:
	{
			   ghost->setx(a);
	}break;
	}
}


int CDistinct::getTimeFall() {
	switch (whichObj)
	{
	case 7:
	{
			  return dog->timeFall;
	}break;
	}
}

void CDistinct::settrend(int trend) {
	switch (whichObj) {
	case 1: stair->setTrend(trend);
		break;
	case 2: stair->setTrend(trend);
		break;
	case 3: stair->setTrend(trend);
		break;
	case 4: stair->setTrend(trend);
		break;
	case 10:ghost->setTrend(trend);
		break;
	case 12:
		break;

	}
}
int CDistinct::gettrend() {
	switch (whichObj) {
	case 1: return stair->getTrend();
		break;
	case 2: return stair->getTrend();
		//break;
	case 3: return stair->getTrend();
		break;
	case 4: return stair->getTrend();
		break;
	case 10: return ghost->getTrend();
		break;
	case 16:brick9->getTrend();
		break;
	}
}

void CDistinct::breakBrick()
{
	switch (whichObj)
	{
	case 29:
	{
			  brick2->brickbreak++;
	}break;
	case 30:
	{
			   brick1->brickbreak++;
	}break;
	case 31:
	{
			   brick3->brickbreak++;
	}break;
	}
}
int CDistinct::getBreakBrick(){
	switch (whichObj)
	{
	case 29:
	{
			   return brick2->brickbreak;
	}break;
	case 30:
	{
			   return brick1->brickbreak;
	}break;
	case 31:
	{
			   return brick3->brickbreak;
	}break;
	}
}

float CDistinct::getVx()
{
	switch (whichObj)
	{
		case 16:
		{
				   return brick9->getVx();
		}break;
	}
}

void CDistinct::GetSMPositionForBoss(float x){

}
void CDistinct::GetSMPositionForBoss(float x, float y, int Trend) 
{
}

void CDistinct::SetHurt(int i){
	switch (whichObj){
	case 15:
	{

	}break;
	}
}
int CDistinct::GetHurt()
{
	return 1;
}
