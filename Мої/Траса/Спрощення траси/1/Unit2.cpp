//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void CreateTrack(int **Track,const int &n,const int &m)
{
    int i,j,in=0,bottom,init;
    T_Rect r;
    for(i=0;i<n;i++)
    {
        bottom=i;
        init=0;
        for(j=0;j<m;j++)
        {
            if(Track[i][j]==-1)
            {
                r=CreateTrack(Track,n,m,i,j,in);
                j=r.Right;
                if(init==0)
                {
                    bottom=r.Bottom;
                    init=1;
                }
                else
                {
                    if(bottom>r.Bottom)
                    {
                        bottom=r.Bottom;
                    }
                }
                in++;
            }
            else
            {
                bottom=i;
            }
        }
        i=bottom;
    }
}
//---------------------------------------------------------------------------
T_Rect CreateTrack(int **Track,const int &n,const int &m,const int &si,const int &sj,
    const int &in)
{
    T_Rect r(sj,si,sj,si);
    int i=si,j=sj;
    while(r.Left>=0 && Track[si][r.Left]==-1)
    {
        r.Left--;
    }
    r.Left++;
    while(r.Right<m && Track[si][r.Right]==-1)
    {
        r.Right++;
    }
    r.Right--;
    r.Top=0;
    r.Bottom=m-1;
    for(j=r.Left;j<=r.Right;j++)
    {
        i=si;
        while(i>=r.Top && Track[i][j]==-1)
        {
            i--;
        }
        r.Top=i+1;
        i=si;
        while(i<=r.Bottom && Track[i][j]==-1)
        {
            i++;
        }
        r.Bottom=i-1;
    }
    for(j=r.Left;j<=r.Right;j++)
    {
        for(i=r.Top;i<=r.Bottom;i++)
        {
            Track[i][j]=in;
        }
    }
    return r;
}
//---------------------------------------------------------------------------
T_Link* CreateLink(int **Track,const int &n,const int &m,int &ln)
{
    T_List2 <T_Link> List(true,false);
    T_Link l,*r=NULL;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<m-1;j++)
        {
            if(Track[i][j]!=-2 && Track[i][j+1]!=-2 && Track[i][j]!=Track[i][j+1])
            {
                l=T_Link(Track[i][j],Track[i][j+1]);
                List.Write(l);
            }
            if(Track[i][j]!=-2 && Track[i+1][j]!=-2 && Track[i][j]!=Track[i+1][j])
            {
                l=T_Link(Track[i][j],Track[i+1][j]);
                List.Write(l);
            }
            if(Track[i][j+1]!=-2 && Track[i+1][j+1]!=-2 && Track[i][j+1]!=Track[i+1][j+1])
            {
                l=T_Link(Track[i][j+1],Track[i+1][j+1]);
                List.Write(l);
            }
            if(Track[i+1][j]!=-2 && Track[i+1][j+1]!=-2 && Track[i+1][j]!=Track[i+1][j+1])
            {
                l=T_Link(Track[i+1][j],Track[i+1][j+1]);
                List.Write(l);
            }
        }
    }
    r=new T_Link[ln=List.GetN()];
    for(i=0;i<ln;i++)
    {
        r[i]=List[i];
    }
    return r;
}
//---------------------------------------------------------------------------
bool operator == (const T_Link &Link1,const T_Link &Link2)
{
    return Link1.min==Link2.min && Link1.max==Link2.max;
}
//---------------------------------------------------------------------------
bool operator != (const T_Link &Link1,const T_Link &Link2)
{
    return !(Link1==Link2);
}
//---------------------------------------------------------------------------
bool operator <= (const T_Link &Link1,const T_Link &Link2)
{
    return Link1.min<=Link2.min;
}
//---------------------------------------------------------------------------
bool operator >= (const T_Link &Link1,const T_Link &Link2)
{
    return Link1.min>=Link2.min;
}
//---------------------------------------------------------------------------
bool operator < (const T_Link &Link1,const T_Link &Link2)
{
    return Link1.min<Link2.min;
}
//---------------------------------------------------------------------------
bool operator > (const T_Link &Link1,const T_Link &Link2)
{
    return Link1.min>Link2.min;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
