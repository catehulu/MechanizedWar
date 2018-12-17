#include "Weapon.h"
#include "wx/graphics.h"
#include <math.h>

Weapon::Weapon(double v,int x,int y,int angle, double height) :
	maxv(v), x(x), y(y), tx(x), ty(y), angle(angle)
{
	
}

void Weapon::Draw(wxBufferedPaintDC &dc)
{
	/*dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLUE), 1, wxPENSTYLE_SOLID));
	dc.DrawCircle(wxPoint(tx,ty), wxCoord(10));*/
	double angle = atan2(-(y_changes-oldy_changes), x_changes-oldx_changes)* 180.0 / 3.1415 ;
	if (angle < 0) angle += 360.0;
	wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
	wxImage temp = img.Rotate(-angle * 3.1415/180.0, wxPoint(0, 0), true);
	//	gungbmp = gc->CreateBitmapFromImage(temp);
	
	//	bodygbmp = gc->CreateBitmapFromImage(tempbody);
		//Sistem Pivot biar tembakan memutar pada satu titik//
	double xcomp = -img.GetHeight() / 2, ycomp = -img.GetHeight() / 4;
	if (angle >= 270 && angle <= 360)  //180-270
	{

	}
	else if ( angle >= 180 && angle <= 270) //270-360
	{
		xcomp = -temp.GetWidth() + img.GetHeight(); //wxMessageOutputDebug().Printf("disini 270");

	}
	else if ( angle >= 90 && angle <= 180)  //0-90
	{
		ycomp = -temp.GetHeight() + img.GetHeight();
		xcomp = -temp.GetWidth() + img.GetHeight(); //wxMessageOutputDebug().Printf("disini 180");
	}
	else if (angle >= 0 && angle <= 90) //90-180
	{
		ycomp = -temp.GetHeight() + img.GetHeight();
	}
	gc->DrawBitmap(temp, tx+xcomp, ty+ycomp, temp.GetWidth(), temp.GetHeight());
	/*wxMessageOutputDebug().Printf("----------bullet stats---------");
	wxMessageOutputDebug().Printf("bullet x %lf.\n", tx);
	wxMessageOutputDebug().Printf("bullet y %lf.\n", ty);*/
	//wxMessageOutputDebug().Printf("bullet angle %lf.\n", angle);
	delete gc;

}

void Weapon::Move(bool direction, int t)
{
	oldx_changes = x_changes;
	oldy_changes = y_changes;
	if (direction) {
		y_changes = v * maxv * sin(angle * 3.1415 / 180.0) * t - (0.5 * t*t*this->g);
		x_changes = v * maxv * cos(angle * 3.1415 / 180.0) * t;
	}
	else {
		y_changes = v * maxv * sin(angle * 3.1415 / 180.0) * t - (0.5 * t*t*this->g);
		x_changes = v * maxv * cos(angle * 3.1415 / 180.0) * t * -1;
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

void Weapon::setV(double v)
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

double Weapon::getV()
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
