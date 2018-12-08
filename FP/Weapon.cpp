#include "Weapon.h"



Weapon::Weapon(int v,int x,int y) :
	v(v), x(x), y(y), tx(x), ty(y)
{
	xs = 30;
	ys = 30;
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

void Weapon::Move(int direction, int t)
{
	int x;
	int y;
	double y_changes;
	double x_changes;
	if (direction == 2) {
		y_changes = v * sin(xs, ys) * t - (0.5 * t*t*this->g);
		x_changes = v * cos(xs, ys) * t;
	}
	else {
		y_changes = v * sin(xs, ys) * t - (0.5 * t*t*this->g);
		x_changes = v * cos(xs, ys) * t * -1;
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

int Weapon::getXS()
{
	return this->xs;
}

int Weapon::getYS()
{
	return this->ys;
}

void Weapon::setV(int v)
{
	this->v = v;
}

void Weapon::setXS(int xs)
{
	this->xs = xs;
}

void Weapon::setYS(int ys)
{
	this->ys = ys;
}

int Weapon::getV()
{
	return this->v;
}

void Weapon::setDmg(int dmg)
{
	this->damage = dmg;
}

double Weapon::cos(double x, double y)
{
	double side;
	side = sqrt(x*x + y*y);

	return x/side;
}

double Weapon::sin(double x, double y)
{
	double side;
	side = sqrt(x*x + y * y);

	return y / side;
}

Weapon::~Weapon()
{
}
