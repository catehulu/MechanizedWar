#include "Game.h"



Game::Game(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1024, 768))
{
	wxStatusBar *sb = CreateStatusBar();
	sb->SetStatusText(wxT("0"));
	Board *board = new Board(this);
	board->SetFocus();
}

Game::~Game()
{
}
