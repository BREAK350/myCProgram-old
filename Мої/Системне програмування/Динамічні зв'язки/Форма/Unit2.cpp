//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TbMyThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TbMyThread::TbMyThread(bool CreateSuspended)
    : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void TbMyThread::SetName()
{
    THREADNAME_INFO info;
    info.dwType = 0x1000;
    info.szName = "MyThread";
    info.dwThreadID = -1;
    info.dwFlags = 0;

    __try
    {
         RaiseException( 0x406D1388, 0, sizeof(info)/sizeof(DWORD),(DWORD*)&info );
    }
    __except (EXCEPTION_CONTINUE_EXECUTION)
    {
    }
}
//---------------------------------------------------------------------------
void __fastcall TbMyThread::Execute()
{
    SetName();
    //---- Place thread code here ----
    int Number=0;
    TbUFAd sa=TbUFAd::CreateSimpleAutomaton("сука",Number,Form1->Canvas);
    sa.Iteration(Number);
}
//---------------------------------------------------------------------------

