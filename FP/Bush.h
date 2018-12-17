#pragma once
#include "Obstacle.h"
class Bush :
	public Obstacle
{
public:
	Bush(int x, int y);
	bool intersect(int x, int y);
	bool healthChange(int dmg);
	void draw(wxBufferedPaintDC &dc);
	~Bush();
private:
	int x, y;
	wxRect* bush;
};
