//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------

bool isNumberEntered = false;
int guessNumber;
int countNumber = 0;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	tittleLabel->Text = "Please enter number to start the game! ";
	countLabel->Text = "0";
	helperLabel->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::confirmButtonClick(TObject *Sender)
{
	if(!isNumberEntered){
	   guessNumber = numberEdit->Text.ToInt();
	   isNumberEntered = true;
	   tittleLabel->Text = "Enter number to GUESS ";
	   numberEdit->Text = "";
	}
	else{
	   if( guessNumber == numberEdit->Text.ToInt()){
		   helperLabel->Text = "You Won!!! Congratulation!!";
		   confirmButton->Enabled = false;
		   return;
	   }
	   else if( guessNumber > numberEdit->Text.ToInt())
		   helperLabel->Text = "Number too low :(( ";
	   else
		   helperLabel->Text = "Number too big :(( ";

		   countLabel->Text = ++countNumber;
//		   numberEdit->Text = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::numberEditClick(TObject *Sender)
{
    numberEdit->Text = "";
}
//---------------------------------------------------------------------------
