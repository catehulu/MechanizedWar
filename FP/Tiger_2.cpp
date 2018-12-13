#include "Tiger_2.h"



Tiger_2::Tiger_2(int x, int y, bool direction)
	:Tank(30, 10)
{
	speed = 5;
	maxhealth = 350;
	currhealth = 350;
	height = 51;
	width = 119;
	wxImage tbody = wxBitmap(wxBITMAP_PNG(#102)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#103)).ConvertToImage();
	tbody.Rescale(width, height, wxIMAGE_QUALITY_HIGH);
	tgun.Rescale(73, 10, wxIMAGE_QUALITY_HIGH);
	weapon = new Weapon(40, gunx, guny, angle,tgun.GetHeight());
	SetBodyImage(tbody);
	SetGunImage(tgun);
	SetDirection(direction);
	this->y = y - tbody.GetHeight();
	this->x = x;
}

void Tiger_2::Move(int maxX, bool direction)
{
	int tempx = x;
	if (!direction)
		tempx += speed * -1;
	else
		tempx += speed;
	if (tempx + 15 >= maxX || tempx <= 0) {
		return;
	}
	else
	{
		x = tempx;
	}
}

Tiger_2::~Tiger_2()
{
	delete weapon;
}
