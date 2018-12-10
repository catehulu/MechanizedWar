#include "Tank.h"


Tank::Tank(int gunx, int guny)
	:gunx(gunx), guny(guny)
{	
}

void Tank::Draw(wxBufferedPaintDC & dc)
{
	wxImage temp = gun.Rotate(-angle * 3.1415 / 180.0, wxPoint(0, 0), true);
	wxImage tempbody = body;
	if (direction)
	{
		temp = temp.Mirror();
		tempbody = tempbody.Mirror();
	}
	gunbmp = wxBitmap(temp);
	bodybmp = wxBitmap(tempbody);
	//Sistem Pivot biar tembakan memutar pada satu titik//
	int xcomp = -gun.GetHeight() / 4, ycomp = -gun.GetHeight() / 4;
	if ((direction && angle >= 270 && angle <= 360) || (!direction && angle >= 180 && angle <= 270))  //180-270
	{

	}
	else if ((direction && angle >= 180 && angle <= 270) || (!direction && angle >= 270 && angle <= 360)) //270-360
	{
		xcomp = -temp.GetWidth() + gun.GetHeight(); //wxMessageOutputDebug().Printf("disini 270");

	}
	else if ((direction && angle >= 90 && angle <= 180) || (!direction && angle >= 0 && angle <= 90)) //0-90
	{
		ycomp = -temp.GetHeight() + gun.GetHeight();
		xcomp = -temp.GetWidth() + gun.GetHeight(); //wxMessageOutputDebug().Printf("disini 180");
	}
	else if ((direction && angle >= 0 && angle <= 90) || (!direction && angle >= 90 && angle <= 180)) //90-180
	{
		ycomp = -temp.GetHeight() + gun.GetHeight();

	}
	//------------------------------------------//

	int ActualGunX = gunx, ActualGunY = guny;
	if (direction)
	{
		ActualGunX = (-(gunx - (body.GetWidth() / 2)) + body.GetWidth() / 2) - 10;

	}
	//wxMessageOutputDebug().Printf("y%d x%d width%d", ActualGunY, ActualGunX, body.GetWidth());
	//Gambar bmp gun yang telah ter-rotate dengan koordinat yang mengkompensasi putaran//
	dc.DrawBitmap(gunbmp, wxPoint(this->x + xcomp + ActualGunX, this->y + ycomp + ActualGunY), true);
	dc.DrawBitmap(bodybmp, wxPoint(this->x, this->y), true);

	//health bar
	dc.SetBrush(wxBrush(wxColour(*wxWHITE)));
	dc.SetPen(wxPen(wxColor(*wxBLACK), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y - 20), wxSize(width,
		13));
	if (currhealth / 10 > 7)
		dc.SetBrush(wxBrush(wxColour(*wxGREEN)));
	else if (currhealth / 10 > 3)
		dc.SetBrush(wxBrush(wxColour(*wxYELLOW)));
	else
		dc.SetBrush(wxBrush(wxColour(*wxRED)));
	//percobaan
	double tmp;
	tmp = width * currhealth / maxhealth;
	dc.DrawRectangle(wxPoint(this->x, this->y - 20), wxSize((int)tmp,
		13));
	//gambar tulisan
	wxFont font(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	wxString x;
	x << currhealth;
	dc.SetFont(font);
	dc.SetTextForeground((wxColor(*wxBLACK)));
	dc.DrawText(x, wxPoint(this->x + (this->width / 2) - 9, this->y - 20));
}

void Tank::Rotate(int amount)
{
	angle += amount;
	if (angle >= 360) angle = 0;
	if (angle < 0) angle = 360;
	weapon->setAngle(angle);
	//wxMessageOutputDebug().Printf("at %d degree",angle);
}

void Tank::SetBodyImage(wxImage res)
{
	this->body = res;
}

void Tank::SetGunImage(wxImage res)
{
	this->gun = res;
}

void Tank::SetDirection(bool direction)
{
	this->direction = direction;
}

bool Tank::GetDirection()
{
	return direction;
}

wxImage Tank::GetBodyImage()
{
	return body;
}

wxImage Tank::GetGunImage()
{
	return gun;
}

bool Tank::checkCollision(int x, int y)
{
	if (weapon->getTx() > x || weapon->getTx() < 0 || weapon->getTy() > y || weapon->getTy() < 0) {
		weapon->setTx(weapon->getX());
		weapon->setTy(weapon->getY());
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
	currhealth -= x;
	if (currhealth <= 0) {
		currhealth = 0;
		return true;
	}
	else return false;
}

Weapon* Tank::getWeapon()
{

	return this->weapon;
}

Tank::~Tank()
{
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
