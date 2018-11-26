#pragma once
#include "Tank.h"
#include "Map.h"
#include "Weapon.h"
#include <vector>
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
	void Aiming(Tank* tank, int direction);
	~Board();

private:
	int shot;
	wxTimer *timer;
	wxTimer *timer2;
	std::vector <Tank*> tanks;
	Map *map;
	int turn;
	int counter;
	wxBitmap* tankpic = NULL;
	int t;
	int stages; //terdiri dari 3 stages, moving,aiming,shooting
};

