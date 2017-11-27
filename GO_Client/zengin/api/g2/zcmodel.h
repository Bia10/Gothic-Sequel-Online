//////////////////////////////////////////////////////////////////////////////
// 
// The G2Ext SDK headers are being published under the 
// Mozilla Public License Version 1.1 (the "License"); you may not use this 
// file except in compliance with the License.
// You may obtain a copy of the License at http://www.mozilla.org/MPL/
// 
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
// License for the specific language governing rights and limitations
// under the License.
// 
// Developed by Christoffer Anselm and Patrick Vogel
// All rights reserved.
//
// G2Ext SDK headers © 2009 by Paindevs and Patrick Vogel
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __API_G2_ZCMODEL_H__
#define __API_G2_ZCMODEL_H__

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

class zCModelAni
{
public:
	zSTRING& GetAniName() { XCALL(0x00598B90); };
};

/** Insert description. */
class zCModel
{
public:
	void Hook_StartAni(zCModelAni*, int);
	//
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void StartAni(int a, int b)					{ XCALL(0x00579960); };

	//
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void StartAni(const zSTRING& pA, int pB)	{ XCALL(0x005796F0); };

	void StartAni(zCModelAni* pA, int pB)		{ XCALL(0x005799D0); };

	void FadeOutAnisLayerRange(int, int) {XCALL(0x0057DAE0); };

	//
	/** This method closes the loadscreen.
	* @usable Ingame only
	*/
	void StopAni(int a)							{ XCALL(0x005792A0); };

	int IsAnimationActive(const zSTRING&) { XCALL(0x00575280); };
	zCModelAni* GetAniFromAniID(int) {XCALL(0x00475680);};
};

#endif  //__API_G2_ZCMODEL_H__