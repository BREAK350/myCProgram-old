//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
message::message(char* fn)
{
    strcpy(fname,fn);
    fp=NULL;
    n=0;
    Load();
}
//---------------------------------------------------------------------------
message::~message()
{
    int i;
    for(i=0;i<n;i++)
    {
        delete[] mess[i];
    }
    delete[] mess;
    n=0;
}
//---------------------------------------------------------------------------
void message::Load()
{
    int i;
    char buffer[256];
    fp=fopen(fname,"rt");
    if(!fp)
    {
        return;
    }
    fscanf(fp,"%d\n",&n);
    mess=new char*[n];
    for(i=0;i<n;i++)
    {
        fgets(buffer,256,fp);
        mess[i]=strdup(buffer);
    }
    fclose(fp);
    fp=NULL;
}
//---------------------------------------------------------------------------
void message::ShowMess(int k)
{
    if(k<0)
    {
        cout<<"�������!³�'���� ��������(k="<<k<<")"<<endl;
    }
    else
    {
        if(k>=n)
        {
            cout<<"�������!�������� ��������(k="<<k<<">="<<n<<")"<<endl;
        }
        else
        {
            cout<<mess[k];
        }
    }
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
