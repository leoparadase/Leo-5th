#include <iostream>
#include <fstream>
#include <string>
#include "LeoInfProtect1.h"
using namespace std;

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
    while (1)
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
    }
}
