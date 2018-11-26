#pragma once
#include <wx\dcclient.h>
#include "wx\dcbuffer.h"
class Map
{
private:
	int x;
	int y;
	int width;
	int height;
public:
	Map();
	Map(int x, int y, int width, int height);
	void Draw(wxBufferedPaintDC &dc, int count,int stages);
};