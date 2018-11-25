#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
#include <math.h>
class Weapon
{
public:
	Weapon(int v,int x,int y);
	void Draw(int t,wxBufferedPaintDC &dc);
	int getX();
	int getY();
	int getDmg();
	void setV(int v);
	int getV();
	void setDmg(int dmg);
	double cos(double x, double y);
	double sin(double x, double y);
	bool colisionCheck(int y, int t);
	~Weapon();
private:
	int x;
	int y;
	int size;
	int v = 500;
	int damage;
	const double g = 0.11;//konstanta gravitasi
};

