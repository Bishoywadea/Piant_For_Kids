#include "Play_Rec.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"Actions\Action.h"
#include<iostream>
#include <windows.h>
#include<chrono>
#include<thread>

Play_Rec::Play_Rec(ApplicationManager*pApp,bool IsEnabled):Action(pApp)
{
	Sound = IsEnabled;
}
void Play_Rec::ReadActionParameters()
{


}
void Play_Rec::Execute(bool read)
{
	if (Sound)
	{
		PlaySound(TEXT("Sounds\\play.wav"), NULL, SND_ASYNC);
	}
	pManager->GetOutput()->PrintMessage("Play icon");
	pManager->PlayRec();
}
void Play_Rec::redo()
{


}
void Play_Rec::undo()
{


}
void Play_Rec::AddMeUndo(bool redo)
{


}
Play_Rec::~Play_Rec()
{
}
void Play_Rec::AddMeRec()
{


}