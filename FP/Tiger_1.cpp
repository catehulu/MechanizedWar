#include "Tiger_1.h"



Tiger_1::Tiger_1(int x, int y, bool direction)
	:Tank(30,10)
{
	speed = 5;
	maxhealth = 260;
	currhealth = 260;
	height = 49;
	width = 135;
	equipedWeapon = 0;

	//inisialisasi senajata
	armoury.push_back(new BasicWeapon(5, gunx, guny, angle));
	armoury.push_back(new SniperWeapon(5, gunx, guny, angle));
	armoury.push_back(new ExplosiveWeapon(5, gunx, guny, angle));

	ammo[0] = 99999;
	ammo[1] = 20;
	ammo[2] = 10;

	weapon = armoury[0];
	wxImageHandler* pngload = new wxPNGHandler();
	wxImage::AddHandler(pngload);
	wxImage tbody = wxBitmap(wxBITMAP_PNG(#106)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#107)).ConvertToImage();
	tbody.Rescale(0.1*tbody.GetWidth(), 0.1*tbody.GetHeight());
	tgun.Rescale(0.1*tgun.GetWidth(), 0.1*tgun.GetHeight());
	SetBodyImage(tbody);
	SetGunImage(tgun);
	SetDirection(direction);
	this->y = y - tbody.GetHeight();
	this->x = x;
}

void Tiger_1::Move(int maxX, bool direction)
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

Tiger_1::~Tiger_1()
{
	delete weapon;
	for (int i = 0; i < armoury.size(); i++)
	{
		delete armoury[i];
	}
}
