//---------------------------------------------------------------------------
#pragma hdrstop
#include "Value.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
char *a;
float x;
//---------------------------------------------------------------------------
float Value(char*str,float xV)
{
 float fx;
 int n;
 n=strlen(str);
 if(n==0)
   a="0";
 else
 {
   a=(char*)malloc(n*sizeof(char));
   strcpy(a,str);
 }
 x=xV;
 fx=_Value(0,n);
 if(n>0)
   free(a);
 return fx;
}
//---------------------------------------------------------------------------

float _Value(int left,int right)
{
   int i,
       d_l=-1,
       d_r=-1;
   int act=-1;
 i=left;
 while(i<right)
  {
   switch(a[i])
    {
     case '(':d_l=i;
              d_r=Skip(i,right);
              i=d_r;
              break;
     case '+':
              case '-':act=i;
                       goto go;
                       break;
     case '*':
              case '/':if((act==-1)||(a[act]=='^'))
                         act=i;
                       break;
     case '^':if(act==-1)
                act=i;
              else
                if((a[act]!='*')&&(a[act]!='/'))
                  act=i;
              break;
    }/*****switch*****/
   i++;
  }/*****while*****/
 go:
 if(act<0)
  {
   if((d_l>=0)&&(d_r>0))
     {
      if(d_l>=4)
       {
        ifsqrt     return sqrt(_Value(d_l+1,d_r));
        ifasin     return asin(_Value(d_l+1,d_r));
        ifacos     return acos(_Value(d_l+1,d_r));
       }
      if(d_l>=3)
       {
        ifsin      return sin(_Value(d_l+1,d_r));
        ifcos      return cos(_Value(d_l+1,d_r));
        ifabs      return fabs(_Value(d_l+1,d_r));
        iftg       return tan(_Value(d_l+1,d_r));
        ifln       return log(_Value(d_l+1,d_r));
        ifexp      return exp(_Value(d_l+1,d_r));
       }
      return _Value(d_l+1,d_r);
     }
  }
 else
  {
   switch(a[act])
    {
     case '+':return(_Value(left,act)+_Value(act+1,right));
     case '-':return(_Value(left,act)-_Value(act+1,right));
     case '*':return(_Value(left,act)*_Value(act+1,right));
     case '/':return(_Value(left,act)/_Value(act+1,right));
     case '^':return pow(_Value(left,act),_Value(act+1,right));
    }
  }
 return _Number(left,right);
}

int Skip(int i,int right)
{
   char d=1;
 i++;
 while((i<right)&&(d>0))
  {
   switch(a[i])
    {
     case '(':d++;break;
     case ')':d--;break;
    }
   i++;
  }
 return (i-1);
}
float _Number(int left,int right)
{
    int i=left;
    int z=0;
    float d=0,k;
 while((i<right)&&(a[i]=='('))
  i++;
 if(a[i]=='P')   return M_PI;
 if(a[i]=='E')   return M_E;
 if(a[i]=='x')   return x;
 while((i<right)&&(a[i]>='0')&&(a[i]<='9'))
 {
  z=z*10+(a[i]-'0');
  i++;
 }
 if((i<right)&&(a[i]=='.'))
  {
   i++;
   k=10;
   while((i<right)&&(a[i]>='0')&&(a[i]<='9')&&(k<10000000))
   {
    d=d+(a[i]-'0')/k;
    k=k*10;
    i++;
   }
  }
 return (z+d);
}
