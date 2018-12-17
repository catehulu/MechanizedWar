#include "BasicWeapon.h"



BasicWeapon::BasicWeapon(int v, int x, int y, int angle) :
	v(v), x(x), y(y), tx(x), ty(y), angle(angle)
{

}

void BasicWeapon::Draw(wxBufferedPaintDC &dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLUE), 1, wxPENSTYLE_SOLID));
	dc.DrawCircle(wxPoint(tx, ty), wxCoord(10));
	wxMessageOutputDebug().Printf("----------bullet stats---------");
	wxMessageOutputDebug().Printf("bullet x %d.\n", x);
	wxMessageOutputDebug().Printf("bullet y %d.\n", y);
}

void BasicWeapon::Move(bool direction, int t)
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

int BasicWeapon::getX()
{
	return this->x;
}

int BasicWeapon::getY()
{
	return this->y;
}

void BasicWeapon::setX(int x)
{
	this->x = x;
}

void BasicWeapon::setY(int y)
{
	this->y = y;
}

int BasicWeapon::getDmg()
{
	return this->damage;
}

int BasicWeapon::getTx()
{
	return tx;
}

int BasicWeapon::getTy()
{
	return ty;
}

void BasicWeapon::setV(int v)
{
	this->v = v;
}

void BasicWeapon::setTx(int tx)
{
	this->tx = tx;
}

void BasicWeapon::setTy(int ty)
{
	this->ty = ty;
}

void BasicWeapon::setAngle(int angle)
{
	this->angle = angle;
}

void BasicWeapon::reset()
{
	tx = x;
	ty = y;
}

int BasicWeapon::getV()
{
	return this->v;
}

void BasicWeapon::setDmg(int dmg)
{
	this->damage = dmg;
}

BasicWeapon::~BasicWeapon()
{
}
