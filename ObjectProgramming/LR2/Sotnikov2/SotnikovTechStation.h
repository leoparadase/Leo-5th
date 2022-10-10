#pragma once
#include "SotnikovStation.h"
class SotnikovTechStation :
    public SotnikovStation
{
public:
    DECLARE_SERIAL(SotnikovTechStation);

    int category;

    SotnikovTechStation();
    virtual ~SotnikovTechStation();

    virtual void c_in();
    virtual void c_out();
    virtual void Serialize(CArchive& f);
};

