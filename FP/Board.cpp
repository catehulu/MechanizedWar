#include "Board.h"
#include "wx/dcbuffer.h"
#include "resource.h"
#define TIMER1_ID 12121
#define TIMER2_ID 12212

Board::Board(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition,
		wxDefaultSize, wxBORDER_NONE)
{
	counter = 0;
	turn = 1;
	t = 1;
	timer = new wxTimer(this, TIMER1_ID);
	timer2 = new wxTimer(this, TIMER2_ID);
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	SetBackgroundColour(wxColour(*wxWHITE));
	map = new Map(0, 600, 1024, 15);
	wxImageHandler* pngload = new wxPNGHandler();
	wxImage::AddHandler(pngload);
	wxImage gambar = wxBitmap(wxBITMAP_PNG(#101)).ConvertToImage();
	gambar.Rescale(108, 34);
	tank1 = new Tank(5,570,gambar);
	tank2 = new Tank(500,570,gambar.Mirror());
	
	timer->Start(1000);
	timer2->Start(1);


	Bind(wxEVT_PAINT, &Board::OnPaint, this);
	Bind(wxEVT_KEY_DOWN, &Board::OnKeyDown, this);
	Bind(wxEVT_TIMER, &Board::OnTimer, this, TIMER1_ID);
	Bind(wxEVT_TIMER, &Board::OnTimeRender, this, TIMER2_ID);
}

void Board::OnPaint(wxPaintEvent & event)
{
	//if (tankpic != NULL) pdc.DrawBitmap(*tankpic, wxPoint(100, 100), true); //coba gambar tank aja
	wxBufferedPaintDC pdc(this);
	pdc.SetBrush(wxBrush(wxColor(*wxWHITE)));
	pdc.DrawRectangle(wxPoint(0, 0), this->GetClientSize());
	this->tank1->Draw(pdc);
	this->tank2->Draw(pdc);
	this->map->Draw(pdc,counter,shot);

	if (shot == 1) {
		wxMessageOutputDebug().Printf("----------shooting stats---------");
		wxMessageOutputDebug().Printf("weapon Y : %d",tank1->getWeapon()->getY());
		if (tank1->getWeapon()->colisionCheck(600, t)) {
			this->tank1->getWeapon()->Draw(t, pdc); //draw bullets
			t++;
		}
		else {
			t = 0;
			shot = 0;
			counter = 0;
			turn *= -1;
			timer->Start(1000);
		}
	}
	

}

void Board::OnKeyDown(wxKeyEvent & event)
{
	if (shot == 1)
		return;
	int keycode = event.GetKeyCode();
	if (turn == -1) {
		switch (keycode)
		{
		case WXK_LEFT:
			Moving(tank2, 1);
			break;
		case WXK_RIGHT:
			Moving(tank2, 2);
			break;
		case WXK_SPACE:
			Shooting(tank2, 1);
		default:
			event.Skip();
			break;
		}
	}

	if (turn == 1) {
		switch (keycode)
		{
		case WXK_LEFT:
			Moving(tank1, 1);
			break;
		case WXK_RIGHT:
			Moving(tank1, 2);
			break;
		case WXK_SPACE:
			Shooting(tank1, 2);
		default:
			event.Skip();
			break;
		}
	}
}

void Board::OnTimer(wxTimerEvent & event)
{
	if (shot == 1)
		counter = 0;
	if (counter == 11)
	{
		turn *= -1;
		counter = 0;
	}
	wxMessageOutputDebug().Printf("----------board stats---------");
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);
	wxMessageOutputDebug().Printf("t event %d.", t);
}

void Board::OnTimeRender(wxTimerEvent & event)
{
	Refresh(true);
}

void Board::Moving(Tank * tank, int direction)
{
	wxMessageOutputDebug().Printf("Move Initiated\n");
	if (direction == 1) {
		tank->Move(-4, GetClientSize().GetWidth());
	}
	else if (direction == 2) {
		tank->Move(4, GetClientSize().GetWidth());
	}
	//this->Update();
	//this->Refresh(true);
}

void Board::Shooting(Tank * tank, int direction)
{
	shot = 1;
	tank->getWeapon()->setX(tank->getX());
	tank->getWeapon()->setY(tank->getY());
	timer->Stop();
}



Board::~Board()
{
	timer->Stop();
	timer2->Stop();
	delete timer;
	delete timer2;
	delete tank1;
	delete tank2;
	delete map;
	delete tankpic;
}
