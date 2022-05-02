// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "frmExamUnit.h"
#include "DMUnit.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDBConcepts *frmDBConcepts;


// ---------------------------------------------------------------------------
__fastcall TfrmDBConcepts::TfrmDBConcepts(TComponent* Owner) : TForm(Owner)
{
	
}
// ---------------------------------------------------------------------------
void __fastcall TfrmDBConcepts::FormShow(TObject *Sender)
{
	//GIVEN - DO NOT CHANGE!
    AnsiString conn = "";
	TStringList *provs = new TStringList;
	GetProviderNames(provs);

    AnsiString DBsource = GetCurrentDir();
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);

	int iJET = provs->IndexOf("Microsoft.Jet.OLEDB.4.0");
	int iACE = provs->IndexOf("Microsoft.ACE.OLEDB.12.0");

	if (iJET > 0)
	{
		conn = "Provider=" + provs->Strings[iJET] + ";Data Source=";
		conn += DBsource + "\\AppFiles\\KrugerPark.mdb";
	}
	else if (iACE > 0)
	{
		conn = "Provider=" + provs->Strings[iACE] + ";Data Source=";
		conn += DBsource + "\\AppFiles\\KrugerPark.accdb";
	}
	conn += ";Mode=ReadWrite;Persist Security Info=False";

	DMod->ADOConn->Connected = false;
	DMod->ADOConn->ConnectionString = conn;
    DMod->ADOConn->LoginPrompt = false;
    try
	{
		DMod->ADOConn->Connected = true;
	}
	catch (EADOError *E)
	{
	  ShowMessage(E->Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmDBConcepts::btnShowDataClick(TObject *Sender) {
	/*
		write code to display ranger id, name, surname and dateappointed
		in the database grid.

		ensure that information is sorted by surname (ascending)
	*/
	//declare variable
	//connectivity
	AnsiString sql ="select rangerid,name,surname,dateappointed from rangers order by surname";
	DMod->ADOConn->Connected = true;
	DMod->ADOdsRanger->Close();
	DMod->ADOdsRanger->CommandText = sql;
	DMod->ADOdsRanger->Open();
	grdRanger->DataSource=DMod->dsRanger;

}
// ---------------------------------------------------------------------------

void __fastcall TfrmDBConcepts::btnFirstClick(TObject *Sender) {
	//move record pointer to first record
	DMod-> ADOdsRanger->First();
}

// ---------------------------------------------------------------------------
void __fastcall TfrmDBConcepts::btnPreviousClick(TObject *Sender) {
	//move record pointer to previous record
	DMod-> ADOdsRanger->Prior();
}

// ---------------------------------------------------------------------------
void __fastcall TfrmDBConcepts::btnNextClick(TObject *Sender) {
	//move record pointer to next record
	DMod-> ADOdsRanger->Next();
}

// ---------------------------------------------------------------------------
void __fastcall TfrmDBConcepts::btnLastClick(TObject *Sender) {
	//move record pointer to last record
	DMod-> ADOdsRanger->Last();
}
// ---------------------------------------------------------------------------

void __fastcall TfrmDBConcepts::btnDispDBEditsClick(TObject *Sender) {
	/*
		Display the surname and appointed in the corresponding data aware fields
		Surname should be displayed by DBEdit1 and Appointed should be shown
		by DBEdit2
	*/
	DBEdit1->DataSource=DMod->dsRanger;
				  DBEdit1-> DataField = "surname";
			   DBEdit2->DataSource=DMod->dsRanger;
				  DBEdit2-> DataField = "DateAppointed";

}
// ---------------------------------------------------------------------------

void __fastcall TfrmDBConcepts::btnDispEditsClick(TObject *Sender) {
    /*
		Display the surname and appointed in the corresponding data components.
		Surname should be displayed by Edit1 and Appointed should be shown
		by Edit2
	*/
Edit1->Text=DMod->ADOdsRanger->FieldByName("surname")->AsAnsiString;
Edit2->Text=DMod->ADOdsRanger->FieldByName("dateappointed")->AsAnsiString;

}
// ---------------------------------------------------------------------------

void __fastcall TfrmDBConcepts::cmbSortChange(TObject *Sender)
{
	/*
		Sort the data in the dataset by the text selected from the combobox.
		for example, if Surname is selected, data in the dataset should now
		be sorted by Surname.
	*/
  //	AnsiString sql = "select rangerid,name,surname,dateappointed from rangers order by current";
		AnsiString current = cmbSort->Items->Strings[cmbSort->ItemIndex];
	/* DMod->ADOdsRanger->Close();
		DMod->ADOdsRanger->CommandText=sql;
		 DMod->ADOdsRanger->Open();
			grdRanger->DataSource=DMod->dsRanger;
												  */
												  ShowMessage(current);

}
//---------------------------------------------------------------------------
