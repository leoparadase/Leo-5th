#include "pch.h"
#include "SotnikovMetroSys.h"

SotnikovMetroSys::SotnikovMetroSys()
{
}

SotnikovMetroSys::~SotnikovMetroSys()
{
}

void SotnikovMetroSys::ViewWrite(CDC* pDC, int& h, int& w)
{
    CString str1 = _T("Metro system:");
    w = str1.GetLength();
    pDC->TextOut(0, h, str1);
    h += 40;
    if (stations.empty())
    {
        pDC->TextOut(0, h, _T("No stations\n"));
        if (string("No stations").length() > w)
            w = str1.GetLength();
    }
    else
        for_each(stations.begin(), stations.end(), bind(&SotnikovStation::ViewWrite, placeholders::_1, pDC, ref(h), ref(w)));
}

void SotnikovMetroSys::LoadFromFile(CArchive& ar)
{
    int count, n;
    ar >> count;
    ar >> n;
    stations.clear();
    stations.reserve(count); 
    for (int i = 0; i < count; i++)
    {
        SotnikovStation* temp;
        ar >> temp;
        shared_ptr<SotnikovStation> s(temp);
        stations.push_back(s);
    }
}

void ArchiveStations(CArchive& archive, shared_ptr<SotnikovStation> station)
{
    archive << station.get();
}

void SotnikovMetroSys::SaveToFile(CArchive& archive)
{
    archive << stations.size();
    for_each(stations.begin(), stations.end(), bind(ArchiveStations, ref(archive), placeholders::_1));
}
