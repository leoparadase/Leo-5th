
// Sotnikov3View.cpp: реализация класса CSotnikov3View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Sotnikov3.h"
#endif

#include "Sotnikov3Doc.h"
#include "Sotnikov3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSotnikov3View

IMPLEMENT_DYNCREATE(CSotnikov3View, CScrollView)

BEGIN_MESSAGE_MAP(CSotnikov3View, CScrollView)
	ON_COMMAND(ID_EDIT_DIALOG, &CSotnikov3View::OnEditDialog)
END_MESSAGE_MAP()

// Создание или уничтожение CSotnikov3View

CSotnikov3View::CSotnikov3View() noexcept
{
	// TODO: добавьте код создания

}

CSotnikov3View::~CSotnikov3View()
{
}

BOOL CSotnikov3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CSotnikov3View

void CSotnikov3View::OnDraw(CDC* pDC)
{
	CSotnikov3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	int h = 0;
	int w = 0;
	pDoc->MetroSys.ViewWrite(pDC, h, w);

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	CSize sizeTotal;
	sizeTotal.cx = w * tm.tmAveCharWidth;
	sizeTotal.cy = h;
	SetScrollSizes(MM_TEXT, sizeTotal);
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


void CSotnikov3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика CSotnikov3View

#ifdef _DEBUG
void CSotnikov3View::AssertValid() const
{
	CScrollView::AssertValid();
}
 
void CSotnikov3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CSotnikov3Doc* CSotnikov3View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSotnikov3Doc)));
	return (CSotnikov3Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CSotnikov3View


void CSotnikov3View::OnEditDialog()
{
	CSotnikovDialog EditDialog(GetDocument());
	EditDialog.DoModal();
	Invalidate();
}
