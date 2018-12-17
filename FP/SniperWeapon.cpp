#include "SniperWeapon.h"



SniperWeapon::SniperWeapon(int v, int x, int y, int angle) :
	v(v), x(x), y(y), tx(x), ty(y), angle(angle)
{

}

void SniperWeapon::Draw(wxBufferedPaintDC &dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLUE), 1, wxPENSTYLE_SOLID));
	dc.DrawCircle(wxPoint(tx, ty), wxCoord(10));
	wxMessageOutputDebug().Printf("----------bullet stats---------");
	wxMessageOutputDebug().Printf("bullet x %d.\n", x);
	wxMessageOutputDebug().Printf("bullet y %d.\n", y);
}

void SniperWeapon::Move(bool direction, int t)
{
	int x;
	int y;
	double y_changes;
	double x_changes;
	if (direction) {
		y_changes = v * sin(angle * 3.1415 / 180.0) * t - (0.5 * t*t*this->g);
		x_changes = v * cos(angle * 3.1415 / 180.0) * t;
	}
	else {
		y_changes = v * sin(angle * 3.1415 / 180.0) * t - (0.5 * t*t*this->g);
		x_changes = v * cos(angle * 3.1415 / 180.0) * t * -1;
	}
	tx = this->x + x_changes;
	ty = this->y - y_changes;
}

int SniperWeapon::getX()
{
	return this->x;
}

int SniperWeapon::getY()
{
	return this->y;
}

void SniperWeapon::setX(int x)
{
	this->x = x;
}

void SniperWeapon::setY(int y)
{
	this->y = y;
}

int SniperWeapon::getDmg()
{
	return this->damage;
}

int SniperWeapon::getTx()
{
	return tx;
}

int SniperWeapon::getTy()
{
	return ty;
}

void SniperWeapon::setV(int v)
{
	this->v = v;
}

void SniperWeapon::setTx(int tx)
{
	this->tx = tx;
}

void SniperWeapon::setTy(int ty)
{
	this->ty = ty;
}

void SniperWeapon::setAngle(int angle)
{
	this->angle = angle;
}

void SniperWeapon::reset()
{
	tx = x;
	ty = y;
}

int SniperWeapon::getV()
{
	return this->v;
}

void SniperWeapon::setDmg(int dmg)
{
	this->damage = dmg;
}


SniperWeapon::~SniperWeapon()
{
}
