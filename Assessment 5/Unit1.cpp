//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
	redOutput->Lines->Clear();
	redOutput->Paragraph->TabCount = 2;
	redOutput->Paragraph->Tab[1] = 110;

	FormatSettings.ShortDateFormat = "dd/mm/yyyy";
}
//---------------------------------------------------------------------------

AnsiString getFieldByNr(AnsiString line, int fieldNr, char del)
{
	line += del;

	int i = 1, pos;
	AnsiString field = "";
	while (i <= fieldNr)
	{
		pos = line.Pos(del);
		field = line.SubString(1, pos-1);
		line.Delete(1, pos);

		i++;
	}

	return field;
}
void __fastcall TForm1::btnLoadClick(TObject *Sender)
{
	//1
	AnsiString id;
	lstRawData = new TStringList(this);
   lstRawData->LoadFromFile("..//..//AppFiles//EmpData.txt");
   for(int i =0;i< lstRawData->Count;i++)
   {
	   CurrentLine= lstRawData->Strings[i];
		   id= getFieldByNr(CurrentLine, 2, '~') ;
		   cmbIDNumbers->Items->Add(id);
		   cmbIDNumbers->ItemIndex=0;


   }
	MessageDlg("ID Captured",mtInformation,TMsgDlgButtons()<<mbOK,0);



}
//---------------------------------------------------------------------------

void __fastcall TForm1::cmbIDNumbersChange(TObject *Sender)
{
	//2

	   AnsiString current = cmbIDNumbers->Items->Strings[cmbIDNumbers->ItemIndex],imgLetters;
	   AnsiString prov,name,lname,names,id,empNo;
	   AnsiString date;
	   int rNo;

	   for(int i =0;i< lstRawData->Count;i++)
	   {
	   CurrentLine= lstRawData->Strings[i];CurrentLine= lstRawData->Strings[i];
	   id= getFieldByNr(CurrentLine, 2, '~') ;
		prov= getFieldByNr(CurrentLine, 3, '~');
		TDateTime* mydate = new TDateTime(getFieldByNr(CurrentLine, 4, '~'));
			   date = mydate->FormatString("dd-mmm-yyyy");
				names= getFieldByNr(CurrentLine, 1, '~');
				name = getFieldByNr(names, 1, ' ');
				  lname = getFieldByNr(names, 2, ' ');
					rNo = rand()%(999-100)+100;
				  empNo = name.SubString(1,1)+lname.SubString(1,1)+IntToStr(rNo);
				 imgLetters= name.SubString(1,1)+lname.SubString(1,1);

		   OneRedLine = "Employee Number : \t"+empNo+"\n\n" +"Name : \t"+name+"\n\n"+"Surame : \t"+lname+"\n\n"+"Identity Number : \t"
				  +current+"\n\n" +"Province : \t"+prov+"\n\n"+"Date Appointed : \t"+date;
				  if(current == id)
				  {
					  redOutput->Lines->Add( OneRedLine);
						imgCardPic->Picture->LoadFromFile("..//..//AppFiles//"+imgLetters+".png");

				  }


			}


}
//---------------------------------------------------------------------------

