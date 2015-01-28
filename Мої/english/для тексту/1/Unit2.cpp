//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TWord::TWord()
{
    word=NULL;
    n=0;
}
//---------------------------------------------------------------------------
TWord::~TWord()
{
    delete word;
    n=0;
}
//---------------------------------------------------------------------------
char* TWord::CreateFirstWord(char *s)
{
    char *ret,*beg;
    ret=s;
    while( *ret && *ret==' ' )
    {
        ret++;
    }
    beg=ret;
    while( *ret && *ret!=' ' )
    {
        ret++;
    }
    if( *ret==' ' )
    {
        *ret='\0';
        word=strdup(beg);
        *ret=' ';
    }
    else
    {
        word=strdup(beg);
    }
    n=ret-beg;
    return ret;
}
//---------------------------------------------------------------------------
char* TWord::GetWord()
{
    return word;
}
//---------------------------------------------------------------------------
TSentence::TSentence()
{
    sentence=NULL;
    Nword=0;
}
//---------------------------------------------------------------------------
TSentence::~TSentence()
{

}                 
//---------------------------------------------------------------------------
char* TSentence::CreateFirstSentence(char *text)
{
    char *ret,*beg,buf;
    int nword=0,probil=1,i;
    beg=ret=text;
    while( *ret && *ret!='.' )
    {
        if( *ret==' ' )
        {
            if( probil==0 )
            {
                probil=1;
                nword++;
            }
            else
            {
                probil++;
            }
        }
        else
        {
            probil=0;
        }
        ret++;
    }
    if( !*ret )
    {
        return NULL;
    }
    ret++;
    buf=*ret;
    *ret='\0';
    sentence=strdup(beg);
    Nword=nword+1;
    words=new TWord[Nword];
    i=0;
    while(*beg)
    {
        beg=words[i].CreateFirstWord(beg);
        i++;
    }
    *ret=buf;
    return ret;
}
//---------------------------------------------------------------------------
char* TSentence::GetSentence()
{
    return sentence;
}
//---------------------------------------------------------------------------
char* TSentence::GetWord(int k)
{
    if( k<0 || k>=Nword )
    {
        return NULL;
    }
    return words[k].GetWord();
}
//---------------------------------------------------------------------------
TText::TText()
{
    sentences=NULL;
    N=0;
}
//---------------------------------------------------------------------------
TText::~TText()
{

}
//---------------------------------------------------------------------------
void TText::CreateTextWithFile(char* fname)
{
    int k=0;
    FILE *fp;
    char buffer[1000];
    fp=fopen(fname,"rt");
    if( !fp )
    {
        return;
    }
    while(fgets(buffer,1000,fp))
    {
        k++;
    }
    N=k+1;
    sentences=new TSentence[N];
    fclose(fp);
    fp=fopen(fname,"rt");
    k=0;
    while(fgets(buffer,1000,fp))
    {
        sentences[k].CreateFirstSentence(buffer);
        k++;
    }
    fclose(fp);
}
//---------------------------------------------------------------------------
char* TText::GetSentences(int k)
{
    if( k<0 || k>=N )
    {
        return NULL;
    }
    return sentences[k].GetSentence();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

