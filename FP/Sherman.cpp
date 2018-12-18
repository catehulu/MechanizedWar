#include "Sherman.h"



Sherman::Sherman(int x, int y, bool direction)
	:Tank(36, 7)
{
	speed = 5;
	maxhealth = 200;
	currhealth = 200;
	height = 45;
	width = 103;
	equipedWeapon = 0;
	damage = 30;

	wxImage tbody = wxBitmap(wxBITMAP_PNG(#110)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#111)).ConvertToImage();
	tbody.Rescale(103, 45, wxIMAGE_QUALITY_HIGH);
	tgun.Rescale(38, 4, wxIMAGE_QUALITY_HIGH);
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

void Sherman::specialEvent(int choose)
{
	if (choose == 1)
		weapon->setDmg(weapon->getDmg() + 5);
}


Sherman::~Sherman()
{
}
