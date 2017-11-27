/* Gothic Online ZenGin research (based on g2ext) */



#ifndef __API_G2_ZCCONSOLE_H__
#define __API_G2_ZCCONSOLE_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADRE
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/zcinputcallback.h"

class zCWorld;
class zCParser;

/** Insert description. */
class zCConsole : public zCInputCallback
{
private:
	zSTRING unk;
	zSTRING unk2;
	zSTRING result;
	char m_datab[256]; // TODO: Get size
public:
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_ZCCONSOLE_H__