#include "TankTraps.h"



TankTraps::TankTraps(int x, int y)
{
	traps1 = wxBitmap(wxBITMAP_PNG(#128)).ConvertToImage();
	traps2 = wxBitmap(wxBITMAP_PNG(#129)).ConvertToImage();
	traps3 = wxBitmap(wxBITMAP_PNG(#130)).ConvertToImage();
	traps1.Rescale(30, 50, wxIMAGE_QUALITY_HIGH);
	traps2.Rescale(30, 50, wxIMAGE_QUALITY_HIGH);
	traps3.Rescale(30, 50, wxIMAGE_QUALITY_HIGH);
	y -= 50;
	this->y = y;
	this->x = x;
	tanktraps = new wxRect(x, y, 30, 50);

}

bool TankTraps::intersect(int x, int y)
{
	if (tanktraps->Contains(x, y))
		return true;
	else
		return false;
}

bool TankTraps::healthChange(int dmg)
{
	health -= dmg;
	
	if (health < 0) {
		health = 0;
		return true;
	}
	else
		return false;
}

void TankTraps::draw(wxBufferedPaintDC & dc)
{
	wxImage tmp;
	if (health >= 1500)
		tmp = traps1;
	else if (health >= 1000)
		tmp = traps2;
	else
		tmp = traps3;
	
	dc.DrawBitmap(tmp, wxPoint(this->x,this->y),true);
}


TankTraps::~TankTraps()
{
	delete tanktraps;
	wxMessageOutputDebug().Printf("Delete commence");
}
