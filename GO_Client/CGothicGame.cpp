#include "stdafx.h"

CGothicGame::CGothicGame()
{
	DLOG("CGothicGame::CGothicGame()");
	bIsFirstFrame = true; //Po u¿yciu tego, w renderze wys³aæ pakiet o gotowoœci clienta
};

void CGothicGame::InitGame() //Uruchamianie z hooka na pokazanie menu :)
{
	//Wczytywanie nazwy œwiata z configu
	//Uruchamianie œwiata z wy³¹czonymi npc'ami
	//Nawi¹zanie po³¹czenia z serwerem i wys³anie pakietu autoryzacyjnego
	//Zmiana czasu na godzine 8:00
	DLOG("CGothicGame::InitGame()");
	oCGame* game = oCGame::GetGame();
	CChat* chat = core.GetChat();
	CConfig* config = core.GetConfig();
	CNetwork* net = core.GetNetwork();

	if( game )
	{
		game -> LoadWorldStartup(zSTRING(core.GetConfig()->GetStartWorld().C_String()));
		//game -> EnterWorld(0, 1, *(zSTRING*)(0x00869978)); //zSTR_EMPTY
		game->EnterWorld(0,1,zSTRING("WORLD.ZEN"));
		oCSpawnManager* spawnManager = game -> GetSpawnManager();
		if( spawnManager )
		{
			oCSpawnManager::SetRemoveRange(2097152.0f); //Usuwanie postaci tylko na duzej odleglosci (zamiast tamtych hookow)
			spawnManager -> SetSpawningEnabled(0); //Wy³¹cza spawnowanie npc
		}
		
		game -> SetTime(0, 8, 0);
		oCNpc* hero = oCNpc::GetHero();
		oCNpc* rockefeller = oCGame::GetGame()->CreateNPC(zSTRING("PC_Rockefeller"), 0.0f, 500.0f, 0.0f);
		rockefeller->SetAsPlayer();
		hero->DestroyNpc();

		//PóŸne hooki
		if( core.IsLateHooksInitiated() == false )
			core.InitializeLateHooks();
		//Inicjalizacja czatu i kilka wiadomoœci informacyjnych
		chat -> InitChat();
		chat -> Show(true);
		chat->AddLine(RakString("Sequel Multiplayer %s", versionString), zCOLOR(255, 196, 0, 255));
		
		//Nawi¹zywanie po³¹czenia z serwerem
		if( net->InitNetwork() == true ) //Inicjacja sieci
		{
			//chat -> AddLine(RakString("Establishing connection with %s:%s...", config->GetServerIp().C_String(), config->GetServerPort().C_String()), zCOLOR(68, 255, 0, 255));
			chat -> AddLine(RakString("Nawi¹zywanie po³¹czenia z %s:%s...", config->GetServerIp().C_String(), config->GetServerPort().C_String()), zCOLOR(255, 196, 0, 255));
			//net -> Connect() przeniesione do pierwszej klatki rendera
		}	
	}
}