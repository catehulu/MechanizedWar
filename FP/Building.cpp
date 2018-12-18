#include "Building.h"



Building::Building(int x, int y)
{
	height = 250;
	y -= height;
	this->y = y;
	this->x = x;
	ynow = y;
	building = new wxRect(x, y, 100, height);

	state1 = wxBitmap(wxBITMAP_PNG(#134)).ConvertToImage();
	state2 = wxBitmap(wxBITMAP_PNG(#135)).ConvertToImage();
	state3 = wxBitmap(wxBITMAP_PNG(#136)).ConvertToImage();

	state1.Rescale(100, 250, wxIMAGE_QUALITY_HIGH);
	state2.Rescale(100, 150, wxIMAGE_QUALITY_HIGH);
	state3.Rescale(100, 100, wxIMAGE_QUALITY_HIGH);

}

bool Building::intersect(int x, int y)
{
	if (building->Contains(x, y))
		return true;
	else
		return false;
}

bool Building::healthChange(int dmg)
{
	health -= dmg;
	if (health >= 800) {
		building->SetHeight(height);
		ynow = y;
	}
	else if (health >= 500) {
		ynow = y + 100;
		building->SetHeight(height - 100);
		building->SetY(ynow);
	}
	else {
		ynow = y + 150;
		building->SetHeight(height - 200);
		building->SetY(ynow);
	}
	if (health < 0) {
		health = 0;
		return true;
	}
	else
		return false;

}

void Building::draw(wxBufferedPaintDC & dc)
{
	if (health >= 800)
		dc.DrawBitmap(state1, wxPoint(x, ynow), true);
	else if(health >= 500)
		dc.DrawBitmap(state2, wxPoint(x, ynow), true);
	else
		dc.DrawBitmap(state3, wxPoint(x, ynow), true);
}


Building::~Building()
{
	delete building;
	wxMessageOutputDebug().Printf("Delete commence");
}
