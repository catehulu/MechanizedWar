#include "Map.h"

Map::Map()
{
}
Map::Map(int x, int y, int width, int height)
	: x(x), y(y), width(width), height(height)
{
}
void Map::Draw(wxPaintDC &dc,int count)
{
	dc.SetBrush(wxBrush(wxColour(*wxRED)));
	dc.SetPen(wxPen(wxColor(*wxGREEN), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(this->width, this->height));
	wxFont font(40, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	wxString x;
	x << count;
	dc.SetFont(font);
	dc.SetTextForeground(wxColour(221, 34, 34));
	dc.DrawText(x, wxPoint(10, 10));
}