#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
#include "Weapon.h"
#include "BasicWeapon.h"
#include "SniperWeapon.h"
#include "ExplosiveWeapon.h"
#include "resource.h"
class Tank
{
public:
	Tank(int gunx, int guny);
	void Draw(wxBufferedPaintDC &dc);
	void DrawVelocity(wxBufferedPaintDC &dc);
	void DrawCurrentWeapon(wxBufferedPaintDC &dc);
	virtual void Move(int maxX,bool direction) = 0;
	void Rotate(int amount);
	void SetBodyImage(wxImage res);
	void SetGunImage(wxImage res);
	void SetDirection(bool direction);
	bool GetDirection();
	wxImage GetBodyImage();
	wxImage GetGunImage();
	virtual bool checkCollision(int x, int y);
	virtual bool tankArea(int x,int y,int weapon);
	bool changeHealth(int x);
	Weapon* getWeapon();
	void changeWeapon(int i);
	int ammoCheck();
	void ammoReduce();
	void initiateShooting();
	~Tank();
	int getX();
	int getY();
	int getEquiped();
	void setX(int x);
	void sety(int y);

protected:
	int x;
	int y;
	Weapon *weapon;
	wxVector <Weapon* > armoury;
	int ammo[3];
	int equipedWeapon = 0;
	int height,width;
	int speed;
	int gunx;
	int guny;
	int angle=0;
	int maxhealth;
	int currhealth;
private:
	int add = 1;
	bool direction;
	wxImage body;
	wxImage gun;
	wxBitmap bodybmp;
	wxBitmap gunbmp;
};

