#pragma once
#include <afx.h> // look for pch.h

class SotnikovStation :
    public CObject
{
public:
    DECLARE_SERIAL(SotnikovStation);

    int id = 0;
    CString name = "null";
    int line = 0;

    SotnikovStation();
    ~SotnikovStation();
    virtual void Serialize(CArchive& ar);
};

