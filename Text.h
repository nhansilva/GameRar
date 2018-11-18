#pragma once
#include "d3dx9.h"
#include <string>
#include "GSprite.h"
#include "iostream"
#include "GCamera.h"
using namespace std;

class CText
{
private:
	LPD3DXFONT font;
	LPD3DXSPRITE fSprite;
	RECT fRec;
	string s1;
	string t;
	string st;
	string h;
	string p;
	HRESULT	hr;
public:
	CText();
	~CText();
	void DrawTextTop(LPDIRECT3DDEVICE9 gDevice, int Score, int time, int stage, int hear, int power);
	void DrawTest(LPDIRECT3DDEVICE9 gDevice, string a);
	void Draw(GSprite* cam);
};