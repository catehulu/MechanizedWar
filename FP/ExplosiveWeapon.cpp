#include "ExplosiveWeapon.h"



ExplosiveWeapon::ExplosiveWeapon(int v, int x, int y, int angle, double height) :
	Weapon(v, x, y, angle, height)
{
	img = wxBitmap(wxBITMAP_PNG(#117)).ConvertToImage();
	double ar = img.GetWidth() / img.GetHeight();
	img.Rescale(ar*height, height, wxIMAGE_QUALITY_HIGH);
	setDmg(10);
}

void ExplosiveWeapon::DrawImpact(wxBufferedPaintDC & dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxRED)));
	dc.SetPen(wxPen(wxColor(*wxRED), 1, wxPENSTYLE_SOLID));
	dc.DrawCircle(wxPoint(impactX, impactY), 60);
}

ExplosiveWeapon::~ExplosiveWeapon()
{
}
