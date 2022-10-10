#pragma once
#include "SotnikovStation.h"
#include "SotnikovTechStation.h"
#include <vector>

class SotnikovMetroSys
{
	vector<shared_ptr<SotnikovStation>> stations;
	vector<shared_ptr<SotnikovStation>>::iterator it;

public:
	SotnikovMetroSys();
	~SotnikovMetroSys();

	void c_read();
	void c_write();

	void f_read();
	void f_write();

	void clr();
};

