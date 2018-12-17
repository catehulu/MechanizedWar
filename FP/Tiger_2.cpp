#include "Tiger_2.h"



Tiger_2::Tiger_2(int x, int y, bool direction)
	:Tank(30, 10)
{
	speed = 5;
	maxhealth = 350;
	currhealth = 350;
	height = 51;
	width = 119;
	equipedWeapon = 0;

	wxImageHandler* pngload = new wxPNGHandler();
	wxImage::AddHandler(pngload);

	wxImage tbody = wxBitmap(wxBITMAP_PNG(#102)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#103)).ConvertToImage();
	tbody.Rescale(width, height, wxIMAGE_QUALITY_HIGH);
	tgun.Rescale(73, 10, wxIMAGE_QUALITY_HIGH);
	//inisialisasi senajata
	armoury.push_back(new BasicWeapon(30, gunx, guny, angle, tgun.GetHeight()));
	armoury.push_back(new SniperWeapon(30, gunx, guny, angle, tgun.GetHeight()));
	armoury.push_back(new ExplosiveWeapon(30, gunx, guny, angle, tgun.GetHeight()));

	ammo[0] = 99999;
	ammo[1] = 20;
	ammo[2] = 10;

	weapon = armoury[0];
	SetBodyImage(tbody);
	SetGunImage(tgun);
	SetDirection(direction);
	this->y = y - tbody.GetHeight();
	this->x = x;
}

void Tiger_2::Move(int maxX, bool direction, wxVector<Obstacle*> obstacle)
{
	int tempx = x;
	if (!direction)
		tempx += speed * -1;
	else
		tempx += speed;
	for (int i = 0; i < obstacle.size(); i++)
	{
		if (obstacle[i]->intersect(tempx, this->y)) {
			return;
		}
	}
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
