#include "Items.h"
//NHỚ XÓA CASE 20,0 UPDATE
CItems::CItems(int io, int x1, int y1)
{
	timeDie = 0;
	this->whichItem = io;
	fire = new CIFire(x1, y1 + AutoFit, 32, 44);
	fire->setIsDie(1);
	switch (io)
	{
	case 1:
	{
		sheart = new CSHeart(x1, y1 + AutoFit, 24, 20);
		sheart->setIsDie(1);
	}break;
	case 2:
	{
		food = new CFood(x1, y1 + AutoFit-84, 32, 26);
		food->setIsDie(1);
	}break;
	case 4:
	{
		whip = new CIWhip(x1, y1 + AutoFit, 32, 32);
		whip->setIsDie(1);
	}break;
	case 5:
	{
		lheart = new CLHeart(x1, y1 + AutoFit, 24, 20);
		lheart->setIsDie(1);
	}break;
	case 7:
	{
		_400coin = new C400Coin(x1, y1 + AutoFit, 32, 32);
		_400coin->setIsDie(1);
	}break;
	case 8:
	{
		_400coin = new C400Coin(x1, y1 + AutoFit, 32, 32);
		_400coin->setIsDie(1);
	}break;

	case 10:
	{
		dagger = new CIDagger(x1, y1 + AutoFit, 32, 18);
		dagger->setIsDie(1);
	}break;
	case 11:
	{
		_600coin = new C600Coin(x1, y1 + AutoFit, 32, 18);
		_600coin->setIsDie(1);
	}break;
	case 12:
	{
		_2up = new C2Up(x1, y1 + AutoFit, 32, 18);
		_2up->setIsDie(1);
	}break;

	default:
	{

	}break;

	}

}

CItems::~CItems()
{

}

void CItems::Draw(GCamera * cam)
{
	
	if (fire->getIsDie() == 0)
	{
		fire->Draw(cam);
	}

	switch (this->getwhichObj())
	{
	case 1:
	{
		if (sheart->getIsDie() == 0 && fire->getIsDie() == 1)
			sheart->Draw(cam);
	}break;
	case 2:
	{
		if (food->getIsDie() == 0)
			food->Draw(cam);
	}break;
	case 4:
	{
		if (whip->getIsDie() == 0 && fire->getIsDie() == 1) whip->Draw(cam);
	}break;
	case 5:
	{
		if (lheart->getIsDie() == 0 && fire->getIsDie() == 1)
			lheart->Draw(cam);
	}break;

	case 8:
	{
		if (_400coin->getIsDie() == 0 && fire->getIsDie() == 1) _400coin->Draw(cam);
	}break;
	case 10:
	{
		if (dagger->getIsDie() == 0 && fire->getIsDie() == 1) dagger->Draw(cam);
	}break;
	case 11:
	{
		if (_600coin->getIsDie() == 0 && fire->getIsDie() == 1) _600coin->Draw(cam);
	}break;
	case 12:
	{
		if (_2up->getIsDie() == 0 && fire->getIsDie() == 1) _2up->Draw(cam);
	}break;
	default:
	{

	}break;

	}
}

int	CItems::getIsDie()
{

	switch (this->getwhichObj())
	{
	case 1:
	{
		return sheart->getIsDie();
	}break;
	case 2:
	{
		return food->getIsDie();
	}break;
	case 4:
	{
		return whip->getIsDie();
	}break;
	case 5:
	{
		return lheart->getIsDie();
	}break;
	case 8:
	{
		return _400coin->getIsDie();
	}break;
	case 9:
	case 10:
	{
		return dagger->getIsDie();
	}break;
	case 11:
	{
		return _600coin->getIsDie();
	}break;
	case 12:
	{
		return _2up->getIsDie();
	}break;
	default:
	{
		return -2;
	}break;

	}
}

void CItems::setIsDie(bool a)
{

	switch (this->getwhichObj())
	{
	case 1:
	{
		sheart->setIsDie(a);
	}break;
	case 2:
	{
		food->setIsDie(a);
	}break;
	case 4:
	{
		whip->setIsDie(a);
	}break;
	case 5:
	{
		lheart->setIsDie(a);
	}break;
	case 8:
	{
		_400coin->setIsDie(a);
	}break;
	case 10:
	{
		dagger->setIsDie(a);
	}break;
	case 11:
	{
		_600coin->setIsDie(a);
	}break;
	case 12:
	{
		_2up->setIsDie(a);
	}break;

	case 17:
	default:
	{

	}break;

	}
}

