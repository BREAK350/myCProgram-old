//---------------------------------------------------------------------------
#ifndef VectorPerformanceH
#define VectorPerformanceH
#include "T_Geometry.h"
//---------------------------------------------------------------------------
class T_Gravity
{
    protected:
        T_Vector Centre;
        float minRadius, // �� ������ �� minRadius ���� ������ �� 0 �� Power
              maxRadius, // �� minRadius �� maxRadius ����� �� Power �� 0
              Power; // ����������� ���� (����������� ������� �������)
                     // Power>0 - �� ������ Power<0 �� ������
        float Angle; // ��� �������� �������� �������
    public:
        /*������������ �� �����������*/
        T_Gravity();
        T_Gravity(const T_Gravity &);
        T_Gravity(const T_Vector &,const float &,const float &,const float &);
        ~T_Gravity() {}
        /*********���������***********/
        /***********�������***********/
        float GetmaxRadius()const { return maxRadius; }
        float GetminRadius()const { return minRadius; }
        float GetPower()const { return Power; }
        T_Vector GetPowerVector(const T_Vector &)const;
        T_Point GetCentre()const { return Centre; }
        void Do_toCentre() { Power=(Power<0)?(Power):(-Power); }
        void Do_fromCentre() { Power=(Power>0)?(Power):(-Power); }
        void Draw(TCanvas *,const TColor &)const;
        void SetRadius(const float &,const float &);
        void SetPower(const float &p) { Power=p; }
        void Interaction(T_AnyVector &)const;
};
//---------------------------------------------------------------------------
const float GravitationalConstant = 1; // ����������� �����
//---------------------------------------------------------------------------
float LawOfGravity(const float &m1, // ���� ������� ���
                   const float &m2, // ���� ������� ���
                   const float &R,  // ������� �� �����
                   const float &G   // ����������� �����
                   ); // ����� ����������� ������. ������� ���� �����䳿 ��
//---------------------------------------------------------------------------
T_Vector DoVectorAttraction(const T_Vector &From,// ������� ������ ����������
                            const T_Vector &To,  // �� ����� From �� �����
                            const float &F      // To � ����� F
                            );
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 