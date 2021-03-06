//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)
#include "CreateDetail.h"
#include "Draw2D.h"
//---------------------------------------------------------------------------
detail det;
//---------------------------------------------------------------------------
int detail::AddNewLine(int n1,int n2,TColor coll)
{
    USI l;
    int i;
    if(n1==n2)
    {
        return -1;
    }
    if(n1>n2)
    {
        n1^=n2^=n1^=n2;
    }
    l=(n1<<8)+n2;
    for(i=0;i<Nline;i++)
    {
        if(l==line[i])
        {
            return i;
        }
    }
    line[Nline]=l;
    clline[Nline]=coll;
    Nline++;
    return (Nline-1);
}
//---------------------------------------------------------------------------
int detail::AddNewPoint(point2D p)
{
    int i;
    if(Npoint>=256)
    {
        return -1;
    }
    for(i=0;i<Npoint;i++)
    {
        if(p==point[i])
        {
            break;
        }
    }
    if(i==Npoint)
    {
        point[Npoint]=p;
        Npoint++;
    }
    return i;
}
//---------------------------------------------------------------------------
void detail::SaveToFile(char*fname)
{
    FILE *f;
    f=fopen(fname,"wb");
    fwrite(&Npoint,sizeof(int),1,f);
    fwrite(&Nline,sizeof(int),1,f);
    fwrite(&S,sizeof(float),1,f);
    fwrite(point,sizeof(point2D),Npoint,f);
    fwrite(line,sizeof(USI),Nline,f);
    fwrite(clline,sizeof(TColor),Nline,f);
    fclose(f);
}
//---------------------------------------------------------------------------
void BeginToCreateDetail()
{
    det.loc.InitXY(0,0);
    det.point=new point2D[256];
    det.line=new USI[10000];
    det.clline=new TColor[10000];
}
//---------------------------------------------------------------------------
void EndToCreateDetail()
{
    det.Npoint=det.Nline=det.alpha=det.S=0;
    delete[] det.point;
    delete[] det.line;
    delete[] det.clline;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

