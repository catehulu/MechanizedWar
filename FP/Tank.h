#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
#include "Weapon.h"
#include "wx/graphics.h"
#include "BasicWeapon.h"
#include "SniperWeapon.h"
#include "ExplosiveWeapon.h"
#include "resource.h"
#include "Obstacle.h"
class Tank
{
public:
	Tank(int gunx, int guny);
	void Draw(wxBufferedPaintDC &dc);
	void DrawVelocity(wxBufferedPaintDC &dc);
	void DrawCurrentWeapon(wxBufferedPaintDC &dc);
	void Move(int maxX,bool direction, wxVector<Obstacle*> obstacle);
	virtual void specialEvent(int choose) = 0;
	void Rotate(int amount);
	void SetBodyImage(wxImage res);
	void SetGunImage(wxImage res);
	void SetDirection(bool direction);
	bool GetDirection();
	wxImage GetBodyImage();
	wxImage GetGunImage();
	virtual bool checkCollision(int x, int y);
	virtual bool checkCollisionObstacle(Obstacle* obstalce);
	virtual bool tankArea(int x,int y,int weapon);
	bool changeHealth(int x);
	Weapon* getWeapon();
	void changeWeapon(int i);
	bool ammoCheck();
	void ammoReduce();
	void initiateShooting();
	~Tank();
	int getX();
	int getY();
	int getWidth();
	int getEquiped();
	int getDmg();
	void setDmg(int i);
	void setX(int x);
	void sety(int y);

protected:
	double x;
	double y;
	Weapon *weapon;
	wxVector <Weapon* > armoury;
	int ammo[3];
	int equipedWeapon = 0;
	int height,width;
	double speed;
	double gunx;
	double guny;
	double angle=0;
	int maxhealth;
	int currhealth;
	int damage;
private:
	int add = 1;
	bool direction;
	wxImage apicon;
	wxImage heicon;
	wxImage body;
	wxImage gun;
	wxBitmap bodybmp;
	wxBitmap gunbmp;
	wxGraphicsBitmap bodygbmp;
	wxGraphicsBitmap gungbmp;
};

