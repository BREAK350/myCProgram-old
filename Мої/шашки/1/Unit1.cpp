//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap*BMP=new Graphics::TBitmap;
doshka d;
kory k[28],cur,pcur,p,ok[28];
int i,player;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    BMP->Width=400;
    BMP->Height=400;
    d.Init(BLACK_PLAYER);
    i=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    d.D_Show(BMP);
    Canvas->Draw(0,0,BMP);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    d.RUN(k,i);
    d.D_Show(BMP);
    Canvas->Draw(0,0,BMP);
    i=0;
}
//---------------------------------------------------------------------------
kory KORY(kory cur)
{
    int i;
    kory kor;
    init(kor,-1,-1);
    for(i=0;i<SD;i++)
    {
        if( S(BMP)*i<cur.i && S(BMP)*(i+1)>cur.i )
        {
            kor.i=i;
        }
        if( S(BMP)*i<cur.j && S(BMP)*(i+1)>cur.j )
        {
            kor.j=i;
        }
    }
    return kor;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    if(i<28)
    {
        k[i]=KORY(cur);
        i++;
    }
    else
    {
        i=0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    int i;
    cur.i=Y;
    cur.j=X;
    p=KORY(cur);
    if( p.i==pcur.i && p.j==pcur.j )
    {
    }
    else
    {
        init(pcur,p.i,p.j);
        if( (p.i+p.j)%2==1 )
        {
            d.D_Show(BMP);
            player=d.ReturnPlayer(pcur);
            if( player==NOTHING )
            {
                BMP->Canvas->Pen->Color=clGreen;
            }
            else
            {
                if( WHO_PLAYER(player)==d.ReturnWHO_GO() )
                {
                    BMP->Canvas->Pen->Color=clBlue;
                    d.ReturnOk(pcur,ok);
                    BMP->Canvas->Brush->Color=clLime;
                    for(i=0;i<28;i++)
                    {
                        if( isCorrectly(ok[i]) )
                        {
                            BMP->Canvas->Rectangle(ok[i].j*S(BMP),ok[i].i*S(BMP),(ok[i].j+1)*S(BMP),(ok[i].i+1)*S(BMP));
                        }
                    }
                }
                else
                {
                    BMP->Canvas->Pen->Color=clRed;
                }
            }
            BMP->Canvas->Brush->Style=bsClear;
            BMP->Canvas->Pen->Width=3;
            BMP->Canvas->Ellipse(pcur.j*S(BMP),pcur.i*S(BMP),(pcur.j+1)*S(BMP),(pcur.i+1)*S(BMP));
            Canvas->Draw(0,0,BMP);
        }
    }
}
//---------------------------------------------------------------------------

