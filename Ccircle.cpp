#include "Ccircle.h"

Ccircle::Ccircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center= P1;
	Radius= P2;
	radius = CalcDistance(P1, P2);
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

bool Ccircle::IsOnFig(int x, int y) const  //Checks to deciding the click is on figure or not //BISHOY
{
	Point P;
	P.x = x;
	P.y = y;
	//to see if the point lie on the circle or not //BISHOY
	return (radius >= CalcDistance(Center, P));
}

Point Ccircle::MOVE(Point p)
{
	Point C0 = Center;
	float rlen = sqrt(pow((Radius.x - Center.x), 2) + pow((Radius.y - Center.y), 2));
	Center.x = p.x;
	Center.y = p.y;
	Radius.x = p.x + rlen;
	Radius.y = p.y;
	return C0;
}

