//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class Test : public TThread
{            
private:
protected:
    void __fastcall Execute();
public:
    __fastcall Test(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
 