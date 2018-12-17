#pragma once
#include "Obstacle.h"
class TankTraps :
	public Obstacle
{
public:
	TankTraps(int x, int y);
	bool intersect(int x, int y);
	bool healthChange(int dmg);
	void draw(wxBufferedPaintDC &dc);
	~TankTraps();
private:
	int x, y;
	wxRect* tanktraps;
	int health = 2000;
	int maxhealth = 2000;
	wxImage traps1;
	wxImage traps2;
	wxImage traps3;
};

