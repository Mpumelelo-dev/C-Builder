//---------------------------------------------------------------------------

#ifndef frmExercise5UnitH
#define frmExercise5UnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Graphics.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TfrmExercise5 : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlRight;
	TPageControl *pgctrlMain;
	TTabSheet *tbsQuestion3;
	TImage *Image1;
	TTabSheet *tbsQuestion4;
	TLabel *Label1;
	TShape *Shape2;
	TLabel *Label2;
	TDBGrid *dbgrdTarrifRates;
	TCheckBox *ckbShowAllTarrifRates;
	TButton *btnLast;
	TButton *btnNext;
	TButton *btnPrior;
	TButton *btnFirst;
	TComboBox *cmbAccomodationTypes;
	TButton *btnDeleteCurrRecord;
	TButton *btnIncreaseBaseRateSQL;
	TDBGrid *dbgrdTarrifRates2;
	TShape *Shape1;
	TLabel *Label4;
	void __fastcall tbsQuestion3Show(TObject *Sender);
	void __fastcall ckbShowAllTarrifRatesClick(TObject *Sender);
	void __fastcall btnFirstClick(TObject *Sender);
	void __fastcall btnPriorClick(TObject *Sender);
	void __fastcall btnNextClick(TObject *Sender);
	void __fastcall btnLastClick(TObject *Sender);
	void __fastcall tbsQuestion4Show(TObject *Sender);
	void __fastcall btnDeleteCurrRecordClick(TObject *Sender);
	void __fastcall btnIncreaseBaseRateSQLClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);


	





private:	// User declarations



public:		// User declarations
	__fastcall TfrmExercise5(TComponent* Owner);

	void ApplySettings(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmExercise5 *frmExercise5;
//---------------------------------------------------------------------------
#endif
