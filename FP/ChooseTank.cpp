#include "ChooseTank.h"
#include "wx/dcbuffer.h"

ChooseTank::ChooseTank(Game* parent) :
	wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	wxImage temp = wxBitmap(wxBITMAP_PNG(#119)).ConvertToImage();
	temp.Rescale(1920, 1080, wxIMAGE_QUALITY_HIGH);
	choosetank = new wxBitmap(temp);
	Initiated();

	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	SetBackgroundColour(wxColour(*wxWHITE));

	Bind(wxEVT_PAINT, &ChooseTank::OnPaint, this);
	Bind(wxEVT_LEFT_DOWN, &ChooseTank::OnClick, this);
}


ChooseTank::~ChooseTank()
{
	Unbind(wxEVT_PAINT, &ChooseTank::OnPaint, this);
	delete choosetank;
}
void ChooseTank::OnClick(wxMouseEvent & event)
{
	if (event.GetX() >= 792 && event.GetX() <= 1124 && event.GetY() >= 886 && event.GetY() <= 991) {
		parentFrame->ShowBoard(cycle , 1);
	}
	else if (event.GetX() >= 103 && event.GetX() <= 184 && event.GetY() >= 557 && event.GetY() <= 624) {
		cycle[0]--;
		if (cycle[0] < min)
			cycle[0] = max;
		Refresh();
	}
	else if (event.GetX() >= 660 && event.GetX() <= 740 && event.GetY() >= 557 && event.GetY() <= 624) {
		cycle[0]++;
		if (cycle[0] > max)
			cycle[0] = min;
		Refresh();
	}
	else if (event.GetX() >= 1175 && event.GetX() <= 1255 && event.GetY() >= 557 && event.GetY() <= 624) {
		cycle[1]--;
		if (cycle[1] < min)
			cycle[1] = max;
		Refresh();
	}
	else if (event.GetX() >= 1732 && event.GetX() <= 1814 && event.GetY() >= 557 && event.GetY() <= 624) {
		cycle[1]++;
		if (cycle[1] > max)
			cycle[1] = min;
		Refresh(true);
	}
}
void ChooseTank::OnPaint(wxPaintEvent & event)
{
	wxBufferedPaintDC pdc(this);
	wxImage tbody;
	pdc.DrawBitmap(*choosetank, wxPoint(0, 0), true);
	int x, y;
	for (int i = 0; i < cycle.size(); i++)
	{
		if (i == 0) {
			x = 232;
			y = 536;
		}
		else
		{
			x = 1304;
			y = 536;
		}
		switch (cycle[i])
		{
		case 0:
			tbody = wxBitmap(wxBITMAP_PNG(#122)).ConvertToImage();
			tbody.Rescale(0.25*tbody.GetWidth(), 0.25*tbody.GetHeight());
			pdc.DrawBitmap(tbody, wxPoint(x, y), true);
			break;
		case 1:
			tbody = wxBitmap(wxBITMAP_PNG(#121)).ConvertToImage();
			tbody.Rescale(0.2*tbody.GetWidth(), 0.2*tbody.GetHeight());
			pdc.DrawBitmap(tbody, wxPoint(x, y), true);
			break;
		case 2:
			tbody = wxBitmap(wxBITMAP_PNG(#123)).ConvertToImage();
			tbody.Rescale(0.2*tbody.GetWidth(), 0.2*tbody.GetHeight());
			pdc.DrawBitmap(tbody, wxPoint(x, y), true);
			break;
		case 3:
			tbody = wxBitmap(wxBITMAP_PNG(#124)).ConvertToImage();
			tbody.Rescale(0.25*tbody.GetWidth(), 0.25*tbody.GetHeight());
			pdc.DrawBitmap(tbody, wxPoint(x+40, y), true);
			break;
		case 4:
			tbody = wxBitmap(wxBITMAP_PNG(#127)).ConvertToImage();
			tbody.Rescale(0.3*tbody.GetWidth(), 0.3*tbody.GetHeight());
			pdc.DrawBitmap(tbody, wxPoint(x+30, y), true);
			break;
		case 5:
			tbody = wxBitmap(wxBITMAP_PNG(#126)).ConvertToImage();
			tbody.Rescale(0.2*tbody.GetWidth(), 0.2*tbody.GetHeight());
			pdc.DrawBitmap(tbody, wxPoint(x, y), true);
			break;
		case 6:
			tbody = wxBitmap(wxBITMAP_PNG(#125)).ConvertToImage();
			tbody.Rescale(0.3*tbody.GetWidth(), 0.3*tbody.GetHeight());
			pdc.DrawBitmap(tbody, wxPoint(x+10, y), true);
		default:
			break;
		}
	}
}

void ChooseTank::Initiated()
{
	for (int i = 0; i < 2; i++)
	{
		cycle.push_back(0);
	}
}

void ChooseTank::Reset()
{
	for (int i = 0; i < 2; i++)
	{
		cycle.pop_back();
	}

	Initiated();
}
