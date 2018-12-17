#include "MainMenu.h"

BEGIN_EVENT_TABLE(MainMenu, wxPanel)
	EVT_PAINT(MainMenu::OnPaint)
	EVT_LEFT_DOWN(MainMenu::OnClick)
END_EVENT_TABLE()

MainMenu::MainMenu(Game* parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	wxImageHandler *pngloader = new wxPNGHandler();
	wxImage::AddHandler(pngloader);
	wxImage temp = wxBitmap(wxBITMAP_PNG(#118)).ConvertToImage();
	temp.Rescale(1920, 1080, wxIMAGE_QUALITY_HIGH);
	mainmenu = new wxBitmap(temp);

}


MainMenu::~MainMenu()
{
}

void MainMenu::OnClick(wxMouseEvent & event)
{
	if (event.GetX() >= 756 && event.GetX() <= 1163 && event.GetY() >= 476 && event.GetY() <= 605) {
		parentFrame->ShowChoose();
	}
	else if (event.GetX() >= 756 && event.GetX() <= 1163 && event.GetY() >= 691 && event.GetY() <= 823) {
		parentFrame->Close(true);
	}
}

void MainMenu::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*mainmenu, wxPoint(0, 0), true);
}
