#pragma once
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <string.h>
#include <windows.h>

using namespace std;



class Bacterium
{
public:
	float pos_x;
	float pos_y;
	float angel;
	char name[10] = "Bacterium";

	int mass;
	int speed;

	virtual void Draw(HDC hdc, COLORREF Color) {};
	//virtual void Move();
	void TurnLeft();
	void TurnRight();
	void MoveForward();
};

class VeganBacterium : public Bacterium
{
public:
	VeganBacterium(float x, float y, float a)
	{
		pos_x = x;
		pos_y = y;
		angel = a;
		mass = 4;
		speed = 6;
	}
	virtual void Draw(HDC hdc, COLORREF Color);
};

class PredatorBacterium : public Bacterium
{
public:
	PredatorBacterium(float x, float y, float a)
	{
		pos_x = x;
		pos_y = y;
		angel = a;
		mass = 6;
		speed = 5;
	}
	virtual void Draw(HDC hdc, COLORREF Color);
};

class OmnivorousBacterium : public Bacterium
{
public:
	OmnivorousBacterium(float x, float y, float a)
	{
		pos_x = x;
		pos_y = y;
		angel = a;
		mass = 5;
		speed = 5;
	}
	virtual void Draw(HDC hdc, COLORREF Color);
};

class Sump
{
public:
	int pos_x;
	int pos_y;

	Bacterium Bacteriums[10];
	int Type; // 0 - Vegan, 1 - Predator, 2 - Omnivorous//
	COLORREF Color;

	Sump(int x, int y,int type, COLORREF color)
	{
		Color = color;

		pos_x = x;
		pos_y = y;
		Type = type;
		for (int i = 0; i < 10; i++)
		{
			switch (Type)
			{
			case 0:
				Bacteriums[i] = VeganBacterium(pos_x, pos_y, 0);
				break;
			case 1:
				Bacteriums[i] = PredatorBacterium(pos_x, pos_y, 0);
				break;
			case 2:
				Bacteriums[i] = OmnivorousBacterium(pos_x, pos_y, 0);
				break;
			}			
		}		
	}

	void Draw(HDC hdc, COLORREF Color);
};


class Sawerage
{
public:
	Sump Sumps[3];

	void Draw(HDC hdc);
};