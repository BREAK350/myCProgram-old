//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Training.h"
#include <conio.h>
#include <windows.h>
T_Training Training;
//---------------------------------------------------------------------------
int MainMenuStatistic()
{
    int n;
    clrscr();
    cout<<"***����������***"<<endl;
    cout<<" 1.�������� ���"<<endl;
    cout<<" 2.������"<<endl;
    cout<<" 0.�����"<<endl;
    cin>>n;
    return n;
}
//---------------------------------------------------------------------------
void MainMenuLoadFromFile()
{
    char fname[1024];
    cout<<"���� �� �����: ";
    flushall();
    gets(fname);
    if(Training.LoadFromFile(fname))
    {
        cout<<"���� ��������";
    }
    else
    {
        cout<<"������� ���������� �����";
    }
    cout<<endl;
    getch();
}
//---------------------------------------------------------------------------
int DisplayMainMenu()
{
    int n;
    clrscr();
    cout<<"***������� ����***"<<endl;
    cout<<" 1.�����������"<<endl;
    cout<<" 2.����������"<<endl;
    cout<<" 0.�����"<<endl;
    cin>>n;
    switch(n)
    {
        case 0: return 0;
        case 1:
            MainMenuLoadFromFile();
            break;
        case 2:
            while(MainMenuStatistic()!=0);
            break;
    }
    return n;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while(DisplayMainMenu()!=0);
    cout<<"���������� ������. �������� �� ������ ...";
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 