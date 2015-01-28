//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
//---------------------------------------------------------------------------
class func
{
    private:
        int size;
        AnsiString text;
    public:
        AnsiString CreateAS(char*,int);
        AnsiString Change(char,char*);
        AnsiString Change(char*,char*);
        AnsiString ChangeFX(char*,char*);
        bool       operator==(char*);
        AnsiString operator=(char*);
        AnsiString operator+(char*);
        func       SelectLN(int,int);
        char*      ReturnChar();
        func       NextLevel();
};
//---------------------------------------------------------------------------
int RightBracket(char*);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
