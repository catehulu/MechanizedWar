#pragma once
#include "wx/dcbuffer.h"
#include <wx\wx.h>
class Obstacle
{
public:
	Obstacle();
	virtual bool intersect(int x, int y) = 0;
	virtual bool healthChange(int dmg) = 0;
	virtual void draw(wxBufferedPaintDC &dc) = 0;
	~Obstacle();
};

