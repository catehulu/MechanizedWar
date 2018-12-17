#include "ExplosiveWeapon.h"



ExplosiveWeapon::ExplosiveWeapon(int v, int x, int y, int angle, double height) :
	Weapon(v, x, y, angle, height)
{
	img = wxBitmap(wxBITMAP_PNG(#117)).ConvertToImage();
	double ar = img.GetWidth() / img.GetHeight();
	img.Rescale(ar*height, height, wxIMAGE_QUALITY_HIGH);
	setDmg(10);
}

ExplosiveWeapon::~ExplosiveWeapon()
{
}
