#include "ChooseTank.h"

BEGIN_EVENT_TABLE(ChooseTank, wxPanel)
	EVT_PAINT(ChooseTank::OnPaint)
	EVT_LEFT_DOWN(ChooseTank::OnClick)
END_EVENT_TABLE()

ChooseTank::ChooseTank(Game* parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	wxImageHandler *jpgloader = new wxJPEGHandler();
	wxImage::AddHandler(jpgloader);
	wxImage image(wxT("Tank Selection.jpg"),
		wxBITMAP_TYPE_JPEG);
	choosetank = new wxBitmap(image);
}


ChooseTank::~ChooseTank()
{
}

void ChooseTank::OnClick(wxMouseEvent & event)
{
	if (event.GetX() >= 756 && event.GetX() <= 1163 && event.GetY() >= 476 && event.GetY() <= 605) {

	}
	else if (event.GetX() >= 756 && event.GetX() <= 1163 && event.GetY() >= 691 && event.GetY() <= 823) {

	}
}

void ChooseTank::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*choosetank, wxPoint(0, 0), true);
}
