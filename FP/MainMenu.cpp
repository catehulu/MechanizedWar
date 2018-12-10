#include "MainMenu.h"

BEGIN_EVENT_TABLE(MainMenu, wxPanel)
	EVT_PAINT(MainMenu::OnPaint)
	EVT_LEFT_DOWN(MainMenu::OnClick)
END_EVENT_TABLE()

MainMenu::MainMenu(Game* parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	wxImageHandler *jpgloader = new wxJPEGHandler();
	wxImage::AddHandler(jpgloader);

	wxImage image(wxT("Main Menu.jpg"),
		wxBITMAP_TYPE_JPEG);
	mainmenu = new wxBitmap(image);

}


MainMenu::~MainMenu()
{
}

void MainMenu::OnClick(wxMouseEvent & event)
{
	if (event.GetX() >= 756 && event.GetX() <= 1163 && event.GetY() >= 476 && event.GetY() <= 605) {
		parentFrame->ShowBoard(1);
	}
	else if (event.GetX() >= 756 && event.GetX() <= 1163 && event.GetY() >= 691 && event.GetY() <= 823) {

	}
}

void MainMenu::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*mainmenu, wxPoint(0, 0), true);
}
