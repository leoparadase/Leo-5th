#include "pch.h"
#include "SotnikovMetroSys.h"
#include "SotnikovStation.h"
#include "SotnikovTechStation.h"

IMPLEMENT_SERIAL(SotnikovMetroSys, CDocument, 0); // look for CObject

SotnikovMetroSys::SotnikovMetroSys()
{
}

SotnikovMetroSys::~SotnikovMetroSys()
{
}

void SotnikovMetroSys::SaveToFile(const char* szPath)
{
	CFile out(CString(szPath), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&out, CArchive::store);

	ar << stations.size();
	for (auto s : stations)
	{
		ar << s.get();
	}

	//ar.Close();
}

void SotnikovMetroSys::LoadFromFile(const char* szPath)
{
	stations.clear();

	CFile in(CString(szPath), CFile::modeRead);
	CArchive ar(&in, CArchive::load);

	int size, n;

	ar >> size;
	//ar >> n;

	for (int i = 0; i < size; i++) {
		SotnikovStation* s = new SotnikovStation;
		ar >> s;
		shared_ptr<SotnikovStation> cur(s);
		stations.push_back(cur);
	}
	//ar.Close();
	//in.Close();
}

void SotnikovMetroSys::ClearAll()
{
	stations.clear();
}
