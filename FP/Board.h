#pragma once
#include "Game.h"
#include "Tank.h"
#include "Map.h"
#include "Weapon.h"
#include "wx/sound.h"
#include "Tiger_1.h"
#include "Tiger_2.h"
#include "Panther.h"
#include "KV_2.h"
#include "Sherman.h"
#include "Pershing.h"
#include "T_34.h"
#include "Obstacle.h"
#include "Building.h"
#include "Bush.h"
#include "TankTraps.h"
#include <vector>
#include <wx/wx.h>
#include <time.h>
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
	wxVector <Obstacle*> obstacle;
	Map *map;
	int turn;
	int counter;
	wxBitmap* imgpic = NULL;
	int t;
	int stages; //terdiri dari 3 stages, moving,aiming,shooting
	Game* parentFrame;
	wxSound *shoot = nullptr;
	wxSound *shotsound = nullptr;

};

