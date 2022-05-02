//---------------------------------------------------------------------------

#ifndef frmLookupUnitH
#define frmLookupUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmLookupDetails : public TForm
{
__published:	// IDE-managed Components
	TListBox *lstLookupDetails;
	TPanel *Panel1;
private:	// User declarations
public:		// User declarations
	__fastcall TfrmLookupDetails(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmLookupDetails *frmLookupDetails;
//---------------------------------------------------------------------------
#endif
