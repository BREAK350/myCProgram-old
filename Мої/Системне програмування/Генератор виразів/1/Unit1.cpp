//---------------------------------------------------------------------------
#pragma hdrstop
#pragma argsused
#include "Unit2.h"
#include <iostream.h>
#include <conio.h>
#include "DFA_HTML.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    randomize();
    char *Expression;
    TbUFA UFA;
    TbDFA DFA;
    int i=0,q,fs,Count;
    int MaxLength;
    char Symbols[]="0123456789qwrtyuiopasdfghjklzxcvbnm";
    string FileName;
    cout<<"Count=";
    cin>>Count;
    cout<<"MaxLength=";
    cin>>MaxLength;
    //cout<<"Symbols=";
    //cin>>Symbols;
    cout<<"FileName=";
    cin>>FileName;
    ofstream ofs((FileName+".html").c_str());
    HeadHTML(ofs);
    while(i<Count)
    {
        Expression=CreateRandom(MaxLength);
        ChangeSymbol(Expression,Symbols);

        UFA.Create(Expression);
        DFA.CreateFrom(UFA);
        DFA.Minimize();
        DFA.DoNotFullyDefined();
        q=DFA.GetCountQ();
        fs=DFA.GetCountFinaleState();
        if(q>=5 && q<7 && fs>1 && fs<4 && isGood(Expression))
        {
            cout<<Expression<<"  -  ["<<q<<";"<<fs<<"]\n";
            WriteInHTML(ofs,Expression,DFA,i);
            i++;
        }
        delete Expression;
    }
    cout<<"end.\n";
    EndHTML(ofs);
    ofs.close();
    getch();
    return 0;
}
//---------------------------------------------------------------------------
