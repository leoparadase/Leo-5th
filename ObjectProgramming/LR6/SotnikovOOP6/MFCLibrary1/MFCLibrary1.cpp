// MFCLibrary1.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"
#include "framework.h"
#include "MFCLibrary1.h"
#include "SotnikovMetroSys.h"
#include "SotnikovStation.h"
#include "SotnikovTechStation.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CMFCLibrary1App

BEGIN_MESSAGE_MAP(CMFCLibrary1App, CWinApp)
END_MESSAGE_MAP()


// Создание CMFCLibrary1App

CMFCLibrary1App::CMFCLibrary1App()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMFCLibrary1App

CMFCLibrary1App theApp;


// Инициализация CMFCLibrary1App

BOOL CMFCLibrary1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

SotnikovMetroSys MetroSys;

extern "C"
{
	// ORIGIN FUNCTIONS

	_declspec(dllexport) void __stdcall Load_From_File(const char* szPath)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		MetroSys.LoadFromFile(szPath);
	}

	_declspec(dllexport) void __stdcall Save_To_File(const char* szPath)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		MetroSys.SaveToFile(szPath);
	}

	_declspec(dllexport) void __stdcall Clear()
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		MetroSys.ClearAll();
	}


	// GET - FUNCTIONS

	_declspec(dllexport) int __stdcall Get_Container_Size() {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return MetroSys.stations.size();
	}

	_declspec(dllexport) bool __stdcall Get_Element_Type(int index)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return static_pointer_cast<SotnikovTechStation>(MetroSys.stations[index])->category;
	}

	_declspec(dllexport) int __stdcall Get_Station_ID(int index)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return MetroSys.stations[index]->id;
	}

	_declspec(dllexport) void __stdcall Get_Station_Name(int index, char* str)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		strcpy(str, MetroSys.stations[index]->name);
	}

	_declspec(dllexport) int __stdcall Get_Station_Line(int index)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return MetroSys.stations[index]->line;
	}

	_declspec(dllexport) int __stdcall Get_Station_Category(int index)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		return static_pointer_cast<SotnikovTechStation>(MetroSys.stations[index])->category;
	}


	// CREATING OBJECTS

	_declspec(dllexport) void __stdcall Create_Station() {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		MetroSys.stations.push_back(make_shared<SotnikovStation>());
	}

	_declspec(dllexport) void __stdcall Create_Tech_Station() {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		MetroSys.stations.push_back(make_shared<SotnikovTechStation>());
	}


	// SET - FUNCTIONS

	_declspec(dllexport) void __stdcall Set_Station_ID(int index, int new_id)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		MetroSys.stations[index]->id = new_id;
	}

	_declspec(dllexport) void __stdcall Set_Station_Name(int index, char* new_name)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		MetroSys.stations[index]->name = new_name;
	}

	_declspec(dllexport) void __stdcall Set_Station_Line(int index, int new_line)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		MetroSys.stations[index]->line = new_line;
	}

	_declspec(dllexport) void __stdcall Set_Station_Category(int index, int new_category)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		static_pointer_cast<SotnikovTechStation>(MetroSys.stations[index])->category = new_category;
	}
}