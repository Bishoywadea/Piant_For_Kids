#include "AddColor.h"

AddColor::AddColor(ApplicationManager* pApp,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}

void AddColor::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearToolBar();
	pOut->CreateColourToolBar();

	pOut->PrintMessage("Click on color to color slected figure");
	//find which colour is picked
	ActionType ACT;

	 ACT = pIn->GetUserAction();
	 switch (ACT)
	 {
	 case ACT_RED:
		 c = RED;
		 UI.FillColor = RED;
		 if (Sound)
		 {
			 PlaySound(TEXT("Sounds\\red.wav"), NULL, SND_ASYNC);
		 }
		 pOut->PrintMessage("RED Color");

		 break;
	 case ACT_BLUE:
		 c = BLUE;
		 UI.FillColor = BLUE;

		 if (Sound)
		 {
			 PlaySound(TEXT("Sounds\\blue.wav"), NULL, SND_ASYNC);
		 }

		 pOut->PrintMessage("Blue Color");
		 break;
	 case ACT_BLACK:
		 c = BLACK;
		 UI.FillColor = BLACK;
		
		 if (Sound)
		 {
			 PlaySound(TEXT("Sounds\\black.wav"), NULL, SND_ASYNC);
		 }
		 pOut->PrintMessage("BLACK Color");
		 break;
	 case ACT_ORANGE:
		 c = ORANGE;
		 UI.FillColor = ORANGE;
		 if (Sound)
		 {
			 PlaySound(TEXT("Sounds\\orange.wav"), NULL, SND_ASYNC);
		 }
		 pOut->PrintMessage("ORANGE Color");
		 break;
	 case ACT_YELLOW:
		 c = YELLOW;
		 UI.FillColor = YELLOW;
		 if (Sound)
		 {
			 PlaySound(TEXT("Sounds\\yellow.wav"), NULL, SND_ASYNC);
		 }
		 pOut->PrintMessage("YELLOW Color");
		 break;
	 case ACT_GREEN:
		 c = GREEN;
		 UI.FillColor = GREEN;
		 if (Sound)
		 {
			 PlaySound(TEXT("Sounds\\green.wav"), NULL, SND_ASYNC);
		 }
		 pOut->PrintMessage("GREEN Color");
		 break;
	 }

	
	


}

void AddColor::Execute()
{
	ReadActionParameters();
	CFigure* F = pManager->Returnselectedfig();
	if (F == NULL)
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Please select a figure");
		return;
	}
	
	F->ChngFillClr(c);

}
