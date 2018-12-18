#include "GameOver.h"

BEGIN_EVENT_TABLE(GameOver, wxPanel)
	EVT_PAINT(GameOver::OnPaint)
	EVT_LEFT_DOWN(GameOver::OnClick)
	EVT_TIMER(1000,GameOver::OnTimer)
END_EVENT_TABLE()

GameOver::GameOver(Game* parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	wxImage temp = wxBitmap(wxBITMAP_PNG(#120)).ConvertToImage();
	temp.Rescale(1920, 1080, wxIMAGE_QUALITY_HIGH);
	gaameover = new wxBitmap(temp);

	timer = new wxTimer(this, 1000);
}


GameOver::~GameOver()
{
	delete gaameover;
	delete timer;
}

void GameOver::OnClick(wxMouseEvent & event)
{
	if (event.GetX() >= 756 && event.GetX() <= 1163 && event.GetY() >= 476 && event.GetY() <= 605) {

	}
	else if (event.GetX() >= 756 && event.GetX() <= 1163 && event.GetY() >= 691 && event.GetY() <= 823) {

	}
}

void GameOver::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	pdc.DrawBitmap(*gaameover, wxPoint(0, 0), true);
	wxFont font(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	pdc.SetFont(font);
	pdc.SetTextForeground((wxColor(*wxBLACK)));
	pdc.DrawText(winner, wxPoint(910, 541));

}

void GameOver::OnTimer(wxTimerEvent & event)
{
	sec++;
	if (sec == 7) {
		timer->Stop();
		parentFrame->ShowMain();
		winner = "";
	}
}

void GameOver::TimerStart(wxString winner)
{
	this->winner = winner;
	timer->Start(1000);
	sec = 0;
}
