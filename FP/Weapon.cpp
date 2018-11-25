#include "Weapon.h"



Weapon::Weapon(int v,int x,int y) :
	v(v), x(x), y(y)
{
}

void Weapon::Draw(int t, wxBufferedPaintDC &dc)
{
	int x;
	int y;
	double y_changes;
	double x_changes;
	y_changes = v * sin(30, 30) * t - (0.5 * t*t*this->g);
	x_changes = v * cos(30, 30) * t;
	x = this->x + x_changes;
	y = this->y - y_changes;
	dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLUE), 1, wxPENSTYLE_SOLID));
	dc.DrawCircle(wxPoint(x,y), wxCoord(10));
	wxMessageOutputDebug().Printf("----------bullet stats---------");
	wxMessageOutputDebug().Printf("bullet x %d.\n", x);
	wxMessageOutputDebug().Printf("bullet x changes %lf.", x_changes);
	wxMessageOutputDebug().Printf("bullet y%d.\n", y);
	wxMessageOutputDebug().Printf("bullet y changes %lf.", y_changes);
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

void Weapon::setV(int v)
{
	this->v = v;
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

bool Weapon::colisionCheck(int y, int t)
{
	int tmp;
	double y_changes;
	y_changes = v * sin(30, 30) * t - (0.5 * t*t*this->g);
	tmp = this->y - y_changes;
	if (tmp > y)
		return false;
	else
		return true;
}


Weapon::~Weapon()
{
}
