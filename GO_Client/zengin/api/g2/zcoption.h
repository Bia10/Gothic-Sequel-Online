/* Gothic Online ZenGin Research */

#ifndef _ZCOPTION_H
#define _ZCOPTION_H

#include "api/g2/zFILE.h"
#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

enum zTOptionPaths
{
	SYSTEM,
	WEB,
	SAVES,
	WORK_DATA,
	WORK_DATA_ANIMS,
	WORK_DATA_CUTSCENES,
	WORK_DATA_SCRIPTS_CONTENT_CUTSCENE,
	WORK_DATA_MESHES,
	WORK_DATA_SCRIPTS,
	WORK_DATA_SOUND,
	WORK_DATA_VIDEO,
	WORK_DATA_MUSIC,
	WORK_DATA_TEXTURES,
	WORK_DATA_TEXTURES_DESKTOP,
	WORK_DATA_WORLDS,
	WORK_DATA_PRESETS,
	WORK_TOOLS_DATA,
	WORK_DATA_ANIMS_COMPILED,
	WORK_DATA_MESHES_COMPILED,
	WORK_DATA_SCRIPTS_COMPILED,
	WORK_DATA_TEXTURES_COMPILED,
	WORK_TOOLS,
	INTERN
};

class zCOption
{
private:
	int vftable;
	char			dataa[16];
	zFILE_FILE*		optionPaths[26];
	char			data[520];
	zSTRING			commandLine;
public:
	zSTRING Hook_ReadString(const zSTRING&, const char*, const char*);

	zSTRING ReadString(const zSTRING&, const char*, const char*){XCALL(0x004648E0)};
	
};

#endif //_ZCOPTION_H