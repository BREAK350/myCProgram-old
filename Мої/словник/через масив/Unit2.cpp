//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CWord::CWord()
{
 eng=NULL;
 ukr=NULL;
}
//---------------------------------------------------------------------------
CWord::~CWord()
{
 free(eng);
 free(ukr);
}
//---------------------------------------------------------------------------
void CWord::Create(char*a)
{
 int i,l_e,l_u;
 l_e=0;
 l_u=0;
 i=0;
 while((a[l_e])&&(a[l_e]!='='))
   l_e++;
 i=l_e+1;
 while((a[i])&&(a[i]!='\n'))
  {
   l_u++;
   i++;
  }
 eng=(char*)malloc(l_e*sizeof(char));
 ukr=(char*)malloc(l_u*sizeof(char));
 for(i=0;i<l_e;i++)
   eng[i]=a[i];
 eng[i]='\0';
 for(i=0;i<l_u;i++)
   ukr[i]=a[i+l_e+1];
 ukr[i]='\0';  
}
//---------------------------------------------------------------------------
void CWord::ShowConsol()
{
 printf("Eng: %s\nUkr: %s\n",eng,ukr);
}
//---------------------------------------------------------------------------
