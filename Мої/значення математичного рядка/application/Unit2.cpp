//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
char *a;
float x;
//---------------------------------------------------------------------------
int CheckFunction(int i)
{
 ifsin(i)
  return 1;
 ifcos(i)
  return 2;
 ifctg(i)
  return 3;
 iftg(i)
  return 4;
 ifpow(i)
  return 5;
 ifln(i)
  return 6;
 ifabs(i)
  return 7;
 return 0;
}
//---------------------------------------------------------------------------
float _ValueX(int left,int right)
{
 int id,kd,i,tgd=-1;
 TActionF act1,act2;
 act1.kd=act2.kd=kd=0;
 act1.id=act2.id=id=-1;
 i=left;
//*****************************************************************
while(i<right)
{
 switch(a[i])
 {
  case '(':kd++;break;
  case ')':kd--;break;
  case '+': if((act1.kd>kd)||(act1.kd==0))
                {
                 act1.id=i;
                 act1.kd=kd;
                }break;
  case '-': if((act1.kd>kd)||(act1.kd==0))
                {
                 act1.id=i;
                 act1.kd=kd;
                }break;
  case '*': if((act2.kd>kd)||(act2.kd==0))
                {
                 act2.id=i;
                 act2.kd=kd;
                }break;
  case '/': if((act2.kd>kd)||(act2.kd==0))
                {
                 act2.id=i;
                 act2.kd=kd;
                }break;
  default : if(CheckFunction(i)>0)
            {
             while((i<right)&&(a[i]!='('))
               i++;
             i++;
             tgd=kd+1;
             while((i<right)&&(tgd!=kd))
             {
              if(a[i]=='(')
               tgd++;
              if(a[i]==')')
               tgd--;
              i++;
             }
             while((i<right)&&(a[i]==')'))
              i++;
             if((i==right)&&(act1.id==-1)&&(act2.id==-1))
             {
              tgd=-10;
              break;
             }
            }
 }
 i++;
}
/*****************************************************************
 while(i<right)
 {
  if(a[i]=='(')
   kd++;
   if(a[i]==')')
    kd--;
   if(CheckFunction(i)>0)
   { //------------------------------------------
    while((i<right)&&(a[i]!='('))
     i++;
    i++;
    tgd=kd+1;
    while((i<right)&&(tgd!=kd))
    {
     if(a[i]=='(')
      tgd++;
     if(a[i]==')')
      tgd--;
     i++;
    }
    while((i<right)&&(a[i]==')'))
     i++;
    if((i==right)&&(act1.id==-1)&&(act2.id==-1))
    {
     tgd=-10;
     break;
    }
   }//------------------------------------------
  if((a[i]=='+')||(a[i]=='-'))
  {
   if((act1.kd>kd)||(act1.kd==0))
   {
    act1.id=i;
    act1.kd=kd;
   }
  }
  if((a[i]=='*')||(a[i]=='/'))
  {
   if((act2.kd>kd)||(act2.kd==0))
   {
    act2.id=i;
    act2.kd=kd;
   }
  }
  i++;
 }
//*****************************************************************/
 if((act2.id>0)&&((act1.kd>act2.kd)||(act1.id==-1)))
  id=act2.id;
 else
  id=act1.id;
 if(tgd==-10)
 {
  tgd=-1;
  switch(CheckFunction(left))
   {
    case 1:return sin(_ValueX(left+4,right-1));
    case 2:return cos(_ValueX(left+4,right-1));
    case 4:return tan(_ValueX(left+3,right-1));
    case 5:
           i=left;
           while((i<right)&&(a[i]!=','))
            i++;
           return pow(_ValueX(left+4,i),_ValueX(i+1,right));
    case 7:return fabs(_ValueX(left+4,right-1));
   }
 }
 if(id>=0)
  switch(a[id])
  {
   case '+':return(_ValueX(left,id)+_ValueX(id+1,right));
   case '-':return(_ValueX(left,id)-_ValueX(id+1,right));
   case '*':return(_ValueX(left,id)*_ValueX(id+1,right));
   case '/':return(_ValueX(left,id)/_ValueX(id+1,right));
  }
 return _NumberX(left,right);
}

float _NumberX(int left,int right)
{
 int i=left;
 int z=0;
 float d=0,k;
 while((i<right)&&(a[i]=='('))
  i++;
 if(a[i]=='P')
  return 3.14159265358979323846;
 if(a[i]=='E')
  return 2.71828182845904523536;
 if((a[i]=='X')||(a[i]=='x'))
  return x;
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

float Value(char *a1,float X)
{
 a=(char*)malloc(strlen(a1)*sizeof(char));
 strcpy(a,a1);
 x=X;
 return _ValueX(0,strlen(a));
}

void BuildGraph(char*f,int scale)
{
 int i,n;
 a=(char*)malloc(strlen(f)*sizeof(char));
 strcpy(a,f);
 n=strlen(a);
 for(i=1;i<Form3->ClientWidth;i++)
 {
  x=(float)(i-Form3->ClientWidth/2)/scale;
  Form3->Canvas->LineTo(i,(Form3->ClientHeight/2-scale*_ValueX(0,n)));
 }
 free(a);
}
