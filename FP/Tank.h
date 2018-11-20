#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
class Tank
{
public:
	Tank(int x,int y, wxImage res);
	void Draw(wxPaintDC &dc);
	void Move(int amount, int maxX);
	void SetImage(wxImage res);
	wxImage GetImage();
	~Tank();
private:
	int x;
	int y;
	wxBitmap* tankpic;

};

