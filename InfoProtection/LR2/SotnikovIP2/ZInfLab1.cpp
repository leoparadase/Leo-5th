// ASCII (extended) - 256 symbols
// n(t) + n(key) mod 256
// char -128...127
// unsigned char 0...255
// Если использовать ограниченные типы данных, не нужно искать остаток от деления
// Запросить файл, запросить ключ, задать имя результирующего файла
// чтение/запись в режиме binary

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string StringInput()
{
	while (1)
	{

		string in;
		cin >> ws;
		getline(cin, in);
		return in;
	}
}

void PetrovEncode(ifstream& Inputfile, ofstream& Outputfile, string& key, char& l1, char& l2)
{
	if ((Inputfile.good()) and (Outputfile.good()))
	{
		int k = 0;
		while (Inputfile.get(l1))
		{
			l2 = char(int(l1) + int(key[k % key.size()]));
			Outputfile << l2;
			k++;
		}
	}
}

void PetrovDecode(ifstream& Inputfile, ofstream& Outputfile, string& key, char& l1, char& l2)
{
	if ((Inputfile.good()) and (Outputfile.good()))
	{
		int k = 0;
		while (Inputfile.get(l1))
		{
			l2 = char(int(l1) - int(key[k % key.size()]));
			Outputfile << l2;
			k++;
		}
	}
}

void PetrovDecypherKey(ifstream& InputFile)
{
	vector<char> v((istreambuf_iterator<char>(InputFile)), istreambuf_iterator<char>());
	float indexes[30] = {};
	for (int i = 1; i < 31; ++i)
	{
		float a = round(v.size() / i);
		float index = 0;
		for (int ii = 0; ii < 256; ++ii)
		{
			float temp = 0;
			for (int iii = 0; iii * i < v.size(); ++iii)
			{
				char t = char(ii);
				if (v[iii * i] == t)
					temp++;
			}
			index += (temp * (temp - 1)) / (a * (a - 1));
		}
		cout << "Groups: " << i << "; Index: " << index << endl;
		indexes[i - 1] = index;
	}
	int assum = 0;
	for (int i = 1; i < 29; i++)
	{
		if (indexes[i] > (indexes[i - 1] + indexes[i + 1]))
		{
			assum = i + 1;
			break;
		}
	}
	int a;
	cout << "Use assumption " << assum << " ? 0 - Yes; 1 - No." << endl;
	cin >> a;
	if (!cin.fail() and !cin.peek() != '\n')
	{
		if (a == 1)
		{
			cout << "Input number of groups: " << endl;
			if (!cin.fail() and !cin.peek() != '\n')
			{
				cin >> assum;
			}
		}
		cout << "Key: ";
		for (int i = 1; i < assum + 1; ++i)
		{
			vector<int> freq = {};
			for (int ii = 0; ii < 256; ++ii)
			{
				int temp = 0;
				for (int iii = 0; (i - 1) + iii * assum < v.size(); ++iii)
				{
					char t = char(ii);
					if (v[(i - 1) + iii * assum] == t)
						temp++;
				}
				freq.push_back(temp);
			}
			int max = *max_element(freq.begin(), freq.end());
			auto freq_symbol = find(freq.begin(), freq.end(), max);
			int index = std::distance(freq.begin(), freq_symbol);
			cout << char(index - 32);
		}
		cout << endl;
	}
}

int main()
{
	int a;
	string Inputname, Outputname;
	string key;
	char l1, l2;
	ifstream Inputfile;
	ofstream Outputfile;
	while (1)
	{
		cout << "Select operation: 0 - Exit, 1 - Encode, 2 - Decode, 3 - Decypher." << endl;
		cin >> a;
		if (!cin.fail() and !cin.peek() != '\n')
		{
			switch (a)
			{
			case 0:
			{
				return 0;
				break;
			}
			case 1:
			{
				cout << "Input original file name:" << endl;
				Inputname = StringInput();
				cout << "Input result file name:" << endl;
				Outputname = StringInput();
				cout << "Input key:" << endl;
				key = StringInput();
				Inputfile.open(Inputname, ios::binary);
				Outputfile.open(Outputname, ios::binary);
				PetrovEncode(Inputfile, Outputfile, key, l1, l2);
				Inputfile.close();
				Outputfile.close();
				break;
			}
			case 2:
			{
				cout << "Input original file name:" << endl;
				Inputname = StringInput();
				cout << "Input result file name:" << endl;
				Outputname = StringInput();
				cout << "Input key:" << endl;
				key = StringInput();
				Inputfile.open(Inputname, ios::binary);
				Outputfile.open(Outputname, ios::binary);
				PetrovDecode(Inputfile, Outputfile, key, l1, l2);
				Inputfile.close();
				Outputfile.close();
				break;
			}
			case 3:
			{
				cout << "Input encoded file name:" << endl;
				Inputname = StringInput();
				ifstream in(Inputname, ios::binary);
				int assum = 0;
				PetrovDecypherKey(in);
			}
			}
		}
	}
}
