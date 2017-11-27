#include "stdafx.h"


CClient::CClient()
{
	new MemLib();
	new CLog();

	DLOG("Gothic Online Debug Console Initialized!");
	DLOG("CClient::CClient()");

	bIsLateHooksInitiated = false;

	pSplashScreen = new CSplashScreen();
	pGothicGame = new CGothicGame();
	pRender = new CRender();
	pConfig = new CConfig();
	pNetwork = new CNetwork();
	pMultiplayer = new CMultiplayer();
	pChat = new CChat();
	pKeyBoard = new CKeyBoard();
};

CClient::~CClient()
{
	DLOG("CClient::~CClient()");
	this->DeInitializeHooks();
	if( IsLateHooksInitiated() == true )
		this->DeInitializeLateHooks();

	delete pMemLib;
	delete pSplashScreen;
	delete pGothicGame;
	delete pRender;
	delete pConfig;
	delete pNetwork;
	delete pMultiplayer;
	delete pChat;
	delete pKeyBoard;
};

void CClient::Start()
{
	DLOG("CClient::Start()");
	//Zmiana nazwy okna
	//CGothicWindow::SetGothicWindowName(RakString("Gothic Online"));
	//Wstawianie hook'ów
	this->InitializeHooks();

	// Initialize keyboard layout
	if (pConfig->GetLanguage() == "ru")
		pKeyBoard->SetLayout(CKeyBoard::RUSSIAN);

	DLOG("Client started");
};

void CClient::ApplyPatches()
{
	DLOG("CClient::ApplyPatches()");

};

void CClient::InitializeHooks()
{
	DLOG("CClient::InitializeHooks()");
	pMemLib->ImportHook(0x0042C8C0, sizeof(int(CGameManager::*)(zSTRING,int)), &CGameManager::Fake_PlayVideo); //Filmiki na pocz¹tku gry
	pMemLib->ImportHook(0x0042D130, sizeof(int(*)()), &Hook_Apply_Options_Video); //Zmiana rozdzielczosci
	pMemLib->ImportHook(0x0042A4F0, sizeof(void(CGameManager::*)(int)), &CGameManager::Hook_Menu); //Hook na menu, "odczepia" siê w innym miejscu
	pMemLib->ImportHook(0x004648E0, sizeof(zSTRING(zCOption::*)(const zSTRING&, const char*, const char*)), &zCOption::Hook_ReadString); //Tutaj zablokujê opcjê "NOWA GRA" z menu
	pMemLib->ImportHook(0x00663950, sizeof(void(oCGame::*)(const zSTRING&, const zSTRING&)), &oCGame::Hook_ChangeLevel); //Zmiana mapy
	pMemLib->ImportHook(0x00665950, sizeof(void(oCGame::*)(oCNpc*,int,const zSTRING&)), &oCGame::Hook_EnterWorld); //Wejscie do swiata
	pMemLib->ImportHook(0x00661680, sizeof(void(oCGame::*)(int,int)), &oCGame::Fake_WriteSavegame); //Blokowanie zapisywania gry
	pMemLib->ImportHook(0x00662D60, sizeof(void(oCGame::*)(int,int)), &oCGame::Fake_LoadSavegame); //Blokowanie wczytywania gry (bo crash)
	pMemLib->ImportHook(0x00427310, sizeof(void(CGameManager::*)(void)), &CGameManager::Hook_Done); //Zamykanie gry
#ifndef DEV_MODE
	pMemLib->ImportHook(0x433D80, sizeof(void(*)(zSTRING)), &Fake_HandleResultString); //Czity gothicowe (marvin, southpark etc.)
#endif //DEV_MODE
};

void CClient::DeInitializeHooks()
{
	DLOG("CClient::DeInitializeHooks()");
	pMemLib->RemoveHook(0x0042C8C0); //filmiki na pocz¹tku
	pMemLib->RemoveHook(0x0042D130); //Zmiana rozdzielczosci
	pMemLib->RemoveHook(0x004648E0); //NOWA GRA z menu
	pMemLib->RemoveHook(0x00663950); //Zmiana mapy
	pMemLib->RemoveHook(0x00665950); //Wejscie do swiata
	pMemLib->RemoveHook(0x00661680); //Zapis gry
	pMemLib->RemoveHook(0x00662D60); //Wczytanie gry
	pMemLib->RemoveHook(0x00427310); //Zamykanie gry

#ifndef DEV_MODE
	pMemLib->RemoveHook(0x433D80); //Gothicowe czity
#endif //DEV_MODE
};

