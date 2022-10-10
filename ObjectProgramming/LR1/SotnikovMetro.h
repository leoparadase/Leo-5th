#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "SotnikovChecks.h"
#include "SotnikovStation.h"

class SotnikovMetro
{
public:

	std::vector <SotnikovStation* > Stations;

	void add(SotnikovStation& Station);
	void del();
	void clr();

	void save();
	void load();

	friend std::ostream& operator << (std::ostream& out, const SotnikovMetro& Metro);
};
