#include "Tank.h"


Tank::Tank(int x, int y, wxImage res, int direction)
	:x(x), y(y), direction(direction)
{
	SetImage(res);
	weapon = new Weapon(10, x, y);
}

void Tank::Draw(wxBufferedPaintDC & dc)
{
	/*dc.SetBrush(wxBrush(wxColour(*wxBLACK)));
	dc.SetPen(wxPen(wxColor(*wxBLUE), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y), wxSize(width,
		height));*/
	dc.DrawBitmap(*this->tankpic,wxPoint(this->x,this->y),true);
	//health bar
	dc.SetBrush(wxBrush(wxColour(*wxWHITE)));
	dc.SetPen(wxPen(wxColor(*wxBLACK), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y-20), wxSize(width,
		13));
	if (health/10 > 7)
		dc.SetBrush(wxBrush(wxColour(*wxGREEN)));
	else if(health / 10 > 3)
		dc.SetBrush(wxBrush(wxColour(*wxYELLOW)));
	else
		dc.SetBrush(wxBrush(wxColour(*wxRED)));
	//percobaan
	double tmp;
	tmp = width * health / 100;
	dc.DrawRectangle(wxPoint(this->x, this->y - 20), wxSize((int)tmp,
		13));
	//gambar tulisan
	wxFont font(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	wxString x;
	x << health;
	dc.SetFont(font);
	dc.SetTextForeground((wxColor(*wxBLACK)));
	dc.DrawText(x, wxPoint(this->x+(this->width/2)-9, this->y - 20));
}

void Tank::Move(int amount, int maxX)
{
	if (x + 15 >= maxX || x <= 0) {
		return;
	}
	else {
		x += amount;
	};
}

void Tank::SetImage(wxImage res)
{
	this->tankpic = new wxBitmap(res);
}

void Tank::setWeapon(int vy, int x, int y)
{
}

bool Tank::checkCollision(Tank * tank)
{
	return false;
}

bool Tank::checkCollision(int x, int y)
{
	if (weapon->tx > x || weapon->tx < 0 || weapon->ty > y || weapon->ty < 0) {
		weapon->tx = weapon->getX();
		weapon->ty = weapon->getY();
		return false;
	}
	else
		return true;
}

bool Tank::tankArea(int x, int y)
{
	if ((x >= this->x && x <= this->x + this->width)
		&& (y >= this->y && y <= this->y + this->width))
		return true;
	else
		return false;
}

bool Tank::changeHealth(int x)
{
	health -= x;
	if (health <= 0) {
		health = 0;
		return true;
	}
	else return false;
}

Weapon* Tank::getWeapon()
{

	return this->weapon;
}


wxImage Tank::GetImage()
{
	return tankpic->ConvertToImage();
}

Tank::~Tank()
{
	delete tankpic;
	delete weapon;
}

int Tank::getX()
{
	return this->x;
}

int Tank::getY()
{
	return this->y;
}
