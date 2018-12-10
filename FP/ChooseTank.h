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
private:
	Game* parentFrame;
	wxBitmap *choosetank = nullptr;
	DECLARE_EVENT_TABLE()
};

