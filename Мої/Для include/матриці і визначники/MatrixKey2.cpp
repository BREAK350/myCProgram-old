//---------------------------------------------------------------------------

#pragma hdrstop

#include "MatrixKey2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
float KeyRez(TKey a)
{
    int i,j,k,r;
    float d;
    TKey b;
    b.n=a.n;
    MemoryAllocation(b);
    KeyToKey(a,b);
    DiagonalKey(b);
    d=1;
    for(k=0;k<b.n;k++)
    {
        d=d*b.e[k][k];
    }
    return d;
}

void ScanKey(TKey &a)
{
    int i,j;
    printf("Input n ");
    scanf("%d",&a.n);
    MemoryAllocation(a);
    printf("Input %d element key\n",a.n*a.n);
    for(i=0;i<a.n;i++)
    {
        for(j=0;j<a.n;j++)
        {
            scanf("%f",&a.e[i][j]);
        }
    }
}

void PrintKey(TKey a)
{
    int i,j;
    printf("Key\n");
    for(i=0;i<a.n;i++,printf("\n"))
    {
        for(j=0;j<a.n;j++)
        {
            printf("%1.2f  ",a.e[i][j]);
        }
    }
}

void MemoryAllocation(TKey&a)
{
    int i;
    if(a.n>0)
    {
        a.e=(float**)malloc(a.n*sizeof(float*));
        for(i=0;i<a.n;i++)
        {
            a.e[i]=(float*)malloc(a.n*sizeof(float));
        }
    }
}

void DiagonalKey(TKey&a)
{
    float d;
    int i,j,k,r;
    for(k=0;k<a.n-1;k++)
    {
        for(i=k+1;i<a.n;i++)
        {
            while((k<a.n-1)&&(a.e[k][k]==0))
            {
                r=k+1;
                while((r<a.n)&&(a.e[r][k]==0))
                {
                    r++;
                }
                if(r<a.n)
                {
                    for(j=k;j<a.n;j++)
                    {
                        a.e[k][j]=a.e[k][j]+a.e[r][j];
                    }
                    break;
                }
                else
                {
                    k++;
                }
            }
            if(k<a.n-1)
            {
                d=a.e[i][k]/a.e[k][k];
                for(j=k;j<a.n;j++)
                {
                    a.e[i][j]=a.e[i][j]-d*a.e[k][j];
                }
            }
        }
    }
}

void KeyToKey(TKey a,TKey&b)
{
    int i,j;
    for(i=0;i<b.n;i++)
    {
        for(j=0;j<b.n;j++)
        {
            b.e[i][j]=a.e[i][j];
        }
    }
}
//---------------------------------------------------------------------------
void MemoryAllocation(TMatrix&a)
{
    int i;
    if((a.n>0)&&(a.m>0))
    {
        a.e=(float**)malloc(a.n*sizeof(float*));
        for(i=0;i<a.n;i++)
        {
            a.e[i]=(float*)malloc(a.m*sizeof(float));
        }
    }
}

void MemoryAllocation(TMatrix&a,int n,int m)
{
    int i;
    a.n=n;
    a.m=m;
    if((a.n>0)&&(a.m>0))
    {
        a.e=(float**)malloc(a.n*sizeof(float*));
        for(i=0;i<a.n;i++)
        {
            a.e[i]=(float*)malloc(a.m*sizeof(float));
        }
    }
}

void ScanMatrix(TMatrix&a)
{
    int i,j;
    printf("Input n ");
    scanf("%d",&a.n);
    printf("Input m ");
    scanf("%d",&a.m);
    MemoryAllocation(a);
    printf("Input %d element matrix\n",a.n*a.m);
    for(i=0;i<a.n;i++)
    {
        for(j=0;j<a.m;j++)
        {
            scanf("%f",&a.e[i][j]);
        }
    }
}

void PrintMatrix(TMatrix a)
{
    int i,j;
    printf("Matrix\n");
    for(i=0;i<a.n;i++,printf("\n"))
    {
        for(j=0;j<a.m;j++)
        {
            printf("%1.2f  ",a.e[i][j]);
        }
    }
}

