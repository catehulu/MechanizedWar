#pragma once
#include "Tank.h"
class Sherman :
	public Tank
{
public:
	Sherman(int x, int y, bool direction = true);
	void specialEvent(int choose);
	~Sherman();
};

