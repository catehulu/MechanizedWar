#pragma once
#include <wx/wx.h>
#include "Game.h"
class ChooseTank : public wxPanel
{
public:
	ChooseTank(Game* parent);
	~ChooseTank();

	void OnClick(wxMouseEvent& event);
	void OnPaint(wxPaintEvent& event);
	void Initiated();
	void Reset();
private:
	int min = 0;
	int max = 6;
	wxVector <int> cycle;
	Game* parentFrame;
	wxBitmap *choosetank = nullptr;
};

