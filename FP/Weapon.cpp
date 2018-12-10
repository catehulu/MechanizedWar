#include "Weapon.h"
#include <math.h>

Weapon::Weapon(int v,int x,int y,int angle) :
	v(v), x(x), y(y), tx(x), ty(y), angle(angle)
{
	
}

void Weapon::Draw(wxBufferedPaintDC &dc)
{
	dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLUE), 1, wxPENSTYLE_SOLID));
	dc.DrawCircle(wxPoint(tx,ty), wxCoord(10));
	wxMessageOutputDebug().Printf("----------bullet stats---------");
	wxMessageOutputDebug().Printf("bullet x %d.\n", x);
	wxMessageOutputDebug().Printf("bullet y %d.\n", y);
}

void Weapon::Move(bool direction, int t)
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

int Weapon::getX()
{
	return this->x;
}

int Weapon::getY()
{
	return this->y;
}

void Weapon::setX(int x)
{
	this->x = x;
}

void Weapon::setY(int y)
{
	this->y = y;
}

int Weapon::getDmg()
{
	return this->damage;
}

int Weapon::getTx()
{
	return tx;
}

int Weapon::getTy()
{
	return ty;
}

void Weapon::setV(int v)
{
	this->v = v;
}

void Weapon::setTx(int tx)
{
	this->tx = tx;
}

void Weapon::setTy(int ty)
{
	this->ty = ty;
}

void Weapon::setAngle(int angle)
{
	this->angle = angle;
}

void Weapon::reset()
{
	tx = x;
	ty = y;
}

int Weapon::getV()
{
	return this->v;
}

void Weapon::setDmg(int dmg)
{
	this->damage = dmg;
}

Weapon::~Weapon()
{
}
