//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <vector.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	WebBrowser1->Navigate(WideString("about:blank"));

	html = new TbTagHTML("html", false);
	TbTagHTML *head = new TbTagHTML("head", false);
	TbTagHTML *body = new TbTagHTML("body", false);
	TbTagHTML *h1 = new TbTagHTML("h1", false);
	TbTagHTML *ol = new TbTagHTML("ol", false);
	TbTextHTML *text = new TbTextHTML("Методи оптимізації");
	
	TbContainerHTML *html_c = new TbContainerHTML();
	TbContainerHTML *body_c = new TbContainerHTML();
	ol_c = new TbContainerHTML();

	html_c->add(head);
	html_c->add(body);

	h1->setContents(text);
	body_c->add(h1);
	body_c->add(ol);
	ol->setContents(ol_c);

	html->setContents(html_c);
	body->setContents(body_c);

	Memo1->Text = html->toString();
	showHTML();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N2Click(TObject *Sender)
{
	Memo1->Visible = !Memo1->Visible;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if(problem)
	{
		TbContentsHTML *contents = problem->nextStep();
		if(contents)
		{
			TbTagHTML *li = new TbTagHTML("li", false);
			li->setContents(contents);
			ol_c->add(li);
        }
    }
	//TbTagHTML *li = new TbTagHTML("li", false);
	//TbTextHTML *text = new TbTextHTML("new <br>text<br>" + IntToStr(i));
	//li->setContents(text);
	//ol_c->add(li);
	//i++;

	Memo1->Text = html->toString();

	showHTML();
}
//---------------------------------------------------------------------------
void TForm2::showHTML()
{
	TMemoryStream *stm = new TMemoryStream();
	Memo1->Lines->SaveToStream(stm);
	stm->Seek(0,0);
	IPersistStreamInit *psi;
	TStreamAdapter *sa = new TStreamAdapter(stm,soReference);
	if (SUCCEEDED(WebBrowser1->Document->QueryInterface(IID_IPersistStreamInit,(void **)&psi)))
	{
		psi->Load(*sa);
	}
	delete stm;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Panel1Resize(TObject *Sender)
{
	Button1->Left = Panel1->Width / 2 - Button1->Width / 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormResize(TObject *Sender)
{
	Memo1->Width = ClientWidth * 0.4;
}
//---------------------------------------------------------------------------
void TForm2::setProblem(TbAbstractProblem *problem)
{
	if(this->problem)
	{
		delete problem;
	}
	this->problem = problem;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
	Memo1->Text = "";
	//ol_c->clear();
	showHTML();
}
//---------------------------------------------------------------------------

