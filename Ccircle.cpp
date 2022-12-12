#include "Ccircle.h"

Ccircle::Ccircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center= P1;
	Radius= P2;
}

void Ccircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(Center, Radius, FigGfxInfo, Selected);
}

void Ccircle::PrintInfo(Output* pOut)
{
	string c = to_string(Center.x) + "," + to_string(Center.y)+" Radius "+to_string(Radius.x)+","+to_string(Radius.y);
	string Id = to_string(ID);
	string isselected = to_string(Selected);

	pOut->PrintMessage("Figure type: Circle,Center: " + c + " ID: " + Id + " Is selected: " + isselected);

}
