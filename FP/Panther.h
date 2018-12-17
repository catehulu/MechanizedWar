#pragma once
#include "Tank.h"
class Panther :
	public Tank
{
public:
	Panther(int x, int y, bool direction = true);
	void specialEvent(int choose);
	~Panther();
};

