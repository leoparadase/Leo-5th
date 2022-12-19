#pragma once
#include "SotnikovStation.h" // look for pch.h
class SotnikovTechStation :
    public SotnikovStation
{
public:
    DECLARE_SERIAL(SotnikovTechStation);

    int category = 0;

    SotnikovTechStation();
    ~SotnikovTechStation();

    virtual void Serialize(CArchive& ar);
};

