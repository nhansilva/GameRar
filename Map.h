#pragma once
#ifndef _MAP_H_
#define _MAP_H_

#include <stdio.h>
#include <conio.h>
#include "GSprite.h"
#include "GTexture.h"
#include "GCamera.h"
#include "Global.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Map
{
private:
	GTexture *GTTile;
	int RowMatrix = 0;
	int ColumnMatrix = 0;
	int TileMap[500][176];
	int fit = 128;
	//int State = 1; //-1: Menu ; 0: Intro, 1: Màn 1, 2: Màn 2, 3: Màn 3

	/////////////////////////////////
	//Bổ sung thêm code(tiền)
	int ScreenColumn;
	int ScreenRow;
	int row, column;
	int x, y;
public:
	GSprite *GSTile;
	Map(int State);
	~Map();
	void ReadMap(char * filename, int State);
	void LoadMap(int State);
	void DrawMap(GCamera *camera, int State);
	//int getState() { return State; };
	//void setState(int a) { State = a; };
	////////////////////////////////
	/////////Source code bổ sung hàm drawmap2 khi mà va chạm cổng ở màn 1 chuyển sang màn 2
	void DrawMap2(LPDIRECT3DDEVICE9 d3ddv,GCamera* camera);
};

#endif
