//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Division(float *f1,int stf,float *g,int stg,float *&q,float *&r)
{
float *f;
int i,stq,restf=stf,j,str;
f=(float*)malloc((stf+1)*sizeof(float));
for(i=0;i<=stf;i++)
 f[i]=f1[i];
if (stf>=stg)
 {
  stq=stf-stg;
  q=(float*)malloc((stq+1)*sizeof(float));
  for(i=0;i<=stq;i++)
    q[i]=0;
  i=0;
  while(restf>=stg)
   {
    q[i]=f[i]/g[0];
    for(j=0;j<=stg;j++)
      f[j+i]=f[j+i]-q[i]*g[j];
    restf--;
    i++;
   }
 }
 i=0;
 while((f[i]==0)&&(i<stf))
  i++;
  str=stf-i;
 if(i<stf)
 {
  r=(float*)malloc(str*sizeof(float));
  for(;i<=stf;i++)
    r[i-str-1]=f[i];
 }
 else
  *r=0;
return str;
}

int ScanPolynomial(float *&f)
{
 int stf,i;
 printf("Input st=");
 scanf("%d",&stf);
 f=(float*)malloc((stf+1)*sizeof(float));
 printf("input coefficients(%d) of polynomial\n",stf+1);
 for(i=0;i<=stf;i++)
   scanf("%f",&f[i]);
 return stf;
}

void ScanPolynomial(polinom&p)
{
 int i;
 printf("Input st=");
 scanf("%d",&p.st);
 p.k=(float*)malloc((p.st+1)*sizeof(float));
 printf("input coefficients(%d) of polynomial\n",p.st+1);
 for(i=0;i<=p.st;i++)
   scanf("%f",&p.k[i]);
}

void PrintPolynomial(float *f,int st)
{
 int i;
 printf("Polynomial\n");
 for(i=0;i<=st;i++)
  {
   if(f[i]>=0)
     printf("+");
   printf("%2.2fx^%d",f[i],st-i);
  }
 printf("\n");
}

void PrintPolynomial(polinom p)
{
 int i;
 printf("Polynomial\n");
 for(i=0;i<=p.st;i++)
  {
   if(p.k[i]>=0)
     printf("+");
   printf("%1.1fx^%d",p.k[i],p.st-i);
  }
 printf("\n");
}


void Division(polinom f1,polinom g,polinom&q,polinom&r)
{
int i,j,stf;
polinom f;
f.st=f1.st;
f.k=(float*)malloc((f1.st+1)*sizeof(float));
for(i=0;i<=f.st;i++)
  f.k[i]=f1.k[i];
stf=f.st;
if (f.st>=g.st)
 {
  q.st=f.st-g.st;
  q.k=(float*)malloc((q.st+1)*sizeof(float));
  for(i=0;i<=q.st;i++)
    q.k[i]=0;
  i=0;
  while(stf>=g.st)
   {
    q.k[i]=f.k[i]/g.k[0];
    for(j=0;j<=g.st;j++)
      f.k[j+i]=f.k[j+i]-q.k[i]*g.k[j];
    stf--;
    i++;
   }
 }
 i=0;
 while((f.k[i]==0)&&(i<f.st))
  i++;
 r.st=f.st-i;
 r.k=(float*)malloc((r.st+1)*sizeof(float));
 for(;i<=f.st;i++)
  r.k[i-r.st-1]=f.k[i];
}
