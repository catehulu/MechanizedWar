#pragma once
#include "Tank.h"
#include "Map.h"
#include "Weapon.h"
#include <wx/wx.h>
class Board : public wxPanel
{
public:
	Board(wxFrame *parent);
	void OnPaint(wxPaintEvent& event);
	void OnKeyDown(wxKeyEvent& event);
	void OnTimer(wxTimerEvent& event);
	void OnTimeRender(wxTimerEvent& event);
	void Moving(Tank* tank, int direction);
	~Board();
private:
	wxTimer *timer;
	wxTimer *timer2;
	Tank *tank1;
	Tank *tank2;
	Map *map;
	int turn;
	wxStatusBar *m_stsbar;
	int counter;
	wxBitmap* tankpic = NULL;
	int t;
};

