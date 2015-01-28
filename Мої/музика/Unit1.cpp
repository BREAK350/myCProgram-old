
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
bool set_track; //глобальной объ€влена дл€ скорости написани€)
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
   MediaPlayer1->FileName = "2.mp4";
   MediaPlayer1->DeviceType=dtAVIVideo;
   MediaPlayer1->Open();
   //TrackBar1->Position = 0;
   //TrackBar1->Max = MediaPlayer1->Length;
   MediaPlayer1->Play();
   Timer1->Enabled = true;
   set_track = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{
 if (TrackBar1->Focused() && MediaPlayer1->Mode == mpPlaying)
   {
   MediaPlayer1->Position = TrackBar1->Position;
   MediaPlayer1->Play();
   MediaPlayer1->SetFocus();
   set_track = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 if(MediaPlayer1->Mode == mpPlaying)
   {

       if (set_track==true)
         {
         MediaPlayer1->Position= TrackBar1->Position;
         MediaPlayer1->Play();
         set_track = false;
         }
       else
         {
         TrackBar1->Position = MediaPlayer1->Position;
         }
   }
   else Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

