#include "Bush.h"



Bush::Bush(int x, int y)
{
	y -= 40;
	bush = new wxRect(x, y, 100, 40);
}

bool Bush::intersect(int x, int y)
{
	return false;
}

bool Bush::healthChange(int dmg)
{
	return false;
}

void Bush::draw(wxBufferedPaintDC & dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxGREEN)));
	dc.DrawRectangle(*bush);
}


Bush::~Bush()
{
}
