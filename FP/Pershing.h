#pragma once
#include "Tank.h"
class Pershing :
	public Tank
{
public:
	Pershing(int x, int y, bool direction = true);
	void specialEvent(int choose);
	~Pershing();
};

