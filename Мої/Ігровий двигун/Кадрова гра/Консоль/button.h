//---------------------------------------------------------------------------
#ifndef buttonH
#define buttonH
#include "TbArray.h"
#include <vcl.h>
#include <iostream.h>
#include <fstream.h>
#include <TbList2.h>
#include "T_Vector2d.h"
//---------------------------------------------------------------------------
class TbButton
{
    private:
        TbArray <TPoint> Point;
        TbArray <string> AddWord,NeedWord;
        string Next;
        int isBelongPoligon(const TPoint &p);
        void Add(TbList2 < string > &Word);
    public:
        TbButton() {}
        void LoadFromFile(ifstream &ifs);
        int onClick(const TPoint &p,string &GameAddress,TbList2 < string > &Word);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
