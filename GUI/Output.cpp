#include "Output.h"
#include<iostream>
using namespace std;

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1500;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 70;

	UI.DrawColor = BLACK;	//Drawing color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.FillColor = UI.BkGrndColor;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SHAPES] = "images\\MenuItems\\Shapes_Menu.jpg";
	MenuItemImages[ITM_COLOUR] = "images\\MenuItems\\Colour_Menu.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select1.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Savegraph.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_STARTREC] = "images\\MenuItems\\Menu_Startrec.jpg";
	MenuItemImages[ITM_STOPREC] = "images\\MenuItems\\Menu_Stoprec.jpg";
	MenuItemImages[ITM_PLAYREC] = "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImages[ITM_PLAYMOOD] = "images\\MenuItems\\Menu_Playmood.jpg";
	MenuItemImages[ITM_CLEARALL] = "images\\MenuItems\\Menu_Clearall.jpg";
	MenuItemImages[ITM_DRAWCOLOUR] = "images\\MenuItems\\DrawColor.jpg";
	MenuItemImages[ITM_SOUND] = "images\\MenuItems\\Menu_Sound.jpg";
	MenuItemImages[ITM_Drag] = "images\\MenuItems\\DRAG.jpg";
	MenuItemImages[ITM_Resize] = "images\\MenuItems\\Resize.jpg";
	//TODO: Prepare images for each menu item and add it to the list  (DONE)

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateShapesToolBar() const   //a method to draw shapes menu
{
	UI.InterfaceMode = MODE_SHAPES;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string ShapesItemImages[SHAPES_ITM_COUNT];
	ShapesItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	ShapesItemImages[ITM_SQU] = "images\\MenuItems\\Menu_Square.jpg";
	ShapesItemImages[ITM_CIR] = "images\\MenuItems\\Menu_Circle.jpg";
	ShapesItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Triangle.jpg";
	ShapesItemImages[ITM_HEX] = "images\\MenuItems\\Menu_Hexa.jpg";
	ShapesItemImages[ITM_BACk] = "images\\MenuItems\\BACK.jpg";
	//TODO: Prepare images for each menu item and add it to the list    (DONE)

	//shapes menu item one image at a time
	for (int i = 0; i < SHAPES_ITM_COUNT; i++)
		pWind->DrawImage(ShapesItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the shapes menu
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateFillColourToolBar() const
{
	UI.InterfaceMode = MODE_Fill_COLOUR;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string ColourItemImages[COLOUR_ITM_COUNT];
	ColourItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	ColourItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	ColourItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	ColourItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	ColourItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";
	ColourItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	ColourItemImages[ITM_BACK] = "images\\MenuItems\\BACK.jpg";
	//TODO: Prepare images for each menu item and add it to the list         (DONE)

	//color menu item one image at a time
	for (int i = 0; i < COLOUR_ITM_COUNT; i++)
		pWind->DrawImage(ColourItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the colour menu
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawColourToolBar() const
{
	UI.InterfaceMode = MODE_Draw_COLOUR;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string ColourItemImages[COLOUR_ITM_COUNT];
	ColourItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	ColourItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	ColourItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";
	ColourItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	ColourItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";
	ColourItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	ColourItemImages[ITM_BACK] = "images\\MenuItems\\BACK.jpg";
	//TODO: Prepare images for each menu item and add it to the list         (DONE)

	//color menu item one image at a time
	for (int i = 0; i < COLOUR_ITM_COUNT; i++)
		pWind->DrawImage(ColourItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the colour menu
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
/////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	string PlayItemImages[COLOUR_ITM_COUNT];
	PlayItemImages[ITM_DRAWMOOD] = "images\\MenuItems\\Menu_Drawmood.jpg";
	PlayItemImages[ITM_HIDESHAPES] = "images\\MenuItems\\Menu_hidebyshapes.jpg";
	PlayItemImages[ITM_HIDECOLOURS] = "images\\MenuItems\\Menu_Hidebycolour.jpg";
	PlayItemImages[ITM_HIDESHAPESANDCOLOURS] = "images\\MenuItems\\Menu_hidebyshapesandcolours.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//play menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(PlayItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	///TODO: write code to create Play mode menu   (DONE)
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawSq(Point center, GfxInfo SqGfxInfo, bool selected,float side)     const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = SqGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (SqGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SqGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawRectangle(center.x - side/2, center.y - side/2, center.x + side/2, center.y + side/2, style);
}
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected)  const
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = TriGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, UI.PenWidth);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawHexa(Point P1, GfxInfo HexaGfxInfo, bool selected,float side)  const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = HexaGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr,UI.PenWidth);
	drawstyle style;
	if (HexaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexaGfxInfo.FillClr);
	}
	else
		style = FRAME;
	const int arrx[] = { P1.x + side,P1.x + side/2,P1.x - side/2,P1.x - side,P1.x - side/2,P1.x + side/2 };
	const int arry[] = { P1.y,P1.y + (0.866) * side,P1.y + ((0.866) * side),P1.y,P1.y - ((0.866) * side),P1.y - ((0.866) * side) };
	pWind->DrawPolygon(arrx, arry, 6, style);
}

void Output::DrawCircle(Point center, Point border, GfxInfo CircleGfxInfo, bool selected)  const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = CircleGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr,UI.PenWidth);
	drawstyle style = FRAME;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}


	int radius = sqrt(pow((center.x - border.x), 2) + pow((center.y) - (border.y), 2));
	pWind->DrawCircle(center.x, center.y, radius, style);
}




//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

