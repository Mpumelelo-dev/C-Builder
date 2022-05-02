//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *redOutput;
	TButton *btnLoad;
	TComboBox *cmbIDNumbers;
	TGroupBox *grpInfo;
	TImage *Image1;
	TImage *imgCardPic;
	void __fastcall btnLoadClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cmbIDNumbersChange(TObject *Sender);
private:	// User declarations

	TStringList *lstRawData;
	AnsiString CurrentLine, OneRedLine;

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
