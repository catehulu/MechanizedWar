#include "KV_2.h"



KV_2::KV_2(int x, int y, bool direction)
	:Tank(27,8)
{
	speed = 3;
	maxhealth = 220;
	currhealth = 220;
	height = 64;
	width = 122;
	equipedWeapon = 0;
	damage = 65;

	wxImage tbody = wxBitmap(wxBITMAP_PNG(#108)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#109)).ConvertToImage();
	tbody.Rescale(122, 64, wxIMAGE_QUALITY_HIGH);
	tgun.Rescale(49, 13, wxIMAGE_QUALITY_HIGH);
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

void KV_2::specialEvent(int choose)
{
	if (choose == 0)
		currhealth -= 20;
}


KV_2::~KV_2()
{
}
