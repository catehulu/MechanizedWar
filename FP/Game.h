#pragma once
#include "wx\wx.h"

class MainMenu;
class GameOver;
class Board;
class ChooseTank;

class Game : public wxFrame
{
private:
	wxBoxSizer* boxSizer;
	MainMenu* mainPanel;
	GameOver* overPanel;
	ChooseTank* choosePanel;
	Board* boardPanel;
	void fitWindowSize();

public:
	Game(const wxString& title);
	void InitComponent();
	void ShowMain();
	void ShowOver(wxString winner);
	void ShowChoose();
	void ShowBoard(wxVector <int>, int mode);
	~Game();
};

