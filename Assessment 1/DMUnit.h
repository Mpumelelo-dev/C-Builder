//---------------------------------------------------------------------------

#ifndef DMUnitH
#define DMUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDMod : public TDataModule
{
__published:	// IDE-managed Components
	TADODataSet *ADOdsRanger;
	TDataSource *dsRanger;
	TADOConnection *ADOConn;
private:	// User declarations
public:		// User declarations
	__fastcall TDMod(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDMod *DMod;
//---------------------------------------------------------------------------
#endif
