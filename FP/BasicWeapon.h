#pragma once
#include "Weapon.h"
class BasicWeapon :
	public Weapon
{
public:
	BasicWeapon(int v, int x, int y, int angle, double height);
	~BasicWeapon();
};

