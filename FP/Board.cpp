#include "Board.h"
#include "wx/dcbuffer.h"
#include "resource.h"
#define TIMER1_ID 12121
#define TIMER2_ID 12212

Board::Board(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition,
		wxDefaultSize, wxBORDER_NONE)
{
	//inisialisasi game awal
	shot = 0;
	stages = 1;
	counter = 0;
	turn = 0;
	t = 1;
	timer = new wxTimer(this, TIMER1_ID);
	timer2 = new wxTimer(this, TIMER2_ID);
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	//inisialisasi map
	SetBackgroundColour(wxColour(*wxWHITE));
	map = new Map(0, 1000, 1920, 15);
	wxImageHandler* pngload = new wxPNGHandler();
	wxImage::AddHandler(pngload);
	wxImage gambar = wxBitmap(wxBITMAP_PNG(#101)).ConvertToImage();
	gambar.Rescale(108, 34);

	//inisialisasi tank
	tanks.push_back(new Tank(5, 970, gambar,2));
	tanks.push_back(new Tank(1700, 970, gambar.Mirror(),1));
	
	timer->Start(1000);
	timer2->Start(1);


	Bind(wxEVT_PAINT, &Board::OnPaint, this);
	Bind(wxEVT_KEY_DOWN, &Board::OnKeyDown, this);
	Bind(wxEVT_TIMER, &Board::OnTimer, this, TIMER1_ID);
	Bind(wxEVT_TIMER, &Board::OnTimeRender, this, TIMER2_ID);
}

void Board::OnPaint(wxPaintEvent & event)
{
	int hit = 1;
	//if (tankpic != NULL) pdc.DrawBitmap(*tankpic, wxPoint(100, 100), true); //coba gambar tank aja
	wxBufferedPaintDC pdc(this);
	pdc.SetBrush(wxBrush(wxColor(*wxWHITE)));
	pdc.DrawRectangle(wxPoint(0, 0), this->GetClientSize());
	//menggambar tank
	for (int i = 0; i < tanks.size(); i++) {
		if(tanks[i] != nullptr)
			this->tanks[i]->Draw(pdc);
	}
	this->map->Draw(pdc,counter,stages);
	//menggambar peluru jika ada kondisi menembak
	if (stages == 3) {
		/*wxMessageOutputDebug().Printf("----------Aiming stats---------");
		wxMessageOutputDebug().Printf("weapon Y : %d",tanks[turn]->getWeapon()->getY());*/
		for (int i = 0; i < tanks.size(); i++)
		{
			if (i == turn || tanks[i] == nullptr)
				continue;
			else if (tanks[i]->tankArea(tanks[turn]->getWeapon()->tx, tanks[turn]->getWeapon()->ty)) {
				if (tanks[i]->changeHealth(tanks[turn]->getWeapon()->getDmg())) {
					delete tanks[i];
					tanks[i] = nullptr;
				}
				tanks[turn]->getWeapon()->tx = tanks[turn]->getWeapon()->getX();
				tanks[turn]->getWeapon()->ty = tanks[turn]->getWeapon()->getY();
				hit = 0;
				break;
			}
		}
		if (tanks[turn]->checkCollision(GetClientSize().GetWidth(), 1000) && hit) {
			this->tanks[turn]->getWeapon()->Move(tanks[turn]->direction, t);
			this->tanks[turn]->getWeapon()->Draw(pdc); //draw bullets
			t++;
		}
		else {
		//inisialisasi setelah proses menembak selesai
			t = 0;
			stages = 1;
			counter = 0;
			turn++;
			timer->Start(1000);
			if (turn == tanks.size())
				turn = 0;
			while (tanks[turn] == nullptr) {
				turn++;
				if (turn == tanks.size())
					turn = 0;
			}
		}
	}
	

}

void Board::OnKeyDown(wxKeyEvent & event)
{
	int keycode = event.GetKeyCode();
	if (stages == 1) { //bagian bergerak,tekan spasi pindah stages
		wxMessageOutputDebug().Printf("Move");
		switch (keycode)
		{
		case WXK_LEFT:
			Moving(tanks[turn], 1);
			break;
		case WXK_RIGHT:
			Moving(tanks[turn], 2);
			break;
		case WXK_SPACE:
			stages++;
			Aiming(tanks[turn], tanks[turn]->direction);
			break;
		default:
			event.Skip();
			break;
		}
	}
	else if (stages == 2) {//bagian aiming, kiri kanan velocity, atas bawah derajat
		wxMessageOutputDebug().Printf("OnKeyShoot");
		int xs = 0;
		int ys = 0;
		int v = 0;
		v = tanks[turn]->getWeapon()->getV();
		xs = tanks[turn]->getWeapon()->getXS();
		ys = tanks[turn]->getWeapon()->getYS();
		int keycode = event.GetKeyCode();
		switch (keycode)
		{
		case WXK_UP:
			ys += 1;
			tanks[turn]->getWeapon()->setYS(ys);
			break;
		case WXK_DOWN:
			ys -= 1;
			if (ys < 0)
				ys = 0;
			tanks[turn]->getWeapon()->setYS(ys);
			break;
		case WXK_LEFT:
			v -= 5;
			if (v < 0)
				v = 0;
			tanks[turn]->getWeapon()->setV(v);
			break;
		case WXK_RIGHT:
			v += 5;
			tanks[turn]->getWeapon()->setV(v);
			break;
		case WXK_SPACE:
			stages++;
			break;
		default:
			event.Skip();
			break;
		}
	}
}
void Board::OnTimer(wxTimerEvent & event)
{
	if (stages == 3) {
		counter = 0;
		timer->Stop();
	}
	if (counter == 10)
	{
		turn++;
		stages = 1;
		counter = 0;
		if (turn == tanks.size())
			turn = 0;
	}
	wxMessageOutputDebug().Printf("----------board stats---------");
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);
	wxMessageOutputDebug().Printf("t event %d.", t);
	wxMessageOutputDebug().Printf("stages event %d.", stages);
}

void Board::OnTimeRender(wxTimerEvent & event)
{
	Refresh(true);
}

void Board::Moving(Tank * tank, int direction)
{
	//wxMessageOutputDebug().Printf("Move Initiated\n");
	if (direction == 1) {
		tank->Move(-4, GetClientSize().GetWidth());
	}
	else if (direction == 2) {
		tank->Move(4, GetClientSize().GetWidth());
	}
	//this->Update();
	//this->Refresh(true);
}

void Board::Aiming(Tank * tank, int direction)
{
	shot = 1;
	if (direction == 1) {
		tank->getWeapon()->setX(tank->getX());
		tank->getWeapon()->setY(tank->getY());
	}
	else {
		tank->getWeapon()->setX(tank->getX() + 80);
		tank->getWeapon()->setY(tank->getY());
	}
}



Board::~Board()
{
	timer->Stop();
	timer2->Stop();
	delete timer;
	delete timer2;
	delete map;
	delete tankpic;
	while (!tanks.empty()) {
		delete tanks.back();
		tanks.pop_back();
	}
}
