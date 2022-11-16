#pragma once
#include "SotnikovStation.h"
#include "pch.h"

class CSotnikovDialog;

class SotnikovTechStation :
    public SotnikovStation
{
    DECLARE_SERIAL(SotnikovTechStation);

    int category;

    SotnikovTechStation();
    virtual ~SotnikovTechStation();

    // virtual void c_in();
    // virtual void c_out();
    
    virtual void Serialize(CArchive& f);
    virtual void ViewWrite(CDC* pDC, int& h, int& w);

    virtual void ReturnValues(CSotnikovDialog* dlg);
    virtual void TakingValues(CSotnikovDialog* dlg);
};

