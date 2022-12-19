#include "pch.h"
#include "SotnikovTechStation.h"
#include "CSotnikovDialog.h"

SotnikovTechStation::SotnikovTechStation()
{
}

SotnikovTechStation::~SotnikovTechStation()
{
}

IMPLEMENT_SERIAL(SotnikovTechStation, SotnikovStation, VERSIONABLE_SCHEMA | 1)


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
	CString utext1 = ("Tech station:");
	pDC->TextOut(0, h, utext1);
	if (utext1.GetLength() > w)
		w = utext1.GetLength();
	h += 40;
	CString utext = ("Name: ") + name + (";   ID: ") + to_string(id).c_str() + (";   Line: ") + to_string(line).c_str() + (";   Category: ") + to_string(category).c_str();
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