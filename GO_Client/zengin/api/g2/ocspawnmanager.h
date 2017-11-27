/* Gothic Online ZenGin research */

#ifndef _OCSPAWNMANAGER_H
#define _OCSPAWNMANAGER_H

#include "api/g2/macros.h"
#include "api/g2/ztypes.h"
#include "api/g2/ocnpc.h"

class oCSpawnManager
{
public:
	void Fake_DeleteNpc(oCNpc* npc);
	int Fake_CheckRemoveNpc(oCNpc* npc);


	static void SetInsertRange(float){XCALL(0x00705FE0)};
	static float GetInsertRange(void){XCALL(0x00705FE0)};
	static void SetRemoveRange(float){XCALL(0x00706000)};
	static float GetRemoveRange(void){XCALL(0x00706010)};
	void SetSpawnTime(float){XCALL(0x00706020)};
	float GetSpawnTime(void){XCALL(0x00706030)};
	void ClearList(void){XCALL(0x00706040)};
	void SpawnImmediately(int){XCALL(0x00706220)};
	void CheckInsertNpcs(void){XCALL(0x007063D0)};
	void CheckInsertNpc(void){XCALL(0x00706880)};
	oCNpc* SummonNpc(int, const zVEC3&, float){XCALL(0x00706E40)};
	oCNpc* SpawnNpc(int, const zSTRING&, float){XCALL(0x00706F40)};
	void SpawnNpc(oCNpc*, const zSTRING&, float){XCALL(0x00706FB0)};
	void SpawnNpc(oCNpc*, const zVEC3&, float){XCALL(0x00707230)};
	int CheckRemoveNpc(oCNpc*){XCALL(0x007075C0)};
	void DeleteNpc(oCNpc*){XCALL(0x00707950)};
	void SetSpawningEnabled(int){XCALL(0x00706210)};

};

#endif //_OCSPAWNMANAGER_H