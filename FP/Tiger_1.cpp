#include "Tiger_1.h"



Tiger_1::Tiger_1(int x, int y, bool direction)
	:Tank(30,10)
{
	speed = 4;
	maxhealth = 260;
	currhealth = 260;
	height = 49;
	width = 107;
	equipedWeapon = 0;
	damage = 45;

	wxImage tbody = wxBitmap(wxBITMAP_PNG(#106)).ConvertToImage();
	wxImage tgun = wxBitmap(wxBITMAP_PNG(#107)).ConvertToImage();
	tbody.Rescale(107, 49, wxIMAGE_QUALITY_HIGH);
	tgun.Rescale(66, 10, wxIMAGE_QUALITY_HIGH);
	//inisialisasi senajata
	armoury.push_back(new BasicWeapon(30, gunx, guny, angle, tgun.GetHeight()));
	armoury.push_back(new SniperWeapon(30, gunx, guny, angle, tgun.GetHeight()));
	armoury.push_back(new ExplosiveWeapon(30, gunx, guny, angle, tgun.GetHeight()));

	armoury[0]->setDmg(armoury[0]->getDmg() + damage);
	armoury[1]->setDmg(armoury[1]->getDmg() + damage);
	armoury[2]->setDmg(armoury[2]->getDmg() + damage);

	ammo[0] = 100;
	ammo[1] = 20;
	ammo[2] = 10;

	weapon = armoury[0];
	SetBodyImage(tbody);
	SetGunImage(tgun);
	SetDirection(direction);
	this->y = y - tbody.GetHeight();
	this->x = x;
}

void Tiger_1::specialEvent(int damage)
{
	if (damage < 5)
		return;
	currhealth += 0.4 * damage;
}

Tiger_1::~Tiger_1()
{
	delete weapon;
	for (int i = 0; i < armoury.size(); i++)
	{
		delete armoury[i];
	}
}
