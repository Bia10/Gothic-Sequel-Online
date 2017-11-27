#include "..\\..\\..\\stdafx.h"

void CGameManager::Hook_Menu(int i)
{
	DLOG("CGameManager::Hook_Menu()");
	pMemLib->RemoveHook(0x0042A4F0); //Tylko usuniêcie hooka, bo ca³a operacja inicjacji jest wykonywana tylko raz
	//Inicjacja gry
	CGothicGame* gothicGame = core.GetGothicGame();
	CNetwork* net = core.GetNetwork();
	
	if( net->IsInitiated() == false )
	{
		gothicGame->InitGame();
	}
	//this->Menu(i);
	//pMemLib->ImportHook(0x0042A4F0, sizeof(void(CGameManager::*)(int)), &CGameManager::Hook_Menu);
};

void CGameManager::Hook_Done()
{
	DLOG("CGameManager::Hook_Done()");
	pMemLib->RemoveHook(0x00427310);
	CNetwork* net = core.GetNetwork();
	if( net )
		if( net->IsConnected() == true )
			net->Disconnect();

	this->Done();
	pMemLib->ImportHook(0x00427310, sizeof(void(CGameManager::*)(void)), &CGameManager::Hook_Done);
};