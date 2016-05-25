#include "stdafx.h"
#include "Classes.h"
#include <math.h>



using namespace std;

void VeganBacterium::Draw(HDC hdc, COLORREF Color) {
	HBRUSH hBrush;

	hBrush = CreateSolidBrush(Color);
	SelectObject(hdc, hBrush);

	int Vector_x = pos_x + cos(angel - 3.14 / 2) * 30;
	int Vector_y = pos_y + sin(angel - 3.14 / 2) * 30;

	MoveToEx(hdc, pos_x, pos_y, NULL);
	LineTo(hdc, Vector_x, Vector_y);

	Ellipse(hdc, pos_x - 15, pos_y - 15, pos_x + 15, pos_y + 15);
	
	HFONT hfont;
	LOGFONT lf;

	memset(&lf, 0, sizeof(lf));
	lf.lfHeight = -12;
	lf.lfItalic = false;
	lstrcpyA((LPSTR)lf.lfFaceName, (LPCSTR)"Arial");
	hfont = CreateFontIndirect(&lf);

	TextOutA(hdc, (int)(pos_x - 30), (int)(pos_y + 30), (LPCSTR)name, lstrlenA((LPCSTR)name));
}

void OmnivorousBacterium::Draw(HDC hdc, COLORREF Color) {
	HBRUSH hBrush;

	hBrush = CreateSolidBrush(Color);
	SelectObject(hdc, hBrush);

	int x1 = pos_x + cos(angel - 3.14 / 2 + 3.14 / 8) * 30;
	int y1 = pos_y + sin(angel - 3.14 / 2 + 3.14 / 8) * 30;

	int x2 = pos_x + cos(angel - 3.14 / 2 - 3.14 / 8) * 30;
	int y2 = pos_y + sin(angel - 3.14 / 2 - 3.14 / 8) * 30;

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, pos_x, pos_y);
	LineTo(hdc, x2, y2);

	Ellipse(hdc, pos_x - 15, pos_y - 15, pos_x + 15, pos_y + 15);

	HFONT hfont;
	LOGFONT lf;

	memset(&lf, 0, sizeof(lf));
	lf.lfHeight = -12;
	lf.lfItalic = false;
	lstrcpyA((LPSTR)lf.lfFaceName, (LPCSTR)"Arial");
	hfont = CreateFontIndirect(&lf);

	TextOutA(hdc, (int)(pos_x - 30), (int)(pos_y + 30), (LPCSTR)name, lstrlenA((LPCSTR)name));
}


void PredatorBacterium::Draw(HDC hdc, COLORREF Color) {
	HBRUSH hBrush;

	hBrush = CreateSolidBrush(Color);
	SelectObject(hdc, hBrush);

	int x1 = pos_x + cos(angel - 3.14 / 2) * 30;
	int y1 = pos_y + sin(angel - 3.14 / 2) * 30;

	int x2 = pos_x + cos(angel - 3.14) * 15;
	int y2 = pos_y + sin(angel - 3.14) * 15;

	int x3 = pos_x + cos(angel) * 15;
	int y3 = pos_y + sin(angel) * 15;

	MoveToEx(hdc, x2, y2, NULL);
	LineTo(hdc, x1, y1);
	LineTo(hdc, x3, y3);

	Ellipse(hdc, pos_x - 15, pos_y - 15, pos_x + 15, pos_y + 15);

	HFONT hfont;
	LOGFONT lf;

	memset(&lf, 0, sizeof(lf));
	lf.lfHeight = -12;
	lf.lfItalic = false;
	lstrcpyA((LPSTR)lf.lfFaceName, (LPCSTR)"Arial");
	hfont = CreateFontIndirect(&lf);

	TextOutA(hdc, (int)(pos_x - 30), (int)(pos_y + 30), (LPCSTR)name, lstrlenA((LPCSTR)name));
}

void Bacterium::TurnLeft()
{
	angel -= (float)speed / 100;
}

void Bacterium::TurnRight()
{
	angel += (float)speed / 100;
}

void Bacterium::MoveForward()
{
	pos_x += cos(angel - 3.14 / 2) * speed;
	pos_y += sin(angel - 3.14 / 2) * speed;
}

void Sump::Draw(HDC hdc, COLORREF Color)
{
	// TODO: sump draw func

	for (int i = 0; i < 10; i++)
	{
		Bacteriums[i].Draw(hdc, Color);
	}
}