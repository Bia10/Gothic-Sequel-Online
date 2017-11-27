/* Gothic Online ZenGin research (based on g2ext) */



#ifndef __API_G2_ZCVISUAL_H__
#define __API_G2_ZCVISUAL_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class zCVisual : public zCObject
{
private:
	char m_data[16];
};

#undef __G2EXT_API_HEADER

#endif  //__API_G2_ZCVISUAL_H__
