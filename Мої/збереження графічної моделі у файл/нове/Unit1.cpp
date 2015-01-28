//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Draw3D.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap*bmp=new Graphics::TBitmap;
float alpha=0;
matrix33 R;
float fi=45,theta=45,S=100;
vector3 loc,see,degree;
TModel mod;
int i=100,j=100;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    mod.LoadFromFile("1.model");
    bmp->Width=ClientWidth;
    bmp->Height=ClientHeight;
    see.Init(45,45);
    loc.Init(0,0,-120);
    mod.S=0.4;
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    alpha-=1;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(degree,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button1->Caption="("+FloatToStr(alpha)+")alpha--";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    alpha+=1;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button1->Caption="("+FloatToStr(alpha)+")alpha--";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    fi--;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Canvas->Draw(0,0,bmp);
    Button3->Caption="("+FloatToStr(fi)+")fi--";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    fi++;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button3->Caption="("+FloatToStr(fi)+")fi--";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    theta++;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button5->Caption="("+FloatToStr(theta)+")theta--";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    theta--;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button5->Caption="("+FloatToStr(theta)+")theta--";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    loc.x--;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button7->Caption="("+FloatToStr(loc.x)+")x--";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
    loc.x++;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button8->Caption="("+FloatToStr(loc.x)+")x++";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
    loc.y--;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button9->Caption="("+FloatToStr(loc.y)+")y--";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
    loc.y++;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button10->Caption="("+FloatToStr(loc.y)+")y++";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
    loc.z--;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button11->Caption="("+FloatToStr(loc.z)+")z--";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
    loc.z++;
    bmp->Canvas->Rectangle(0,0,ClientWidth,ClientHeight);
    see.Init(fi,theta);
    mod.Draw3DModel(see,alpha,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Button11->Caption="("+FloatToStr(loc.z)+")z++";
    degree.Init(fi,theta,alpha);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
    for(i=0;i<bmp->Width;i++)
    for(j=0;j<bmp->Height;j++){
    if(isPointIsTriangle(i,j,100,100.1,100,300,400,10))
    {
        bmp->Canvas->Pixels[i][j]=clBlue;
    }
    }
    Canvas->Draw(0,0,bmp);
}
//---------------------------------------------------------------------------

