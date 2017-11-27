#include "stdafx.h"
#ifdef DEV_MODE
bool noclip = false;
#endif
CRender::CRender()
{
	DLOG("CRender::CRender()");
};

void CRender::Render()
{
	//Wys³anie pakietu o gotowoœci clienta do dzia³ania
	CNetwork* net = core.GetNetwork();
	CGothicGame* gothicGame = core.GetGothicGame();
	zCInput* input = zCInput::GetInput();
	if( gothicGame->bIsFirstFrame == true )
	{
		CConfig* config = core.GetConfig();

		if( net -> IsInitiated() == true && net -> IsConnected() == false)
			net -> Connect(config->GetServerIp(), atoi(config->GetServerPort().C_String())); //Nawi¹zywanie po³¹czenia
		gothicGame->bIsFirstFrame = false;
	}
	//Render chat
	CChat* chat = core.GetChat();
	if( chat )
		chat->Render();
	
	//Receiver/gui debug drawing
	if( net->IsInitiated() == true )
	{
		net->GetReceiver()->ReceivePackets(net);
		zCursor::GetCursor().OnUpdate(); //Kursor
	}
	//Connected shitz
	if( net->IsConnected() == true )
	{
		if( playerManager.GetLocalPlayer() != NULL )
			playerManager.GetLocalPlayer()->Pulse();

		//core.GetMultiplayer()->RepairDoor();
		playerManager.RepairAllPlayers(); //BRAND NEW!!!

		if( scr.IsScriptLoaded() == true )
			scr.OnRender();

#ifndef DEV_MODE
		//Sprawdzenie czy marvin nie jest aktywny
		if (!scr.GetScriptVars()->isMarvinEnabled && oCGame::GetGame()->game_testmode)
		{
			CGameManager::GetGameManager()->ExitGame();
			ExitProcess(0);
		}
#endif //DEV_MODE
	}
	if(input->KeyToggled(KEY_LALT) && input->KeyToggled(KEY_F4))
	{
		CGameManager::GetGameManager()->Done();
		ExitProcess(0);
	}
#ifdef DEV_MODE
	oCNpc* hero = oCNpc::GetHero();
	static zCAIBase* defaultAI = (*(zCAIBase**)((DWORD)hero+0x0B0));
	static zVEC3 pos = hero->GetPosition();
	if(input->KeyToggled(KEY_NUMPAD5))
	{
		noclip = !noclip;
		if(noclip == true)
		{
			pos = hero->GetPosition();
			hero->SetAI(0);
		}
		else hero->SetAI(defaultAI);
	}
	if(noclip == true)
	{
		hero->CompleteHeal();
		if(input->KeyPressed(KEY_NUMPAD4)) pos.x -= 50;
		if(input->KeyPressed(KEY_NUMPAD6)) pos.x += 50;
		if(input->KeyPressed(KEY_NUMPAD2)) pos.z -= 50;
		if(input->KeyPressed(KEY_NUMPAD8)) pos.z += 50;
		if(input->KeyPressed(KEY_NUMPAD7)) pos.y += 50;
		if(input->KeyPressed(KEY_NUMPAD1)) pos.y -= 50;
		if(input->KeyPressed(KEY_NUMPAD9)) hero->SetHeading(hero->GetHeading()+3);
		if(input->KeyPressed(KEY_NUMPAD3)) hero->SetHeading(hero->GetHeading()-3);
		hero->SetPosition(pos.x, pos.y, pos.z);
		zCView* view = zCView::GetScreen();
		view->Print(5000, 1500, zSTRING("NOCLIP: ON"));
	}
#endif
};