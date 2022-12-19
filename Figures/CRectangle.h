#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"
#include<fstream>
class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	int pvid;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	void PrintInfo(Output* pOut);
	virtual bool IsOnFig(int x, int y) const;
	void MOVE(Point p1);
	virtual void Save(ofstream& OutFile);
};

#endif