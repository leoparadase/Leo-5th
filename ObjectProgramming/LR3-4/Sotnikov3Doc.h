
// Sotnikov3Doc.h: интерфейс класса CSotnikov3Doc 
//


#pragma once
#include "SotnikovMetroSys.h"

class CSotnikov3Doc : public CDocument
{
protected: // создать только из сериализации
	CSotnikov3Doc() noexcept;
	DECLARE_DYNCREATE(CSotnikov3Doc)

// Атрибуты
public:
	SotnikovMetroSys MetroSys;
	void Add(CSotnikovDialog* dlg, int typeFlag);
	void Modify(CSotnikovDialog* dlg, int pos);
// Операции
public:
	
// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSotnikov3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnEditDialog();
};
