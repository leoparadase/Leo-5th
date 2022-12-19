// MFCLibrary1.h: основной файл заголовка для библиотеки DLL MFCLibrary1
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCLibrary1App
// Реализацию этого класса см. в файле MFCLibrary1.cpp
//

class CMFCLibrary1App : public CWinApp
{
public:
	CMFCLibrary1App();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
