#pragma once
#include "SotnikovMetro.h"

void SotnikovMetro::add(SotnikovStation& Station)
{
	std::cin >> Station;

	if (!Stations.empty())
	{
		for (auto* it : Stations)
		{
			if (Station.getID() == it->getID())
			{
				std::cout << "Not unique ID, try again." << std::endl << std::endl;
			}
			else
			{
				Stations.push_back(&Station);
				std::cout << "Station added." << std::endl << std::endl;
			}
		}
	}
	else
	{
		Stations.push_back(&Station);
		std::cout << "Station added." << std::endl << std::endl;
	}
}

void SotnikovMetro::del()
{
	int k = 0;

	std::cout << "What station you want to delete? Enter ID (0 for exit): ";
	int ent_ID = getInt();
	std::cout << std::endl;

	if (ent_ID == 0)
		{
		return;
		}
	else
	{
		for (auto it = Stations.begin(); it != Stations.end(); it++)
		{
			SotnikovStation* next = *it;
			if (ent_ID == next->getID())
			{
				delete* it;
				Stations.erase(it);
				k++;
			}
		}
		std::string done_message = (k == 1) ? "Done." : "ID not found.";
		std::cout << done_message << std::endl;
	}
}

void SotnikovMetro::clr()
{
	for (auto it : Stations)
	{
		delete it;
	}
	Stations.clear();
}

void SotnikovMetro::save()
{
	if (Stations.empty())
	{
		std::cout << "Nothing to save." << std::endl << std::endl;
	}
	else
	{
		std::ofstream file;
		file.open(getFileName());
		
		if (file.good()) {
			for (auto it : Stations) {
				file << "STATION" << std::endl;
				file << *it;
			}
			
			file.close();
			std::cout << "Saved" << std::endl << std::endl;
		}
		else
		{
			std::cout << "Can't save the file." << std::endl << std::endl;
		}
	}
}

void SotnikovMetro::load()
{
	std::ifstream file;
	std::string str = getFileName();
	file.open(str, std::ios::in);

	if (file.good())
	{
		clr();
		while (!file.eof())
		{
			getline(file, str);
			if (str == "STATION") {
				SotnikovStation* s = new SotnikovStation();
				file >> *s;
				Stations.push_back(s);
			}
		}
		std::cout << "Loaded." << std::endl << std::endl;
	}
	else
	{
		std::cout << "Can't load from file." << std::endl << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const SotnikovMetro& Metro)
{
	
	
	if (!Metro.Stations.empty())
	{
		for (auto it : Metro.Stations)
		{
			out << *it << std::endl << std::endl;
		}
	}
	else
	{
		out << "Nothing found." << std::endl;
	}
	return out;
}
