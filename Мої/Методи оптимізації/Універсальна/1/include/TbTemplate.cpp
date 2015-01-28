//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbTemplate.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TbTemplate::replace(const String &what, const String &insert)
{
	int i = text.Pos(what);
	if(i > 0)
	{
		text.Delete(i, what.Length());
		text.Insert(insert, i);
	}
}
//---------------------------------------------------------------------------
String TbTemplate::generateAttribute(const String &nameAttribute)
{
	return String("${") + nameAttribute + "}";
}
//---------------------------------------------------------------------------
TbTemplate::TbTemplate(const String &text)
{
 	this->text = text;
}
//---------------------------------------------------------------------------
void TbTagHTML::setBody(const TbTemplate &templ)
{
	templs.clear();
	templs.push_back(templ);
}
//---------------------------------------------------------------------------
void TbTagHTML::setBody(const vector<TbTemplate> &templs)
{
	this->templs = templs;
}
//---------------------------------------------------------------------------
void TbTagHTML::add(const TbTemplate &templ)
{
	templs.push_back(templ);
}
//---------------------------------------------------------------------------
String TbTagHTML::toString()const
{
	String res;
	int size = templs.size();
	for(int i = 0; i < size; i++)
	{

	}
	return res;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
TbTemplate TbHTMLFactory::getBODY()
{
	TbTagHTML t;
	TbTemplate p = t;
    return p;
}
//---------------------------------------------------------------------------
TbTemplate TbTemplateFactory::generateOL(const int &count, const String &prefix)
{
	String text = "<ol>";
	for(int i = 0; i < count; i++)
	{
		String attributeName = TbTemplate::generateAttribute(prefix + IntToStr(i));
		text = text + "<li>" + attributeName + "</li>";
	}
	text = text + "</ol>";
	return TbTemplate(text);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
