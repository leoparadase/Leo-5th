#include "pch.h"
#include "SotnikovTechStation.h"

SotnikovTechStation::SotnikovTechStation()
{
}

SotnikovTechStation::~SotnikovTechStation()
{
}

IMPLEMENT_SERIAL(SotnikovTechStation, SotnikovStation, 1)

void SotnikovTechStation::c_in()
{
	SotnikovStation::c_in();

	cout << "Category: ";
	cin >> category;

	//cout << endl << endl;
}

void SotnikovTechStation::c_out()
{
	SotnikovStation::c_out();

	cout << "Category: " << category;
}

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
