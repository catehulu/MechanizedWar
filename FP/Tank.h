#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
class Tank
{
public:
	Tank(int x,int y, wxImage body, wxImage gun, bool direction = true);
	void Draw(wxBufferedPaintDC &dc);
	void Move(int amount, int maxX);
	void Rotate(int amount);
	void SetBodyImage(wxImage res);
	void SetGunImage(wxImage res);
	void SetDirection(bool direction);
	bool GetDirection();
	wxImage GetBodyImage();
	wxImage GetGunImage();
	~Tank();
private:
	int x;
	int y;
	int gunx=30;
	int guny=10;
	int angle=0;
	bool direction;
	wxImage body;
	wxImage gun;
	wxBitmap bodybmp;
	wxBitmap gunbmp;

};

