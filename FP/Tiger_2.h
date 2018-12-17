#pragma once
#include "Tank.h"
class Tiger_2 :
	public Tank
{
public:
	Tiger_2(int x, int y, bool direction = true);
	void Move(int maxX, bool direction, wxVector<Obstacle*> obstacle);
	~Tiger_2();
};

