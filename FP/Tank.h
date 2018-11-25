#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
#include "Weapon.h"
class Tank
{
public:
	Tank(int x,int y, wxImage res);
	void Draw(wxBufferedPaintDC &dc);
	void Move(int amount, int maxX);
	void SetImage(wxImage res);
	void setWeapon(int vy, int x, int y);
	Weapon* getWeapon();
	wxImage GetImage();
	~Tank();
private:
	int x;
	int y;
	wxBitmap* tankpic;
	Weapon *weapon;
};

