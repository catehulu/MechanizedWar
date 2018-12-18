#pragma once
#include "Weapon.h"
class ExplosiveWeapon :
	public Weapon
{
public:
	ExplosiveWeapon(int v, int x, int y, int angle, double height);
	void DrawImpact(wxBufferedPaintDC &dc);
	~ExplosiveWeapon();
};

