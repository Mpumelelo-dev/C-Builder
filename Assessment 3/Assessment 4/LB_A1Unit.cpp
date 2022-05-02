//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LB_A1Unit.h"
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
void __fastcall TForm1::btnGenerateClick(TObject *Sender)
{

   /*	1. Generate 10 random numbers between 40 and 90
	2. Add those numbers to a listbox
	3. Before adding a repeating number,
	edit the existing number and concatenate a '#' next to it
    4. Update the label to keep track of the number of numbers
	*/
		Randomize();
	int randNo,count=0;
	for(int x = 0;x<10;x++)
	{
	   randNo= rand() % (90-40+1) + 40;
		lstNumbers->Items->Add( randNo);
			   count++;
	   }

 int i, j;
   AnsiString temp[10],current;
for(i = 0; i<10; i++) {
   for(j = i+1; j<10; j++)
   {
	  if(lstNumbers->Items->Strings[i] == lstNumbers->Items->Strings[j]) {
		 temp[j] = lstNumbers->Items->Strings[i];
		 lstNumbers->Items->Strings[i] = lstNumbers->Items->Strings[j];
		lstNumbers->Items->Strings[j] = temp[j]+"#";

	  }
   }

}
	for(j = i+1; j<10; j++)
	{
	  current = temp[j];
	   lstNumbers->Items->Add(current);

	}
    	for(int x = 0;x<10;x++)
	{
	  lstNumbers->Items->Strings[x]=lstNumbers->Items->Strings[x].Delete(4,2);
	}

  lblCountNumbers->Caption=count;
 lstNumbers->ItemIndex=0;
}


//---------------------------------------------------------------------------
void __fastcall TForm1::btnSortClick(TObject *Sender)
{
	//SORT THE NUMBERS IN LISTBOX IN DESCENDING ORDER
   int i, j;
   AnsiString temp[10],current;
for(i = 0; i<10; i++) {
   for(j = i+1; j<10; j++)
   {
	  if(lstNumbers->Items->Strings[j] > lstNumbers->Items->Strings[i]) {
		 temp[j] = lstNumbers->Items->Strings[i];
		 lstNumbers->Items->Strings[i] = lstNumbers->Items->Strings[j];
		lstNumbers->Items->Strings[j] = temp[j];

	  }
   }

}
	for(j = i+1; j<10; j++)
	{
	  current = temp[j];
	   lstNumbers->Items->Add(current);
	}
  }
//---------------------------------------------------------------------------
void __fastcall TForm1::btnDeleteSelClick(TObject *Sender)
{

lstNumbers->Items->Strings[lstNumbers->ItemIndex]=lstNumbers->Items->Strings[lstNumbers->ItemIndex].Delete(1,3);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnDeleteAllClick(TObject *Sender)
{
	//DELETE ALL NUMBERS FROM A LISTBOX
	for(int x = 0;x<10;x++)
	{
	  lstNumbers->Items->Strings[x]=lstNumbers->Items->Strings[x].Delete(1,3);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnDeleteRandomlyClick(TObject *Sender)
{
	//GENERATE A RANDOM NUMBER FROM 0-9 AND DELETE A NUMBER FROM LISTBOX
	//USING THAT RANDOM NUMBER.
	int num = Random(10);
    ShowMessage(num);
	 lstNumbers->Items->Strings[num]=lstNumbers->Items->Strings[num].Delete(1,3);
}
//---------------------------------------------------------------------------
