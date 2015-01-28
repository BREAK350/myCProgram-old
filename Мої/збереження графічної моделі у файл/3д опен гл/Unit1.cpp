//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <stdlib.h>
#include "glu.h"
#include "gl.h"
TForm1 *Form1;
GLint Width = 512, Height = 512;
const int CubeSize = 200;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
PIXELFORMATDESCRIPTOR pfd =
	{
sizeof(PIXELFORMATDESCRIPTOR),  // размер этого pfd
1,                              // номер версии
PFD_DRAW_TO_WINDOW |           // поддерживайте окно
PFD_SUPPORT_OPENGL |          // support OpenGL // поддерживайте OPENGL
PFD_DOUBLEBUFFER,             // double buffered // вдвоем буферизовано
PFD_TYPE_RGBA,                  // RGBA type
24,                             // 24-bit color depth 24-разрядная цветная глубина
0, 0, 0, 0, 0, 0,               // color bits ignored цветные проигнорированные куски
0,                              // no alpha buffer  // нет алфавитного буфера	
0,                              // shift bit ignored // сменный проигнорированный кусок
0,                              // no accumulation buffer // нет буфера накопления
0, 0, 0, 0,                     // accum bits ignored // accum куски проигнорировали
32,                             // 32-bit z-buffer // 32-разрядный z-buffer
0,                              // no stencil buffer  // нет буфера трафарета
0,                              // no auxiliary buffer  // нет вспомогательного буфера
PFD_MAIN_PLANE,                 // main layer // главный слой
0,                              // reserved // занято
0, 0, 0                         // layer masks ignored  // проигнорированные маски слоя
    };

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  glLineWidth(3);      // ширина 3

  glBegin(GL_LINE_STRIP); // см. ниже
  glColor3ub(255,0,0);
  glVertex3d(-2.7,3,0);
  glVertex3d(-1,3,0);

  glColor3f(0,1.0f,0);
  glVertex3d(-1.5,3.3,0);
  glColor3f(0,0,1.0f);
  glVertex3d(-1,3.5,0);
  glEnd();

}
//---------------------------------------------------------------------------
void Display(void)
{
    int left, right, top, bottom;

    left  = (Width - CubeSize) / 2;
    right = left + CubeSize;
    bottom = (Height - CubeSize) / 2;
    top = bottom + CubeSize;

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
      glVertex2f(left,bottom);
      glVertex2f(left,top);
      glVertex2f(right,top);
      glVertex2f(right,bottom);
    glEnd();


    glFinish();
}
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Display();
}
//---------------------------------------------------------------------------
