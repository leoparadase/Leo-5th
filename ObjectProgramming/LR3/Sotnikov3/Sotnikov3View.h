
// Sotnikov3View.h: интерфейс класса CSotnikov3View
//

#pragma once


class CSotnikov3View : public CScrollView
{
protected: // создать только из сериализации
	CSotnikov3View() noexcept;
	DECLARE_DYNCREATE(CSotnikov3View)

// Атрибуты
public:
	CSotnikov3Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора

// Реализация
public:
	virtual ~CSotnikov3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в Sotnikov3View.cpp
inline CSotnikov3Doc* CSotnikov3View::GetDocument() const
   { return reinterpret_cast<CSotnikov3Doc*>(m_pDocument); }
#endif

