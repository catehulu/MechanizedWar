#pragma once
#include <wx/wx.h>
#include "Game.h"
class MainMenu : public wxPanel
{
public:
	MainMenu(Game* parent);
	~MainMenu();

	void OnClick(wxMouseEvent& event);
	void OnPaint(wxPaintEvent& event);
private:
	Game* parentFrame;
	wxBitmap *mainmenu = nullptr;
	DECLARE_EVENT_TABLE()
};

