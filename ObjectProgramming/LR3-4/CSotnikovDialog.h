#pragma once
#include "Sotnikov3Doc.h"

// Диалоговое окно CSotnikovDialog

class CSotnikovDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CSotnikovDialog)

	

public:
	CSotnikovDialog(CSotnikov3Doc* pDC, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CSotnikovDialog();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CSotnikov3Doc* pDoc;

	CString s_id;
	CEdit e_id;
	CString s_name;
	CEdit e_name;
	CString s_line;
	CEdit e_line;
	CString s_category;
	CEdit e_category;

	CListBox listbox;
	
	virtual BOOL OnInitDialog();

	CButton add_station;
	CButton add_techStation;
	CButton delete_station;
	//CButton save;
	CButton modify_station;

	afx_msg void OnLbnSelchangeListbox();

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	//afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CStatic cText;
	CStatic idText;
	CStatic nameText;
	CStatic lineText;
};
