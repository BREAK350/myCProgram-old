//---------------------------------------------------------------------------

#ifndef functionH
#define functionH
#define pi 3.14159265358979323846
//---------------------------------------------------------------------------
#endif
struct vector3 {
float v[3];
              };
struct matrix3 {
float a[3][3];
              };
struct matrix4 {
float a[4][4];
              };
struct point2 {
float x,y;
              };
struct point3 {
float x,y,z;
              };
struct data3dWorld {
point3 Point_of_view;
int scale;
int alfa,betta,gamma;
int distance;
int side;
int height;
int eyes;
                   };
struct data2dWorld {
int x0;
int y0;
                   };
//---------------------------------------------------------------------------
vector3 VectorNaMatrix3(vector3,matrix3);
void PrintVector3(vector3);
void ScanVector3(vector3&);
void PrintMatrix3(matrix3);
void ScanMatrix3(matrix3&);
point2 xyz_xy(point3,data3dWorld data);
point3 AbsoluteXYZ(point3,data3dWorld);
void InitData3(data3dWorld&);
void InitData2(data2dWorld&);
int Line3D(point3,point3,data3dWorld,data2dWorld);
point3 convert_point3(float,float,float);
point2 convert_point2(float,float);
