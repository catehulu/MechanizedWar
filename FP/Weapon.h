#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
#include <math.h>
class Weapon
{
public:
	Weapon();
	virtual void Draw(wxBufferedPaintDC &dc) = 0;
	virtual void Move(bool direction,int t) = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getV() = 0;
	virtual int getDmg() = 0;
	virtual int getTx() = 0;
	virtual int getTy() = 0;
	virtual void setX(int x) = 0;
	virtual void setY(int y) = 0;
	virtual void setDmg(int dmg) = 0;
	virtual void setV(int v) = 0;
	virtual void setTx(int tx) = 0;
	virtual void setTy(int ty) = 0;
	virtual void setAngle(int angle) = 0;
	virtual void reset() = 0;
	~Weapon();

};

