//---------------------------------------------------------------------------
#include "Object.h"
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Display.h"
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
void __fastcall TForm1::N17Click(TObject *Sender)
{
    float x;
    x=StrToFloat(Edit10->Text);
    Projection=SM.GetPc(x);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N18Click(TObject *Sender)
{
    float x,y;
    x=StrToFloat(Edit10->Text);
    y=StrToFloat(Edit11->Text);
    Projection=SM.GetPab(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N12Click(TObject *Sender)
{
    Projection=SM.GetIsometric();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N14Click(TObject *Sender)
{
    float x;
    x=StrToFloat(Edit10->Text);
    Projection=SM.GetCavalier(x);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N15Click(TObject *Sender)
{
    Projection=SM.GetCabinet();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    float x,y,z;
    x=StrToFloat(Edit7->Text);
    y=StrToFloat(Edit8->Text);
    z=StrToFloat(Edit9->Text);
    Model=SM.GetD(x,y,z);
    x=StrToFloat(Edit4->Text);
    y=StrToFloat(Edit5->Text);
    z=StrToFloat(Edit6->Text);
    Model=Model*SM.GetRotationX(x*M_PI/180)*
                SM.GetRotationY(y*M_PI/180)*
                SM.GetRotationZ(z*M_PI/180);
    x=StrToFloat(Edit1->Text);
    y=StrToFloat(Edit2->Text);
    z=StrToFloat(Edit3->Text);
    Model=Model*SM.GetT(x,y,z);

    Image1->Canvas->Rectangle(-1,-1,1000,1000);
    Obj.DoMatrix(Model*Projection);
    Obj.Draw(Image1->Canvas,T_Point3(0,0,1),200,200);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::XoY1Click(TObject *Sender)
{
    Projection=SM.GetPz();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::XoZ1Click(TObject *Sender)
{
    Projection=SM.GetPy();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::YoZ1Click(TObject *Sender)
{
    Projection=SM.GetPx();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N13Click(TObject *Sender)
{
    float x,y;
    x=StrToFloat(Edit10->Text);
    y=StrToFloat(Edit11->Text);
    Projection=SM.GetAxonometric(x,y);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N11Click(TObject *Sender)
{
    Projection=SM.GetDymetriya();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N19Click(TObject *Sender)
{
    float x,y,z;
    x=StrToFloat(Edit10->Text);
    y=StrToFloat(Edit11->Text);
    z=StrToFloat(Edit12->Text);
    Projection=SM.GetPabc(x,y,z);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
    ifstream ifs("Tetra.txt");
    Obj.LoadFromFile(ifs);
    ifs.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
    ifstream ifs("Cub.txt");
    Obj.LoadFromFile(ifs);
    ifs.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)
{
    ifstream ifs("Okta.txt");
    Obj.LoadFromFile(ifs);
    ifs.close();
}
//---------------------------------------------------------------------------

