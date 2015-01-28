//---------------------------------------------------------------------------
#pragma hdrstop
#include "MatrixH.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TMatrix::TMatrix()
{
    mP=mN=mN=0;
    L=NULL;
}
//---------------------------------------------------------------------------
TMatrix::~TMatrix()
{
    int i,j;
    for(i=0;i<mP;i++)
    {
        for(j=0;j<mN;j++)
        {
            delete L[i][j];
        }
        delete L[i];
    }
    delete L;
    L=NULL;
}
//---------------------------------------------------------------------------
void TMatrix::SaveToFile(char *fname)
{
    int i,j;
    FILE *f;
    f=fopen(fname,"wb");
    fwrite(&mP,1,sizeof(int),f);
    fwrite(&mN,1,sizeof(int),f);
    fwrite(&mM,1,sizeof(int),f);
    for(i=0;i<mP;i++)
    {
        for(j=0;j<mN;j++)
        {
            fwrite(L[i][j],mM,sizeof(char),f);
        }
    }
    fclose(f);
}
//---------------------------------------------------------------------------
bool TMatrix::LoadFromFile(char *fname)
{
    FILE *f;
    int p,n,m;
    f=fopen(fname,"rb");
    if(!f)
    {
        return false;
    }
    Delete();
    fread(&p,1,sizeof(int),f);
    fread(&n,1,sizeof(int),f);
    fread(&m,1,sizeof(int),f);
    Create(p,n,m);
    for(p=0;p<mP;p++)
    {
        for(n=0;n<mN;n++)
        {
            fread(L[p][n],mM,sizeof(char),f);
        }
    }
    fclose(f);
    return true;
}
//---------------------------------------------------------------------------
void TMatrix::RandomMatrix(int p)
{
    int i,j,k;
    randomize();
    Delete();
    Create(random(p)+1,random(p)+10,random(p)+10);
    for(i=0;i<mP;i++)
    {
        for(j=0;j<mN;j++)
        {
            for(k=0;k<mM;k++)
            {
                L[i][j][k]=random(2);
            }
        }
    }
}
//---------------------------------------------------------------------------
void TMatrix::Delete()
{
    int i,j;
    for(i=0;i<mP;i++)
    {
        for(j=0;j<mN;j++)
        {
            delete L[i][j];
        }
        delete L[i];
    }
    delete L;
    L=NULL;
    mP=mN=mM=0;
}
//---------------------------------------------------------------------------
void TMatrix::Create(int p,int n,int m)
{
    int i,j;
    Delete();
    mP=p;
    mN=n;
    mM=m;
    L=new char**[mP];
    for(i=0;i<mP;i++)
    {
        L[i]=new char*[mN];
        for(j=0;j<mN;j++)
        {
            L[i][j]=new char[mM];
        }
    }
}
//---------------------------------------------------------------------------
void TMatrix::Create(int p,int n,int m,int Type)
{
    int i,j,k;
    Create(p,n,m);
    for(i=0;i<p;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                L[i][j][k]=Type;
            }
        }
    }
}
//---------------------------------------------------------------------------
void TMatrix::Create(int n,int m)
{
    Create(1,n,m);
}
//---------------------------------------------------------------------------
void TMatrix::Insert(int p0,int n0,int m0,const TMatrix &M)
{
    int i,j,k,mp,mn,mm;
    mp=(p0+M.mP>mP)?(mP):(p0+M.mP);
    mn=(n0+M.mN>mN)?(mN):(n0+M.mN);
    mm=(m0+M.mM>mM)?(mM):(m0+M.mM);
    for(i=(p0>0)?(p0):(0);i<mp;i++)
    {
        for(j=(n0>0)?(n0):(0);j<mn;j++)
        {
            for(k=(m0>0)?(m0):(0);k<mm;k++)
            {
                L[i][j][k]=M.L[i-p0][j-n0][k-m0];
            }
        }
    }
}
//---------------------------------------------------------------------------
TMatrix::TMatrix(const TMatrix &M)
{
    int i,j,k;
    mP=M.mP;
    mN=M.mN;
    mM=M.mM;
    L=new char**[mP];
    for(i=0;i<mP;i++)
    {
        L[i]=new char*[mN];
        for(j=0;j<mN;j++)
        {
            L[i][j]=new char[mM];
            for(k=0;k<mM;k++)
            {
                L[i][j][k]=M.L[i][j][k];
            }
        }
    }
}
//---------------------------------------------------------------------------
TMatrix& TMatrix::operator = (const TMatrix &M)
{
    int i,j,k;
    if(&M==this)
    {
        return *this;
    }
    Delete();
    mP=M.mP;
    mN=M.mN;
    mM=M.mM;
    L=new char**[mP];
    for(i=0;i<mP;i++)
    {
        L[i]=new char*[mN];
        for(j=0;j<mN;j++)
        {
            L[i][j]=new char[mM];
            for(k=0;k<mM;k++)
            {
                L[i][j][k]=M.L[i][j][k];
            }
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
TMatrix TMatrix::CreateCopy()
{
    return TMatrix(*this);
}
//---------------------------------------------------------------------------
void TMatrix::SaveToFileLicense(char *fname)
{
    int i,j,a,b,c;
    FILE *f;
    f=fopen(fname,"wb");
    randomize();
    b=random(900)+100;
    c=random(900)+100;
    a=FuncLicense(b,c);
    fwrite(&a,1,sizeof(int),f);
    fwrite(&b,1,sizeof(int),f);
    fwrite(&c,1,sizeof(int),f);
    fwrite(&mP,1,sizeof(int),f);
    fwrite(&mN,1,sizeof(int),f);
    fwrite(&mM,1,sizeof(int),f);
    for(i=0;i<mP;i++)
    {
        for(j=0;j<mN;j++)
        {
            fwrite(L[i][j],mM,sizeof(char),f);
        }
    }
    fclose(f);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int TMatrix::LoadFromFileLicense(char *fname)
{
    FILE *f;
    int p,n,m,a,b,c,iLicense=1;
    f=fopen(fname,"rb");
    if(!f)
    {
        return -1;
    }
    Delete();
    fread(&a,1,sizeof(int),f);
    fread(&b,1,sizeof(int),f);
    fread(&c,1,sizeof(int),f);
    if(a!=FuncLicense(b,c) && a!=FuncUser(b,c))
    {
        fclose(f);
        LoadFromFile(fname);
        return 0;
    }
    if(a==FuncLicense(b,c))
    {
        iLicense=2;
    }
    fread(&p,1,sizeof(int),f);
    fread(&n,1,sizeof(int),f);
    fread(&m,1,sizeof(int),f);
    Create(p,n,m);
    for(p=0;p<mP;p++)
    {
        for(n=0;n<mN;n++)
        {
            fread(L[p][n],mM,sizeof(char),f);
        }
    }
    fclose(f);
    return iLicense;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
