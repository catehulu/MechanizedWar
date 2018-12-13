#include "Tank.h"
#include "wx/graphics.h"


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
//	gungbmp = gc->CreateBitmapFromImage(temp);
//	bodygbmp = gc->CreateBitmapFromImage(tempbody);
	//Sistem Pivot biar tembakan memutar pada satu titik//
	double xcomp = -gun.GetHeight() / 2, ycomp = -gun.GetHeight() / 4;
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

	double ActualGunX = gunx, ActualGunY = guny;
	double gunh = temp.GetHeight();
	double gunw = temp.GetWidth();
	if (direction)
	{
		ActualGunX = (-(gunx - ((float)body.GetWidth() / 2)) + (float)body.GetWidth() / 2) - (float)gun.GetHeight()/4;

	}
	//wxMessageOutputDebug().Printf("y%d x%d width%d", ActualGunY, ActualGunX, body.GetWidth());
	//Gambar bmp gun yang telah ter-rotate dengan koordinat yang mengkompensasi putaran//
	dc.DrawBitmap(gunbmp, wxPoint(this->x + xcomp + ActualGunX, this->y + ycomp + ActualGunY), true);
	dc.DrawBitmap(bodybmp, wxPoint(this->x, this->y), true);
	/*gc->DrawBitmap(gungbmp, this->x + xcomp + ActualGunX, this->y + ycomp + ActualGunY ,gunw,gunh);
	gc->DrawBitmap(bodygbmp, this->x, this->y,body.GetWidth(),body.GetHeight());*/

	//health bar
	dc.SetBrush(wxBrush(wxColour(*wxWHITE)));
	dc.SetPen(wxPen(wxColor(*wxBLACK), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y - 20), wxSize(width,
		13));
	double percentage = ((float)currhealth / (float)maxhealth);
	int red = percentage <= 0.5f ? 255 : 255 - (percentage*2.0* 255);
	int green = percentage >= 0.5f ? 255 : (percentage*2.0* 255);
	dc.SetBrush(wxBrush(wxColour(red, green, 0)));
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

void Tank::DrawVelocity(wxBufferedPaintDC & dc)
{
	double tv;
	dc.SetBrush(wxBrush(wxColour(*wxWHITE)));
	dc.SetPen(wxPen(wxColor(*wxBLACK), 1, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(this->x, this->y - 60), wxSize(width,
		13));
	tv = weapon->getV()*100+add;
	if (tv > 100 || tv < 0)
		add *= -1;
	int red = tv<=50?255:255 - (((tv/50)) * 255);
	int green = tv>=50?255:(((tv /50)) * 255);
	dc.SetBrush(wxBrush(wxColour(red,green,0)));
	int tmp;
	tmp = width * tv / 100;
	dc.DrawRectangle(wxPoint(this->x, this->y - 60), wxSize(tmp,
		13));
	wxMessageOutputDebug().Printf("tv %lf | tmp %d", tv, tmp);
	weapon->setV(tv/100);
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

void Tank::setX(int x)
{
	this->x = x;
}

void Tank::sety(int y)
{
	this->y = y;
}
