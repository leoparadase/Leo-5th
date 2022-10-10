#include "pch.h"
#include "SotnikovStation.h"

SotnikovStation::SotnikovStation()
{
}

SotnikovStation::~SotnikovStation()
{
}

IMPLEMENT_SERIAL(SotnikovStation, CObject, 1)

void SotnikovStation::c_in()
{
	string temp;
	
	cout << "Ready to read the station properties:" << endl << endl;

	cout << "ID: ";
	cin >> id;
	
	cout << "Name: ";
	getline(cin >> ws, temp);
	name = temp.c_str();

	cout << "Line: ";
	cin >> line;

	//cout << endl << endl;
}

void SotnikovStation::c_out()
{

	cout << "ID: " << id << endl
		<< "Name: " << (LPCTSTR)name << endl
		<< "Line: " << line << endl;

}

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
