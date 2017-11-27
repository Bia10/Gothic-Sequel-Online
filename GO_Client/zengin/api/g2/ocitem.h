/* Gothic Online ZenGin research (based on g2ext) */


#ifndef __API_G2_OCITEM_H__
#define __API_G2_OCITEM_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"
#include "api/g2/zcobject.h"
#include "api/g2/ocvob.h"
#include "api/g2/zcvob.h"

class oCNpc;
class zCView;
class zCWorld;

/** Insert description. */
class oCItem : public oCVob
{
public:
	int		idx;
	zSTRING name;
	zSTRING nameID;
	int		hp;
	int		hp_max;
	int     mainflags;
	int		flags;
	int		weight;
	int     value;

	// -- weapons		
	int     damageType;
	int     damageTotal;
	int     damage[8];

	// -- armor 
	int     wear;
	int     protection[8];

	// -- food
	int     nutrition;

	// -- use attributes
	int     cond_atr[3];
	int     cond_value[3];

	// -- attributes that will be changed on equip
	int     change_atr[3];
	int     change_value[3];

	// -- parser functions
	int     magic;
	int     on_equip;
	int     on_unequip;	
	int     on_state[4];			

	// -- owner									
	int		owner;			//	owner: npc instance
	int		ownerGuild;		//	owner: guild
	int		disguiseGuild;

	// -- visual
	zSTRING	visual;

	// -- change of mesh on equip
	zSTRING visual_change;	//	ASC file
	zSTRING effect;			//  Effect instance

	int		visual_skin;

	zSTRING	scemeName;
	int		material;	
	int		munition;		//	Instance of ammunition

	int 	spell;			
	int		range;			

	int		mag_circle;

	zSTRING	description;
	zSTRING	text[6];
	int		count[6];

	// -- inventory presentation
	int	    inv_zbias;								//  far plane (how far the item goes into the room by the z-axis)
	int		inv_rotx;								//  rotation around x-axis (in degrees)
	int 	inv_roty;								//  rotation around y-axis (in degrees)
	int 	inv_rotz;								//  rotation around z-axis (in degrees)
	int 	inv_animate;							//  rotate the item

private:
	char _data[28];

public:
	void SetAmount(int amount)
	{
		*(int*)((DWORD)this + 0x2E4) = amount;
	}

	int GetAmount()
	{
		return *(int*)((DWORD)this + 0x2E4);
	}

	//.text:00712160 ; public: zINT __thiscall oCItem::GetCount(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetCount(zINT p1)
	{
		XCALL(0x0069F450);
	};

	//.text:00711420 ; public: virtual zINT __thiscall oCItem::GetInstance(void)
	/** This method returns the instance of the item.
	* @return Item instance. 
	* @usable Ingame only
	*/
	zINT GetInstance(void)
	{
		XCALL(0x0069E820);
	};

	//.text:00713D30 ; public: virtual class zSTRING __thiscall oCItem::GetInstanceName(void)
	/** This method returns the instance name of the item.
	* @return Item instance name. 
	* @usable Ingame only
	*/
	zSTRING GetInstanceName(void)
	{
		XCALL(0x006A0CA0);
	};

	//.text:00712880 ; public: class zSTRING __thiscall oCItem::GetName(int)
	/** This method returns the instance name of the item.
	* @param  Item instance.
	* @return Item instance name. 
	* @usable Ingame only
	*/
	zSTRING GetName(zINT instance)
	{
		XCALL(0x0069FAD0);
	};

	//.text:00698E50 ; public: class zSTRING __thiscall oCItem::GetSchemeName(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetSchemeName(void)
	{
		XCALL(0x00635950);
	};

	//.text:00713CC0 ; public: virtual zINT __thiscall oCItem::GetScriptInstance(class zSTRING &, zINT &)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING GetScriptInstance(zSTRING & p1, zINT p2)
	{
		XCALL(0x006A0C30);
	};

	//.text:00712B80 ; public: zINT __thiscall oCItem::GetStateEffectFunc(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetStateEffectFunc(zINT p1)
	{
		XCALL(0x0069FDE0);
	};
	//.text:007120F0 ; public: class zSTRING & __thiscall oCItem::GetText(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	zSTRING & GetText(zINT p1)
	{
		XCALL(0x0069F3E0);
	};

	//.text:00712650 ; public: zINT __thiscall oCItem::GetValue(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zINT GetValue(void)
	{
		XCALL(0x0069F8C0);
	};
};

/** Insert description. */
class oCItemContainer
{
protected:
	int		_vtbl;
public:
	void*	contents;
	oCNpc*	npc;
	zSTRING titleText;
	int		invMode;
	int		selectedItem;
	int		offset;
	int		maxSlotsCol;
	int		imaxSlotsColScr;
	int		maxSlotsRow;
	int		maxSlotsRowScr;
	int		maxSlots;
	int     marginTop;
	int     marginLeft;
	zBOOL   frame;
	zBOOL   right;
	zBOOL   ownList;
	zBOOL   prepared;
	zBOOL   passive;
	int     TransferCount;
	zCView* viewTitle;
	zCView* viewBack;
	zCView* viewItem;
	zCView* viewItemActive;
	zCView* viewItemHightlighted;
	zCView* viewItemActiveHighlighted;
	zCView* viewItemInfo;
	zCView* viewItemInfoItem;
	zCView* textView;
	zCView* viewArrowAtTop;
	zCView* viewArrowAtBottom;
	zCWorld*rndWorld;
	int     posx;
	int     posy;
	zBOOL   m_bManipulateItemsDisabled;
	zBOOL   m_bCanTransferMoreThanOneItem;
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_OCITEM_H__