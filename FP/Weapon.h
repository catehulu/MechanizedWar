#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
#include <math.h>
class Weapon
{
public:
	Weapon(int v,int x,int y,int angle);
	void Draw(wxBufferedPaintDC &dc);
	void Move(bool direction,int t);
	int getX();
	int getY();
	int getV();
	int getDmg();
	int getXS();
	int getYS();
	int getTx();
	int getTy();
	void setX(int x);
	void setY(int y);
	void setDmg(int dmg);
	void setV(int v);
	void setTx(int tx);
	void setTy(int ty);
	void setAngle(int angle);
	void reset();
	~Weapon();
private:
	int tx;//posisi x temporary senjata
	int ty;//posisi y temporary senjata
	int x;//posisi x senjata
	int y;//posisi y senjata
	int size;
	int v = 500;
	int damage = 100;
	const double g = 0.11;//konstanta gravitasi
	int angle;
};

