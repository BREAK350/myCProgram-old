//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbFrame.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TbFrame::LoadFromFile(ifstream &ifs)
{
    char buf[64];
    int Count;
    ifs>>buf;
    NamePicture=buf;
    ifs>>Count;
    Button.SetCount(Count);
    for(int i=0;i<Count;i++)
    {
        Button[i].LoadFromFile(ifs);
    }
}
//---------------------------------------------------------------------------
int TbFrame::onClick(const TPoint &p,string &FrameAddress,TbList2 < string > &Word)
{
    int q=0;
    for(int i=0;q==0 && i<Button.GetCount();i++)
    {
        q=Button[i].onClick(p,FrameAddress,Word);
    }
    return q;
}
//---------------------------------------------------------------------------
void TbGame::LoadFromFile(const char *FileName)
{
    char *buffn=strdup(FileName);
    int k=strlen(FileName)-strlen(GAMESTART);
    if(k>0)
    {
        buffn[k]=0;
    }
    GameAddress=buffn;
    delete buffn;
    ifstream ifs((GameAddress+GAMESTART).c_str());
    if(!ifs.eof())
    {
        Word.DeleteAll();
        char buf[128];
        ifs>>buf;
        LoadFrame(buf);
        Draw();
    }
    ifs.close();
}
//---------------------------------------------------------------------------
void TbGame::onClick(const TPoint &p)
{
    string NewFrameAddress;
    if(Frame.onClick(p,NewFrameAddress,Word)==1)
    {
        LoadFrame(NewFrameAddress);
        Draw();
    }
}
//---------------------------------------------------------------------------
void TbGame::LoadFrame(const string &FileName)
{
    ifstream frame((GameAddress+FileName+info).c_str());
    if(!frame.eof())
    {
        FrameAddress=FileName;
        Frame.LoadFromFile(frame);
    }
    frame.close();
}
//---------------------------------------------------------------------------
void TbGame::Draw()
{
    bmp->LoadFromFile((GameAddress+FrameAddress+Frame.NamePicture).c_str());
    Canvas->Draw(0,0,bmp);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
