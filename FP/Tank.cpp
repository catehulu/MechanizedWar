#include "Tank.h"


Tank::Tank(int x, int y, wxImage res)
	:x(x),y(y)
{
	SetImage(res);
}

void Tank::Draw(wxPaintDC & dc)
{
	/*dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLUE), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(40,
	10));*/
	dc.DrawBitmap(*this->tankpic,wxPoint(this->x,this->y),true);
	
}

void Tank::Move(int amount, int maxX)
{
	if (x + 15 >= maxX || x <= 0) {
		return;
	}
	else {
		x += amount;
	};
}

void Tank::SetImage(wxImage res)
{
	this->tankpic = new wxBitmap(res);
}


wxImage Tank::GetImage()
{
	return tankpic->ConvertToImage();
}

Tank::~Tank()
{
	delete tankpic;
}
