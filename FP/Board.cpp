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
	m_stsbar = parent->GetStatusBar();
	turn = -1;
	timer = new wxTimer(this, TIMER1_ID);
	timer2 = new wxTimer(this, TIMER2_ID);
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	SetBackgroundColour(wxColour(*wxBLACK));
	map = new Map(0, 600, 1024, 15);
	wxImageHandler* pngload = new wxPNGHandler();
	wxImage::AddHandler(pngload);
	wxImage body = wxBitmap(wxBITMAP_PNG(#106)).ConvertToImage();
	wxImage gun = wxBitmap(wxBITMAP_PNG(#107)).ConvertToImage();
	body.Rescale(0.1*body.GetWidth(), 0.1*body.GetHeight());
	gun.Rescale(0.1*gun.GetWidth(), 0.1*gun.GetHeight());
	tank1 = new Tank(5,570-body.GetHeight(),body,gun);
	tank2 = new Tank(500,570-body.GetHeight(),body,gun,false);
	
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
	this->map->Draw(pdc,counter);
	
}

void Board::OnKeyDown(wxKeyEvent & event)
{
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
		case WXK_UP:
			tank2->Rotate(1);
			break;
		case WXK_DOWN:
			tank2->Rotate(-1);
			break;
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
		case WXK_UP:
			tank1->Rotate(1);
			break;
		case WXK_DOWN:
			tank1->Rotate(-1);
			break;
		default:
			event.Skip();
			break;
		}
	}
}

void Board::OnTimer(wxTimerEvent & event)
{
	if (counter == 11)
	{
		turn *= -1;
		counter = 0;
	}
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);
}

void Board::OnTimeRender(wxTimerEvent & event)
{
	Refresh(true);
	//tank1->Rotate(1);
	//tank2->Rotate(1);
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



Board::~Board()
{
	Unbind(wxEVT_PAINT, &Board::OnPaint, this);
	Unbind(wxEVT_KEY_DOWN, &Board::OnKeyDown, this);
	Unbind(wxEVT_TIMER, &Board::OnTimer, this, TIMER1_ID);
	Unbind(wxEVT_TIMER, &Board::OnTimeRender, this, TIMER2_ID);
	timer->Stop();
	timer2->Stop();
	delete timer;
	delete timer2;
	delete tank1;
	delete tank2;
	delete map;
}
