#include "Tiger_1.h"



Tiger_1::Tiger_1(int x, int y, bool direction)
	:Tank(30,10)
{
	speed = 4;
	maxhealth = 260;
	currhealth = 260;
	height = 49;
	width = 107;
	wxImage tbody = wxBitmap(wxBITMAP_PNG(#106)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#107)).ConvertToImage();
	tbody.Rescale(107, 49, wxIMAGE_QUALITY_HIGH);
	tgun.Rescale(66, 10, wxIMAGE_QUALITY_HIGH);
	weapon = new Weapon(30, gunx, guny, angle,tgun.GetHeight());
	SetBodyImage(tbody);
	SetGunImage(tgun);
	SetDirection(direction);
	this->y = y - tbody.GetHeight();
	this->x = x;
}

void Tiger_1::Move(int maxX, bool direction)
{
	double tempx = x;
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

Tiger_1::~Tiger_1()
{
	delete weapon;
}
