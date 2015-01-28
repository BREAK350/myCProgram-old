//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma argsused
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------
void Print(int **M,const int &n,const int &m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%3d",M[i][j]);
        }
        cout<<endl;
    }
}
//---------------------------------------------------------------------------
int** CreateMatrix(int &n,int &m)
{
    int **M,i,j;
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    M=new int* [n];
    for(i=0;i<n;i++)
    {
        M[i]=new int [m];
        for(j=0;j<m;j++)
        {
            M[i][j]=-1;
        }
    }
    return M;
}
//---------------------------------------------------------------------------
void Add(int **M,const int &n,const int &m)
{
    string Event;
    int i,j;
    do
    {
        cout<<"> ";
        cin>>Event;
        if(Event=="add")
        {
            cin>>i>>j;
            M[i][j]=-2;
        }
    }
    while(Event!="back");
}
//---------------------------------------------------------------------------
void Print(T_Link *Link,const int &n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<Link[i].min<<'-'<<Link[i].max<<endl;
    }
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int n,m,**M=CreateMatrix(n,m),ln;
    T_Link *Link=NULL;
    Print(M,n,m);
    Add(M,n,m);
    Print(M,n,m);
    CreateTrack(M,n,m);
    cout<<"After CreateTrack:\n";
    Print(M,n,m);
    Link=CreateLink(M,n,m,ln);
    cout<<"Link:\n";
    Print(Link,ln);
    getch();
    return 0;
}
//---------------------------------------------------------------------------

