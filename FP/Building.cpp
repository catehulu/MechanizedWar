#include "Building.h"



Building::Building(int x, int y)
{
	height = 250;
	y -= height;
	this->y = y;
	this->x = x;
	building = new wxRect(x, y, 100, height);
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
	}
	else if (health >= 500) {
		building->SetHeight(height - 100);
		building->SetY(y + 100);
	}
	else {
		building->SetHeight(height - 200);
		building->SetY(y + 200);
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
	if(health >= 800)
		dc.SetBrush(wxBrush(wxColour(*wxGREEN)));
	else if(health >= 500)
		dc.SetBrush(wxBrush(wxColour(*wxYELLOW)));
	else
		dc.SetBrush(wxBrush(wxColour(*wxRED)));
	dc.DrawRectangle(*building);
}


Building::~Building()
{
	delete building;
}
