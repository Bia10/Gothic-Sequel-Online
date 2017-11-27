/* Gothic Online ZenGin research (based on g2ext) */



#ifndef __ZCVIEW_H_INCLUDED__
#define __ZCVIEW_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

class zCTexture;
class zCFont;
class zCViewText {};

class zTSystemContextHandle;

#define VIEW_VXMAX 8192
#define VIEW_VYMAX 8192

/** Insert description. */
enum zTviewID 
{
	VIEW_SCREEN,
	VIEW_VIEWPORT,
	VIEW_ITEM
};	

/** Insert description. */
enum zTViewFX
{
	VIEW_FX_NONE,
	VIEW_FX_ZOOM,
	VIEW_FX_MAX	
};

/** Insert description. */
enum zTRnd_AlphaBlendFunc   
{   
	zRND_ALPHA_FUNC_MAT_DEFAULT,
	zRND_ALPHA_FUNC_NONE,           
	zRND_ALPHA_FUNC_BLEND,          
	zRND_ALPHA_FUNC_ADD,                    
	zRND_ALPHA_FUNC_SUB,                    
	zRND_ALPHA_FUNC_MUL,                    
	zRND_ALPHA_FUNC_MUL2,                   
	zRND_ALPHA_FUNC_TEST,           
	zRND_ALPHA_FUNC_BLEND_TEST      
};

/** zCView base class. */
class zCViewBase
{
private:
	int _vtbl;
};

/** Insert description. */
class zCView : public zCViewBase
{
private:
	zTViewFX				zEViewFX;
	int						m_bFillZ;
	zCView*					next;
	zTviewID				viewID;
	int						flags;
	int						intflags;
	int						ondesk;
	zTRnd_AlphaBlendFunc	alphafunc;
	zCOLOR					color; 
	int						alpha;
	zCList<zCView>          childs;

	//zList <zCView>        childs;
	int compare;			//(*Compare)(zCView *ele1,zCView *ele2);
	int count;				//int
	int last;				//zCView*;
	int wurzel;				//zCView*

	zCView*					owner;
	zCTexture*				backTex;

	int						vposx; 
	int 					vposy; 
	int 					vsizex;
	int 					vsizey;

	int 					pposx; 
	int 					pposy; 
	int 					psizex;
	int 					psizey;

	zCFont* 				font;
	zCOLOR					fontColor;

	int 					px1;
	int 					py1;
	int 					px2;
	int 					py2;

	int 					winx;
	int 					winy;  

	zCList<zCViewText>      textLines;

	int 					scrollMaxTime;
	int 					scrollTimer;

	zTViewFX 				fxOpen;
	zTViewFX 				fxClose;
	float 					timeDialog;
	float 					timeOpen;
	float 					timeClose;
	float 					speedOpen;   
	float 					speedClose;
	int 					isOpen;
	int 					isClosed;
	int 					continueOpen;
	int 					continueClose;
	int 					removeOnClose;
	int 					resizeOnOpen;
	int 					maxTextLength;
	zSTRING 				textMaxLength;      
	zVEC2 					posCurrent_0;
	zVEC2 					posCurrent_1;            
	zVEC2 					posOpenClose_0;
	zVEC2 					posOpenClose_1;

	char					_data[256];
public:
	void Hook_Print(zINT p1, zINT p2, zSTRING & p3);

