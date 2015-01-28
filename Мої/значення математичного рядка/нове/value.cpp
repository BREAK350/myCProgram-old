//---------------------------------------------------------------------------

#pragma hdrstop

#include "value.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
char *a;
float x;
//---------------------------------------------------------------------------
float Value(char*str,float xV)
{
 int n;
 n=strlen(str);
 a=(char*)malloc(n*sizeof(char));
 strcpy(a,str);
 x=xV;
 return _Value(0,n);
}

float _Value(int left,int right)
{
 Operatciya p;
 Data d;
 USI i;
 p.LS.level=-1;
 p.LS.starshynstvo=-1;
 p.i=-1;
 d.TypeOperatciyi=-1;
 d.level=0;
//*********************poshuk operatciyi**********************
 i=left;
 while(i<right)
  {
   switch(a[i])
    {
     case '(':d.level++;break;
     case ')':d.level--;break;
     case '+':
              case '-':if(p.i==-1)
                          {
                           PRYSV;
                           p.LS.starshynstvo=1;
                          }
                       else
                           if(p.LS.level>d.level)
                              PRYSV;
                       break;
     case '*':
              case '/':if(p.i==-1)
                          {
                           PRYSV;
                           p.LS.starshynstvo=2;
                          }
                       else
                          {
                           if(p.LS.level>d.level)
                              PRYSV;
                           if((p.LS.level==d.level)&&(p.LS.starshynstvo==1))
                              PRYSV;
                          }
                       break;
     default :if((a[i]>='0')&&(a[i]<='9')||(a[i]=='.'))
                break;
              if3f(i)
                {
                 i+=4;
                }
    }/*****switch*****/
   i++;
  }/*****while*****/
 //************************************************************
 if(p.i>-1)
  {
   switch(a[p.i])
     {
      case '+':return (_Value(left,p.i)+_Value(p.i+1,right));
      case '-':return (_Value(left,p.i)-_Value(p.i+1,right));
      case '*':return (_Value(left,p.i)*_Value(p.i+1,right));
      case '/':return (_Value(left,p.i)/_Value(p.i+1,right));
     }
  }
 else
   {
    if(d.TypeOperatciyi==1)
      {
      
      }
   }


}
