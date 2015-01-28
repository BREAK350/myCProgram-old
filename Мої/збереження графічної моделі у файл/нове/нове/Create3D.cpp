//---------------------------------------------------------------------------
#pragma hdrstop
#include "Create3D.h"
int i,j;
Line l;
//---------------------------------------------------------------------------
CreateModel::CreateModel()
{
    N_point=N_line=N_triagle=0;
}
//---------------------------------------------------------------------------
void CreateModel::AddNewPoint(vector3 add)
{
    if(N_point>=256)
    {
        return;
    }
    for(i=0;i<N_point;i++)
    {
        if(add.x==Point[i].x && add.y==Point[i].y && add.z==Point[i].z)
        {
            break;
        }
    }
    if(i==N_point)
    {
        Point[N_point]=add;
        N_point++;
    }
}
//---------------------------------------------------------------------------
bool isRivne(vector3 v1,vector3 v2)
{
    if(v1.x==v2.x && v1.y==v2.y && v1.z==v2.z)
    {
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
void CreateModel::AddNewLine(int n1,int n2,TColor coll)
{
    if(n1==n2)
    {
        return;
    }
    if(n1>n2)
    {
        n1^=n2^=n1^=n2;
    }
    l.l=(n1<<8)+n2;
    for(i=0;i<N_line;i++)
    {
        if(l.l==line[i].l)
        {
            return;
        }
    }
    line[N_line].l=l.l;
    clline[N_line]=coll;
    N_line++;
}
//---------------------------------------------------------------------------
void CreateModel::SaveToFile(char*fname)
{
    FILE *f;
    f=fopen(fname,"wb");
    fwrite(&N_point,sizeof(int),1,f);
    fwrite(&N_line,sizeof(int),1,f);
    fwrite(&N_triagle,sizeof(int),1,f);
    fwrite(Point,sizeof(vector3),N_point,f);
    fwrite(line,sizeof(Line),N_line,f);
    fwrite(clline,sizeof(TColor),N_line,f);
    fwrite(cltriagle,sizeof(TColor),N_triagle,f);
    fclose(f);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
