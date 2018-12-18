#include "Pershing.h"



Pershing::Pershing(int x, int y, bool direction)
	:Tank(30,10)
{
	speed = 5;
	maxhealth = 310;
	currhealth = 310;
	height = 45;
	width = 109;
	equipedWeapon = 0;
	damage = 60;

	wxImage tbody = wxBitmap(wxBITMAP_PNG(#104)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#105)).ConvertToImage();
	tbody.Rescale(109, 45, wxIMAGE_QUALITY_HIGH);
	tgun.Rescale(78, 9, wxIMAGE_QUALITY_HIGH);
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

void Pershing::specialEvent(int choose)
{
	if (choose == 0)
		weapon->setCol(0);
}


Pershing::~Pershing()
{
}
