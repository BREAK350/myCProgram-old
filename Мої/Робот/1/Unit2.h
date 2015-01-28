//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
class T_Energy
{
    private:
        float Mechanical,      // ��������
              Electromagnetic, // ��������������
              Chemical,        // ������
              Nuclear,         // ������
              Thermal,         // �������
              Gravitational;   // �����������
    public:
        T_Energy(){}
        T_Energy(const float &m,const float &e,const float &c,const float &n,
            const float &t,const float &g) { Init(m,e,c,n,t,g); }
        operator float()const;
        bool operator >= (const T_Energy &)const;
        bool operator <= (const T_Energy &)const;
        T_Energy operator + (const T_Energy &)const;
        void Init(const float &,const float &,const float &,const float &,const float &,const float &);
};
//---------------------------------------------------------------------------
class T_Material
{
    private:
        T_Energy InternalEnergy,     // �������� ������
                 MinInternalEnergy,  // �������� ������
                 MaxInternalEnergy,  // ����������� ������
                 DoBalance;          // ����������� ��������� ����㳿 �� ������� ����
    public:
};
//---------------------------------------------------------------------------
class T_Arsenal
{
    private:
        T_Material Material;
        T_Energy Improve,Index;
        float Volume;
    public:
};
//---------------------------------------------------------------------------
class T_Weapon:public T_Arsenal
{
};
//---------------------------------------------------------------------------
class T_Shield:public T_Arsenal
{
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 