#pragma once
#include <wx\wx.h>
#include <wx\dcclient.h>
#include "wx/dcbuffer.h"
class Tank
{
public:
	Tank(int x,int y, wxImage res);
	void Draw(wxBufferedPaintDC &dc);
	void Move(int amount, int maxX);
	void SetImage(wxImage res);
	wxImage GetImage();
	~Tank();
private:
	int x;
	int y;
	wxBitmap* tankpic;

};

