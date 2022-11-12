#pragma once


// Диалоговое окно CSotnikovDialog

class CSotnikovDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSotnikovDialog)

public:
	CSotnikovDialog(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CSotnikovDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
