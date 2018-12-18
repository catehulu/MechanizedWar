#include "T_34.h"



T_34::T_34(int x, int y, bool direction)
	:Tank(40,10)
{
	speed = 5;
	maxhealth = 210;
	currhealth = 210;
	height = 39;
	width = 93;
	equipedWeapon = 0;
	damage = 30;

	wxImage tbody = wxBitmap(wxBITMAP_PNG(#112)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#113)).ConvertToImage();
	tbody.Rescale(93, 39, wxIMAGE_QUALITY_HIGH);
	tgun.Rescale(56, 8, wxIMAGE_QUALITY_HIGH);

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

void T_34::specialEvent(int damage)
{
	if (damage <= 5)
		return;
	currhealth += damage/2;

}


T_34::~T_34()
{
}
