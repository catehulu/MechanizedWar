#pragma once
#include "Tank.h"
class Tiger_1 :
	public Tank
{
public:
	Tiger_1(int x, int y, bool direction = true);
	void Move(int maxX, bool direction);
	~Tiger_1();
};

