#pragma once
#include <afx.h>
#include "pch.h"
#include "Header.h"

using namespace std;


class SotnikovStation :
    public CObject
{
    DECLARE_SERIAL(SotnikovStation);

    CString name;
    int id, line;

    SotnikovStation();
    virtual ~SotnikovStation();

    // virtual void c_in();
    // virtual void c_out();

    virtual void Serialize(CArchive& f);
    virtual void ViewWrite(CDC* pDC, int& h, int& w);
};

