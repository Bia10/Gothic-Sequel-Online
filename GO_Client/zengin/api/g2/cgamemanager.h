#ifndef __API_G2_CGAMEMANAGER_H__
#define __API_G2_CGAMEMANAGER_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/ocgame.h"

/** Insert description. */
class CGameManager
{
public:
	//GO hooks
	int Fake_PlayVideo(zSTRING Filename, int i1){ return 1; };
	void Hook_Menu(int i);
	void Hook_Done();
	//End Go hooks

	void Done(){XCALL(0x00427310);};

	//.text:00425780 ; public: int __thiscall CGameManager::ExitGame(void)
	/** This method closes Gothic. 
	* @usable Ingame only
	*/
	int ExitGame(void)
	{
		XCALL(0x00427560);
	};

	//.text:0042B1B0 ; public: class oCGame * __thiscall CGameManager::GetGame(void)
	/** This method returns the current oCGame instance.
	* @returns Current oCGame instance.
	* @usable Ingame only
	*/
	oCGame* GetGame(void)
	{
		XCALL(0x0042C0F0);
	};

	void Menu(int iA){XCALL(0x0042A4F0)};
	void InitScreen_Open(void){XCALL(0x00427BB0)};
	void GameInit(void){XCALL(0x004282F0)};

	/** This method returns the current CGameManager instance
	* @usable Ingame only
	*/
	inline static CGameManager*		GetGameManager(){ return *(CGameManager**)0x008A31D8; };
};

#undef __G2EXT_API_HEADER

#endif //__API_G2_CGAMEMANAGER_H__