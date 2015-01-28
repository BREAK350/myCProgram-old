//---------------------------------------------------------------------------

#pragma hdrstop

#include "MathFunction.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

float _Value(char *a,int left,int right)
{
 int id,kd,i,tgd=-1;
 TAction act1,act2;
 act1.kd=act2.kd=kd=0;
 act1.id=act2.id=id=-1;
 i=left;
 while(i<right)
 {
  if(a[i]=='(')
   kd++;
  if(a[i]==')')
   kd--;
  if(CheckFunction(a,i)>0)
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
 if((act2.id>0)&&((act1.kd>act2.kd)||(act1.id==-1)))
  id=act2.id;
 else
  id=act1.id;
 if(tgd==-10)
 {
  tgd=-1;
  switch(CheckFunction(a,left))
   {
    case 1:return sin(_Value(a,left+4,right-1));
    case 2:return cos(_Value(a,left+4,right-1));
    case 4:return tan(_Value(a,left+3,right-1));
    case 5:
           i=left;
           while((i<right)&&(a[i]!=','))
            i++;
           return pow(_Value(a,left+4,i),_Value(a,i+1,right-1));
    case 7:return fabs(_Value(a,left+4,right-1));
   }
 }
 if(id>=0)
  switch(a[id])
  {
   case '+':return(_Value(a,left,id)+_Value(a,id+1,right));
   case '-':return(_Value(a,left,id)-_Value(a,id+1,right));
   case '*':return(_Value(a,left,id)*_Value(a,id+1,right));
   case '/':return(_Value(a,left,id)/_Value(a,id+1,right));
  }
 return _Number(a,left,right);
}

float _Number(char *a,int left,int right)
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

float Value(char *a)
{
 return(_Value(a,0,strlen(a)));
}

int CheckFunction(char*a,int i)
{
 if((a[i]=='s')&&(a[i+1]=='i')&&(a[i+2]=='n'))
  return 1;
 if((a[i]=='c')&&(a[i+1]=='o')&&(a[i+2]=='s'))
  return 2;
 if((a[i]=='c')&&(a[i+1]=='t')&&(a[i+2]=='g'))
  return 3;
 if((a[i]=='t')&&(a[i+1]=='g'))
  return 4;
 if((a[i]=='p')&&(a[i+1]=='o')&&(a[i+2]=='w'))
  return 5;
 if((a[i]=='l')&&(a[i]=='n'))
  return 6;
 if((a[i]=='a')&&(a[i+1]=='b')&&(a[i+2]=='s'))
  return 7;
 return 0;
}
//---------------------------------------------------------------------------
float _ValueX(char *a,int left,int right,float X)
{
 int id,kd,i,tgd=-1;
 TAction act1,act2;
 act1.kd=act2.kd=kd=0;
 act1.id=act2.id=id=-1;
 i=left;
 while(i<right)
 {
  if(a[i]=='(')
   kd++;
  if(a[i]==')')
   kd--;
  if(CheckFunction(a,i)>0)
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
 if((act2.id>0)&&((act1.kd>act2.kd)||(act1.id==-1)))
  id=act2.id;
 else
  id=act1.id;
 if(tgd==-10)
 {
  tgd=-1;
  switch(CheckFunction(a,left))
   {
    case 1:return sin(_ValueX(a,left+4,right-1,X));
    case 2:return cos(_ValueX(a,left+4,right-1,X));
    case 4:return tan(_ValueX(a,left+3,right-1,X));
    case 5:
           i=left;
           while((i<right)&&(a[i]!=','))
            i++;
           return pow(_ValueX(a,left+4,i,X),_ValueX(a,i+1,right,X));
    case 7:return fabs(_ValueX(a,left+4,right-1,X));
   }
 }
 if(id>=0)
  switch(a[id])
  {
   case '+':return(_ValueX(a,left,id,X)+_ValueX(a,id+1,right,X));
   case '-':return(_ValueX(a,left,id,X)-_ValueX(a,id+1,right,X));
   case '*':return(_ValueX(a,left,id,X)*_ValueX(a,id+1,right,X));
   case '/':return(_ValueX(a,left,id,X)/_ValueX(a,id+1,right,X));
  }
 return _NumberX(a,left,right,X);
}

float _NumberX(char *a,int left,int right,float X)
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
 if(a[i]=='X')
  return X;
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

float Value(char *a,float X)
{
 return _ValueX(a,0,strlen(a),X);
}

void StartProgram()
{
 char work;
 do
 {
  printf("Welcome\nInput\n M-Mathematical expression\n F-Function\n E-end");
  work=getch();
  clrscr();
  if((work=='e')||(work=='E')){printf("GoodBye:)");getch();exit(0);}
  if((work=='m')||(work=='M')) Mathematical_expression();
  if((work=='f')||(work=='F')) Function();
 }
 while((work!='e')||(work!='E'));
}

void Mathematical_expression()
{
 char a[300];
 printf("Input mathematical expression\nf=");
 gets(a);
 printf(" f=%f;\n",Value(a));
 getch();
 clrscr();
}
void Function()
{
 int n,i;
 char a[300];
 char x[100];
 float X;
 printf("Input mathematical function\nf=");
 gets(a);
 printf("Input n=");
 scanf("%d",&n);
 gets(x);
 for(i=0;i<n;i++)
 {
  printf("%d) Input X=",i+1);
  gets(x);
  X=Value(x);
  printf("  f(%1.2f)=%f;\n",X,Value(a,X));
 }
 getch();
 clrscr();
}

void TheProgramBeginsFILE()
{
 FILE*fp;
 char a[100];
 fp=fopen("TheProgramBegins.txt","rt");
 if(!fp)
  {
   printf("Error! not find file \"TheProgramBegins.txt\"");
   getch();
   exit(0);
  }
 else
 {
  while(fgets(a,100,fp))
   printf(a);
  fclose(fp);
  getch();
  clrscr();
 }
}
