#include "BasicWeapon.h"



BasicWeapon::BasicWeapon(int v, int x, int y, int angle, double height) :
	Weapon(v, x, y, angle, height)
{
	img = wxBitmap(wxBITMAP_PNG(#116)).ConvertToImage();
	double ar = img.GetWidth() / img.GetHeight();
	img.Rescale(ar*height, height, wxIMAGE_QUALITY_HIGH);
}

BasicWeapon::~BasicWeapon()
{
}
