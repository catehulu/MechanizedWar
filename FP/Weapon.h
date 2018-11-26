#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
#include <math.h>
class Weapon
{
public:
	Weapon(int v,int x,int y);
	void Draw(int direction,int t,wxBufferedPaintDC &dc);
	int getX();
	int getY();
	int getV();
	int getDmg();
	int getXS();
	int getYS();
	void setX(int x);
	void setY(int y);
	void setDmg(int dmg);
	void setV(int v);
	void setXS(int xs);
	void setYS(int ys);
	double cos(double x, double y);
	double sin(double x, double y);
	bool colisionCheck(int y, int t);
	~Weapon();
private:
	int xs;//jarak x untuk mencari segitiga
	int ys;//jarak y untuk mencari segitiga
	int x;//posisi x senjata
	int y;//posisi y senjata
	int size;
	int v = 500;
	int damage;
	const double g = 0.11;//konstanta gravitasi
};
