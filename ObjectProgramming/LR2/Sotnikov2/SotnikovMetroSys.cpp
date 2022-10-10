#include "pch.h"
#include "SotnikovMetroSys.h"

SotnikovMetroSys::SotnikovMetroSys()
{
}

SotnikovMetroSys::~SotnikovMetroSys()
{
	clr();
}

void SotnikovMetroSys::c_read()
{
	shared_ptr<SotnikovStation> temp;
	
	cout << "What to add?" << endl
		<< "1. Station" << endl
		<< "2. Tech Station" << endl;

	int choise;
	cin >> choise;
	cout << endl << endl;

	switch (choise)
	{
	case 1:
	{
		temp = make_shared<SotnikovStation>();
		break;
	}
	case 2:
	{
		temp = make_shared<SotnikovTechStation>();
		break;
	}
	}

	(*temp).c_in();

	// ID check temp -> id
	int k = 0;

	for (auto test : stations)
	{
		if (test->id == temp->id)
		{
			k++;
		}
	}

	if (k > 0)
	{
		cout << "Not unique ID. Try again." << endl << endl;
	}
	else
	{
		stations.push_back(temp);
		cout << endl << "Added." << endl << endl;
	}
}

void SotnikovMetroSys::c_write()
{
	if (!stations.empty())
	{
		cout << "List of stations: " << endl << endl;
		
		for (auto i = stations.begin(); i < stations.end(); ++i)
		{
			(*i)->c_out();
			cout << endl << endl;
		}
	}
	else
		cout << "No stations." << endl << endl;
}

void SotnikovMetroSys::f_read()
{
	stations.clear();
	
	string temp;

	cout << "Enter file's name: ";
	cin >> temp;

	CFile file((LPCTSTR)(temp.c_str()), CFile::modeRead);
	CArchive f(&file, CArchive::load);
	int count, n;

	f >> count;
	f >> n;

	for (int i = 0; i < count; i++)
	{
		SotnikovStation* temp = new SotnikovStation;
		f >> temp;
		shared_ptr<SotnikovStation> s(temp);
		stations.push_back(s);
	}

	f.Close();
	file.Close();
	cout << "Loaded." << endl << endl;
}

void SotnikovMetroSys::f_write()
{
	string temp;

	cout << "Enter file's name: ";
	cin >> temp;

	CFile file((LPCTSTR)(temp.c_str()), CFile::modeCreate | CFile::modeWrite);
	CArchive f(&file, CArchive::store);

	f << stations.size();

	for (auto it : stations)
	{
		f << it.get();
	}
	f.Close();
	file.Close();
	cout << "Saved." << endl << endl;
}

void SotnikovMetroSys::clr()
{
	//for (auto it : stations)
	//	*it;
	stations.clear();
	cout << "Cleared." << endl << endl;
}
