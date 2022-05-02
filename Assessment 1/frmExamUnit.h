//---------------------------------------------------------------------------

#ifndef frmExamUnitH
#define frmExamUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TfrmDBConcepts : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *grdRanger;
	TLabel *Label1;
	TButton *btnShowData;
	TButton *btnFirst;
	TButton *btnPrevious;
	TButton *btnLast;
	TButton *btnNext;
	TDBEdit *DBEdit1;
	TDBEdit *DBEdit2;
	TLabel *Label2;
	TLabel *Label3;
	TButton *btnDispDBEdits;
	TButton *btnDispEdits;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label6;
	TComboBox *cmbSort;
	void __fastcall btnShowDataClick(TObject *Sender);
	void __fastcall btnNextClick(TObject *Sender);
	void __fastcall btnFirstClick(TObject *Sender);
	void __fastcall btnPreviousClick(TObject *Sender);
	void __fastcall btnLastClick(TObject *Sender);
	void __fastcall btnDispDBEditsClick(TObject *Sender);
	void __fastcall btnDispEditsClick(TObject *Sender);
	void __fastcall cmbSortChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmDBConcepts(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDBConcepts *frmDBConcepts;
//---------------------------------------------------------------------------
#endif
