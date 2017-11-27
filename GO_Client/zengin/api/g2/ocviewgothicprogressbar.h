/* Gothic Online ZenGin research (based on g2ext) */

/////////////////////////////////////////////////////////////////////////////*/

#ifndef __OCVIEWGOTHICPROGRESSBAR_H_INCLUDED__
#define __OCVIEWGOTHICPROGRESSBAR_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/zcview.h"
#include "api/g2/ocviewprogressbar.h"

/** Insert description. */
class oCViewGothicProgressBar : public oCViewProgressBar
{
private:
	char _data[0x256];

};

#undef __G2EXT_API_HEADER

#endif  //__OCVIEWGOTHICPROGRESSBAR_H_INCLUDED__