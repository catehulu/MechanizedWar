#pragma once
#include "Tank.h"
class KV_2 :
	public Tank
{
public:
	KV_2(int x, int y, bool direction = true);
	void specialEvent(int choose);
	~KV_2();
};

