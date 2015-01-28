//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
int RD[SIZE_DOSHKA][SIZE_DOSHKA];
//---------------------------------------------------------------------------
void doshka::Init(int COLOR1)
{
    int i,j;
    int COLOR2;
    COLOR1=(COLOR1==WHITE_PLAYER)?(WHITE_PLAYER):(BLACK_PLAYER);
    COLOR2=(COLOR1==BLACK_PLAYER)?(WHITE_PLAYER):(BLACK_PLAYER);
    UPSTAIRS=COLOR1;
    WHO_GO=WHITE_PLAYER;
    for(i=0;i<SIZE_DOSHKA;i++)
    {
        for(j=0;j<SIZE_DOSHKA;j++)
        {
            D[i][j]=NOTHING;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<SIZE_DOSHKA;j+=2)
        {
            D[i][j+(i+1)%2]=COLOR1;
        }
    }
    for(i=5;i<SIZE_DOSHKA;i++)
    {
        for(j=0;j<SIZE_DOSHKA;j+=2)
        {
            D[i][j+(i+1)%2]=COLOR2;
        }
    }
    BLACK=WHITE=12;
}
//---------------------------------------------------------------------------
void doshka::D_Show(Graphics::TBitmap*bmp)
{
    //clMaroon, clWhite
    //clBlack, clAqua
    //clYellow
    int i,j;
    if(bmp->Width!=bmp->Height)
    {
        return;
    }
    bmp->Canvas->Pen->Width=1;
    bmp->Canvas->Pen->Color=clBlack;
    bmp->Canvas->Brush->Style=bsSolid;
    for(i=0;i<SIZE_DOSHKA;i++)
    {
        for(j=0;j<SIZE_DOSHKA;j++)
        {
            bmp->Canvas->Brush->Color=((i+j)%2==0)?(clWhite):(clMaroon);
            bmp->Canvas->Rectangle(j*S(bmp),i*S(bmp),(j+1)*S(bmp),(i+1)*S(bmp));
            if(D[i][j]==NOTHING)
            {
                continue;
            }
            bmp->Canvas->Brush->Color=(D[i][j]==BLACK_PLAYER || D[i][j]==BLACK_QUEEN)?(clBlack):(clAqua);
            bmp->Canvas->Ellipse(j*S(bmp)+S(bmp)*0.9,i*S(bmp)+S(bmp)*0.9,(j+1)*S(bmp)-S(bmp)*0.9,(i+1)*S(bmp)-S(bmp)*0.9);
            if( D[i][j]==BLACK_QUEEN || D[i][j]==WHITE_QUEEN )
            {
                bmp->Canvas->Brush->Color=clYellow;
                bmp->Canvas->Ellipse(j*S(bmp)+S(bmp)*0.6,i*S(bmp)+S(bmp)*0.6,(j+1)*S(bmp)-S(bmp)*0.6,(i+1)*S(bmp)-S(bmp)*0.6);
            }
        }
    }
}
//---------------------------------------------------------------------------
int doshka::CreateCanGo(kory kor)
{
    int i,j,k;
    if( !isCorrectly(kor) || DK(kor)==NOTHING || WHO_PLAYER(DK(kor))!=WHO_GO )
    {
        return 0;
    }
    for(i=0;i<28;i+=4)
    {
        init(ok[i+0],kor.i-(i/4+1),kor.j-(i/4+1));
        init(ok[i+1],kor.i-(i/4+1),kor.j+(i/4+1));
        init(ok[i+2],kor.i+(i/4+1),kor.j+(i/4+1));
        init(ok[i+3],kor.i+(i/4+1),kor.j-(i/4+1));
    }
    for(i=27;i>=8;i--)
    {
        if( isQUEEN(DK(kor)) )
        {
            if( isCorrectly(ok[i]) )
            {
                if( DK(ok[i])!=NOTHING )
                {
                    init(ok[i],-1,-1);
                }
                else
                {
                    k=0;
                    for(j=0;j<i/4;j++)
                    {
                        if( DK(ok[i-(j+1)*4])!=NOTHING )
                        {
                            k++;
                            if( WHO_PLAYER(DK(ok[i-(j+1)*4]))==WHO_PLAYER(DK(kor)) )
                            {
                                k++;
                            }
                        }
                    }
                    if(k>1)
                    {
                        init(ok[i],-1,-1);
                    }
                }
            }
        }
        else
        {
            init(ok[i],-1,-1);
        }
    }
    for(i=4;i<8;i++)
    {
        if( isQUEEN(DK(kor)) )
        {
            if( isCorrectly(ok[i]) )
            {
                if( DK(ok[i])!=NOTHING )
                {
                    init(ok[i],-1,-1);
                }
                else
                {
                    if( DK(ok[i-4])!=NOTHING )
                    {
                        if( WHO_PLAYER(DK(kor))==WHO_PLAYER(DK(ok[i-4])) )
                        {
                            init(ok[i],-1,-1);
                        }
                    }
                }
            }
        }
        else
        {
            if( isCorrectly(ok[i]) )
            {
                if( DK(ok[i])!=NOTHING )
                {
                    init(ok[i],-1,-1);
                }
                else
                {
                    if( DK(ok[i-4])==NOTHING || WHO_PLAYER(DK(kor))==WHO_PLAYER(DK(ok[i-4])) )
                    {
                        init(ok[i],-1,-1);
                    }
                }
            }
        }
    }
   /* if( !isQUEEN(DK(kor)) )
    {
        if( WHO_PLAYER(DK(kor))==UPSTAIRS )
        {
            init(ok[4],-1,-1);
            init(ok[5],-1,-1);
        }
        else
        {
            init(ok[6],-1,-1);
            init(ok[7],-1,-1);
        }
    }*/
    for(i=0;i<4;i++)
    {
        if( isCorrectly(ok[i]) )
        {
            if( DK(ok[i])!=NOTHING )
            {
                init(ok[i],-1,-1);
            }
        }
    }
    if( !isQUEEN(DK(kor)) )
    {
        if( WHO_PLAYER(DK(kor))==UPSTAIRS )
        {
            init(ok[0],-1,-1);
            init(ok[1],-1,-1);
        }
        else
        {
            init(ok[2],-1,-1);
            init(ok[3],-1,-1);
        }
    }
    return 1;
}
//---------------------------------------------------------------------------
int doshka::CanGo(kory beg,kory end)
{
    int i;
    if( isCorrectly(beg) && isCorrectly(end) && CreateCanGo(beg)==1)
    {
        for(i=0;i<28;i++)
        {
            if( end.i==ok[i].i && end.j==ok[i].j )
            {
                return 1;
            }
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
void doshka::RUN(kory *k,int n)
{
    int i;
    kory kill;
    if( n<2 || n>=28)
    {
        return;
    }
    for(i=1;i<n;i++)
    {
        if( CanGo(k[i-1],k[i])==1 )
        {
            kill=isKill(k[i-1],k[i]);
            DK(k[i])=DK(k[i-1]);
            DK(k[i-1])=NOTHING;
            if( WHO_PLAYER(DK(k[i]))==UPSTAIRS && k[i].i==7 )
            {
                DK(k[i])=BE_QUEEN(DK(k[i]));
            }
            if( WHO_PLAYER(DK(k[i]))!=UPSTAIRS && k[i].i==0 )
            {
                DK(k[i])=BE_QUEEN(DK(k[i]));
            }
            if( isCorrectly(kill) )
            {
                DK(kill)=NOTHING;
            }
            else
            {
                break;
            }
        }
        else
        {
            return;
        }
    }

    WHO_GO=OPPOSITE(WHO_GO);
}
//---------------------------------------------------------------------------
kory doshka::isKill(kory beg,kory end)
{
    int i;
    kory kill,p,d;
    init(kill,-1,-1);
    init(p,ZNAK(end.i-beg.i),ZNAK(end.j-beg.j));
    i=1;
    while( beg.i+i*p.i!=end.i )
    {
        init(d,beg.i+i*p.i,beg.j+i*p.j);
        if( DK(d)!=NOTHING && WHO_PLAYER(DK(d))==OPPOSITE(DK(beg)) )
        {
            init(kill,d.i,d.j);
        }
        i++;
    }
    return kill;
}
//---------------------------------------------------------------------------
int doshka::ReturnPlayer(kory k)
{
    if( isCorrectly(k) )
    {
        return DK(k);
    }
    return 0;
}
//---------------------------------------------------------------------------
int doshka::ReturnWHO_GO()
{
    return WHO_GO;
}
//---------------------------------------------------------------------------
void doshka::ReturnD()
{
    int i,j;
    for(i=0;i<SD;i++)
    {
        for(j=0;j<SD;j++)
        {
            RD[i][j]=D[i][j];
        }
    }
}
//---------------------------------------------------------------------------
void doshka::ReturnOk(kory k,kory*&_ok)
{
    int i;
    CreateCanGo(k);
    for(i=0;i<28;i++)
    {
        _ok[i]=ok[i];
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
