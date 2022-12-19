#pragma once
#include "pch.h"
#include "SotnikovStation.h"

class SotnikovMetroSys :
    public CObject
{
public:
    DECLARE_SERIAL(SotnikovMetroSys);

    vector<shared_ptr<SotnikovStation>> stations;

    SotnikovMetroSys();
    ~SotnikovMetroSys();

    void SaveToFile(const char* szPath);
    void LoadFromFile(const char* szPath);

    void ClearAll();
};

