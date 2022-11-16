
// Sotnikov3.h: основной файл заголовка для приложения Sotnikov3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CSotnikov3App:
// Сведения о реализации этого класса: Sotnikov3.cpp
//

class CSotnikov3App : public CWinApp
{
public:
	CSotnikov3App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSotnikov3App theApp;
