/* Gothic Online ZenGin research (based on g2ext) */



#ifndef __API_G2_OCGAME_H__
#define __API_G2_OCGAME_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/zcsession.h"
#include "api/g2/zcparser.h"
#include "api/g2/ocobjectfactory.h"
#include "api/g2/ocnpc.h"
#include "api/g2/ocspawnmanager.h"


class zCView;
class zCWorld;
class oCWorldTimer;
class zCViewProgressBar;
class oCSavegameManager;
class oCViewStatusBar;
class oCGameInfo;
class zCVobLight;    
class oCGuilds;                        
class oCInfoManager;               
class oCNewsManager;                 
class oCSVMManager;           
class oCTradeManager;               
class oCPortalRoomManager;
class oCSpawnManager;  

enum oHEROSTATUS
{
	HERO_NORMAL,
	HERO_THREATENED,
	HERO_FIGHTING
};
	
enum oTGameDialogView
{
	GAME_VIEW_SCREEN,
	GAME_VIEW_CONVERSATION,       
	GAME_VIEW_AMBIENT,       
	GAME_VIEW_CINEMA,       
	GAME_VIEW_CHOICE,
	GAME_VIEW_NOISE,
	GAME_VIEW_MAX
};

/** Insert description */
typedef struct 
{
	zSTRING     objName;
	int         stateNum;
	int         hour1,min1;
	int         type;
} TObjectRoutine;

/** Insert description. */
class oCGame : public zCSession
{
public:
	float 				cliprange;
    float 				fogrange;
    int 				inScriptStartup;
    int 				inLoadSaveGame;
    int 				inLevelChange;
	
	zCView* 			array_view[GAME_VIEW_MAX];
    int 				array_view_visible[GAME_VIEW_MAX];
    int 				array_view_enabled[GAME_VIEW_MAX];
    
    oCSavegameManager* 	savegameManager;      
    zCView*				game_text;                           
    zCView*				load_screen;                           
    zCView*				save_screen;                       
    zCView*				pause_screen;                        
    oCViewStatusBar* 	hpBar;
    oCViewStatusBar* 	swimBar;  
    oCViewStatusBar* 	manaBar;
    oCViewStatusBar* 	focusBar;
    int 				showPlayerStatus;

    int 				game_drawall;
    int 				game_frameinfo;
    int 				game_showaniinfo;
    int 				game_showwaynet;
    int 				game_testmode;
    int 				game_editwaynet;
    int 				game_showtime;
    int 				game_showranges;
    int 				drawWayBoxes;
    int 				scriptStartup;
    int 				showFreePoints; 
    oCNpc*  			showRoutineNpc;   

    int 				loadNextLevel;                             
    zSTRING 			loadNextLevelName;                            
    zSTRING 			loadNextLevelStart;                         
    
    zVEC3 				startpos;                   
    oCGameInfo* 		gameInfo;
    zCVobLight*  		pl_light;                
    float 				pl_lightval;                          

    oCWorldTimer*   	wldTimer;           
    float 				timeStep;
    int 				singleStep;                             

    oCGuilds* 			guilds;                        
    oCInfoManager* 		infoman;               
    oCNewsManager*		newsman;                 
    oCSVMManager*  		svmman;           
    oCTradeManager*  	trademan;               
    oCPortalRoomManager*portalman;
    oCSpawnManager* 	spawnman;         
    
    float 				music_delay;                           
    oCNpc* 				watchnpc;                               

    int 				m_bWorldEntered;                             
    float 				m_fEnterWorldTimer;                           
    
    int 				initial_hour;                                    
    int 				initial_minute;                                 

    zCArray<zCVob*>           debugInstances;

    int 				debugChannels;      
    int 				debugAllInstances;

	int 				oldRoutineDay;
    
    zCListSort<TObjectRoutine>    objRoutineList;
        
    zCListSort<TObjectRoutine>* currentObjectRoutine;
    
    zCViewProgressBar* 	progressBar;

	zCArray<zCVisual*>  visualList;

public:
	//GO Hooks
	void Fake_WriteSavegame(int,int);
	void Fake_LoadSavegame(int,int);
	void Hook_Render(void);
	int Hook_HandleEvent(int key);
	void Hook_ChangeLevel(zSTRING const & map1, zSTRING const & map2);
	void Hook_EnterWorld(class oCNpc*, int, const zSTRING&);
	//End GO Hooks

	zCView * oCGame::GetTextView(void) { XCALL(0x0065F010); }
	void SetShowPlayerStatus(int p1) {XCALL(0x0065F130);};
	int GetShowPlayerStatus(){XCALL(0x0065F190);};
	void EnableTestmode(int enabled)
	{
		game_testmode = enabled;
	}
	
