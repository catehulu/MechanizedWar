#pragma once
#include "Obstacle.h"
class Building :
	public Obstacle
{
public:
	Building(int x,int y);
	bool intersect(int x, int y);
	bool healthChange(int dmg);
	void draw(wxBufferedPaintDC &dc);
	~Building();
private:
	int x, y;
	wxRect* building;
	int health = 1000;
	int maxhealth = 1000;
	int height;
};

