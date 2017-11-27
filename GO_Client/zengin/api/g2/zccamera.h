/* Gothic Online ZenGin research (based on g2ext) */



#ifndef __API_G2_ZCCAMERA_H__
#define __API_G2_ZCCAMERA_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"


struct zTCamVertSimple
{
	float				x,y,z;      
	zVEC2				texuv;
	zCOLOR				color;
};

enum zTCam_DrawMode 
{ 
	zCAM_DRAW_NORMAL, 
	zCAM_DRAW_NOTHING, 
	zCAM_DRAW_WIRE, 
	zCAM_DRAW_FLAT, 
	zCAM_DRAW_TEX 
};


enum { zTCAM_POLY_NUM_VERT = 4 };


/** Insert description. */
class zCCamera
{	
public:
	char dataa[164];
	zMAT4 camMatrix; // decimal 164
	char data[2108];
	zCVob* connectedVob;
	char datab[16];

};

#undef __G2EXT_API_HEADER

#endif  //__API_G2_ZCCAMERA_H__