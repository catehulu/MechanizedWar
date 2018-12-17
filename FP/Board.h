#pragma once
#include "Game.h"
#include "Tank.h"
#include "Map.h"
#include "Weapon.h"
#include "Tiger_1.h"
#include <vector>
#include <wx/wx.h>
class Board : public wxPanel
{
public:
	Board(Game *parent);
	void OnPaint(wxPaintEvent& event);
	void OnKeyDown(wxKeyEvent& event);
	void OnTimer(wxTimerEvent& event);
	void OnTimeRender(wxTimerEvent& event);
	void Moving(Tank* tank, bool direction);
	void Shooting(Tank* tank, bool direction);
	void GameOver(wxString winner);
	void InitMode1(wxVector <int> choosen);
	~Board();

private:
	int shot;
	int mode;
	int team1;
	int team2;
	wxTimer *timer;
	wxTimer *timer2;
	wxVector <Tank*> tanks;
	Map *map;
	int turn;
	int counter;
	wxBitmap* tankpic = NULL;
	int t;
	int stages; //terdiri dari 3 stages, moving,aiming,shooting
	Game* parentFrame;
};

