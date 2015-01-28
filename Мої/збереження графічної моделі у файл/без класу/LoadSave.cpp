//---------------------------------------------------------------------------
#pragma hdrstop
#include "LoadSave.h"
#include "CreateModel.h"
//---------------------------------------------------------------------------
void SaveToFile(TModel mod,char*fname)
{
    int i,k;
    FILE *f;
    if(mod.n_point<=0)
    {
        return;
    }
    f=fopen(fname,"wb");
    fwrite(&mod.n_point,1,sizeof(int),f);
    fwrite(mod.point,mod.n_point,sizeof(Point3D),f);
    for(i=0,k=0;i<mod.n_point;i++)
    {
        k+=i;
    }
    k=k/8+1;
    fwrite(mod.grf,k,sizeof(graf),f);
    fclose(f);
}
//---------------------------------------------------------------------------
void LoadFromFile(TModel &mod,char*fname)
{
    int i,k;
    FILE *f;
    f=fopen(fname,"rb");
    fread(&mod.n_point,1,sizeof(int),f);
    free(mod.point);
    mod.point=(Point3D*)malloc(mod.n_point*sizeof(Point3D));
    fread(mod.point,mod.n_point,sizeof(Point3D),f);
    CreateGraf(mod);
    for(i=0,k=0;i<mod.n_point;i++)
    {
        k+=i;
    }
    k=k/8+1;
    fread(mod.grf,k,sizeof(graf),f);
    fclose(f);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#pragma package(smart_init)
