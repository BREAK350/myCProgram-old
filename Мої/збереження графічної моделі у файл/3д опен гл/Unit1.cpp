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
sizeof(PIXELFORMATDESCRIPTOR),  // ������ ����� pfd
1,                              // ����� ������
PFD_DRAW_TO_WINDOW |           // ������������� ����
PFD_SUPPORT_OPENGL |          // support OpenGL // ������������� OPENGL
PFD_DOUBLEBUFFER,             // double buffered // ������ ������������
PFD_TYPE_RGBA,                  // RGBA type
24,                             // 24-bit color depth 24-��������� ������� �������
0, 0, 0, 0, 0, 0,               // color bits ignored ������� ����������������� �����
0,                              // no alpha buffer  // ��� ����������� ������	
0,                              // shift bit ignored // ������� ����������������� �����
0,                              // no accumulation buffer // ��� ������ ����������
0, 0, 0, 0,                     // accum bits ignored // accum ����� ���������������
32,                             // 32-bit z-buffer // 32-��������� z-buffer
0,                              // no stencil buffer  // ��� ������ ���������
0,                              // no auxiliary buffer  // ��� ���������������� ������
PFD_MAIN_PLANE,                 // main layer // ������� ����
0,                              // reserved // ������
0, 0, 0                         // layer masks ignored  // ����������������� ����� ����
    };

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  glLineWidth(3);      // ������ 3

  glBegin(GL_LINE_STRIP); // ��. ����
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
