//---------------------------------------------------------------------------

#ifndef frmExamSectionAUnitH
#define frmExamSectionAUnitH
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
class TfrmExamPartA : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlRight;
	TPageControl *pgctrlMain;
	TTabSheet *tbsQuestion1;
	TImage *Image1;
	TTabSheet *tbsQuestion2;
	TButton *btnLoad;
	TRichEdit *redOutput;
	TStatusBar *StatusBar;
	TLabel *Label3;
	TShape *Shape3;
	TPanel *pnlCampCode;
	TPanel *pnlCampType;
	TImage *imgCamp;
	TListBox *lstCamps;

	void __fastcall tbsQuestion2Show(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnLoadClick(TObject *Sender);
	void __fastcall lstCampsClick(TObject *Sender);
	void __fastcall tbsQuestion1Show(TObject *Sender);







private:	// User declarations

	AnsiString oneRedLine;

	TStringList *lstRawDataList;
	AnsiString CurrentLine;

	TPanel *myPanel;


public:		// User declarations
	__fastcall TfrmExamPartA(TComponent* Owner);

	void ApplySettings(TObject *Sender);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmExamPartA *frmExamPartA;
//---------------------------------------------------------------------------
#endif
