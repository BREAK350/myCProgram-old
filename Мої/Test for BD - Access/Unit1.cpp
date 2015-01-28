// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	String r1 =
	"SELECT EngWords.value as eng, UkrWords.value as ukr FROM UkrWords INNER JOIN (EngWords INNER JOIN [Translation] ON (EngWords.id = Translation.idEngWord) AND (EngWords.id = Translation.idEngWord)) ON UkrWords.id = Translation.idUkrWord ORDER BY EngWords.value, UkrWords.value;";
	String r2 =
	"SELECT EngWords.value, Count(Translation.idEngWord) AS [Count-idEngWord] FROM EngWords INNER JOIN [Translation] ON (EngWords.id = Translation.idEngWord) AND (EngWords.id = Translation.idEngWord) GROUP BY EngWords.value ORDER BY EngWords.value;";
	String r3 =
	"SELECT EngWords.id, EngWords.value FROM EngWords WHERE (((EngWords.value) Like '%oo%')) ORDER BY EngWords.value;";
	showResult(Memo1, r3, ADOQuery1);
	std::vector<int> v;
	v.push_back(2);
	int size = v.size();
	size=0;
}

// ---------------------------------------------------------------------------
void TForm1::showResult(TMemo *memo, const String &request,
	TADOQuery *ADOQuery) {
	ADOQuery->Close();
	ADOQuery->SQL->Add(request);
	ADOQuery->Open();
	ADOQuery->First();
	memo->Clear();
	while (!ADOQuery->Eof) {
		String records = "|";
		for (int i = 0; i < ADOQuery->Fields->Count; i++) {
			records = records + ADOQuery->Fields->FieldByNumber(i + 1)
			->AsWideString + "|";
		}
		memo->Lines->Add(records);
		ADOQuery->Next();
	}
}
// ---------------------------------------------------------------------------
