//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool bSetupPixelFormat(HDC hdc)
{
    bool r=false;
    PIXELFORMATDESCRIPTOR pfd,*ppfd;
    int pixelformat;
    ppfd=&pfd;
    ppfd->nSize=sizeof(PIXELFORMATDESCRIPTOR);
    ppfd->nVersion=1;
    ppfd->dwFlags=PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    ppfd->dwLayerMask=PFD_MAIN_PLANE;
    ppfd->iPixelType=PFD_TYPE_RGBA;
    ppfd->cColorBits=16;
    ppfd->cDepthBits=16;
    ppfd->cAccumBits=0;
    ppfd->cStencilBits=0;
    if((pixelformat=ChoosePixelFormat(hdc,ppfd))!=0)
    {
        r=SetPixelFormat(hdc,pixelformat,ppfd);
    }
    return r;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    ghDC=GetDC(Handle);
    if(!bSetupPixelFormat(ghDC))
    {
        Close();
    }
    ghRC=wglCreateContext(ghDC);
    wglMakeCurrent(ghDC,ghRC);
    glClearColor(0.0,0.0,0.0,0.0);
    FormResize(Sender);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    float p[4]={3,3,3,1},
        d[3]={-1,-1,-3};
    glLightfv(GL_LIGHT0,GL_POSITION,p);
    glLightfv(GL_LIGHT0,GL_SPOT_DIRECTION,d);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
    glViewport(0,0,Width,Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,2,12);
    gluLookAt(0,0,5,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
}
//---------------------------------------------------------------------------
void TForm1::Draw()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    /*GLUquadricObj *quadObj;
    quadObj=gluNewQuadric();
    gluQuadricDrawStyle(quadObj,GLU_FILL);
    gluSphere(quadObj,2,10,10);
    gluDeleteQuadric(quadObj);
    */
    glColor3f(0.0,1.0,0.0);
    glRotatef(3,0,1,1);
    glBegin(GL_POLYGON);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(1.0,0.0,1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(0.0,1.0,0.0);
    glEnd();
    
    SwapBuffers(ghDC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    Draw();
}
//---------------------------------------------------------------------------

