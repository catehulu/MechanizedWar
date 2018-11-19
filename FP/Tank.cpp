#include "Tank.h"



Tank::Tank(int x, int y)
	:x(x),y(y)
{
}

void Tank::Draw(wxPaintDC & dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLUE), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(40,
	10));
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


Tank::~Tank()
{
}
