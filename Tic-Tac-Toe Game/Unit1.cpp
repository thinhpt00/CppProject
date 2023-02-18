//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------

char currentPlayerSymbol = 'x';

bool TForm1::isPlayerWin(){
	if( !Button1->Text.IsEmpty() && Button1->Text == Button2->Text && Button1->Text == Button3->Text )
		return true;
	if( !Button1->Text.IsEmpty() && Button1->Text == Button4->Text && Button1->Text == Button7->Text )
		return true;
	if( !Button1->Text.IsEmpty() && Button1->Text == Button5->Text && Button1->Text == Button9->Text )
		return true;
	if( !Button2->Text.IsEmpty() && Button2->Text == Button5->Text && Button2->Text == Button8->Text )
		return true;
	if( !Button3->Text.IsEmpty() && Button3->Text == Button6->Text && Button3->Text == Button9->Text )
		return true;
	if( !Button4->Text.IsEmpty() && Button4->Text == Button5->Text && Button4->Text == Button6->Text )
		return true;
	if( !Button7->Text.IsEmpty() && Button7->Text == Button8->Text && Button7->Text == Button9->Text )
		return true;
	if( !Button3->Text.IsEmpty() && Button3->Text == Button5->Text && Button3->Text == Button7->Text )
		return true;

	return false;
}


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	playerLabel->Text = currentPlayerSymbol;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	TButton* clickedButton=dynamic_cast<TButton*>(Sender);
	clickedButton->Text =  currentPlayerSymbol;

	if(isPlayerWin()){
//		int Color = TAlphaColor(claGreen);
		Label2->Text = currentPlayerSymbol;
//		Label1->TextSettings->FontColor = Color;
		Label1->Text = " Player     is the winner!!";
		playerLabel->Text = "";
//		winnerLabel->Text = "You Won!!";
		return;
	}

	if( currentPlayerSymbol == 'x' )
		currentPlayerSymbol = 'o';
	else
		currentPlayerSymbol = 'x';

	playerLabel->Text = currentPlayerSymbol;


}
//---------------------------------------------------------------------------
