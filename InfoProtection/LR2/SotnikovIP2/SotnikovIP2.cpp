#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm> 

using namespace std;


bool cmp(pair<char, int>& a, pair<char, int>& b)
{
	return a.second > b.second;
}

vector<pair<char, int>> sort(multimap<char, int> M)
{
	vector<pair<char, int>> A;

	for (auto it : M)
	{
		A.push_back(it);
	}

	sort(A.begin(), A.end(), cmp);

	return A;
}

vector<pair<char, int>> frequency_letters(vector<char> text)
{
	multimap<char, int> lettersCodes;
	multimap<char, int> lettersFreqs;
	int freq;

	for (auto i : text)
		lettersCodes.insert(pair<char, int>(i, (int)i));
	for (int i = -128; i <= 127; i++) {
		freq = lettersCodes.count(i);
		if (freq != 0)
			lettersFreqs.insert(pair<char, int>(i, freq));
	}

	//sort(lettersFreqs.begin(), lettersFreqs.end(), [](const pair<char, float>& p1, const pair<char, float>& p2) {return p1.second < p2.second; });
	
	vector<pair<char, int>> sorted = sort(lettersFreqs);

	return sorted;
}

float indexS(vector<char> text) 
{
	multimap<char, int> lettersCodes;
	multimap<char, int> lettersFreqs;
	int freq;

	for (auto i : text)
		lettersCodes.insert(pair<char, int>(i, (int)i));
	for (int i = 0; i <= 255; i++) {
		freq = lettersCodes.count(i);
		if (freq != 0)
			lettersFreqs.insert(pair<char, int>(i, freq));
	}

	float index = 0;
	int N = text.size();

	for (auto fi : lettersFreqs) {
		index += fi.second * (fi.second - 1);
	}

	return index / (N * (N - 1));
}

