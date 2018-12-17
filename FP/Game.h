#pragma once
#include <wx/sound.h>
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
	wxSound *bgmmain=nullptr;
	wxSound *bgmover = nullptr;

public:
	Game(const wxString& title);
	void InitComponent();
	void ShowMain();
	void ShowOver(wxString winner);
	void ShowChoose();
	void ShowBoard(wxVector <int>, int mode);
	~Game();
};

