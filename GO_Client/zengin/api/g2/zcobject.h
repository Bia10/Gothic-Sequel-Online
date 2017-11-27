/* Gothic Online ZenGin research (based on g2ext) */


#ifndef __API_G2_ZCOBJECT_H__
#define __API_G2_ZCOBJECT_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

class zCArchiver;

/** ZenGin object base class. */
class zCObject
{
private:
	int		_vtbl;
protected:
	int		refCtr;
	int		hashIndex;
	int		hashNext;
	zSTRING objectName;
public:    
	int Release(void)
	{
		XCALL(0x0042DB30);
	};

};

class zCObjectNVT
{
private:
	//int		_vtbl;
protected:
	int		refCtr;
	int		hashIndex;
	int		hashNext;
	zSTRING objectName;
};
#undef __G2EXT_API_HEADER

#endif //__API_G2_ZCOBJECT_H__