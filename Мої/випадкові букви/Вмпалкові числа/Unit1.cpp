//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#pragma argsused
#include <windows.h>
#include <conio.h>
int main(int argc, char* argv[])
{
    int n,b;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    printf("�������� �����.\n������ ����������� ���� ����� ");
    scanf("%d",&n);
    getchar();
    randomize();
    printf("**************************************************\n");
    while(b)
    {
        printf("*  -������ �����: _-= %d =-_                     *\n",1+random(n));
        printf("* 1- ����������, 0- ��������� ������: ");
        scanf("%d",&b);
    }
    printf("**************************************************\n������ �������� ���������. ��������� ������:");
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 