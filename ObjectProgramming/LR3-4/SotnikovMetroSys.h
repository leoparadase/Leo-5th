#pragma once
#include "pch.h"
#include "SotnikovStation.h"
#include "SotnikovTechStation.h"

class SotnikovMetroSys
{
public:
	vector <shared_ptr<SotnikovStation>> stations;

	SotnikovMetroSys();
	~SotnikovMetroSys();

	void ViewWrite(CDC* pDC, int& h, int& w);
	void LoadFromFile(CArchive& ar);
	void SaveToFile(CArchive& ar);
};

