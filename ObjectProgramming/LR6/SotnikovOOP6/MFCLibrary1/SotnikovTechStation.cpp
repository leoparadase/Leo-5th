#include "pch.h"
#include "SotnikovTechStation.h"

IMPLEMENT_SERIAL(SotnikovTechStation, SotnikovStation, VERSIONABLE_SCHEMA | 1);

SotnikovTechStation::SotnikovTechStation()
{
}

SotnikovTechStation::~SotnikovTechStation()
{
}

void SotnikovTechStation::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		SotnikovStation::Serialize(ar);
		ar << category;
	}
	else
	{
		SotnikovStation::Serialize(ar);
		ar >> category;
	}
}
