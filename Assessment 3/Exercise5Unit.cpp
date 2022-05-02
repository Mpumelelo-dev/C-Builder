//---------------------------------------------------------------------------

#include <vcl.h>
#include <JPEG.hpp>
#pragma hdrstop

#include "Exercise5Unit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma resource "*.dfm"
TfrmExercise5 *frmExercise5;
char Code;

//---------------------------------------------------------------------------
// GetFieldByNr
AnsiString getFieldByNr(AnsiString aLine, int fieldNr, char delimiter)
{
	aLine += delimiter;
	int pos;
	AnsiString field;
	for (int i = 1; i <= fieldNr; i++) {
		pos = aLine.Pos(delimiter);
		field = aLine.SubString(1, pos - 1);
		aLine.Delete(1, pos);
	}
	return field;
}

//---------------------------------------------------------------------------

__fastcall TfrmExercise5::TfrmExercise5(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TfrmExercise5::FormShow(TObject *Sender)
{
    // Given code do not delete

	FormatSettings.DecimalSeparator = '.';
	FormatSettings.ShortDateFormat = "yyyy/mm/dd";
	FormatSettings.DateSeparator = '/';
	FormatSettings.TimeSeparator = ':';

	AnsiString DBsource = GetCurrentDir();
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);
	AnsiString conn = "Provider=";
	TStringList *providers = new TStringList;
	GetProviderNames(providers);

	if (providers->IndexOf("Microsoft.Jet.OLEDB.4.0") > 0)
	{
		conn += "Microsoft.Jet.OLEDB.4.0;Data Source=";
		conn += DBsource + "\\AppFiles\\KrugerPark.mdb";
	}
	else if (providers->IndexOf("Microsoft.ACE.OLEDB.12.0") > 0)
	{
		 conn += "Microsoft.ACE.OLEDB.12.0;Data Source=";
		 conn += DBsource + "\\AppFiles\\KrugerPark.accdb";
	}

	conn += ";Mode=ReadWrite;Persist Security Info=False";

	DMod->ADOConn->LoginPrompt = false;

	DMod->ADOConn->Connected = false;
	DMod->ADOConn->ConnectionString = conn;
	try
	{
		DMod->ADOConn->Connected = true;
		DMod->ADOdsTarrifs->Active = true;
	}
   catch (EDatabaseError  *E)
	{
	  ShowMessage("Can't connect!");
	}

   pgctrlMain->ActivePageIndex = 0;
   tbsQuestion3Show(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmExercise5::tbsQuestion3Show(TObject *Sender)
{
	//3.1
	DMod->ADOdsTemp->Close();
	DMod->ADOdsTemp->CommandText="select AccomodationType,accomDesc from TarrifRates t,AccomodationTypes a where a.AccomCode = t.AccomodationType order by t.AccomodationType";
	DMod->ADOdsTemp->Open();
	DMod->DSTemp->DataSet= DMod->ADOdsTemp;
		cmbAccomodationTypes->Clear();
		for(DMod->ADOdsTemp->First();!DMod->ADOdsTemp->Eof;DMod->ADOdsTemp->Next())
		{

	   AnsiString  accomodation = DMod->ADOdsTemp->FieldByName("AccomodationType")->AsAnsiString + "-" + DMod->ADOdsTemp->FieldByName("AccomDesc")->AsAnsiString;
	cmbAccomodationTypes-> Items->Add(accomodation);
				  }
				  cmbAccomodationTypes-> ItemIndex =0;
				  //temp2
						DMod->ADOdsTemp2->Close();
						  DMod->ADOdsTemp2->CommandText="select * from TarrifRates";
						   DMod->ADOdsTemp2->Open();
							  DMod->DSTemp2->DataSet= DMod->ADOdsTemp2;
							  dbgrdTarrifRates->DataSource= DMod->DSTemp2;


}
//---------------------------------------------------------------------------

void __fastcall TfrmExercise5::ckbShowAllTarrifRatesClick(TObject *Sender)
{
	//3.2

  if(ckbShowAllTarrifRates->Checked == true)
  {
	//ShowMessage("it is checked");
	AnsiString acctype = cmbAccomodationTypes->Items->Strings[cmbAccomodationTypes->ItemIndex];
	int posdel = acctype.Pos('-');
	AnsiString accomodationType = acctype.SubString(1,posdel-1);
	ShowMessage(accomodationType);
	DMod->ADOdsTemp2-> Close();
	   DMod->ADOdsTemp2->CommandText="select * from TarrifRates where AccomodationType = :at";
	   DMod->ADOdsTemp2->Parameters->ParamByName("at")->Value=  accomodationType;
	DMod->ADOdsTemp2->Open();

   DMod->DSTemp2->DataSet= DMod->ADOdsTemp2;

  }
  else
  {
   //	ShowMessage("it is not checked");
		DMod->ADOdsTemp->Close();
	  DMod->DSTemp->DataSet=DMod->ADOdsTemp;
	DMod->ADOdsTemp->CommandText="select * from TarrifRates";
						   DMod->ADOdsTemp->Open();
							  DMod->DSTemp->DataSet= DMod->ADOdsTemp;
							  dbgrdTarrifRates->DataSource= DMod->DSTemp;
  }
}
//---------------------------------------------------------------------------

//3.3
void __fastcall TfrmExercise5::btnFirstClick(TObject *Sender)
{
DMod->ADOdsTemp2->First()	;
DMod->ADOdsTemp->First();
}
//---------------------------------------------------------------------------

void __fastcall TfrmExercise5::btnPriorClick(TObject *Sender)
{
  DMod->ADOdsTemp2->Prior()	  ;
  DMod->ADOdsTemp->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TfrmExercise5::btnNextClick(TObject *Sender)
{
   DMod->ADOdsTemp2->Next()	 ;
   DMod->ADOdsTemp->Next();
}
//---------------------------------------------------------------------------

void __fastcall TfrmExercise5::btnLastClick(TObject *Sender)
{
 DMod->ADOdsTemp2->Last();
 DMod->ADOdsTemp->Last();
}
//---------------------------------------------------------------------------
void __fastcall TfrmExercise5::tbsQuestion4Show(TObject *Sender)
{
   // GIVEN
		  //DMod->DSTarrifs->DataSet=  DMod->ADOdsTarrifs;
	dbgrdTarrifRates->DataSource = DMod->DSTarrifs;
}
//---------------------------------------------------------------------------

void __fastcall TfrmExercise5::btnDeleteCurrRecordClick(TObject *Sender)
{
	//4.1

	try
	{
	if(MessageDlg("are you sure you want to delete the current record?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)

	{
		DMod->ADOdsTarrifs->Delete();
		DMod->ADOdsTarrifs->Refresh();
	}
	}
	  catch (EDatabaseError  *E)
	{
	  ShowMessage("Can't connect!");
	}


}
//---------------------------------------------------------------------------

void __fastcall TfrmExercise5::btnIncreaseBaseRateSQLClick(TObject *Sender)
{
	//4.2
	{
	AnsiString InputString = InputBox(L"Input Box", L"Accomodation Type Code?", L"");
		AnsiString sql1 ="UPDATE TarrifRates ";
		   AnsiString sql2 = "SET BaseRate = BaseRate *1.1 ";
		   AnsiString sql3 = "WHERE AccomodationType  = :at "  ;
		   AnsiString Final = sql1 + sql2 + sql3 ;

		   //=(select AccomodationType FROM TarrifRates WHERE  AccomodationType
	 DMod->ADOUseQuery1 ->SQL->Add(Final);
	 //DMod->ADOUseQuery1 ->SQL->Add(sql2);
	 //DMod->ADOUseQuery1 ->SQL->Add(sql3);
	 DMod->ADOUseQuery1->Parameters->ParamByName("at")->Value=  InputString;
	 DMod->ADOUseQuery1->ExecSQL();

	 int affected = DMod->ADOUseQuery1->RowsAffected;
			MessageDlg("There are " + IntToStr(affected) + " Rows updated",
				mtInformation, TMsgDlgButtons(), 0) ;

	}

}
//---------------------------------------------------------------------------
