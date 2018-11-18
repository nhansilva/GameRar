#pragma once
class CScore
{
	int _Score;		//Số điểm hiện có
	int _Power;		//Chữ P - số mạng
	int _SimonBlood; // Máu của simon
	int _EnemyBlood; // Máu của enemy
	int _BeforeDie; //Lưu lại màn mà simon trước khi tạch
	int _Time;
public:
	CScore();
	~CScore();
	int _Heart;     //Số quả tim đã ăn
	//Hàm tính điểm
	void CalculatorHurt(int a); //Truyền vào số máu bị mất
	void CalculatorHurtBoss(int a);
	void CalculatorItem(int a); //Truyền vào biến item nào
	void CalculatorWhenBossDie();
	void CalculatorOrb();
	void Calculator1Sec();
	//Get
	int GetScore() { return _Score; };
	int GetHeart() { return _Heart; };
	int GetPower() { return _Power; };
	int GetSimonBlood() { return _SimonBlood; };
	int GetEnemyBlood() { return _EnemyBlood; };
	int GetBeforeDie() { return _BeforeDie; };
	int GetTime() { return _Time; };

	// SET
	void SetScore(int a) { _Score = a; };
	void SetHeart(int a) { _Heart = a; };
	void SetPower(int a) { _Power = a; };
	void SetSimonBlood(int a) { _SimonBlood = a; };
	void SetEnemyBlood(int a) { _EnemyBlood = a; };
	void SetBeforeDie(int a) { _BeforeDie = a; };
	void SetTime(int a) { _Time = a; };
};

