//---------------------------------------------------------------------------
#pragma hdrstop
#include "DFA_HTML.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TableHTML(ofstream &ofs,const TbDFA &DFA)
{
    int q=DFA.GetCountQ();
    int s=DFA.GetCountS();
    //ofs<<"    <CENTER>"<<endl;
    ofs<<"          <TABLE border=1 cellpadding=10 cellspacing=1>"<<endl;
    ofs<<"            <TR>"<<endl;
    ofs<<"              <TH></TH>"<<endl;
    for(int j=0;j<s;j++)
    {
        ofs<<"              <TH>'"<<(char)DFA.GetSymbol(j)<<"'</TH>"<<endl;
    }
    ofs<<"            </TR>"<<endl;
    for(int i=0;i<q;i++)
    {
        ofs<<"            <TR>"<<endl;
        if(DFA.isEndQ(i))
        {
            ofs<<"              <TH>("<<i<<")</TH>"<<endl;
        }
        else
        {
            ofs<<"              <TH>"<<i<<"</TH>"<<endl;
        }
        for(int j=0;j<s;j++)
        {
            ofs<<"              <TD>"<<DFA.GetElement(i,j)<<"</TD>"<<endl;
        }
        ofs<<"            </TR>"<<endl;
    }
    ofs<<"          </TABLE>"<<endl;
    //ofs<<"    </CENTER>"<<endl;
}
//---------------------------------------------------------------------------
void WriteInHTML(ofstream &ofs,const char *Expression,const TbDFA &DFA,const int &i)
{
    ofs<<"      <TR>"<<endl;
    ofs<<"        <TD>"<<endl;
    ofs<<"          <H3>Варіант № "<<i+1<<"</H3>"<<endl;
    ofs<<"          <H4>"<<Expression<<"</H4>"<<endl;
    ofs<<"        </TD>"<<endl;
    ofs<<"        <TD>"<<endl;
        TableHTML(ofs,DFA);
    ofs<<"        </TD>"<<endl;
    ofs<<"      </TR>"<<endl;
}
//---------------------------------------------------------------------------
void HeadHTML(ofstream &ofs)
{
    ofs<<"<HTML>"<<endl;
    ofs<<"  <HEAD>"<<endl;
    ofs<<"    <TITLE> Лабораторна робота №5 </TITLE>"<<endl;
    ofs<<"  </HEAD>"<<endl;
    ofs<<"  <BODY>"<<endl;
    //ofs<<"    <H1>Тема: Побудова регулярного виразу по  скінченному автомату</H1>"<<endl;
    ofs<<"    <TABLE align=\"center\" border cellspacing=0 cellpadding=5>"<<endl;
    ofs<<"      <CAPTION><H3>Побудова регулярного виразу по скінченному автомату</H3></CAPTION>"<<endl;
}
//---------------------------------------------------------------------------
void EndHTML(ofstream &ofs)
{
    ofs<<"    </TABLE>"<<endl;
    ofs<<"  <CENTER><FONT size=\"2\">&copy; Усі права захищені</FONT></CENTER>"<<endl;
    ofs<<"  </BODY>"<<endl;
    ofs<<"</HTML>"<<endl;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 