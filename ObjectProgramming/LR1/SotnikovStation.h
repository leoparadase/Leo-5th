#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "SotnikovChecks.h"

class SotnikovStation
{
private:
	int id;

public:
	std::string name;
	int line;
	int depth;

	void edit();
	void editID();
	int getID();
	void enterID(int num);

	friend std::istream& operator >> (std::istream& out, SotnikovStation& Station);
	friend std::ostream& operator << (std::ostream& out, const SotnikovStation& Station);
	
	friend std::ifstream& operator >> (std::ifstream& out, SotnikovStation& Station);
	friend std::ofstream& operator << (std::ofstream& out, const SotnikovStation& Station);	
};
