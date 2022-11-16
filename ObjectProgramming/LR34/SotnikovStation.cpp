#pragma once
#include "pch.h"
#include "SotnikovStation.h"
#include "CSotnikovDialog.h"

SotnikovStation::SotnikovStation()
{
}

SotnikovStation::~SotnikovStation()
{
}

IMPLEMENT_SERIAL(SotnikovStation, CObject, 1)

//void SotnikovStation::c_in()
//{
//	string temp;
//
//	cout << "Ready to read the station properties:" << endl << endl;
//
//	cout << "ID: ";
//	cin >> id;
//
//	cout << "Name: ";
//	getline(cin >> ws, temp);
//	name = temp.c_str();
//
//	cout << "Line: ";
//	cin >> line;
//
//	//cout << endl << endl;
//}

//void SotnikovStation::c_out()
//{
//
//	cout << "ID: " << id << endl
//		<< "Name: " << (LPCTSTR)name << endl
//		<< "Line: " << line << endl;
//
//}

void SotnikovStation::Serialize(CArchive& f)
{
	CObject::Serialize(f);
	if (f.IsStoring())
	{
		f << id << name << line;
	}
	else
	{
		f >> id >> name >> line;
	}
}

void SotnikovStation::ViewWrite(CDC* pDC, int& h, int& w)
{
	CString utext1 = _T("Station:");
	pDC->TextOut(0, h, utext1);
	if (utext1.GetLength() > w)
		w = utext1.GetLength();
	h += 40;
	CString utext = _T("Name: ") + name + _T(";   ID: ") + to_string(id).c_str() + _T(";   Line: ") + to_string(line).c_str();
	pDC->TextOut(0, h, utext);
	if (utext.GetLength() > w)
		w = utext.GetLength();
	h += 40;
}

void SotnikovStation::ReturnValues(CSotnikovDialog* dlg)
{
	dlg->s_id = to_string(this->id).c_str();
	dlg->s_name = this->name;
	dlg->s_line = to_string(this->line).c_str();
}

void SotnikovStation::TakingValues(CSotnikovDialog* dlg)
{
	id = stoi((LPCTSTR)(dlg->s_id));
	name = (LPCTSTR)(dlg->s_name);
	line = stoi((LPCTSTR)(dlg->s_line));
}
