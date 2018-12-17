#pragma once
#include "Tank.h"
class T_34 :
	public Tank
{
public:
	T_34(int x, int y, bool direction = true);
	void specialEvent(int choose);
	~T_34();
};

