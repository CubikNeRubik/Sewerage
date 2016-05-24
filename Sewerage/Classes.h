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

class Sawerage
{
	Sump Sumps[3];
	//test

	void Draw();
};

class Sump
{
	int pos_x;
	int pos_y;

	Bacterium Bacteriums[10];
	int Type; // 0 - Vegan, 1 - Predator, 2 - Omnivorous//
	COLORREF Color;
	void Draw();
};

class Bacterium
{
public:
	int pos_x;
	int pos_y;
	int angel;

	int mass;
	int speed;

	Bacterium()
	{
		mass = 5;
		speed = 5;
	}

	void Draw();
	void Move();
};

class VeganBacterium : Bacterium
{
	VeganBacterium()
	{
		mass = 4;
		speed = 6;
	}
};

class PreatorBacterium : Bacterium
{
	PreatorBacterium()
	{
		mass = 6;
		speed = 5;
	}
};

class OmnivorousBacterium : Bacterium
{
	OmnivorousBacterium()
	{
		mass = 5;
		speed = 5;
	}
};