TMatrix SummaMatrix(TMatrix a,TMatrix b)
{
    int i,j;
    TMatrix c;
    if((a.n==b.n)&&(a.m==b.m)&&(a.n>0)&&(a.m>0))
    {
        MemoryAllocation(c,a.n,a.m);
        for(i=0;i<c.n;i++)
        {
            for(j=0;j<c.m;j++)
            {
                c.e[i][j]=a.e[i][j]+b.e[i][j];
            }
        }
    }
    else
    {
        c.n=-1;
    }
    return c;
}

TMatrix DobytokMatrix(TMatrix a,TMatrix b)
{
    int i,j,k;
    TMatrix c;
    if((a.m==b.n)&&(a.n>0)&&(a.m>0))
    {
        c.n=a.n;
        c.m=b.m;
        MemoryAllocation(c);
        for(i=0;i<c.n;i++)
        {
            for(j=0;j<c.m;j++)
            {
                c.e[i][j]=0;
                for(k=0;k<a.m;k++)
                {
                    c.e[i][j]+=a.e[i][k]*b.e[k][j];
                }
            }
        }
    }
    else
    {
        c.n=-1;
    }
    return c;
}

TMatrix Transpon(TMatrix a)
{
    int i,j;
    TMatrix b;
    if((a.n>0)&&(a.m>0))
    {
        MemoryAllocation(b,a.m,a.n);
        for(i=0;i<b.n;i++)
        {
            for(j=0;j<b.m;j++)
            {
                b.e[i][j]=a.e[j][i];
            }
        }
    }
    else
    {
        b.n=-1;
    }
    return b;
}

void DiagonalMatrix(TMatrix&a)
{
    float d;
    int i,j,k,r;
    int min;
    if(a.n>a.m)
    {
        min=a.m;
    }
    else
    {
        min=a.n;
    }
    for(k=0;k<min-1;k++)
    {
        for(i=k+1;i<a.n;i++)
        {
            while((k<min-1)&&(a.e[k][k]==0))
            {
                r=k+1;
                while((r<a.n)&&(a.e[r][k]==0))
                {
                    r++;
                }
                if(r<a.n)
                {
                    for(j=k;j<a.m;j++)
                    {
                        a.e[k][j]=a.e[k][j]+a.e[r][j];
                    }
                    break;
                }
                else
                {
                    k++;
                }
            }
            if(k<min-1)
            {
                d=a.e[i][k]/a.e[k][k];
                for(j=k;j<a.m;j++)
                {
                    a.e[i][j]=a.e[i][j]-d*a.e[k][j];
                }
            }
        }
    }
}

TMatrix NumberToMatrix(float a,TMatrix b)
{
    int i,j;
    TMatrix c;
    MemoryAllocation(c,b.n,b.m);
    for(i=0;i<c.n;i++)
    {
        for(j=0;j<c.m;j++)
        {
            c.e[i][j]=a*b.e[i][j];
        }
    }
    return c;
}

TKey MinorMatrix(TMatrix a,int r,int s)
{
    int i,j;
    TKey b;
    r--;
    s--;
    if(a.n==a.m)
    {
        if((r>=0)&&(r<a.n)&&(s>=0)&&(s<a.m))
        {
            b.n=a.n-1;
        }
        else
        {
            b.n=-1;
            return b;
        }
        MemoryAllocation(b);
        for(i=0;i<r;i++)
        {
            for(j=0;j<s;j++)
            {
                b.e[i][j]=a.e[i][j];
            }
            for(j=s+1;j<a.m;j++)
            {
                b.e[i][j-1]=a.e[i][j];
            }
        }
        for(i=r+1;i<a.n;i++)
        {
            for(j=0;j<s;j++)
            {
                b.e[i-1][j]=a.e[i][j];
            }
            for(j=s+1;j<a.m;j++)
            {
                b.e[i-1][j-1]=a.e[i][j];
            }
        }
    }
    else
    {
        b.n=-1;
    }
    return b;
}
//---------------------------------------------------------------------------
TKey MatrixToKey(TMatrix a)
{
    int i,j;
    TKey b;
    if(a.n==a.m)
    {
        b.n=a.n;
        MemoryAllocation(b);
        for(i=0;i<b.n;i++)
        {
            for(j=0;j<b.n;j++)
            {
                b.e[i][j]=a.e[i][j];
            }
        }
    }
    else
    {
        b.n=-1;
    }    
    return b;
}