	//.text:007A5700 ; public: __thiscall zCView::zCView(int, int, int, int, enum  zTviewID)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCView(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x00735F80);
	};

	void Constructor(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x00735F80);
	};

	void Destructor()
	{
		XCALL(0x00736040);
	};

	void ClrFlags(int)
	{
		XCALL(0x00736960);
	}

	//.text:007A5640 ; public: __thiscall zCView::zCView(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCView()
	{
		XCALL(0x00735EC0);
	};

	//.text:007A6E30 ; public: void __thiscall zCView::Close(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Close(void)
	{
		XCALL(0x00737660);
	};

	//.text:007AA140 ; public: void __thiscall zCView::ClrPrintwin(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ClrPrintwin(void)
	{
		XCALL(0x00700570);
	};

	//.text:007A6810 ; int __stdcall zCView__Create(int, int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Create(zSTRING& background, zTViewFX fx0, zTViewFX fx1, float unk0, int unk1)
	{
		XCALL(0x006FCC90);
	};

	//.text:007A6750 ; public: void __thiscall zCView::DrawItems(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void DrawItems(void)
	{
		XCALL(0x00736F90);
	};

	//.text:007A9A10 ; public: int __thiscall zCView::FontSize(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int FontSize(zSTRING & pA)
	{
		XCALL(0x0073A480);
	};

	//.text:007A99F0 ; public: int __thiscall zCView::FontY(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int FontY(void)
	{
		XCALL(0x0073A460);
	};

	//.text:007A5B20 ; public: void __thiscall zCView::Init(int, int, int, int, enum  zTviewID)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x007363C0);
	};

	//.text:007A5CC0 ; public: void __thiscall zCView::Init(int, int, class zSTRING const &, enum  zTviewID)
	/** Insert description. 
	* usable Ingame only
	*/
	void Init(int pA, int pB, zSTRING & pD, zTviewID pE)
	{
		XCALL(0x00736560);
	};

	//.text:007A5990 ; public: void __thiscall zCView::Init(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(void)
	{
		XCALL(0x00736230);
	};

	//.text:007A6130 ; public: void __thiscall zCView::InsertBack(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void InsertBack(zSTRING const & pA)
	{
		XCALL(0x007369E0);
	};

	//.text:007ABAD0 ; public: void __thiscall zCView::InsertItem(class zCView * Element, zBOOL StayOnTop)
	/** Insert description. 
	* @usable Ingame only
	*/
	void InsertItem(void* Element, int StayOnTop = false)
	{
		XCALL(0x0073C660);
	};

	//.text:007A7860 ; public: void __thiscall zCView::GetExtends(int &, int &, int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetExtends(int & x, int & y, int & cx, int & cy)
	{
		XCALL(0x007380B0);
	};

	//.text:007A7830 ; public: void __thiscall zCView::GetPixelSize(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPixelSize(int & x, int & y)
	{
		XCALL(0x00738080);
	};

	//.text:007A7660 ; public: void __thiscall zCView::GetPos(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPos(int & x, int & y)
	{
		XCALL(0x00737EB0);
	};

	//.text:007A7810 ; public: void __thiscall zCView::GetSize(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetSize(int & x, int & y)
	{
		XCALL(0x00738060);
	};

	//.text:007ABF70 ; public: virtual void __thiscall zCView::Line(int, int, int, int, struct zCOLOR const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Line(int x, int y, int x1, int y1, const zCOLOR& col)
	{
		XCALL(0x0073CB20);
	};
	//.text:007A9A40 ; public: void __thiscall zCView::Print(zINT, zINT, class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/

	void Print(zINT p1, zINT p2, const zSTRING & p3)
	{
		XCALL(0x0073A4B0);
	};

	//.text:007ABD10 ; public: void __thiscall zCView::RemoveItem(class zCView *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RemoveItem(void* Element)
	{
		XCALL(0x0073C8B0);
	};

	//.text:007A6080 ; public: void __thiscall zCView::SetColor(struct zCOLOR const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetColor(const zCOLOR & p1)
	{
		XCALL(0x00736930);
	};

	//.text:007A9920 ; public: void __thiscall zCView::SetFont(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFont(const zSTRING & p1)
	{
		XCALL(0x0073A360);
	};

	//.text:007A9910 ; public: void __thiscall zCView::SetFontColor(struct zCOLOR const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFontColor(const zCOLOR & p1)
	{
		XCALL(0x0073A380);
	};

	//.text:007A75B0 ; public: void __thiscall zCView::SetPos(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetPos(int pA, int pB)
	{
		XCALL(0x00737E00);
	};
	void SetFlags(int){XCALL(0x00736950);};
	void SetTransparency(int){XCALL(0x00736910);};
	zCFont* GetFont(){XCALL(0x0073A3C0);};
	//.text:007A77A0 ; public: void __thiscall zCView::SetSize(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetSize(int pA, int pB)
	{
		XCALL(0x00737FF0);
	};
	zSTRING GetFontName(void){XCALL(0x0073A3D0)};

	/** This method returns the current zCView instance
	* @usable Ingame only
	*/
	static zCView* CreateView(int x, int y, int width, int height, zSTRING& texture);
	inline static zCView* GetScreen() { return *(zCView**)0x00926414; };
};

/** Insert description */
class zCViewProgressBar
{
private:
	char m_cData[8];
	int  m_nProgress;
	char m_cData2[24];
public:

};

#undef __G2EXT_API_HEADER

#endif // __ZCVIEW_H_INCLUDED__