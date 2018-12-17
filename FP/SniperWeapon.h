#pragma once
#include "Weapon.h"
class SniperWeapon :
	public Weapon
{
public:
	SniperWeapon(int v, int x, int y, int angle, double height);
	~SniperWeapon();
};

