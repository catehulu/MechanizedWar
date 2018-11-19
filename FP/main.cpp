#include <wx/wx.h>
#include "Game.h"
class MyApp : public wxApp
{
public:
	virtual bool OnInit();

};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	srand(time(NULL));
	Game *game = new Game(wxT("Mechanized War"));
	game->Center();
	game->Show(true);
	return true;
}