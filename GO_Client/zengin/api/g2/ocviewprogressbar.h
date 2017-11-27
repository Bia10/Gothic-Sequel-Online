/* Gothic Online ZenGin research (based on g2ext) */


#ifndef __OCVIEWPROGRESSBAR_H_INCLUDED__
#define __OCVIEWPROGRESSBAR_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

/** Insert description. */
class oCViewProgressBar : public zCView
{
private:
	char _data[0x200];
public:

};

#undef __G2EXT_API_HEADER

#endif  //__OCVIEWPROGRESSBAR_H_INCLUDED__