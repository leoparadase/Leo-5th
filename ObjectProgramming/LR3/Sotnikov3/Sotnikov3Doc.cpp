
// Sotnikov3Doc.cpp: реализация класса CSotnikov3Doc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Sotnikov3.h"
#endif

#include "Sotnikov3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSotnikov3Doc

IMPLEMENT_DYNCREATE(CSotnikov3Doc, CDocument)

BEGIN_MESSAGE_MAP(CSotnikov3Doc, CDocument)
	ON_COMMAND(ID_EDIT_DIALOG, &CSotnikov3Doc::OnEditDialog)
END_MESSAGE_MAP()


// Создание или уничтожение CSotnikov3Doc

CSotnikov3Doc::CSotnikov3Doc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CSotnikov3Doc::~CSotnikov3Doc()
{
}

BOOL CSotnikov3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)

	return TRUE;
}




// Сериализация CSotnikov3Doc

void CSotnikov3Doc::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		MetroSys.SaveToFile(archive);
	}
	else
	{
		MetroSys.LoadFromFile(archive);
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CSotnikov3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CSotnikov3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CSotnikov3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CSotnikov3Doc

#ifdef _DEBUG
void CSotnikov3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSotnikov3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CSotnikov3Doc



void CSotnikov3Doc::OnEditDialog()
{
	// TODO: добавьте свой код обработчика команд
}