void standard_analysis()
{
	// Reading from the file

	string filename;
	cout << "Enter file's name: ";
	cin >> filename;
	ifstream fin(filename, ios::binary);
	vector<char> text((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	fin.close();

	// Calculating parameters

	float index = indexS(text);
	vector<pair<char, int>> freqLetters = frequency_letters(text);

	// Output

	cout << "Standard's analysis: " << endl << endl
		<< "Index: " << index << endl << endl
		<< "Most frequent letters: " << endl;

	int i = 0;

	for (auto it : freqLetters) 
	{
		cout << it.first << " (Probability: " << (float(it.second) / float(text.size())) << ")" << endl;

		i++;
		if (i == 5)
		{
			cout << endl;
			break;
		}
	}
}

vector<char> readiSymbol(int i, vector<char> text)
{
	vector<char> readedText;
	int flag = 1;

	for (auto it : text)
	{
		if (flag == i)
		{
			readedText.push_back(it);
			flag = 1;
		}
		else
		{
			flag++;
		}
	}

	return readedText;
}

void encoded_moves() 
{
	// Reading from the file

	string filename;
	cout << "Enter file's name: ";
	cin >> filename;
	ifstream fin(filename, ios::binary);
	vector<char> text((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	fin.close();

	multimap<int, float> indexesS;
	multimap<int, char> mostFrequentLetters;

	// Indexes and most frequent letters

	for (int i = 1; i != 26; i++)
	{
		vector<char> readedText = readiSymbol(i, text);
		float index = indexS(readedText);
		char mostFreq = frequency_letters(readedText).begin()->first;

		indexesS.insert(pair<int, float>(i, index));
		mostFrequentLetters.insert(pair<int, char>(i, mostFreq));
	}

	// Prediction

	/*int prediction = 0;
	
	for (auto it = indexesS.find(2); it != indexesS.end(); it++)
	{
		auto it_test = indexesS.find(1);
		auto it_test2 = indexesS.find(3);
		
		if ((it->second > (it_test->second)) && (prediction == 0) && (it->second > (it_test2->second)))
		{
			int prediction = it->first;
			break;
		}

		it_test++;
	}*/

	// Output

	cout << "Indexes: " << endl << endl;

	for (auto it : indexesS) cout << "Group " << it.first << ": " << it.second << endl;

	cout << endl <<  "Enter key length: ";

	int prediction;
	cin >> prediction;
	cout << endl << endl;

	//-----------------TRY TO GUESS KEY WORD-------------------------------
	string guessedWord;

	for (int i = 1; i < prediction + 1; ++i)
	{
		vector<int> freq = {};
		for (int j = 0; j < 256; ++j)
		{
			int temp = 0;
			for (int k = 0; (i - 1) + k * prediction < text.size(); ++k)
			{
				char t = char(j);
				if (text[(i - 1) + k * prediction] == t)
					temp++;
			}
			freq.push_back(temp);
		}
		int max = *max_element(freq.begin(), freq.end());
		auto freq_symbol = find(freq.begin(), freq.end(), max);
		int index = std::distance(freq.begin(), freq_symbol);
		guessedWord = guessedWord + char(index - 32);
	}
	cout << "Guessed word: " << guessedWord << endl << endl;
	//-----------------------------------------------------------------------------
	// Decryption

	ifstream fin2(filename, ios::binary);
	ofstream fout2(filename + "_decoded.txt", ios::binary);

	char i, o;
	int k = 0;

	while (fin2.get(i))
	{
		o = i - guessedWord[k % guessedWord.size()];
		fout2 << o;
		k++;
		break;
	}

	fin2.close();
	fout2.close();

	cout << "Done." << endl << endl;
}

void Something(std::ifstream& inputFile, std::string& inputFileName, std::ofstream& outputFile, std::string& outputFileName, char& i, int a, char& o, std::string& keyword, int& k)
{
	inputFile.open(inputFileName, ios::binary);
	outputFile.open(outputFileName, ios::binary);

	if (inputFile.good())
	{
		while (inputFile.get(i))
		{
			switch (a)
			{
			case 1:
			{
				o = i + keyword[k % keyword.size()];
				outputFile << o;
				k++;
				break;
			}
			case 2:
			{
				o = i - keyword[k % keyword.size()];
				outputFile << o;
				k++;
				break;
			}
			}
		}
		cout << "Done." << endl << endl;
	}
	else
	{
		cout << "Can't load from file." << endl << endl;
	}
}

void NamesFilling(std::string& inputFileName, std::string& outputFileName, std::string& keyword)
{
	cout << "Enter input file's name: ";
	cin >> inputFileName;
	cout << endl;

	cout << "Enter output file's name: ";
	cin >> outputFileName;
	cout << endl;

	cout << "Enter keyword: ";
	cin >> keyword;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	
	while (1) 
	{
		cout << "Choose the action: " << endl << endl
			<< "1. Standard's analysis" << endl
			<< "2. Analysis & guessing keyword" << endl
			<< "3. Encoding & decoding" << endl
			<< "0. Exit" << endl;

		int choose;
		cin >> choose;

		cout << endl << endl;

		switch (choose) 
		{
		case 1: 
		{
			standard_analysis();
			break;
		}
		case 2: 
		{
			encoded_moves();
			break;
		}
		case 3:
		{
			string inputFileName;
			string outputFileName;
			string keyword;
			ifstream inputFile;
			ofstream outputFile;
			char i, o;
			int a;
			int k = 0;

			cout << "What to do?" << endl
				<< "1. Encode" << endl
				<< "2. Decode" << endl
				<< "0. Exit" << endl;
			cin >> a;
			if (a == 0) break;
			cout << endl;

			NamesFilling(inputFileName, outputFileName, keyword);

			Something(inputFile, inputFileName, outputFile, outputFileName, i, a, o, keyword, k);
			break;
		}
		case 0: 
		{
			return 0;
			break;
		}
		default: 
		{
			cout << "Try again." << endl << endl;
			break;
		}
		}
	}

}