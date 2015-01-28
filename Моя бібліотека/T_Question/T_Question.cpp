//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Question.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Question::T_Question()
{
    Question=NULL;
    Variant=NULL;
    CorrectAnswers=NULL;
}
//---------------------------------------------------------------------------
T_Question::T_Question(const T_Question &Q)
{
    int i,n;
    Question=(Q.Question)?(strdup(Q.Question)):(NULL);
    CorrectAnswers=(Q.CorrectAnswers)?(strdup(Q.CorrectAnswers)):(NULL);
    n=strlen(CorrectAnswers);
    Variant=new char * [n];
    for(i=0;i<n;i++)
    {
        Variant[i]=strdup(Q.Variant[i]);
    }
}
//---------------------------------------------------------------------------
T_Question::~T_Question()
{
    Delete();
}
//---------------------------------------------------------------------------
T_Question::T_Question(const char *Q,char **V,const char *CA)
{
    int i,n;
    Question=(Q)?(strdup(Q)):(NULL);
    CorrectAnswers=(CA)?(strdup(CA)):(NULL);
    n=strlen(CA);
    Variant=new char * [n];
    for(i=0;i<n;i++)
    {
        Variant[i]=strdup(V[i]);
    }
}
//---------------------------------------------------------------------------
void T_Question::Delete()
{
    int i,n=GetN();
    delete[] Question;
    delete[] CorrectAnswers;
    for(i=0;i<n;i++)
    {
        delete[] Variant[i];
    }
    delete[] Variant;
    Question=NULL;
    Variant=NULL;
    CorrectAnswers=NULL;
}
//---------------------------------------------------------------------------
void T_Question::Create(const char *Q,char **V,const char *CA)
{
    int i,n;
    Delete();
    Question=(Q)?(strdup(Q)):(NULL);
    CorrectAnswers=(CA)?(strdup(CA)):(NULL);
    n=strlen(CA);
    Variant=new char * [n];
    for(i=0;i<n;i++)
    {
        Variant[i]=strdup(V[i]);
    }
}
//---------------------------------------------------------------------------
float T_Question::CheckAnswer(const char *CA)
{
    int i=0,n=GetN(),k=0,ca=0,nCA=strlen(CA);
    if(CorrectAnswers && CA)
    {
        ca=GetNCorrectAnswers();
        while(i<n && i<nCA)
        {
            if(CA[i]=='1')
            {
                if(CorrectAnswers[i]=='1')
                {
                    k++;
                }
                else
                {
                    k--;
                }
            }
            else
            {
                if(CorrectAnswers[i]=='1')
                {
                    k--;
                }
            }
            i++;
        }
        while(i<n)
        {
            if(CorrectAnswers[i]=='1')
            {
                k--;
            }
            i++;
        }
    }
    return (ca)?((float)k/ca):(0);
}
//---------------------------------------------------------------------------
int T_Question::GetNCorrectAnswers()const
{
    int i,n=GetN(),ca=0;
    for(i=0;i<n;i++)
    {
        ca+=CorrectAnswers[i]-'0';
    }
    return ca;
}
//---------------------------------------------------------------------------
void T_Question::SaveToFile(FILE *f)
{
    int i,n=GetN();
    fprintf(f,"%s\n%s\n",Question,CorrectAnswers);
    for(i=0;i<n;i++)
    {
        fprintf(f,"%s\n",Variant[i]);
    }
}
//---------------------------------------------------------------------------
void T_Question::LoadFromFile(FILE *f)
{
    int i,n;
    char buf[1028];
    Delete();
    fgets(buf,1028,f);
    DoCorect(buf);
    Question=strdup(buf);
    fgets(buf,1028,f);
    DoCorect(buf);
    CorrectAnswers=strdup(buf);
    n=GetN();
    Variant=new char * [n];
    for(i=0;i<n;i++)
    {
        fgets(buf,1028,f);
        DoCorect(buf);
        Variant[i]=strdup(buf);
    }
}
//---------------------------------------------------------------------------
void DoCorect(char *s)
{
    int i=0;
    if(s)
    {
        while(s[i])
        {
            if(s[i]=='\n')
            {
                s[i]=0;
            }
            i++;
        }
    }
}
//---------------------------------------------------------------------------
void T_Question::SaveToFile(ofstream &ofs)
{
    int i,n=GetN();
    ofs<<Question<<endl<<CorrectAnswers;
    for(i=0;i<n;i++)
    {
        ofs<<Variant[i]<<endl;
    }
}
//---------------------------------------------------------------------------
void T_Question::LoadFromFile(ifstream &ifs)
{
    int i,n;
    char buf[1028];
    Delete();
    ifs>>buf;
    DoCorect(buf);
    Question=strdup(buf);
    ifs>>buf;
    DoCorect(buf);
    CorrectAnswers=strdup(buf);
    n=GetN();
    Variant=new char* [n];
    for(i=0;i<n;i++)
    {
        ifs>>buf;
        DoCorect(buf);
        Variant[i]=strdup(buf);
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
