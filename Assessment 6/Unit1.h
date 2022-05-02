//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *dbgrdRangers;
	TLabel *Label1;
	TButton *btnInsert;
	TButton *btnUpdate;
	TButton *btnDel;
	TEdit *edtName;
	TEdit *edtSurname;
	TEdit *edtReportCamp;
	TDateTimePicker *DateTimePicker1;
	TComboBox *cmbRanks;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnInsertClick(TObject *Sender);
	void __fastcall btnUpdateClick(TObject *Sender);
	void __fastcall btnDelClick(TObject *Sender);
private:	// User declarations
    AnsiString Ranks[5];
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
