#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();
	pOut->ClearDrawArea();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	//pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	//pIn->GetPointClicked(x,y);	//Wait for any click

	//
	/////////////////////////////////////////////////////////////////////////////////////
	//// TEST 2:	
	////			Drawing all the Figures with all possible states: 
	////			Non-filled, Filled, and highlighted in both cases			
	/////////////////////////////////////////////////////////////////////////////////////
	//
	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2,P3;

	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);
	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);
	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);
	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);
	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	pOut->CreateDrawToolBar();
	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	// 2.2.1 - Drawing non-filled square
	pOut->PrintMessage("Drawing a Square ==> normal,  Click a point");
	pIn->GetPointClicked(P1.x,P1.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawSq(P1, gfxInfo, false);
	// 2.2.2 - Drawing highlighted non-filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted,  Click a point");
	pIn->GetPointClicked(x,y);
	pOut->DrawSq(P1, gfxInfo, true);
	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	pOut->CreateDrawToolBar();
	// 2.2.3 - Drawing a filled square
	pOut->PrintMessage("Drawing a Square ==> filled,  Click a point");
	pIn->GetPointClicked(P1.x, P1.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawSq(P1, gfxInfo, false);
	// 2.1.4 - Drawing a highlighted filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawSq(P1, gfxInfo, true);
	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	pOut->CreateDrawToolBar();
	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
    // 2.3.1 - Drawing non-filled and non-Highlighted Triangle
	pOut->PrintMessage("Drawing an Triangle, non-filled and non-Highlighted,  Click three points");
	pIn->GetPointClicked(P1.x,P1.y);
	pIn->GetPointClicked(P2.x,P2.y);
	pIn->GetPointClicked(P3.x,P3.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawTri(P1,P2,P3, gfxInfo, false);
	// 2.3.2 - Drawing non-filled and Highlighted Triangle
	pOut->PrintMessage("Drawing an Triangle, non-filled and Highlighted,  Click to highlight");
	pIn->GetPointClicked(x,y);
	pOut->DrawTri(P1,P2,P3, gfxInfo, true);
	// 2.3.3 - Drawing filled and non-Highlighted Triangle
	pOut->PrintMessage("Drawing an Triangle, filled and non-Highlighted,  Click three points");
	pIn->GetPointClicked(P1.x,P1.y);
	pIn->GetPointClicked(P2.x,P2.y);
	pIn->GetPointClicked(P3.x,P3.y);
	gfxInfo.DrawClr = BLUE;	
	gfxInfo.isFilled = true;
	pOut->DrawTri(P1,P2,P3, gfxInfo,false);
    // 2.3.4 - Drawing filled and Highlighted Triangle
	pOut->PrintMessage("Drawing an Triangle, filled and Highlighted,  Click to highlight");
	pIn->GetPointClicked(x,y);
	pOut->DrawTri(P1,P2,P3, gfxInfo, true);
	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	pOut->CreateDrawToolBar();
	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	// 2.4.1 - Drawing non-filled and non-Highlighted Hexagon
	pOut->PrintMessage("Drawing an Hexagon, non-filled and non-Highlighted,  Click a points");
	pIn->GetPointClicked(P1.x,P1.y);
	gfxInfo.DrawClr = BLACK;
	gfxInfo.isFilled = false;
	pOut->DrawHexa(P1,gfxInfo, false);
	// 2.4.2 - Drawing non-filled and Highlighted Hexagon
	pOut->PrintMessage("Drawing an Hexagon, non-filled and Highlighted,  Click to highlight");
	pIn->GetPointClicked(x,y);
	pOut->DrawHexa(P1,gfxInfo, true);
	// 2.4.3 - Drawing filled and non-Highlighted Hexagon
	pOut->PrintMessage("Drawing an Hexagon, non-filled and non-Highlighted,  Click a point");
	pIn->GetPointClicked(P1.x,P1.y);
	gfxInfo.DrawClr = BLUE;	
	gfxInfo.isFilled = true;
	pOut->DrawHexa(P1,gfxInfo,false);
	// 2.4.4 - Drawing filled and Highlighted Hexagon
	pOut->PrintMessage("Drawing an Hexagon, filled and Highlighted,  Click to highlight");
	pIn->GetPointClicked(x,y);
	pOut->DrawHexa(P1,gfxInfo, true);
	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	pOut->CreateDrawToolBar();
	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	// 2.5.1 - Drawing non-filled and non-Highlighted Circle
	pOut->PrintMessage("Drawing an Circle, non-filled and non-Highlighted,  Click two points");
	pIn->GetPointClicked(P1.x,P1.y);
	pIn->GetPointClicked(P2.x,P2.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	
	gfxInfo.isFilled = false;
	pOut->DrawCircle(P1,P2,gfxInfo,false);
	// 2.5.2 - Drawing non-filled and Highlighted Circle
    pOut->PrintMessage("Drawing an Circle, non-filled and Highlighted,  Click to highlight");
	pIn->GetPointClicked(x,y);
	pOut->DrawCircle(P1,P2,gfxInfo,true);
	// 2.5.3 - Drawing filled and non-Highlighted Circle
	pOut->PrintMessage("Drawing an Circle, filled and non-Highlighted,  Click two points");
	pIn->GetPointClicked(P1.x,P1.y);
	pIn->GetPointClicked(P2.x,P2.y);
	gfxInfo.DrawClr = BLUE;	
	gfxInfo.isFilled = true;
	pOut->DrawCircle(P1,P2,gfxInfo,false);
	// 2.5.4 - Drawing filled and Highlighted Circle
	pOut->PrintMessage("Drawing an Circle, filled and Highlighted,  Click to highlight");
	pIn->GetPointClicked(x,y);
	pOut->DrawCircle(P1,P2,gfxInfo,true);
	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	pOut->CreateDrawToolBar();
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");

	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings");

	pOut->PrintMessage("You entered " + pIn->GetSrting(pOut));
	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	
	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ACT_RED:
			pOut->PrintMessage("Action: red colour chosen , Click anywhere");
				break;
		case ACT_BLACK:
			pOut->PrintMessage("Action: black colour chosen , Click anywhere");
			break;
		case ACT_BLUE:
			pOut->PrintMessage("Action: blue colour chosen , Click anywhere");
			break;
		case ACT_ORANGE:
			pOut->PrintMessage("Action: orange colour chosen , Click anywhere");
			break;
		case ACT_YELLOW:
			pOut->PrintMessage("Action: yellow colour chosen , Click anywhere");
			break;
		case ACT_GREEN:
			pOut->PrintMessage("Action: green colour chosen , Click anywhere");
			break;
		case ACT_DELETE:
			pOut->PrintMessage("Action: DELETE ICON , Click anywhere");
			break;
		case ACT_MOVE:
			pOut->PrintMessage("Action: MOVE ICON , Click anywhere");
			break;
		case ACT_SELECTONE:
			pOut->PrintMessage("Action: SELECT ONE ICON , Click anywhere");
			break;
		case ACT_UNDO:
			pOut->PrintMessage("Action: UNDO ICON , Click anywhere");
			break;
		case ACT_REDO:
			pOut->PrintMessage("Action: REDO ICON , Click anywhere");
			break;
		
		case DRAW_RECT:
				pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
				break;
		case DRAW_CIRCLE:
			pOut->PrintMessage("Action: Draw a circle , Click anywhere");
			break;
		case DRAW_TRIANGLE:
			pOut->PrintMessage("Action: Draw a triangle , Click anywhere");
			break;
		case DRAW_HEXAGON:
			pOut->PrintMessage("Action: Draw a hexagon , Click anywhere");
			break;
		case SHAPES_MENU:
			//pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
			pOut->ClearToolBar();
			pOut->CreateShapesToolBar();
			break;
		case COLOUR_MENU:
			//pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
			pOut->ClearToolBar();
			pOut->CreateColourToolBar();
			break;
		
		case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
		case HIDE_SHAPES:
			pOut->PrintMessage("Action: hide shapes , Click anywhere");
			break;
		case HIDE_SHAPSANDCOLOURS:
			pOut->PrintMessage("Action: hide shapes and colours, Click anywhere");
			break;
		case HIDE_COLOURS:
			pOut->PrintMessage("Action:hide colours, Click anywhere");
			break;
 
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->ClearToolBar();
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
			pOut->ClearToolBar();
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
				pOut->CreatePlayToolBar();
				break;


		///TODO: Add more cases for the other action types


		case EXIT:				
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


