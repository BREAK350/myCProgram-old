//---------------------------------------------------------------------------
#ifndef TbFrameH
#define TbFrameH
#include "button.h"
//---------------------------------------------------------------------------
const char GAMESTART[]="GAMESTART.txt";
const char info[]="info.txt";
//---------------------------------------------------------------------------
class TbFrame
{
    public:
        string NamePicture; /* c1.bmp   */
        TbArray < TbButton > Button;
    public:
        TbFrame() {}
        void LoadFromFile(ifstream &ifs);
        int onClick(const TPoint &p,string &FrameAddress,TbList2 < string > &Word);
};
//---------------------------------------------------------------------------
class TbGame
{
    private:
        TbFrame Frame;
        Graphics::TBitmap *bmp;
        TCanvas *Canvas;
        string GameAddress; /*  D:\..\Game1\   - тут знаходиться GAMESTART.txt і папки */
        string FrameAddress; /* Data\p1\  - адрес папки, де знаходиться info.txt  */
        TbList2 < string > Word;
        void LoadFrame(const string &FileName);
        void Draw();
    public:
        TbGame(TCanvas *_Canvas) { Canvas=_Canvas; bmp=new Graphics::TBitmap; }
        void LoadFromFile(const char *FileName); // FileName=GameAddress+GAMESTART
        void onClick(const TPoint &p);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
