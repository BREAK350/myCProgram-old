//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Main.h"
#include "Details.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
const int Interval=500;  // 50 = 1s
int timer=10*50;
T_Animation
    Anim_Cursor(Anim_POINTER,NULL,1,&T_AnimationLink(0,0,SizePicture,SizePicture)),
    Anim_Map(Anim_POINTER,NULL,1,&T_AnimationLink(0,0,SizePicture,SizePicture));
//---------------------------------------------------------------------------
const int nG=10;
const int nW=10;
T_Gun *G[nG];
T_Warrior *W[nW];
T_Map *MAP=NULL;
bool add=false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int i;
    for(i=0;i<nG;i++)
    {
        G[i]=NULL;
    }
    for(i=0;i<nW;i++)
    {
        W[i]=NULL;
    }
    Anim_Cursor.LoadPicture("Picture//Cursor.bmp");
    Anim_Map.LoadPicture("Picture//bg3.bmp");
    Timer1->Interval=REPAINTTIME;
    Timer2->Interval=REPAINTTIME;
    ClientHeight=400;
    ClientWidth=700;
    MAP=new T_Map(13,15,Anim_Cursor,Anim_Map,10,5);
    //======================================
    T_AnimationLink alW[]=
        {
            T_AnimationLink(0,0,SizePicture,SizePicture),
            T_AnimationLink(SizePicture,0,2*SizePicture,SizePicture),
            T_AnimationLink(2*SizePicture,0,3*SizePicture,SizePicture),
            T_AnimationLink(3*SizePicture,0,4*SizePicture,SizePicture)
        };
    T_AnimationLink alG[]=
        {
            T_AnimationLink(0,0,SizePicture,2*SizePicture),
            T_AnimationLink(SizePicture,0,2*SizePicture,2*SizePicture)
        };
    T_Animation AnimW(Anim_POINTER,NULL,4,alW);
    T_Animation AnimG(Anim_POINTER,NULL,2,alG);
    //================Warrior==================
    W[0]=new T_Warrior(T_Point(0,0),AnimW,60,50);
    W[0]->GetAnim()->LoadPicture("Picture//W1a.bmp");
    //=================Gun=====================
    G[0]=new T_Gun(T_Point(0,0),AnimG,50,3,3);
    G[0]->GetAnim()->LoadPicture("Picture//G1a.bmp");
}
//---------------------------------------------------------------------------
void TForm1::Clear()
{
    Canvas->Rectangle(-1,-1,Width,Height);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    switch(Key)
    {
        case 37:
            MAP->Cursor_LEFT();
            break;
        case 38:
            MAP->Cursor_UP();
            break;
        case 39:
            MAP->Cursor_RIGHT();
            break;
        case 40:
            MAP->Cursor_DOWN();
            break;
        case 13:
            MAP->AddGun(*G[0]);
            break;
        case 187:
            MAP->AddWarrior(*W[0],50);
            break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    if(MAP->NextStep()<=0)
    {
        Timer1->Enabled=false;
    }
    MAP->Draw(200,200,Canvas);
    if(!add && MAP->GetAmountWarrior()==0)
    {
        Timer2->Enabled=true;
        timer=Interval;
        W[0]->UpLife(50);
        add=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
    timer--;
    if(timer<0)
    {
        timer=999999;
        Timer2->Enabled=false;
        MAP->AddWarrior(*W[0],50);
        add=false;
    }
    Label1->Caption=IntToStr(timer/50);
}
//---------------------------------------------------------------------------

