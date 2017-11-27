#include "..\\..\\..\\stdafx.h"

void Fake_HandleResultString(zSTRING str)
{
};

int Hook_Apply_Options_Video()
{
	pMemLib->RemoveHook(0x0042D130);
	if( core.IsLateHooksInitiated() == true )
		core.DeInitializeLateHooks();
	int result = Apply_Options_Video();
	if( core.IsLateHooksInitiated() == false )
		core.InitializeLateHooks();
	pMemLib->ImportHook(0x0042D130, sizeof(int(*)()), &Hook_Apply_Options_Video);
	return result;
};

int ConsoleEval(zSTRING& s, zSTRING& msg)
{
	XCALL(0x00625B30);
};

int Apply_Options_Video()
{
	XCALL(0x0042D130);
};

void HandleResultString(zSTRING str)
{
	XCALL(0x00433D80);
};

int __cdecl vidGetFPSRate()
{
	XCALL(0x00502030);
};

void __cdecl vidToggleFullScreenMode()
{
	XCALL(0x005030C0);
};