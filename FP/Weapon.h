#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
#include <math.h>
class Weapon
{
public:
	Weapon(double v,int x,int y,int angle, double height);//default constructor weapon
	void Draw(wxBufferedPaintDC &dc);//gambar peluru
	void Move(bool direction,int t);//pergerakan peluru memakai rumus parabola
	int getX();
	int getY();
	double getV();
	int getDmg();
	int getTx();
	int getTy();
	void setX(int x);
	void setY(int y);
	void setDmg(int dmg);
	void setV(double v);
	void setTx(int tx);
	void setTy(int ty);
	void setAngle(int angle);
	void reset();
	~Weapon();
protected:
	wxImage img;
private:
	double tx;//posisi x temporary senjata
	double ty;//posisi y temporary senjata
	double x;//posisi x senjata
	double y;//posisi y senjata
	double maxv;
	double oldy_changes=0;//perubahan y lama
	double oldx_changes=0;// perubahan x lama
	double y_changes = 0;//perubahan y baru
	double x_changes = 0;//perubahan y lama
	int size;
	double v = 0;
	int damage = 100;
	const double g = 0.11;//konstanta gravitasi
	int angle;
};

