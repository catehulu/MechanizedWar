#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
class Tank
{
public:
	Tank(int x,int y);
	void Draw(wxPaintDC &dc);
	void Move(int amount, int maxX);
	~Tank();
private:
	int x;
	int y;

};

