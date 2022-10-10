#pragma once
#include "SotnikovChecks.h"
#include "SotnikovMetro.h"
#include "SotnikovStation.h"

using namespace std;

int main()
{
	SotnikovMetro MetroSys;

	while (1)
	{
		cout << "Welcome back! Choose the action: " << endl
			<< "1. Add new station" << endl
			<< "2. View all stations" << endl
			<< "3. Load from file" << endl
			<< "4. Save to file" << endl
			<< "5. Clear stations" << endl
			<< "0. Exit" << endl << endl;

		int choise = getInt(0, 6);

		cout << endl;

		switch (choise)
		{
		case 1:
		{
			SotnikovStation* Station = new SotnikovStation();
			MetroSys.add(*Station);
			break;
		}
		case 2:
		{
			cout << MetroSys;
			break;
		}
		case 3:
		{
			MetroSys.load();
			break;
		}
		case 4:
		{
			MetroSys.save();
			break;
		}
		case 5:
		{
			MetroSys.clr();
			cout << "Cleared." << endl << endl;
			break;
		}
		default:
		{
			return 0;
		}
		}
	}
}
