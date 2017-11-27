/* Gothic Online ZenGin research (based on g2ext) */


#ifndef __API_G2_ZCPARSER_H__
#define __API_G2_ZCPARSER_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

#include "api/g2/zcpar_symbol.h"

#pragma warning(disable:4731) // -- suppress C4731:"frame pointer register 'ebp' modified by inline assembly code"

class zCPar_File;
class zCPar_TreeNode;
class zCViewProgressBar;
class zCView;

/** Insert description */
typedef struct 
{
	zCPar_Symbol*	preAllocatedSymbols;
	int				nextPreAllocated;
} zCPar_SymbolTable;

/** Insert description. */
typedef enum  
{
	zCPVOID, 
	zCPFLOAT, 
	zCPINT, 
	zCPSTRING, 
	zCPCLASS, 
	zCPFUNC,
	zCPPROTOTYPE, 
	zCPINSTANCE
} zCParser_CallType;

#define zMAX_SYM_DATASTACK 2048

/** ZenGin Daedalus script parser. */
class zCParser
{
private:
	void (__cdecl * msgfunc)( zSTRING );

	zCArray<zCPar_File*>	file;
	zCPar_SymbolTable		symtab;
	zCArray<zCPar_Symbol*>  table;
	zCArraySort<int>		tablesort;

	zCPar_Symbol*			lastsym;
	zCPar_Symbol*			firstsym; 

	//zCPar_StringTable stringtab;
	zCArray<zSTRING*>		stringtab;

	//zCPar_Stack               stack;
	int stack_stack;                            //0x0048 zBYTE*  // Stackbegin
	int stack_stackptr;                         //0x004C zBYTE* or zWORD* or int*
	int stack_stacklast;                        //0x0050 zBYTE* or zWORD* or int*
	int stack_stacksize;                        //0x0054 int //Stack size in Bytes

	//zCPar_DataStack           datastack;
	int stack[zMAX_SYM_DATASTACK];				//0x0058
	int sptr;                                   //0x085C int

	zCPar_Symbol* _self;

	zSTRING fname;
	zSTRING mainfile;
	int compiled;          
	int treesave;               
	int datsave;              
	int parse_changed;
	int treeload;
	int mergemode;             
	int linkingnr;
	int linec;
	int line_start;
	int ext_parse;
	char* pc_start;
	char* pc;
	char* oldpc;
	char* pc_stop;
	char* oldpc_stop;
	int params;
	int in_funcnr;
	int in_classnr;
	int stringcount;
	zCPar_Symbol* in_func;
	zCPar_Symbol* in_class;
	int error;
	int stop_on_error;
	int errorline;
	char* prevword_index[16];
	int prevline_index[16];
	int prevword_nr;
	zSTRING  aword;     
	int _instance;           
	int instance_help;
	zCViewProgressBar* progressBar;
	zCPar_TreeNode* tree;
	zCPar_TreeNode* treenode;
	zCView* win_code;
	int debugmode;
	int curfuncnr;
	int labelcount;
	int* labelpos;

	//zCList <zSTRING>*     add_funclist;
	zCList<zSTRING*> add_funclist;
	int add_funclist_data;							//zString*
	int add_funclist_next;							//zCList<zSTRING>*

	zSTRING add_filename;                            //zSTRING                          
	int add_created;                                //zBOOL
public:

	//.text:00793470 ; public: int __thiscall zCParser::GetIndex(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int GetIndex(class zSTRING const & pA)
	{
		XCALL(0x00723120);
	};


	//.text:0078EBA0 ; public: int __thiscall zCParser::Parse(class zSTRING)
	/** Parses a *.d or a *.src file
	* @param  File name
	* @usable Ingame only
	*/
	int Parse(zSTRING zsFileName)
	{
		XCALL(0x0071E400);
	};

	//.text:0078EE20 ; public: int __thiscall zCParser::ParseSource(class zSTRING &)
	/** Parses a *.src file
	* @param  File name
	* @usable Ingame only
	*/
	int ParseSource(zSTRING & zsFileName)
	{
		XCALL(0x0071E6D0);
	};

	/** This method returns the current zCParser instance
	* @usable Ingame only
	*/
	static zCParser* GetParser()
	{
		return (zCParser*)0x00925048;
	};
};

#undef __G2EXT_API_HEADER

#endif // __API_G2_ZCPARSER_H__

