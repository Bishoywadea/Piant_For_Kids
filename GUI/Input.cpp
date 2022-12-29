#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

void Input::watchDrag(buttonstate& state, button btn, int& x, int& y)
{
	state = pWind->GetButtonState(btn, x, y);
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
		{
			pWind->FlushMouseQueue();   // to clear all the buffer mouse clicks
			return Label;
		}
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SHAPES: return SHAPES_MENU;         //icon to open the shapes
			case ITM_COLOUR: return COLOUR_MENU;         //icon to open the colours
			case ITM_EXIT: return EXIT;                  //icon to close the program
			case ITM_DELETE: return ACT_DELETE;          //icon to delete the shape selected
			case ITM_SELECT: return ACT_SELECT;       //icon to select a shape
			case ITM_UNDO: return ACT_UNDO;              //icon to undo
			case ITM_SAVE: return ACT_SAVE;              //icon to save the draw 
			case ITM_LOAD: return ACT_LOAD;              //icon to save the draw 
			case ITM_MOVE: return ACT_MOVE;              //icon to move the selected shape
			case ITM_REDO: return ACT_REDO;    //icon to redo
			case ITM_CLEARALL: return ACT_CLEARALL;
			case ITM_PLAYMOOD: return TO_PLAY;           //icon to go to play mode
			case ITM_DRAWCOLOUR:return ACT_CHNGDRAWCOLOUR;
			case ITM_SOUND:return Sound;
			case ITM_Drag:return Drag;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	//[4] If user in shapes menu and clicks on the shape
	else if (UI.InterfaceMode == MODE_SHAPES)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;       //icon to draw rect
			case ITM_SQU: return DRAW_SQUARE;      //icon to draw square
			case ITM_CIR: return DRAW_CIRCLE;      //icon to draw circle
			case ITM_TRI: return DRAW_TRIANGLE;    //icon to draw triangle
			case ITM_HEX: return DRAW_HEXAGON;     //icon to draw hexagon
			case ITM_BACk: return TO_DRAW;       //back icon

			default: return BACK_ICON;	           //A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	//[5] If user in color menu and clicks on the colour
	else if (UI.InterfaceMode == MODE_COLOUR)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RED: return ACT_RED;         //icon to color red
			case ITM_BLUE: return ACT_BLUE;       //icon to color blue
			case ITM_GREEN: return ACT_GREEN;     //icon to color green
			case ITM_ORANGE: return ACT_ORANGE;   //icon to color orange
			case ITM_BLACK: return ACT_BLACK;     //icon to color black
			case ITM_YELLOW: return ACT_YELLOW;   //icon to color yellow
			default: return TO_DRAW;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

	}
	//[6] If user in mode play and clicks on the icon in it
	else if (UI.InterfaceMode == MODE_PLAY)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_DRAWMOOD: return TO_DRAW;                               // icon to go back to draw mode
			case ITM_HIDESHAPES: return HIDE_SHAPES;                         // icon to go hide shapes
			case ITM_HIDESHAPESANDCOLOURS: return HIDE_SHAPSANDCOLOURS;      // icon to go hide shapes and colour
			case ITM_HIDECOLOURS: return HIDE_COLOURS;                       // icon to go hide colours
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
}
/////////////////////////////////

Input::~Input()
{
}
