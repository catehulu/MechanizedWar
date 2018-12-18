#include "Panther.h"



Panther::Panther(int x, int y, bool direction)
	:Tank(41,10)
{
	speed = 6;
	maxhealth = 220;
	currhealth = 220;
	height = 49;
	width = 114;
	equipedWeapon = 0;
	damage = 40;

	wxImage tbody = wxBitmap(wxBITMAP_PNG(#114)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#115)).ConvertToImage();
	tbody.Rescale(114, 49, wxIMAGE_QUALITY_HIGH);
	tgun.Rescale(79, 10, wxIMAGE_QUALITY_HIGH);
	//inisialisasi senajata
	armoury.push_back(new BasicWeapon(30, gunx, guny, angle, tgun.GetHeight()));
	armoury.push_back(new ExplosiveWeapon(30, gunx, guny, angle, tgun.GetHeight()));

	armoury[0]->setDmg(armoury[0]->getDmg() + damage);
	armoury[1]->setDmg(armoury[1]->getDmg() + damage);

	ammo[0] = 100;
	ammo[1] = 20;

	weapon = armoury[0];
	SetBodyImage(tbody);
	SetGunImage(tgun);
	SetDirection(direction);
	this->y = y - tbody.GetHeight();
	this->x = x;
}

void Panther::specialEvent(int choose)
{
	if (choose == 3)
		speed = 3;
	if (choose == 4)
		speed = 6;
}


Panther::~Panther()
{
}