	int IsTestmodeEnabled()
	{
		return game_testmode;
	}
	
	//.text:006C2BD0 ; public: virtual void __thiscall oCGame::CloseLoadscreen(void)
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void CloseLoadscreen(void)
	{
		XCALL(0x0065EF80);
	};

	//.text:006C2630 ; public: virtual void __thiscall oCGame::CloseSavescreen(void)
	/** This method closes the savescreen.
	* @usable Ingame only
	*/
	void CloseSavescreen(void)
	{
		XCALL(0x0065E940);
	};

	//.text:006C4E70 ; public: virtual void __thiscall oCGame::GetTime(int &, int &, int &)
	/** This method returns the current ingame time.
	* @param day Reference to integer variable for the day value.
	* @param hwr Reference to integer variable for the hour value. 
	* @param min Reference to integer variable for the minute value.
	* @usable Ingame only
	*/
	void GetTime(int & day, int & hwr, int & min)
	{
		XCALL(0x00661280);
	};

	//.text:006C2C80 ; public: class oCWorldTimer * __thiscall oCGame::GetWorldTimer(void)
	/** This method returns the current world timer instance.
	* @usable Ingame only
	*/
	oCWorldTimer* GetWorldTimer(void)
	{
		XCALL(0x0065F020);
	};

	// zCSession::GetWorld(void)
	/** This method returns the current zCWorld instance of oCGame.
	* @usable Ingame only
	*/
	zCWorld* GetWorld(void) 
	{ 
		XCALL(0x005D5110);
	};
	
	void LoadWorld(int, const zSTRING&){XCALL(0x00665330)};
	void EnterWorld(class oCNpc*, int, const zSTRING&){XCALL(0x00665950)};
	void ClearGameState(void){XCALL(0x00662460)};
	void CallScriptInit(void){XCALL(0x0065E2C0)};
	void LoadWorldStartup(const zSTRING&){XCALL(0x00666080)};
	oCSpawnManager* GetSpawnManager(void){XCALL(0x0065F0A0)};

	//.text:006C2690 ; public: virtual void __thiscall oCGame::OpenLoadscreen(bool, class zSTRING)
	/** This method opens the loadscreen.
	* @usable Ingame only
	*/
	void OpenLoadscreen(int p1, zSTRING p2)
	{
		XCALL(0x0065E9A0);
	};

	//.text:006C2250 ; public: virtual void __thiscall oCGame::OpenSavescreen(bool)
	/** This method opens the savescreen.
	* @usable Ingame only
	*/
	void OpenSavescreen(bool p1)
	{
		XCALL(0x0065E530);
	};

	//.text:006C8AD0 ; public: virtual void __thiscall oCGame::Pause(int)
	/** This method pauses the game. 
	* @usable Ingame only
	*/
	void Pause(int p1 = 0)
	{
		XCALL(0x00664CD0);
	};

	//.text:006C4DE0 ; public: virtual void __thiscall oCGame::SetTime(int, int, int)
	/** This method sets the ingame time.
	* @param day Day
	* @param hwr Hour
	* @param min Minute
	* @usable Ingame only
	*/
	void SetTime(int day, int hwr, int min)
	{
		XCALL(0x006611F0);
	};

	//.text:006C8D50 ; public: virtual void __thiscall oCGame::Unpause(void)
	/** This method continues the game. 
	* @usable Ingame only
	*/
	void Unpause(void)
	{
		XCALL(0x00664F80);
	};

	/** Insert description.
	* @usable Ingame only
	*/
	zCViewProgressBar* GetProgressBar(void)
	{
		return *(zCViewProgressBar**)(this+0x172); //Possible this address broken in g1 (i does not tested it)
	};
	
	void Render(void)
	{
		XCALL(0x006648F0)
	};
	
	void ChangeLevel(zSTRING const & map1, zSTRING const & map2) //U¿ywaæ do zmiany mapy
	{
		XCALL(0x00663950)
	};

	void LoadGame(int, zSTRING&){XCALL(0x00662B20)};

	void WriteSavegame(int,int){XCALL(0x00661680);};
	void LoadSavegame(int,int){XCALL(0x00662D60);};

	int HandleEvent(int key){XCALL(0x0068A300)};
	virtual zVEC3 GetStartPos(){XCALL(0x0065C190);};
	oCNpc* CreateNPC(zSTRING& instance, float x, float y, float z); //From ocgame.cpp
	zCWorld* GetGameWorld(){XCALL(0x0065EFE0);};

	
	/** This method returns the current oCGame instance
	* @usable Ingame only
	*/
	inline static oCGame* GetGame() { return *(oCGame**)0x00920D8C; };
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_OCGAME_H__