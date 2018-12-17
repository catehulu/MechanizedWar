#include "ExplosiveWeapon.h"



ExplosiveWeapon::ExplosiveWeapon(int v, int x, int y, int angle) :
	v(v), x(x), y(y), tx(x), ty(y), angle(angle)
{

}

void ExplosiveWeapon::Draw(wxBufferedPaintDC &dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLUE), 1, wxPENSTYLE_SOLID));
	dc.DrawCircle(wxPoint(tx, ty), wxCoord(10));
	wxMessageOutputDebug().Printf("----------bullet stats---------");
	wxMessageOutputDebug().Printf("bullet x %d.\n", x);
	wxMessageOutputDebug().Printf("bullet y %d.\n", y);
}

void ExplosiveWeapon::Move(bool direction, int t)
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

int ExplosiveWeapon::getX()
{
	return this->x;
}

int ExplosiveWeapon::getY()
{
	return this->y;
}

void ExplosiveWeapon::setX(int x)
{
	this->x = x;
}

void ExplosiveWeapon::setY(int y)
{
	this->y = y;
}

int ExplosiveWeapon::getDmg()
{
	return this->damage;
}

int ExplosiveWeapon::getTx()
{
	return tx;
}

int ExplosiveWeapon::getTy()
{
	return ty;
}

void ExplosiveWeapon::setV(int v)
{
	this->v = v;
}

void ExplosiveWeapon::setTx(int tx)
{
	this->tx = tx;
}

void ExplosiveWeapon::setTy(int ty)
{
	this->ty = ty;
}

void ExplosiveWeapon::setAngle(int angle)
{
	this->angle = angle;
}

void ExplosiveWeapon::reset()
{
	tx = x;
	ty = y;
}

int ExplosiveWeapon::getV()
{
	return this->v;
}

void ExplosiveWeapon::setDmg(int dmg)
{
	this->damage = dmg;
}


ExplosiveWeapon::~ExplosiveWeapon()
{
}
