//---------------------------------------------------------------------------

#ifndef LB_A1UnitH
#define LB_A1UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TListBox *lstNumbers;
	TButton *btnGenerate;
	TButton *btnDeleteAll;
	TButton *btnDeleteSel;
	TButton *btnSort;
	TLabel *lblCountNumbers;
	TButton *btnDeleteRandomly;
	void __fastcall btnGenerateClick(TObject *Sender);
	void __fastcall btnSortClick(TObject *Sender);
	void __fastcall btnDeleteSelClick(TObject *Sender);
	void __fastcall btnDeleteAllClick(TObject *Sender);
	void __fastcall btnDeleteRandomlyClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
