#include "Board.h"
#include "wx/dcbuffer.h"
#define TIMER1_ID 12121
#define TIMER2_ID 12212

Board::Board(Game *parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	//inisialisasi game awal

	timer = new wxTimer(this, TIMER1_ID);
	timer2 = new wxTimer(this, TIMER2_ID);
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	//inisialisasi map
	SetBackgroundColour(wxColour(*wxWHITE));
	map = new Map(0, 1000, 1920, 15);

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
	if (stages == 2)
		tanks[turn]->DrawVelocity(pdc);
	//menggambar peluru jika ada kondisi menembak
	if (stages == 3) {
		/*wxMessageOutputDebug().Printf("----------Aiming stats---------");
		wxMessageOutputDebug().Printf("weapon Y : %d",tanks[turn]->getWeapon()->getY());*/
		for (int i = 0; i < tanks.size(); i++)
		{
			if (i == turn || tanks[i] == nullptr)
				continue;
			else if (tanks[i]->tankArea(tanks[turn]->getWeapon()->getTx(), tanks[turn]->getWeapon()->getTy())) {
				if (tanks[i]->changeHealth(tanks[turn]->getWeapon()->getDmg())) {
					if (!tanks[i]->GetDirection())
						team1--;
					else {
						team2--;
					}
					delete tanks[i];
					tanks[i] = nullptr;
				}
				tanks[turn]->getWeapon()->reset();
				hit = 0;
			}
		}
		if (tanks[turn]->checkCollision(GetClientSize().GetWidth(), 1000) && hit) {
			this->tanks[turn]->getWeapon()->Move(tanks[turn]->GetDirection(), t);
			this->tanks[turn]->getWeapon()->Draw(pdc); //draw bullets
			t++;
		}
		else {
			if (team1 == 0) {
				GameOver("Team 1");
			}
			else if (team2 == 0) {
				GameOver("Team 2");
			}
		//inisialisasi setelah proses menembak selesai
			else {
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
	

}

void Board::OnKeyDown(wxKeyEvent & event)
{
	int keycode = event.GetKeyCode();
	wxMessageOutputDebug().Printf("%d",keycode);
	if (stages == 1) { //bagian bergerak,tekan spasi pindah stages
		wxMessageOutputDebug().Printf("Move");
		switch (keycode)
		{
		case 'a':
		case 'A':
			Moving(tanks[turn], false);
			break;
		case 'd':
		case 'D':
			Moving(tanks[turn], true);
			break;
		case WXK_SPACE:
			stages++;
			Aiming(tanks[turn], tanks[turn]->GetDirection());
			tanks[turn]->getWeapon()->setV(0);
			break;
		default:
			event.Skip();
			break;
		}
	}
	else if (stages == 2) {//bagian aiming, kiri kanan velocity, atas bawah derajat
		wxMessageOutputDebug().Printf("OnKeyShoot");
		int v = 0;
		v = tanks[turn]->getWeapon()->getV();
		int keycode = event.GetKeyCode();
		switch (keycode)
		{
		case 'w':
		case 'W':
			tanks[turn]->Rotate(1);
			break;
		case 's':
		case 'S':
			tanks[turn]->Rotate(-1);
			break;
		/*case 'a':
		case 'A':
			v -= 5;
			if (v < 0)
				v = 0;
			tanks[turn]->getWeapon()->setV(v);
			break;
		case 'd':
		case 'D':
			v += 5;
			tanks[turn]->getWeapon()->setV(v);
			break;*/
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
	counter++;
	wxMessageOutputDebug().Printf("----------board stats---------");
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter);
	wxMessageOutputDebug().Printf("t event %d.", t);
	wxMessageOutputDebug().Printf("stages event %d.", stages);
}

void Board::OnTimeRender(wxTimerEvent & event)
{
	Refresh(true);
}

void Board::Moving(Tank * tank, bool direction)
{
	//wxMessageOutputDebug().Printf("Move Initiated\n");
	if (!direction) {
		tank->Move(GetClientSize().GetWidth(),direction);
	}
	else if (direction) {
		tank->Move(GetClientSize().GetWidth(),direction);
	}
	//this->Update();
	//this->Refresh(true);
}

void Board::Aiming(Tank * tank, bool direction)
{
	shot = 1;
	if (!direction) {
		tank->getWeapon()->setX(tank->getX());
		tank->getWeapon()->setY(tank->getY());
	}
	else {
		tank->getWeapon()->setX(tank->getX() + 80);
		tank->getWeapon()->setY(tank->getY());
	}
}

void Board::GameOver(wxString winner)
{
	timer->Stop();
	timer2->Stop();
	while (!tanks.empty()) {
		delete tanks.back();
		tanks.pop_back();
	}

	parentFrame->ShowOver(winner);

}

void Board::InitMode1(wxVector <int> choosen)
{

	shot = 0;
	stages = 1;
	counter = 0;
	turn = 0;
	t = 1;

	int x;
	//inisialisasi tank
	switch (choosen[0])
	{
	case 0:
		tanks.push_back(new Tiger_1(5, 1000));
		break;
	case 1:
		tanks.push_back(new Tiger_2(5, 1000));
		break;
	default:
		break;
	}

	switch (choosen[1])
	{
	case 0:
		tanks.push_back(new Tiger_1(1600, 1000, false));
		break;
	case 1:
		tanks.push_back(new Tiger_2(1600, 1000, false));
		break;
	default:
		break;
	}

	team1 = 1;
	team2 = 1;

	timer->Start(1000);
	timer2->Start(1);
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
	Unbind(wxEVT_PAINT, &Board::OnPaint, this);
	Unbind(wxEVT_KEY_DOWN, &Board::OnKeyDown, this);
	Unbind(wxEVT_TIMER, &Board::OnTimer, this, TIMER1_ID);
	Unbind(wxEVT_TIMER, &Board::OnTimeRender, this, TIMER2_ID);
}
