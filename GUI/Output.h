#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreateShapesToolBar() const;
	void CreateFillColourToolBar() const;
	void CreateDrawColourToolBar() const;
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	void ClearToolBar() const;

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawSq(Point P1, GfxInfo SquareGfxInfo, bool selected,float side)      const;
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected)  const;
	void DrawHexa(Point P1, GfxInfo TriGfxInfo, bool selected,float side)  const;
	void DrawCircle(Point center, Point border, GfxInfo CircleGfxInfo, bool selected)  const;
	///Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif