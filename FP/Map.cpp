#include "Map.h"
#include "wx/dcbuffer.h"

Map::Map(int x, int y, int width, int height)
	: x(x), y(y), width(width), height(height)
{
	jalan = wxBitmap(wxBITMAP_PNG(#138)).ConvertToImage();
	jalan.Rescale(1920, 80, wxIMAGE_QUALITY_HIGH);
}
void Map::Draw(wxBufferedPaintDC &dc,int count,int stages)
{
	dc.SetBrush(wxBrush(wxColour(*wxRED)));
	dc.SetPen(wxPen(wxColor(*wxGREEN), 1, wxPENSTYLE_SOLID));
	dc.DrawBitmap(this->jalan, wxPoint(this->x, this->y), true);
	//dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(this->width, this->height));
	if (stages > 2)
		return;
	wxFont font(40, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	wxString x;
	x << count;
	dc.SetFont(font);
	dc.SetTextForeground(wxColour(221, 34, 34));
	dc.DrawText(x, wxPoint(10, 10));
}