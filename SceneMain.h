#ifndef _SCENEMAIN_H_
#define _SCENEMAIN_H_
#include <map>
#include "Game.h"
#include "GCamera.h"
#include "QuadTree.h"
#include "Board.h"
#include "BLood.h"
#include "Play.h"
#include "Exit.h"
#include "Simon.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Sweet_AABB.h"
#include <string>
#include<vector>
#include "Whip.h"
#include "FireBall.h"
#include "White.h"
#include "Score.h"
//////////////////////////////////////////////
//Source bổ sung weapon(Tiền updated)
#include "Weapon.h"
#include "Sword.h"
#include "BoardItem.h"

using namespace std;
class SceneMain: public CGame
{
private: 
	//stair
	int phaseUpStair;//giai doan len cau thang có 4
	int phaseDownStair;
	void GoUpStair(float x, float y, int trend);
	int PreUpStair;
	void GoDownStair(float x, float y, int trend);
	int PreDownStair;
	//stair
	string teststring = "";
	QuadTree * QT;
	Map *maps;
	GCamera *cam, *camObj; 
	CBoard * board;
	CBlood * blood;

	CSimon *simon;
	bool onBrick;
	CWhite *white;
	CScore *score;
	CBoardItem *boardItem;
	////////////////////////
	//Tiền updated
	bool isPlay_Exit = true;
	//int State = 3;
	int delay = 30;
	bool lockKeyboard = 0;
	bool trendFallDog;
	/////////////////////////////////////
	//(Tiền updated)
	vector<Weapon*> weapons;
	map<int, CDistinct*> *Enemys;
	vector<CObject*> Effects;
	vector<Weapon*>weaponsEnemy;
	int EndingScene ;
	int test = 0;
	int stepOpenTheGate;
	int xToOpen;
	bool isOpenTheGate;
	//bool colliGroundRight, colliGroundLeft;
	//Kiểm tra khi simon lấy roi thì set màu cho simon
	int CollectMorningStar;
	bool cohieu = true;//dung cho boss doi: chi thuc hien 1 lan
	bool eatOrb = false;//khi an qua trung de set qua man;
	bool stopsimon = false;//khi an qua trung phim bi khoa;
	bool simondied = false;// simon da chet;
	bool countSimondied = false;// dem thoi gian simon chet chuan bi reset
	int animation;
	bool isColliFood;//Bien cho cuc thit ve thi simon ve o truoc do
	int typeWeapon = 0;
	//
	int minT = 0;
	int minC = 0;//vong lap thoi gian cho diem tang;
	int minS = 0;//vong lap thoi gian chuan bi khoa phim;
	int minD = 0;// dem thoi gian chuan bi reset
	//
protected:	
	map<int, CDistinct*> *listObjDist;
	map<int, CItems*> *listItemDist;
	map< int, CDistinct*> *Grounds;
	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);
	virtual void OnKeyDown(int KeyCode);
	void LoadOther();
	void LoadMap1();
	////////////////////////////////////////(Tiền thêm hàm EndScene1)
	int EndScene1();
	/////////////////////////////////////////////////////////////////
	void LoadMap2();
	void LoadMap21();
	void RenderStage(LPDIRECT3DDEVICE9 d3ddv,int t);
	void UpdateObject(GCamera * cam, int t);//thêm vào hàm này
	void CollisionState(int t);
	void OpenTheGate();
	void MoveCamera(bool up, bool down);
	void MoveDownCamera();
	void MoveUpCamera();
	void FlashAnimation();
	void SetDieAllEnemy();
public:
	SceneMain(int _nCmdShow);
	~SceneMain();
};

#endif