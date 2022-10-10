// Sotnikov2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "framework.h"
#include "Sotnikov2.h"
#include "SotnikovMetroSys.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Единственный объект приложения
//CWinApp theApp;

using namespace std;


void Menu()
{
    cout << "Welcome back! Choose the action: " << endl
        << "1. Add station" << endl
        << "2. Show stations" << endl
        << "3. Load from file" << endl
        << "4. Save to file" << endl
        << "5. Clear stations" << endl
        << "0. Exit" << endl;
}

void Actions()
{
    int choose;
    SotnikovMetroSys st;

    while (1)
    {
        Menu();
        cin >> choose;
        cout << endl << endl;

        switch (choose)
        {
        case 1:
        {
            st.c_read();
            break;
        }
        case 2:
        {
            st.c_write();
            break;
        }
        case 3:
        {
            st.f_read();
            break;
        }
        case 4:
        {
            st.f_write();
            break;
        }
        case 5:
        {
            st.clr();
            break;
        }
        case 0:
        {
            return;
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

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // инициализировать MFC, а также печать и сообщения об ошибках про сбое
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: вставьте сюда код для приложения.
            wprintf(L"Критическая ошибка: сбой при инициализации MFC\n");
            nRetCode = 1;
        }
        else
        {
            Actions(); // TODO: вставьте сюда код для приложения.
        }
    }
    else
    {
        // TODO: измените код ошибки в соответствии с потребностями
        wprintf(L"Критическая ошибка: сбой GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
