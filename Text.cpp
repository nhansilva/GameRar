#include "Text.h"
CText::CText()
{

}

CText::~CText()
{

}

void CText::DrawTextTop(LPDIRECT3DDEVICE9 gDevice, int Score, int time, int stage, int hear, int power)
{
	gDevice->BeginScene();

	hr = D3DXCreateFont(gDevice, 30, 12, FW_NORMAL, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_MODERN, "Arial", &font);
	//GetClientRect(G_hWnd, &fRec);
	if (SUCCEEDED(hr))
	{
		//SetRect(&fRec, 0, 15, 500, 500);
		s1 = std::to_string(Score);
		t = std::to_string(time);
		st = std::to_string(stage);
		h = std::to_string(hear);
		p = std::to_string(power);
		SetRect(&fRec, 0, 2, 500, 110);
		if (font)
		{
			//
			//font->DrawTextA(NULL, m.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
			string s = " SCORE : " + s1 + "       TIME: " + t + "   STAGE    " + st + " \n PLAYER:                                            " + h + " \n ENEMY :                                            " + p;
			font->DrawText(fSprite, s.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
			//font->DrawTextA(fSprite, s.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
		}
	}

	gDevice->EndScene();
	if (font != NULL)
		font->Release();
}
void CText::DrawTest(LPDIRECT3DDEVICE9 gDevice, string a)
{
	gDevice->BeginScene();

	hr = D3DXCreateFont(gDevice, 30, 12, FW_NORMAL, 1, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_MODERN, "Arial", &font);
	//GetClientRect(G_hWnd, &fRec);
	if (SUCCEEDED(hr))
	{
		SetRect(&fRec, 0, 80, 500, 110);
		if (font)
		{

			font->DrawText(fSprite, a.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
			//font->DrawTextA(fSprite, s.c_str(), -1, &fRec, DT_LEFT, D3DCOLOR_XRGB(255, 255, 255));
		}
	}

	gDevice->EndScene();
	if (font != NULL)
		font->Release();
}
void CText::Draw(GSprite* cam)
{

}


