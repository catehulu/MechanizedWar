#include "Bush.h"



Bush::Bush(int x, int y)
{
	y -= 40;
	this->x = x;
	this->y = y;
	bush = new wxRect(x, y, 100, 40);
	bushes = wxBitmap(wxBITMAP_PNG(#137)).ConvertToImage();
	bushes.Rescale(100, 40, wxIMAGE_QUALITY_HIGH);
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
	dc.DrawBitmap(bushes, wxPoint(x, y));
}


Bush::~Bush()
{
	delete bush;
	wxMessageOutputDebug().Printf("Delete commence");
}
