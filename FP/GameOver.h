#pragma once
#include <wx/wx.h>
#include "Game.h"
class GameOver : public wxPanel
{
public:
	GameOver(Game* parent);
	~GameOver();

	void OnClick(wxMouseEvent& event);
	void OnPaint(wxPaintEvent& event);
	void OnTimer(wxTimerEvent& event);
	void TimerStart(wxString winner);

private:
	wxString winner;
	wxTimer* timer;
	Game* parentFrame;
	wxBitmap *gaameover = nullptr;
	DECLARE_EVENT_TABLE()
	int sec;
};

