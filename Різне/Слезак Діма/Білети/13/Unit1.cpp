//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include <math.h>
//---------------------------------------------------------------------------
/*Білет №13*/
struct Student
{
    string name;
    int group;
    int k;
};
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int n=0;
    Student *Students=NULL;
    cout<<"n=";
    cin>>n;
    if(n>0)
    {
        Students=new Student[n];
        for(int i=0;i<n;i++)
        {
            cout<<"name=";
            cin>>Students[i].name;
            cout<<"group=";
            cin>>Students[i].group;
            cout<<"k=";
            cin>>Students[i].k;
        }

        for(int i=0;i<n;i++)
        {
            if(Students[i].group==2 && Students[i].k>14)
            {
                cout<<Students[i].name<<endl;
            }
        }
    }
    getch();
    return 0;
}
//---------------------------------------------------------------------------
