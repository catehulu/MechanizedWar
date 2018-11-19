#pragma once
#include <wx\dcclient.h>
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
	void Draw(wxPaintDC &dc, int count);
};