void CClient::InitializeLateHooks()
{
	DLOG("CClient::InitializeLateHooks()");
	pMemLib->ImportHook(0x006648F0, sizeof(void(oCGame::*)(void)), &oCGame::Hook_Render); //Render
	pMemLib->ImportHook(0x0068A300, sizeof(int(oCGame::*)(int)), &oCGame::Hook_HandleEvent); //Hook na klawiaturê
	pMemLib->ImportHook(0x006C5A50, sizeof(void(oCNpc::*)(void)), &oCNpc::Fake_DropAllInHand); //Blokowanie wypadania miecza przy upadku
	pMemLib->ImportHook(0x00478AA0, sizeof(void(oCMag_Book::*)(void)), &oCMag_Book::Hook_Spell_Cast); //Magia
	pMemLib->ImportHook(0x006D3830, sizeof(int(oCNpc::*)(zCVob*)), &oCNpc::Hook_DoDropVob); //Wyrzucanie itemu
	pMemLib->ImportHook(0x006D3430, sizeof(int(oCNpc::*)(zCVob*)), &oCNpc::Hook_DoTakeVob); //Podnoszenie itemu
	pMemLib->ImportHook(0x006C6570, sizeof(void(oCNpc::*)(int)), &oCNpc::Hook_SetMovLock); //Blokada ruchu (do skryptow)
	pMemLib->ImportHook(0x006EFFA0, sizeof(void(oCNpc::*)(void)), &oCNpc::Hook_OpenInventory); //OpenInventory
	pMemLib->ImportHook(0x006F0200, sizeof(void(oCNpc::*)(void)), &oCNpc::Hook_CloseInventory); //CloseInventory co tu du¿o mówiæ?
	pMemLib->ImportHook(0x006BB2D0, sizeof(int(oCNpc::*)(zSTRING&)), &oCNpc::Hook_ApplyOverlay); // Przechwytywanie dodania overlay
	pMemLib->ImportHook(0x006BB620, sizeof(void(oCNpc::*)(zSTRING&)), &oCNpc::Hook_RemoveOverlay); // Przechwytywanie usuniêcia overlay
	pMemLib->ImportHook(0x006E4C40, sizeof(int(oCNpc::*)(zSTRING&, float)), &oCNpc::Hook_ApplyTimedOverlayMds);
	//pMemLib->ImportHook(0x0073A4B0, sizeof(void(zCView::*)(zINT, zINT, zSTRING &)), &zCView::Hook_Print);
	pMemLib->ImportHook(0x006C42F0, sizeof(void(oCNpc::*)(float, oCNpc*)), &oCNpc::Hook_DropUnconscious);
	pMemLib->ImportHook(0x006D3100, sizeof(void(oCNpc::*)(int)), &oCNpc::Hook_DoShootArrow);
	pMemLib->ImportHook(0x00781E70, sizeof(void(oCNpc::*)(oSDamageDescriptor&)), &oCNpc::Hook_OnDamage_Anim);
	pMemLib->ImportHook(0x007784F0, sizeof(void(oCNpc::*)(oSDamageDescriptor&)), &oCNpc::Hook_OnDamage_Script);
	this->bIsLateHooksInitiated = true;
	
};
void CClient::DeInitializeLateHooks()
{
	DLOG("CClient::DeInitializeLateHooks()");
	pMemLib->RemoveHook(0x006648F0); //render
	pMemLib->RemoveHook(0x0068A300); //Hook na klawiaturê
	pMemLib->RemoveHook(0x006C5A50); //Blokowanie wypadania miecza przy upadku
	pMemLib->RemoveHook(0x00478AA0); //Magia
	pMemLib->RemoveHook(0x006D3830); //Wyrzucenie itemu
	pMemLib->RemoveHook(0x006D3430); //Podnoszenie itemu
	pMemLib->RemoveHook(0x006C6570); //Blokada ruchu
	pMemLib->RemoveHook(0x006EFFA0); //OpenInventory
	pMemLib->RemoveHook(0x006F0200); //CloseInventory
	pMemLib->RemoveHook(0x006BB2D0); //Przechwytywanie dodania overlay
	pMemLib->RemoveHook(0x006BB620); //Przechwytywanie usuniêcia overlay
	pMemLib->RemoveHook(0x006E4C40);
	//pMemLib->RemoveHook(0x0073A4B0);
	pMemLib->RemoveHook(0x006C42F0);
	pMemLib->RemoveHook(0x006D3100);
	pMemLib->RemoveHook(0x00781E70);
	pMemLib->RemoveHook(0x007784F0);
	this->bIsLateHooksInitiated = false;
};