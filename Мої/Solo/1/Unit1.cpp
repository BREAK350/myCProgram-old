//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TMain *Main;
int ReductionStatisticTimer=0;
//---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner)
    : TForm(Owner)
{
    Language=Ukrainian;
    Start=false;
    randomize();
    Lessons=NULL;
    GetCheckedFinger();
    isEndllesText=false;
    for(int i=0;i<33;i++)
    {
        KeyStatistic[i]=1;
    }
    ErrorKey=-1;
}
//---------------------------------------------------------------------------
void TMain::ReductionStatistic()
{
    for(int i=0;i<33;i++)
    {
        if(KeyStatistic[i]>1)
        {
            KeyStatistic[i]--;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMain::FieldKeyPress(TObject *Sender, char &Key)
{
    if(isEndllesText)
    {
        if(Key==Field->Text[1])
        {
            ErrorKey=-1;
            if(Field->Text[1]==' ')
            {
                Field->Text=Field->Text.Delete(1,1)+GenerateWordForEndllesText()+' ';
                if(ReductionStatisticTimer>0)
                {
                    ReductionStatisticTimer--;
                }
                else
                {
                    ReductionStatistic();
                }
            }
            else
            {
                Field->Text=Field->Text.Delete(1,1);
            }
            Field->SelStart=0;
            Field->SelLength=1;
        }
        else
        {
            if(Field->Text[1]!=' ')
            {
                KeyStatistic[GetActiveKey()]++;
                switch(Language)
                {
                    case English:
                        ErrorKey=GetIndexKey(EnglishSymbol,Key);
                        break;
                    case Ukrainian:
                        ErrorKey=GetIndexKey(UkrainianSymbol,Key);
                        break;
                }
            }
            ReductionStatisticTimer++;
        }
    }
    else
    {
        if(Field->SelStart<Field->Text.Length())
        {
            if(Progress->Progress<Progress->MaxValue)
            {
                if(Key==Field->Text[Field->SelStart+1])
                {
                    ErrorKey=-1;
                    Field->SelStart++;
                    Field->SelLength=1;
                }
                else
                {
                    Field->SelStart=0;
                    Field->SelLength=1;
                    Progress->Progress=0;

                    switch(Language)
                    {
                        case English:
                            ErrorKey=GetIndexKey(EnglishSymbol,Key);
                            break;
                        case Ukrainian:
                            ErrorKey=GetIndexKey(UkrainianSymbol,Key);
                            break;
                    }
                }
            }
            else
            {
                Again();
            }
        }
        else
        {
            Message->Visible=true;
            if(Lessons)
            {
                if(Lessons->next())
                {
                    loadFromFile((lessons+Lessons->getCurr()).c_str());
                    Again();
                }
                else
                {
                    Start=false;
                }
            }
            else
            {
                Start=false;
            }
        }
    }
    if(N4->Caption=="З клавіатурою")
    {
        KeyBoard->Repaint();
    }
}
//---------------------------------------------------------------------------
void TMain::loadFromFile(const wchar_t *fileName)
{
	ifstream ifs(fileName);
    char buf[1024];
    ifs.get(buf,1024);
    Field->Text=buf;
    ifs.close();
}
//---------------------------------------------------------------------------
void TMain::Again()
{
    Message->Visible=false;
    Start=(isEndllesText==false);
    Progress->Progress=0;
    Field->SelStart=0;
    Field->SelLength=1;
    int max=Field->Text.Length();
    Progress->MaxValue=(max>0)?(max):(1);
    Field->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMain::N2Click(TObject *Sender)
{
    OpenDialog1->Execute();
    if(OpenDialog1->FileName.Length()>0)
    {
        loadFromFile(OpenDialog1->FileName.c_str());
        Again();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMain::NLanguageEnglishClick(TObject *Sender)
{
    ActivateKeyboardLayout(LoadKeyboardLayout("00000409",0),0);
    Language=English;
    NLanguage->Caption="Мова(Англійська)";
}
//---------------------------------------------------------------------------
void __fastcall TMain::NLanguageUkrainianClick(TObject *Sender)
{
    ActivateKeyboardLayout(LoadKeyboardLayout("00000422",0),0);
    Language=Ukrainian;
    NLanguage->Caption="Мова(Українська)";
}
//---------------------------------------------------------------------------
void __fastcall TMain::Timer1Timer(TObject *Sender)
{
    if(Start && Field->SelStart>0)
    {
        Progress->Progress++;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMain::N7Click(TObject *Sender)
{
    Again();
    if(isEndllesText)
    {
        for(int i=0;i<33;i++)
        {
            KeyStatistic[i]=1;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMain::N6Click(TObject *Sender)
{
    OpenDialog1->Execute();
    if(OpenDialog1->FileName.Length()>0)
    {
        if(Lessons)
        {
            delete Lessons;
            Lessons=NULL;
        }
        lessons=OpenDialog1->FileName;
        int i=lessons.Length();
        while(lessons[i]!='\\')
        {
            i--;
        }
        Lessons=new TLessons(lessons.c_str());
        lessons.SetLength(i);
        loadFromFile((lessons+Lessons->getCurr()).c_str());
        Again();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMain::N8Click(TObject *Sender)
{
    Timer1->Enabled=!Timer1->Enabled;
    if(Timer1->Enabled)
    {
        N8->Caption="Виключити таймер";
    }
    else
    {
        N8->Caption="Включити таймер";
    }
}
//---------------------------------------------------------------------------
String TMain::GenerateWord()const
{
    String word;
    switch(Language)
    {
        case English:
            word=GenerateWord(EnglishSymbol);
            break;
        case Ukrainian:
            word=GenerateWord(UkrainianSymbol);
    }
    return word;
}
//---------------------------------------------------------------------------
String TMain::GenerateWordForEndllesText()const
{
    String word;
    switch(Language)
    {
        case English:
            word=GenerateWordForEndllesText(EnglishSymbol);
            break;
        case Ukrainian:
            word=GenerateWordForEndllesText(UkrainianSymbol);
    }
    return word;
}
//---------------------------------------------------------------------------
String TMain::GenerateWord(const char Key[2][33])const
{
    String word;
    word.SetLength(random(8)+1);
    for(int i=0;i<word.Length();i++)
    {
        int index=random(FingerChecked[0]);
        int indexLetter=random(Finger[FingerChecked[index+1]][0]);

        word[i+1]=Key[random(CheckBoxBigSymbol->Checked+1)]
                     [Finger[FingerChecked[index+1]][indexLetter+1]];
    }
    return word;
}
//---------------------------------------------------------------------------
String TMain::GenerateWordForEndllesText(const char Key[2][33])const
{
    String word;
    int Count=0;
    for(int i=0;i<FingerChecked[0];i++)
    {
        for(int j=0;j<Finger[FingerChecked[i+1]][0];j++)
        {
            Count+=KeyStatistic[Finger[FingerChecked[i+1]][j+1]];
        }
    }
    word.SetLength(random(8)+1);
    for(int k=0;k<word.Length();k++)
    {
        int r=random(Count);
        int i=0,j=0;
        i=0;
        while(i<FingerChecked[0] && r>=0)
        {
            j=0;
            while(j<Finger[FingerChecked[i+1]][0] && r>=0)
            {
                r-=KeyStatistic[Finger[FingerChecked[i+1]][j+1]];
                if(r>=0)
                {
                    j++;
                }
            }
            if(r>=0)
            {
                i++;
            }
        }
        word[k+1]=Key[random(CheckBoxBigSymbol->Checked+1)]
                     [Finger[FingerChecked[i+1]][j+1]];
    }
    return word;
}
//---------------------------------------------------------------------------
void TMain::GetCheckedFinger()
{
    int count=0;
    count+=Finger0->Checked;
    count+=Finger1->Checked;
    count+=Finger2->Checked;
    count+=Finger3->Checked;
    count+=Finger5->Checked;
    count+=Finger6->Checked;
    count+=Finger7->Checked;
    count+=Finger8->Checked;
    FingerChecked[0]=count;
    if(count>0)
    {
        count=1;
        if(Finger0->Checked)
        {
            FingerChecked[count]=0;
            count++;
        }
        if(Finger1->Checked)
        {
            FingerChecked[count]=1;
            count++;
        }
        if(Finger2->Checked)
        {
            FingerChecked[count]=2;
            count++;
        }
        if(Finger3->Checked)
        {
            FingerChecked[count]=3;
            count++;
        }
        if(Finger5->Checked)
        {
            FingerChecked[count]=5;
            count++;
        }
        if(Finger6->Checked)
        {
            FingerChecked[count]=6;
            count++;
        }
        if(Finger7->Checked)
        {
            FingerChecked[count]=7;
            count++;
        }
        if(Finger8->Checked)
        {
            FingerChecked[count]=8;
            count++;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMain::N9Click(TObject *Sender)
{
    if(isEndllesText==false)
    {
        Field->Clear();
        if(FingerChecked[0]>0)
        {
            int size=random(30)+5;
            for(int i=0;i<size;i++)
            {
                Field->Text=Field->Text+GenerateWord()+' ';
            }
            Again();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TMain::N10Click(TObject *Sender)
{
    Options->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TMain::OptionsOKClick(TObject *Sender)
{
    Options->Visible=false;
    GetCheckedFinger();
    Again();
}
//---------------------------------------------------------------------------
void __fastcall TMain::FieldClick(TObject *Sender)
{
    //int a=Field->SelStart;
    Message->Visible=false;
    if(isEndllesText)
    {
        Again();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMain::FormKeyPress(TObject *Sender, char &Key)
{
    ShowMessage("FormKeyPress");
}
//---------------------------------------------------------------------------
void __fastcall TMain::N3Click(TObject *Sender)
{
    if(isEndllesText)
    {
        N3->Caption="Скінченний текст";
        isEndllesText=false;
        N9Click(Sender);
    }
    else
    {
        N3->Caption="Нескінченний текст";
        isEndllesText=true;
        Field->Clear();
        if(FingerChecked[0]>0)
        {
            int size=10;
            for(int i=0;i<size;i++)
            {
                Field->Text=Field->Text+GenerateWord()+' ';
            }
            Again();
        }
        Timer1->Enabled=false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMain::N4Click(TObject *Sender)
{
    KeyBoard->Show();
    N4->Caption="З клавіатурою";
}
//---------------------------------------------------------------------------
int TMain::GetActiveKey()const
{
    int i=0;
    switch(Language)
    {
        case English:
            i=GetActiveKey(EnglishSymbol);
            break;
        case Ukrainian:
            i=GetActiveKey(UkrainianSymbol);
            break;
    }
    return i;
}
//---------------------------------------------------------------------------
int TMain::GetIndexKey(const char Key[2][33],const char &s)
{
    int i=0;
    while(i<33 && Key[0][i]!=s && Key[1][i]!=s)
    {
        i++;
    }
    return (i<33)?(i):(-1);
}
//---------------------------------------------------------------------------
int TMain::GetActiveKey(const char Key[2][33])const
{
    int i=0;
    char s=GetActiveSymbol();
    while(i<33 && Key[0][i]!=s && Key[1][i]!=s)
    {
        i++;
    }
    return (i<33)?(i):(-1);
}
//---------------------------------------------------------------------------
char TMain::GetActiveSymbol()const
{
    char s=0;
    if(Field->Text.Length()>0)
    {
        s=Field->Text[Field->SelStart+1];
    }
    return s;
}
//---------------------------------------------------------------------------

