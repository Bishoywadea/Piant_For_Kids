#include "Square.h"

Square::Square(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
}

void Square::Draw(Output* pOut) const
{
	pOut->DrawSq(Center, FigGfxInfo, Selected);
}

void Square::PrintInfo(Output* pOut)
{
	string c = to_string(Center.x) + "," + to_string(Center.y);
	string Id = to_string(ID);
	string isselected = to_string(Selected);

	pOut->PrintMessage("Figure type:Square,Center: " + c + " ID: " + Id + " Is selected: " + isselected);

}
