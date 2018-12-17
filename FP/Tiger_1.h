#pragma once
#include "Tank.h"
class Tiger_1 :
	public Tank
{
public:
	Tiger_1(int x, int y, bool direction = true);
	void specialEvent(int choose);
	~Tiger_1();
};

