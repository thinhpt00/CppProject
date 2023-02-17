//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::addButtonClick(TObject *Sender)
{
	String textInput = editText->Text;
	listBox->Items->Add(textInput);
	editText->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::listBoxItemClick(TCustomListBox * const Sender, TListBoxItem * const Item)

{
	int index = Item->Index;
    listBox->Items->Delete(index);
}
//---------------------------------------------------------------------------

