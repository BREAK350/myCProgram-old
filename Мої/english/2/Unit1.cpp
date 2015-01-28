//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner),dictionary("test.txt")
{
    randomize();
    changes=false;
}
//---------------------------------------------------------------------------
void TForm1::TestShow()
{
    Menu->Visible=false;
    Test->Visible=true;
    Test->Color=clBtnFace;
    Variant1->Font->Color=clBlack;
    Variant2->Font->Color=clBlack;
    Variant3->Font->Color=clBlack;
    Variant4->Font->Color=clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TestButtonClick(TObject *Sender)
{
    if(dictionary.getCount()>=4)
    {
        TestShow();
        int index[4],i=0,num,j,ind[4];
        while(i<4)
        {
            num=random(dictionary.getCount());
            j=0;
            while(j<i && num!=index[j])
            {
                j++;
            }
            if(j==i)
            {
                index[i]=num;
                i++;
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=3;j>i;j--)
            {
                if(index[i]>index[j])
                {
                    num=index[i];
                    index[i]=index[j];
                    index[j]=num;
                }
            }
        }
        Words *res=dictionary.get(index,4);
        for(i=0;i<4;i++)
        {
            index[i]=0;
            ind[i]=0;
        }
        i=random(4);
        ind[i]=1;
        Question->Caption=res[i].getEng();
        correctAnswer=random(4);
        switch(correctAnswer)
        {
            case 0:Variant1->Caption=res[i].getUkr();break;
            case 1:Variant2->Caption=res[i].getUkr();break;
            case 2:Variant3->Caption=res[i].getUkr();break;
            case 3:Variant4->Caption=res[i].getUkr();break;
        }
        index[correctAnswer]=1;
        j=1;
        for(i=0;i<4;i++)
        {
            if(ind[i]==0)
            {
                while(index[j=random(4)]==1){}
                index[j]=1;
                switch(j)
                {
                    case 0:Variant1->Caption=res[i].getUkr();break;
                    case 1:Variant2->Caption=res[i].getUkr();break;
                    case 2:Variant3->Caption=res[i].getUkr();break;
                    case 3:Variant4->Caption=res[i].getUkr();break;
                }
            }
        }
        delete res;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddButtonClick(TObject *Sender)
{
    Menu->Visible=false;
    Add->Visible=true;    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Variant1Click(TObject *Sender)
{
    Result(0);
}
//---------------------------------------------------------------------------
void TForm1::Result(const int &res)
{
    if(res==correctAnswer)
    {
        Test->Color=clGreen;
    }
    else
    {
        Test->Color=clRed;
    }
    Variant1->Font->Color=clRed;
    Variant2->Font->Color=clRed;
    Variant3->Font->Color=clRed;
    Variant4->Font->Color=clRed;
    switch(correctAnswer)
    {
        case 0:Variant1->Font->Color=clGreen;break;
        case 1:Variant2->Font->Color=clGreen;break;
        case 2:Variant3->Font->Color=clGreen;break;
        case 3:Variant4->Font->Color=clGreen;break;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Variant2Click(TObject *Sender)
{
    Result(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Variant3Click(TObject *Sender)
{
    Result(2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Variant4Click(TObject *Sender)
{
    Result(3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BackClick(TObject *Sender)
{
    Test->Visible=false;
    Menu->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NextClick(TObject *Sender)
{
    TestShow();
    TestButtonClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddBtnClick(TObject *Sender)
{
    if(EngEdit->Text.Length()>0 && UkrEdit->Text.Length()>0)
    {
        Words add;
        add.setEng(EngEdit->Text.Trim());
        add.setUkr(UkrEdit->Text.Trim());
        dictionary.add(add);

        EngEdit->Text="";
        UkrEdit->Text="";
        changes=true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(changes)
    {
        dictionary.saveToFile("test.txt");
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CancelClick(TObject *Sender)
{
    Add->Visible=false;
    Menu->Visible=true;    
}
//---------------------------------------------------------------------------