Box CItems::GetBox(GCamera *camera)
{
	switch (this->getwhichObj())
	{
	case 1:
	{
		return sheart->GetBox(camera);
	}break;
	case 2:
	{
		return food->GetBox(camera);
	}break;
	case 4:
	{
		return whip->GetBox(camera);
	}break;
	case 5:
	{
		return lheart->GetBox(camera);
	}break;

	case 8:
	{
		return _400coin->GetBox(camera);
	}break;

	case 10:
	{
		return dagger->GetBox(camera);
	}break;
	case 11:
	{
		return _600coin->GetBox(camera);
	}break;
	case 12:
	{
		return _2up->GetBox(camera);
	}break;
	default:
	{
		return Box(0, 0, 0, 0, 0, 0);
	}break;

	}
}

void CItems::Update(int t)
{

	if (fire->getIsDie() == 0)
	{
		fire->Update(t);
		timeDie = 0;
	}
	else
	{
		if(whichItem != 17 && this->getwhichObj() != 2) timeDie++;
		if (this->timeDie > 200)
		{
			this->setIsDie(true);
		}
	}
	switch (this->getwhichObj())
	{
	case 1:
	{
		if (sheart->getIsDie() == 0 && fire->getIsDie() == 1)
		{
			sheart->Update(t);
		}
	}break;
	case 2:
	{
		if (food->getIsDie() == 0 && fire->getIsDie() == 1) food->Update(t);
	}break;
	case 4:
	{
		if (whip->getIsDie() == 0 && fire->getIsDie() == 1)
		{
			whip->Update(t);
		}
	}break;
	case 5:
	{
		if (lheart->getIsDie() == 0 && fire->getIsDie() == 1)
		{
			lheart->Update(t);
		}
	}break;
	case 8:
	{
		if (_400coin->getIsDie() == 0 && fire->getIsDie() == 1)
		{
			_400coin->Update(t);
		}
	}break;
	case 10:
	{
		if (dagger->getIsDie() == 0 && fire->getIsDie() == 1)
		{
			dagger->Update(t);
		}
	}break;
	case 11:
	{
		if (_600coin->getIsDie() == 0 && fire->getIsDie() == 1)
		{
			_600coin->Update(t);
		}
	}break;
	case 12:
	{
		if (_2up->getIsDie() == 0 && fire->getIsDie() == 1)
		{
			_2up->Update(t);
		}
	}break;
	default:
	{

	}break;

	}
}

void CItems::Fall()
{
	switch (this->getwhichObj())
	{
	case 1:
	{
		if (fire->getIsDie() == true)
		{
			sheart->Fall();
		}
	}break;
	case 2:{
	    if (fire->getIsDie() == true)
	    {
			food->Fall();
	    }
	}break;
	case 4:
	{
		if (fire->getIsDie() == 1) whip->Fall();
	}break;
	case 5:
	{
		if (fire->getIsDie() == true)
		{
			lheart->Fall();
		}
	}break;
	case 8:
	{
		if (fire->getIsDie() == 1) _400coin->Fall();
	}break;
	case 10:
	{
		if (fire->getIsDie() == 1) dagger->Fall();
	}break;
	case 11:
	{
		if (fire->getIsDie() == 1) _600coin->Fall();
	}break;
	default:
	{

	}break;

	}
}

void CItems::StopFall()
{

	switch (this->getwhichObj())
	{
	case 1:
	{
		sheart->StopFall(0);
	}break;
	case 2:
	{
		food->StopFall(0);
	}break;
	case 4:
	{
		whip->StopFall(0);
	}break;
	case 5:
	{
		lheart->StopFall(0);
	}break;
	case 8:
	{
		_400coin->StopFall(0);
	}break;
	case 10:
	{
		dagger->StopFall(0);
	}break;
	case 11:
	{
		_600coin->StopFall(0);
	}break;

	default:
	{

	}break;

	}
}


void CItems::setX(int a)
{

	switch (this->getwhichObj())
	{
	case 1:
	{
		sheart->setx(a);
	}break;
	case 2:
	{
		food->setx(a);
	}break;
	case 4:
	{
		whip->setx(a);
	}break;
	case 5:
	{
		lheart->setx(a);
	}break;
	case 8:
	{
		_400coin->setx(a);
	}break;

	case 10:
	{
		dagger->setx(a);
	}break;
	case 11:
	{
		_600coin->setx(a);
	}break;
	default:
	{

	}break;

	}
}


void CItems::setY(int a)
{

	switch (this->getwhichObj())
	{
	case 1:
	{
		sheart->sety(a);
	}break;
	case 2:
	{
	    food->sety(a);
	}break;
	case 11:
	{
		_600coin->sety(a);
	}break;
	}
}

void CItems::setFireDie(int a)
{
	fire->setIsDie(a);
}

void CItems::setXFire(int a)
{
	fire->setx(a);
	//this->setX(a);
}

void CItems::setYFire(int a)
{
	fire->sety(a);
	//this->setY(a);
}

void CItems::setCountTime(){
	fire->setCountTime();
}
