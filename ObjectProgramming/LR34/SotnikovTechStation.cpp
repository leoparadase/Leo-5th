#include "pch.h"
#include "SotnikovTechStation.h"
#include "CSotnikovDialog.h"

SotnikovTechStation::SotnikovTechStation()
{
}

SotnikovTechStation::~SotnikovTechStation()
{
}

IMPLEMENT_SERIAL(SotnikovTechStation, SotnikovStation, 1)

//void SotnikovTechStation::c_in()
//{
//	SotnikovStation::c_in();
//
//	cout << "Category: ";
//	cin >> category;
//
//	//cout << endl << endl;
//}
//
//void SotnikovTechStation::c_out()
//{
//	SotnikovStation::c_out();
//
//	cout << "Category: " << category;
//}

void SotnikovTechStation::Serialize(CArchive& f)
{
	SotnikovStation::Serialize(f);
	if (f.IsStoring())
	{
		f << category;
	}
	else
	{
		f >> category;
	}
}

void SotnikovTechStation::ViewWrite(CDC* pDC, int& h, int& w)
{
	CString utext1 = _T("Tech station:");
	pDC->TextOut(0, h, utext1);
	if (utext1.GetLength() > w)
		w = utext1.GetLength();
	h += 40;
	CString utext = _T("Name: ") + name + _T(";   ID: ") + to_string(id).c_str() + _T(";   Line: ") + to_string(line).c_str() + _T(";   Category: ") + to_string(category).c_str();
	pDC->TextOut(0, h, utext);
	if (utext.GetLength() > w)
		w = utext.GetLength();
	h += 40;
}

void SotnikovTechStation::ReturnValues(CSotnikovDialog* dlg)
{
	SotnikovStation::ReturnValues(dlg);
	dlg->s_category = to_string(category).c_str();
}

void SotnikovTechStation::TakingValues(CSotnikovDialog* dlg)
{
	SotnikovStation::TakingValues(dlg);
	category = stoi((LPCTSTR)(dlg->s_category));
}