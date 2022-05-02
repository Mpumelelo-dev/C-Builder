//---------------------------------------------------------------------------

#include <vcl.h>
#include <JPEG.hpp>
#pragma hdrstop

#include "frmExamSectionAUnit.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma resource "*.dfm"
TfrmExamPartA *frmExamPartA;
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
void __fastcall TfrmExamPartA::tbsQuestion2Show(TObject *Sender)
{
   ApplySettings(this);   // GIVEN
}
//---------------------------------------------------------------------------

void TfrmExamPartA::ApplySettings(TObject *Sender)
{
   // Given code
   redOutput->Lines->Clear();
   redOutput->Paragraph->TabCount = 6;
   redOutput->Paragraph->Tab[1] = 150;
   redOutput->Paragraph->Tab[2] = 200;
   redOutput->Paragraph->Tab[3] = 250;
   redOutput->Paragraph->Tab[4] = 300;
   redOutput->Paragraph->Tab[5] = 350;
   redOutput->Paragraph->Tab[6] = 400;
}
//---------------------------------------------------------------------------
void __fastcall TfrmExamPartA::FormShow(TObject *Sender)
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
	}
   catch (EDatabaseError  *E)
	{
	  ShowMessage("Can't connect!");
	}

   pgctrlMain->ActivePageIndex = 0;
   tbsQuestion1Show(this);

}
//---------------------------------------------------------------------------
__fastcall TfrmExamPartA::TfrmExamPartA(TComponent* Owner)
	: TForm(Owner)
{
   //GIVEN
   lstRawDataList = new TStringList;

}
//---------------------------------------------------------------------------
//===========================================================================

// Question 1.1
// Total (7)
AnsiString CreateFunkyName(AnsiString CampName)   // 1
{
   AnsiString newName,oldWord;
						  int x = 0;
  //int len = CampName.Length();
  newName = CampName.UpperCase();
  for (int i = 1; i<= CampName.Length() ; i++)
  {
	if(i%3==2)
  {
	  newName[i]=tolower(newName[i]);

  }
  }
  return newName;

}

//---------------------------------------------------------------------------
void __fastcall TfrmExamPartA::tbsQuestion1Show(TObject *Sender)
{
 // Question 1.2
 myPanel = new TPanel(this);
	  myPanel->Parent=tbsQuestion1;
	  tbsQuestion1->Font->Color = clWebGold;
			  tbsQuestion1->Font->Size= 25;
			  myPanel->Left=464;
				 myPanel->Top=184;
				 myPanel->Height=50;
				 myPanel->Width=273;
					myPanel->Caption = "CampName";




}
//---------------------------------------------------------------------------


void __fastcall TfrmExamPartA::lstCampsClick(TObject *Sender)
{
 // Question 1.3
 AnsiString detail;
 AnsiString code;
		 detail = lstCamps->Items->Strings[lstCamps->ItemIndex];
	   //	 ShowMessage(detail);
				 DMod->ADOdsCamps->Close();
			   DMod->ADOdsCamps->CommandText="select * from Camps where CampDescription like :cc";
			  DMod-> ADOdsCamps->Parameters->ParamByName("cc")->Value= detail+"%";
				  DMod->ADOdsCamps->Open();
					pnlCampCode->Caption =  DMod->ADOdsCamps->FieldByName("CampCode")->AsAnsiString;
					   pnlCampType->Caption=DMod->ADOdsCamps->FieldByName("CampType")->AsAnsiString;
						//loading images
						imgCamp-> Picture->LoadFromFile("..//..//AppFiles//"+detail+".jpg");
						 //calling the funkyname function on the mypanel
							myPanel->Caption = CreateFunkyName(detail);





}
//---------------------------------------------------------------------------


void __fastcall TfrmExamPartA::btnLoadClick(TObject *Sender)
{
  // Question 2.1
  // Given
  AnsiString RangerDet, CampCode, MDCount, ANCount, EVCount;
  int MDTotal = 0, ANTotal = 0, EVTotal = 0;
  AnsiString CurrentLine,oneline,totals;

  redOutput->Lines->Clear();
  AnsiString Header1 = "KNP Rangers and Game Drives";
  AnsiString Line1 =   "===========================";
  AnsiString Header2 = "RangerDetails\tCamp Code\tMorning\tNoon\tEvening";
  AnsiString Line2 =   "-------------\t---------\t-------\t----\t-------";
  redOutput->Lines->Add(Header1);
  redOutput->Lines->Add(Line1);
  redOutput->Lines->Add(Header2);
  redOutput->Lines->Add(Line2);

  // Code here

  lstRawDataList = new TStringList();
  lstRawDataList->LoadFromFile("..//..//AppFiles//RangerDrives.csv");

 for(int i =0; i < lstRawDataList->Count;i++)
  {
	 CurrentLine = lstRawDataList->Strings[i];
  RangerDet= getFieldByNr(CurrentLine, 1,',');
	  CampCode	=   getFieldByNr(CurrentLine, 2,',');
	  MDCount =	getFieldByNr(CurrentLine, 3,',');
	 ANCount  =	getFieldByNr(CurrentLine, 4,',');
	 EVCount  =	getFieldByNr(CurrentLine, 5,',');
		 MDTotal=MDTotal+MDCount;
		  ANTotal=ANTotal+ ANCount;
			EVTotal=EVTotal+EVCount;
	  oneline =  CampCode +"\t" + CampCode +"\t" + MDCount +"\t" +ANCount +"\t" +EVCount;
	  redOutput->Lines->Add(oneline);
  }

   redOutput->Lines->Add("\t\t--------\t------\t------\t");
  // redOutput->Lines->Add("Total\t\t"+MDTotal+"\t"+ANTotal+"\t"+EVTotal);


}
//---------------------------------------------------------------------------


