#include "Game.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "ChooseTank.h"
#include "Board.h"


void Game::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(1920, 1080));
	this->Layout();
}

Game::Game(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	/*wxStatusBar *sb = CreateStatusBar();
	sb->SetStatusText(wxT("0"));*/

	this->InitComponent();

}

void Game::InitComponent()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->mainPanel = new MainMenu(this);
	this->mainPanel->Show(false);
	this->boxSizer->Add(mainPanel, 1, wxEXPAND, 0);

	this->overPanel = new GameOver(this);
	this->overPanel->Show(false);
	this->boxSizer->Add(overPanel, 1, wxEXPAND, 0);

	this->choosePanel = new ChooseTank(this);
	this->choosePanel->Show(false);
	this->boxSizer->Add(choosePanel, 1, wxEXPAND, 0);

	this->boardPanel = new Board(this);
	this->boardPanel->Show(false);
	this->boxSizer->Add(boardPanel, 1, wxEXPAND, 0);

	SetSizer(boxSizer);
	ShowMain();
}

void Game::ShowMain()
{
	this->mainPanel->Show(true);
	this->overPanel->Show(false);
	this->choosePanel->Show(false);
	this->boardPanel->Show(false);

	fitWindowSize();
}

void Game::ShowOver(wxString winner)
{
	this->overPanel->TimerStart(winner);

	this->mainPanel->Show(false);
	this->overPanel->Show(true);
	this->choosePanel->Show(false);
	this->boardPanel->Show(false);

	fitWindowSize();
}

void Game::ShowChoose()
{
	this->mainPanel->Show(false);
	this->overPanel->Show(false);
	this->choosePanel->Show(true);
	this->boardPanel->Show(false);

	fitWindowSize();
}

void Game::ShowBoard(int i)
{
	if (i == 1)
		boardPanel->InitMode1();
	this->mainPanel->Show(false);
	this->overPanel->Show(false);
	this->choosePanel->Show(false);
	this->boardPanel->Show(true);
	this->boardPanel->SetFocusFromKbd();


	fitWindowSize();
}

Game::~Game()
{
}
