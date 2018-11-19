#include "Board.h"



Board::Board(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition,
		wxDefaultSize, wxBORDER_NONE)
{
	counter = 0;
	m_stsbar = parent->GetStatusBar();
	turn = 1;
	timer = new wxTimer(this, 1);
	SetBackgroundColour(wxColour(*wxWHITE));
	map = new Map(0, 600, 1024, 15);
	tank1 = new Tank(5,590);
	tank2 = new Tank(500,590);
	timer->Start(1000);

	Connect(wxEVT_PAINT, wxPaintEventHandler(Board::OnPaint));
	Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(Board::OnKeyDown));
	Connect(wxEVT_TIMER, wxCommandEventHandler(Board::OnTimer));
}

void Board::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
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
		default:
			event.Skip();
			break;
		}
	}
}

void Board::OnTimer(wxCommandEvent & event)
{
	if (counter == 11)
	{
		turn *= -1;
		counter = 0;
	}
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);
	Refresh();

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
	Refresh();
}



Board::~Board()
{
	timer->Stop();
	delete timer;
	delete tank1;
	delete tank2;
	delete map;
}
