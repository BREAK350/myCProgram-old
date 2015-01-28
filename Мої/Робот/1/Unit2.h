//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
class T_Energy
{
    private:
        float Mechanical,      // механічна
              Electromagnetic, // електромагнітна
              Chemical,        // хімічна
              Nuclear,         // ядерна
              Thermal,         // теплова
              Gravitational;   // гравітаційна
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
        T_Energy InternalEnergy,     // внутрішня енергія
                 MinInternalEnergy,  // мінімальна енергія
                 MaxInternalEnergy,  // максимальна енегрія
                 DoBalance;          // балансіровка внутрішньої енергії за одиницю часу
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
 