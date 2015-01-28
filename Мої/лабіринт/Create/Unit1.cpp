//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "CreateH.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TCreate C;
int Type=ROAD;
int License=2;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    C.BeginCreate(1,10,10);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
    int H,W;
    C.ResizeScale(-5);
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    C.GetSizePicture(H,W);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);   //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{
    int H,W;
    C.ResizeScale(5);           //
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    C.GetSizePicture(H,W);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
    int H,W;
    C.ResizeQuadrat(-1);      //
    C.GetSizePicture(H,W);
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{
    int H,W;
    C.ResizeQuadrat(1);
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    C.GetSizePicture(H,W);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);    //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N9Click(TObject *Sender)
{
    Type=BEGIN;                     //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N12Click(TObject *Sender)
{
    AnsiString fname;
    SaveDialog1->Execute();
    fname=SaveDialog1->FileName+".Lab";        //
    C.SaveToFileLicense(fname.c_str());
    License=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N11Click(TObject *Sender)
{
    OpenDialog1->Execute();                           //
	License=C.LoadFromFileLicense(OpenDialog1->FileName.t_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender)
{
    C.Create(1,10,10,ROAD);         //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N18Click(TObject *Sender)
{
    Type=END;              //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N19Click(TObject *Sender)
{
    Type=ROAD;           //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N20Click(TObject *Sender)
{
    Type=WALL;       //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N13Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    int H,W;
    Form1->Show();
    C.GetSizePicture(H,W);
    Form1->ClientHeight=H+20;
    Form1->ClientWidth=W+20;
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);
    Form1->Constraints->MinHeight=H+20+58;
    Form1->Constraints->MinWidth=W+20+16;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
    int H,W;
    C.GetSizePicture(H,W);
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7750501Click(TObject *Sender)
{
    int H,W;
    C.SetScale(50);
    C.SetQuadrat(3,3);
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    C.GetSizePicture(H,W);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);   //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10x1035x351Click(TObject *Sender)
{
    int H,W;
    C.SetScale(35);
    C.SetQuadrat(5,5);
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    C.GetSizePicture(H,W);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);   //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N21x2125x251Click(TObject *Sender)
{
    int H,W;
    C.SetScale(25);
    C.SetQuadrat(10,10);
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    C.GetSizePicture(H,W);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);   //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N49x4910x101Click(TObject *Sender)
{
    int H,W;
    C.SetScale(10);
    C.SetQuadrat(24,24);
    Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    C.GetSizePicture(H,W);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);   //
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N14Click(TObject *Sender)
{
    Type=HALFWALL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    int H,W;
    switch(Key)
    {
        case 38:
            C.Move(UP);
            break;
        case 39:
            C.Move(RIGHT);
            break;                       
        case 40:
            C.Move(DOWN);
            break;
        case 37:
            C.Move(LEFT);
            break;
        case 188:
            C.Move(DOWNFLOOR);
            break;
        case 190:
            C.Move(UPFLOOR);
            break;
        case 13:
            if(License==2)
            {
                int H,W;
                C.AddElement(Type);
                C.GetSizePicture(H,W);
                C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);
            }
            break;
    }
    C.GetSizePicture(H,W);
    C.Draw((ClientWidth-W)/2,(ClientHeight-H)/2,Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N15Click(TObject *Sender)
{
    int p,n,m;
    Panel1->Visible=true;
    C.GetSize(p,n,m);
    Edit1->Text=IntToStr(p);
    Edit2->Text=IntToStr(n);
    Edit3->Text=IntToStr(m);
    RadioButton1->Checked=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
    int p,n,m;
    p=StrToInt(Edit1->Text);
    n=StrToInt(Edit2->Text);
    m=StrToInt(Edit3->Text);
    if(RadioButton1->Checked)
    {
        C.ResizePositive(p,n,m,Type);
    }
    else
    {
        C.ResizeNegative(p,n,m,Type);
    }
    Panel1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N16Click(TObject *Sender)
{
    Type=GOUP;    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N17Click(TObject *Sender)
{
    Type=GODOWN;    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N22Click(TObject *Sender)
{
    OpenDialog1->Execute();
    C.LoadStyle(OpenDialog1->FileName.t_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N23Click(TObject *Sender)
{
    C.DeleteStyle();    
}
//---------------------------------------------------------------------------

