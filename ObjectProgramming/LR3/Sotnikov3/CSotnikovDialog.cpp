// CSotnikovDialog.cpp: файл реализации
//

#include "pch.h"
#include "Sotnikov3.h"
#include "CSotnikovDialog.h"
#include "afxdialogex.h"


// Диалоговое окно CSotnikovDialog

IMPLEMENT_DYNAMIC(CSotnikovDialog, CDialogEx)

CSotnikovDialog::CSotnikovDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
{

}

CSotnikovDialog::~CSotnikovDialog()
{
}

void CSotnikovDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSotnikovDialog, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений CSotnikovDialog
