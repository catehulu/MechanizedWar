#include "Tank.h"


Tank::Tank(int x, int y, wxImage body, wxImage gun, bool direction)
	:x(x),y(y)
{
	SetBodyImage(body);
	SetGunImage(gun);
	SetDirection(direction);
	

}

void Tank::Draw(wxBufferedPaintDC & dc)
{
	wxImage temp = gun.Rotate(-angle*3.1415 / 180.0, wxPoint(0, 0), true);
	wxImage tempbody = body;
	if (direction)
	{
		temp = temp.Mirror();
		tempbody = tempbody.Mirror();
	}
	gunbmp = wxBitmap(temp);
	bodybmp = wxBitmap(tempbody);
	//Sistem Pivot biar tembakan memutar pada satu titik//
	int xcomp= -gun.GetHeight() / 4, ycomp= -gun.GetHeight() / 4;
	if ((direction && angle >= 270 && angle <= 360) || (!direction && angle >= 180 && angle <=270))  //180-270
	{
		
	}
	else if ((direction && angle >= 180 && angle <= 270) || (!direction && angle >= 270 && angle <= 360 )) //270-360
	{
		xcomp = -temp.GetWidth() + gun.GetHeight();wxMessageOutputDebug().Printf("disini 270");
		
	}
	else if ((direction && angle >= 90 && angle <= 180) || (!direction && angle >= 0 && angle <= 90 )) //0-90
	{
		ycomp = -temp.GetHeight()+ gun.GetHeight();
		xcomp = -temp.GetWidth() + gun.GetHeight();wxMessageOutputDebug().Printf("disini 180");
	}
	else if ((direction && angle >= 0 && angle <= 90) || (!direction && angle >= 90 && angle <= 180)) //90-180
	{
		ycomp = -temp.GetHeight()+gun.GetHeight();
		
	}
	//------------------------------------------//

	int ActualGunX = gunx, ActualGunY = guny;
	if (direction)
	{
		ActualGunX =(-(gunx - (body.GetWidth() / 2))+body.GetWidth()/2)-10;

	}
	wxMessageOutputDebug().Printf("y%d x%d width%d", ActualGunY, ActualGunX,body.GetWidth());
	//Gambar bmp gun yang telah ter-rotate dengan koordinat yang mengkompensasi putaran//
	dc.DrawBitmap(gunbmp, wxPoint(this->x+xcomp+ActualGunX, this->y+ycomp+ActualGunY),true);
	dc.DrawBitmap(bodybmp, wxPoint(this->x, this->y),true);

	
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

void Tank::Rotate(int amount)
{
	angle += amount;
	if (angle >= 360) angle = 0;
	if (angle < 0) angle = 360;
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
	return this->body;
}

wxImage Tank::GetGunImage()
{
	return gun;
}

Tank::~Tank()
{
	
}
