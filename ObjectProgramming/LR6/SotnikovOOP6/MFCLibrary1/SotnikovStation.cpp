#include "pch.h"
#include "SotnikovStation.h"

IMPLEMENT_SERIAL(SotnikovStation, CObject, 0);

SotnikovStation::SotnikovStation()
{
}

SotnikovStation::~SotnikovStation()
{
}

void SotnikovStation::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << id << name << line;
	}
	else
	{
		ar >> id >> name >> line;
	}
}

