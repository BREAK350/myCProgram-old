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
    cout<<"***Статистика***"<<endl;
    cout<<" 1.Показати все"<<endl;
    cout<<" 2.Змінити"<<endl;
    cout<<" 0.Вихід"<<endl;
    cin>>n;
    return n;
}
//---------------------------------------------------------------------------
void MainMenuLoadFromFile()
{
    char fname[1024];
    cout<<"Шлях до файла: ";
    flushall();
    gets(fname);
    if(Training.LoadFromFile(fname))
    {
        cout<<"Файл загружен";
    }
    else
    {
        cout<<"Помилка відкривання файла";
    }
    cout<<endl;
    getch();
}
//---------------------------------------------------------------------------
int DisplayMainMenu()
{
    int n;
    clrscr();
    cout<<"***Головне меню***"<<endl;
    cout<<" 1.Завантажити"<<endl;
    cout<<" 2.Статистика"<<endl;
    cout<<" 0.Вихід"<<endl;
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
    cout<<"Завершення роботи. Натисніть на клавішу ...";
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 