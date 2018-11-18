#include "Score.h"
CScore::CScore()
{

	_Score = 100;		//Số điểm hiện có
	_Heart = 7;     //Số quả tim đã ăn
	_Power = 3;		//Chữ P - số mạng
	_SimonBlood = 16; // Máu của simon
	_EnemyBlood = 16; // Máu của enemy
	_BeforeDie = 1; //Lưu lại màn mà simon trước khi tạch
	_Time = 300; //Thời gian đi 1 map
}


void CScore::CalculatorHurt(int a)
{
	//for (int i = 0; i < a; i++)
	{
		_SimonBlood--;
	}
}

void CScore::CalculatorHurtBoss(int a) {
	_EnemyBlood-=a;
}

void CScore::CalculatorItem(int a)
{
	switch (a)
	{
	case 1: // Tim nhỏ =>Tăng 1 quả tym
	{
		_Heart++;
	}break;
	case 2: //Cục thịt => Khôi phục máo 100%
	{
		_SimonBlood = 16;
	}break;
	case 3: //Cái rìu
	{

	}break;
	case 4: //Cái roi
	{

	}break;
	case 5: // Tim lớn =>Tăng 5 quả tym
	{
		_Heart = _Heart + 5;
	}break;
	case 6: // Boomerang
	{

	}break;
	case 7: //$ tiền 400 =>Tăng thêm 400 Coin
	{
		_Score += 400;
	}break;
	case 8: //$ tiền 1000 =>Tăng thêm 1000 Coin
	{
		_Score += 1000;
	}break;
	case 10: // Cây rìu
	{

	}break;
	case 11:  //$ tiền 700 =>Tăng thêm 700 Coin
	{
		_Score += 700;
	}break;
	case 12:
	{
		_Power += 2;
	}break;
	

	default:
	{

	}break;

	}
}

void CScore::CalculatorWhenBossDie()
{
	_Score += 3000;
}

void CScore::CalculatorOrb() //Chet Boss: cộng 3000 | Tim: SoTim*100 | Time: time*10
{
	if (_SimonBlood < 16) _SimonBlood++;
	if (_SimonBlood == 16) {
		if (this->_Time > 0)
		{
			_Score += 10;
			_Time--;
		}
		if (_Time == 0) {
			_Time = 0;
			if (_Heart > 0)
			{
				_Score += 100;
				_Heart--;
				if (_Heart == 0) _Heart = 0;
			}
		}
	}
}

void CScore::Calculator1Sec()
{
	_Time--;
	if (_Time < 0) _Time = 0;
}