//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <fstream.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    ofstream ofs("test1.txt");
    ofs <<"onClick"<<endl
        <<'{'<<endl
        <<"    if 2 == 3"<<endl
        <<"    {"<<endl
        <<"        Goto \"cadr_2\\info.txt\""<<endl
        <<"    }"<<endl
        <<'}'<<endl;
    ofs.close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    ifstream ifs("test1.txt");
    char buf[256];
    ifs>>buf;
    while(!ifs.eof())
    {
        Memo1->Lines->Add(buf);
        ifs>>buf;
    }
}
//---------------------------------------------------------------------------
