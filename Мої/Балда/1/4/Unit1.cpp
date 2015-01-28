//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Balda.h"
#include <conio.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int max=0;
    TPoint *p;
    TWords w;
    ABC a;
    TMatrix m;
    w.AddWord("12345");
    w.AddWord("123");
    w.AddWord("34567");
    w.AddWord("987654321");
    w.AddWord("758");
    w.AddWord("09876");
    w.AddWord("6789");
    a.AddLetters('0');
    a.AddLetters('1');
    a.AddLetters('2');
    a.AddLetters('3');
    a.AddLetters('4');
    a.AddLetters('5');
    a.AddLetters('6');
    a.AddLetters('7');
    a.AddLetters('8');
    a.AddLetters('9');
    m.Create(5);
    m.Write(0,0,'1');
    m.Write(0,1,'2');
    m.Write(0,3,'4');
    m.Write(0,4,'5');
    p=m.SearchMaxWord(w,a,max);
    cout<<m.CreateChar(p,max);
    getch();
    return 0;
}
//---------------------------------------------------------------------------
