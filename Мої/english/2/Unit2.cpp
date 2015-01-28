//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
Dictionary::Dictionary(const char *FileName)
{
    char buf[BUFSIZE];
    ifstream ifs(FileName);
    bool isNotEnd=true;
    Words add;
    int addGood,index=0;
    ifs.get(buf,BUFSIZE);
    while(isNotEnd)
    {
        index=0;
        do
        {
            addGood=add.init(&buf[index]);
            if(addGood>0)
            {
                index+=addGood;
                words.Add(add);
            }
        }
        while(addGood>0);
        if(addGood==0)
        {
            isNotEnd=false;
        }
        else
        {
            strcpy(buf,&buf[index]);
            ifs.get(&buf[BUFSIZE-index-1],index);
        }
    }
    ifs.close();
}
//---------------------------------------------------------------------------
void Dictionary::show(const char *fileName)
{
    ofstream ofs(fileName);
    words.CurrSetFirst();
    ofs<<words.GetCount()<<endl;
    while(words.CurrCorrect())
    {
        ofs<<words.GetCurr().getEng().c_str()
           <<'='
           <<words.GetCurr().getUkr().c_str()
           <<endl;
        words.CurrSetNext();
    }
    ofs.close();
}
//---------------------------------------------------------------------------
Words* Dictionary::get(const int *index,const int &size) // 0<=index<Count
{
    Words *res=new Words[size];
    words.CurrSetFirst();
    int i=0,k=0;
    while(k<size)
    {
        while(i<index[k])
        {
            words.CurrSetNext();
            i++;
        }
        res[k]=words.GetCurr();
        k++;
    }
    return res;
}
//---------------------------------------------------------------------------
void Dictionary::saveToFile(const char *fileName)
{
    ofstream ofs(fileName);
    words.CurrSetFirst();
    while(words.CurrCorrect())
    {
        ofs<<words.GetCurr().getEng().c_str()
           <<'&'
           <<words.GetCurr().getUkr().c_str()
           <<';';
        words.CurrSetNext();
    }
    ofs<<'.';
    ofs.close();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
