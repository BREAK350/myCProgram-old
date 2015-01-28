//---------------------------------------------------------------------------
#ifndef DataH
#define DataH
#include <stdio.h>
#include <time.h>
#define ADDER 4
#define DAY(day) ((day)*86400)
#define TWENTY_DAY 1728000
//---------------------------------------------------------------------------
struct TbData
{
    time_t t;
    double end,begin,price;
    TbData() {}
    TbData(const time_t &t,const double &end,const double &begin,const double &price);
    double Different()const { return end-begin; }
    double Summ()const { return price*Different(); }
    time_t Time() { time(&t); return t; }
};
//---------------------------------------------------------------------------
void SaveToFile(FILE *File,const TbData &Data);
void LoadFromFile(FILE *File,TbData &Data);
void SaveToFile(FILE *File,const int &n,const TbData *Data);
void LoadFromFile(FILE *File,int &n,TbData *&Data);
void SaveToFile(const char *FileName,const int &n,const TbData *Data);
void LoadFromFile(const char *FileName,int &n,TbData *&Data);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
