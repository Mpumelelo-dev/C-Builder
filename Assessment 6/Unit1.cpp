//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "DMUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Ranks[0] = "Recruit";
	Ranks[1] = "Park";
	Ranks[2] = "Park";
	Ranks[3] = "Section";
	Ranks[4] = "Senior";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
	AnsiString DBsource = GetCurrentDir();
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);
	DBsource.Delete(DBsource.LastDelimiter("\\"), 40);
	AnsiString conn = EmptyAnsiStr;

	TStringList *providers = new TStringList;
	GetProviderNames(providers);

	if (providers->IndexOf("Microsoft.Jet.OLEDB.4.0") > 0)
	{
		conn = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=";
		conn += DBsource + "\\AppFiles\\KrugerPark.mdb";
	}
	else if (providers->IndexOf("Microsoft.ACE.OLEDB.12.0") > 0)
	{
		 conn = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=";
		 conn += DBsource + "\\AppFiles\\KrugerPark.accdb";
	}



	conn += ";Mode=ReadWrite;Persist Security Info=False";

	DMod->ADOConn->LoginPrompt = false;

	DMod->ADOConn->Connected = false;
	DMod->ADOConn->ConnectionString = conn;
	try
	{
		DMod->ADOConn->Connected = true;
		Label1->Caption = "Successfully Connected";

		DMod->ADOdsRangers->Connection = DMod->ADOConn;
		DMod->ADOdsRangers->Active = false;
		DMod->ADOdsRangers->CommandText = "SELECT * FROM Rangers";
		DMod->ADOdsRangers->Active = true;

		/*
			Write code to display ranger details inside the rangers database grid
		*/
		DMod->DSRangers->DataSet = DMod->ADOdsRangers;
		dbgrdRangers->DataSource=DMod->DSRangers;
	}
	catch (EADOError *E)
	{
	  ShowMessage(E->Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnInsertClick(TObject *Sender)
{
	//CREATION OF A NEW RECORD USING SQL.
	/*
	Write code to insert a new ranger into the rangers table. Ensure that the ranger to be
	inserted has a unique ID, in the same sequence as the existing IDs. Use ADOdsTemp for
	obtaining the highest ID, and add one to it to have a new unique ID.



	Additionally, implement ADOCommand to insert a new ranger record using parameters.
	Display a message to indicate that a record has been inserted and ENSURE THAT
	WE CAN SEE THE INSERTED RECORD in the database grid.
	*/
	   //OBTAINING HIGHEST ID
	  DMod-> ADOdsTemp->Close();
	  DMod-> ADOdsTemp->CommandText="select  Max(RangerId) as High from Rangers";
	  DMod-> ADOdsTemp->Open();
	   //	DMod-> ADOdsTemp->Edit();
//DMod-> ADOdsTemp->FieldByName("High")->AsFloat+1;
	   //	DMod-> ADOdsTemp->Post();
	  int highId =DMod-> ADOdsTemp->FieldByName("High")->AsFloat;
	 AnsiString newId =IntToStr(highId+1);
	  ShowMessage(newId);

	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnUpdateClick(TObject *Sender)
{
	/*
	  UPDATE A RANGER USING NO-SQL

	  An array of Ranks is provided to you (declared in the h file, and initialised
	  with ranger ranks in the constructor).

	  Update the rank of rangers to the next available rank. For
	  example, if the ranger was a Recruit ranger, he/she should then be promoted
	  to Field ranger. However, if the ranger is already a Senior ranger, do not update.

	  Ensure that before you update, you check if the dataset can be edited.

	  Count and display the total number of rangers promoted to the next rank using
	  a message dialog.

	*/

}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnDelClick(TObject *Sender)
{
	/*
		Write code to delete that newly added ranger from the table with confirmation.
	*/
}
//---------------------------------------------------------------------------

