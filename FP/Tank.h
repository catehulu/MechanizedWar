#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
#include "Weapon.h"
class Tank
{
public:
	Tank(int x,int y, wxImage res,int direction);
	void Draw(wxBufferedPaintDC &dc);
	void Move(int amount, int maxX);
	void SetImage(wxImage res);
	void setWeapon(int vy, int x, int y);
	bool checkCollision(Tank* tank);
	bool checkCollision(int x, int y);
	bool tankArea(int x,int y);
	bool changeHealth(int x);
	Weapon* getWeapon();
	wxImage GetImage();
	~Tank();
	int getX();
	int getY();
	int direction; //1 untuk kekiri 2 untuk kekanan,kemungkinan diganti jadi 1 dan -1 karena rencana inisialisasi tank kiri dulu baru kanan
private:
	int x;
	int y;
	int height = 34,width = 108;
	int health = 100;
	wxBitmap* tankpic;
	Weapon *weapon;
};

