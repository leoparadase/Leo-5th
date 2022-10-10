#pragma once
#include "SotnikovStation.h"

void SotnikovStation::edit()
{
    std::cout << "Editing station No. " << getID() << " (" << name << ") " << std::endl;
    std::cout << std::endl << "What you want to change?" << std::endl
        << "1. Name" << std::endl
        << "2. Line" << std::endl
        << "0. Back to home" << std::endl << std::endl;

    int choise = getInt(0, 2);

    switch (choise)
    {
    case 1:
        {
            std::cout << "New name: ";
            name = getString();
            break;
        }
    case 2:
        {
            std::cout << "Line: ";
            line = getInt();
            break;
        }
    default:
        {
            break;
        }
    }

    std::cout << "Done." << std::endl << std::endl;

}

void SotnikovStation::editID()
{
    id = getInt(1);
}

int SotnikovStation::getID()
{
    return id;
}

void SotnikovStation::enterID(int num)
{
    id = num;
}


std::istream& operator>>(std::istream& out, SotnikovStation& Station)
{
    std::cout << "Ready to read station properties." << std::endl;

    std::cout << "ID: ";
    Station.editID();

    std::cout << "Name: ";
    Station.name = getString();

    std::cout << "Line: ";
    Station.line = getInt();

    std::cout << "Depth: ";
    Station.depth = getInt(0, 200);

    std::cout << std::endl;

    return out;
}

std::ostream& operator<<(std::ostream& out, const SotnikovStation& Station)
{
    out << "ID: " << Station.id << std::endl
        << "Name: " << Station.name << std::endl
        << "Line: " << Station.line << std::endl
        << "Depth: " << Station.depth
        << std::endl;

    return out;
}

std::ifstream& operator>>(std::ifstream& out, SotnikovStation& Station)
{
    std::string value;

    getline(out, value);
    //Station.enterID(stoi(value));
    Station.id = stoi(value);

    getline(out, value);
    Station.name = value;

    getline(out, value);
    Station.line = stoi(value);

    getline(out, value);
    Station.depth = stoi(value);

    return out;
}

std::ofstream& operator<<(std::ofstream& out, const SotnikovStation& Station)
{
    out << Station.id << std::endl
        << Station.name << std::endl
        << Station.line << std::endl
        << Station.depth << std::endl << std::endl;

    return out;
}
