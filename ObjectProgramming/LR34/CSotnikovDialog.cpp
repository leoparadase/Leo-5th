// CSotnikovDialog.cpp: файл реализации
//

#include "pch.h"
#include "Sotnikov3.h"
#include "CSotnikovDialog.h"
#include "afxdialogex.h"


// Диалоговое окно CSotnikovDialog

IMPLEMENT_DYNAMIC(CSotnikovDialog, CDialogEx)

CSotnikovDialog::CSotnikovDialog(CSotnikov3Doc* pDC, CWnd* pParent)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, s_id(_T(""))
	, s_name(_T(""))
	, s_line(_T(""))
	, s_category(_T(""))
{
	pDoc = pDC;
}

CSotnikovDialog::~CSotnikovDialog()
{
}

void CSotnikovDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, add_station);
	DDX_Control(pDX, IDC_BUTTON2, add_techStation);
	DDX_Control(pDX, IDC_BUTTON3, delete_station);
	//DDX_Control(pDX, IDC_BUTTON4, save);
	DDX_Control(pDX, IDC_BUTTON5, modify_station);

	DDX_Text(pDX, IDC_EDIT1, s_id);
	DDX_Control(pDX, IDC_EDIT1, e_id);

	DDX_Text(pDX, IDC_EDIT2, s_name);
	DDX_Control(pDX, IDC_EDIT2, e_name);

	DDX_Text(pDX, IDC_EDIT3, s_line);
	DDX_Control(pDX, IDC_EDIT3, e_line);

	DDX_Text(pDX, IDC_EDIT4, s_category);
	DDX_Control(pDX, IDC_EDIT4, e_category);

	DDX_Control(pDX, IDC_LISTBOX, listbox);

	DDX_Control(pDX, IDC_X4, cText);
	DDX_Control(pDX, IDC_X1, idText);
	DDX_Control(pDX, IDC_X2, nameText);
	DDX_Control(pDX, IDC_X3, lineText);
}


BEGIN_MESSAGE_MAP(CSotnikovDialog, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LISTBOX, &CSotnikovDialog::OnLbnSelchangeListbox)
	ON_BN_CLICKED(IDC_BUTTON1, &CSotnikovDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSotnikovDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSotnikovDialog::OnBnClickedButton3)
	//ON_BN_CLICKED(IDC_BUTTON4, &CSotnikovDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CSotnikovDialog::OnBnClickedButton5)
END_MESSAGE_MAP()


// Обработчики сообщений CSotnikovDialog


void CSotnikovDialog::OnLbnSelchangeListbox()
{
	s_id = "";
	s_name = "";
	s_line = "";
	s_category = "";
	
	int pos = listbox.GetCurSel();
	auto P = pDoc->MetroSys.stations[pos];
	P->ReturnValues(this);
	UpdateData(false);

	if (listbox.GetCurSel() >= 0)
		delete_station.EnableWindow(true);

	if (GetDlgItemText(IDC_EDIT4, s_category) != NULL)
	{
		idText.ShowWindow(SW_SHOW);
		e_id.ShowWindow(SW_SHOW);

		nameText.ShowWindow(SW_SHOW);
		e_name.ShowWindow(SW_SHOW);

		lineText.ShowWindow(SW_SHOW);
		e_line.ShowWindow(SW_SHOW);

		e_category.ShowWindow(SW_SHOW);
		cText.ShowWindow(SW_SHOW);
	}
	else
	{
		idText.ShowWindow(SW_SHOW);
		e_id.ShowWindow(SW_SHOW);

		nameText.ShowWindow(SW_SHOW);
		e_name.ShowWindow(SW_SHOW);

		lineText.ShowWindow(SW_SHOW);
		e_line.ShowWindow(SW_SHOW);

		e_category.ShowWindow(SW_HIDE);
		cText.ShowWindow(SW_HIDE);
	}
}


BOOL CSotnikovDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	for_each(pDoc->MetroSys.stations.begin(), pDoc->MetroSys.stations.end(), [&](shared_ptr<SotnikovStation> id_)
		{
			CString s = to_string(id_->id).c_str();
			listbox.AddString(s);
		});

	listbox.SetCurSel(pDoc->MetroSys.stations.size() - 1);

	return TRUE;
}


int typeFlag;


void CSotnikovDialog::OnBnClickedButton1() // SotnikovStation
{
	typeFlag = 0;

	e_category.ShowWindow(SW_HIDE);
	cText.ShowWindow(SW_HIDE);

	s_id = "0";
	s_name = "0";
	s_line = "0";
	UpdateData(false);

	pDoc->Add(this, typeFlag);
	CString s = to_string(pDoc->MetroSys.stations[pDoc->MetroSys.stations.size() - 1]->id).c_str();
	listbox.AddString(s);
	listbox.SetCurSel(pDoc->MetroSys.stations.size() - 1);
	OnLbnSelchangeListbox();
}


void CSotnikovDialog::OnBnClickedButton2() // SotnikovTechStation
{
	typeFlag = 1;

	e_category.ShowWindow(SW_SHOW);
	cText.ShowWindow(SW_SHOW);

	s_id = "0";
	s_name = "0";
	s_line = "0";
	s_category = "0";
	UpdateData(false);

	pDoc->Add(this, typeFlag);
	CString s = to_string(pDoc->MetroSys.stations[pDoc->MetroSys.stations.size() - 1]->id).c_str();
	listbox.AddString(s);
	listbox.SetCurSel(pDoc->MetroSys.stations.size() - 1);
	OnLbnSelchangeListbox();
}


void CSotnikovDialog::OnBnClickedButton3() // Delete
{
	int pos = listbox.GetCurSel();

	for (int i = pos; i < pDoc->MetroSys.stations.size() - 1; i++)
		pDoc->MetroSys.stations[i] = pDoc->MetroSys.stations[i + 1];

	pDoc->MetroSys.stations.pop_back();
	listbox.DeleteString(pos);

	if (pos < pDoc->MetroSys.stations.size())
		listbox.SetCurSel(pos);
	else
		listbox.SetCurSel(pos - 1);

	if (listbox.GetCurSel() == -1)
	{
		s_id.Empty();
		s_name.Empty();
		s_line.Empty();
		s_category.Empty();
	}
	else
		OnLbnSelchangeListbox();

	UpdateData(false);
}

void CSotnikovDialog::OnBnClickedButton5() // Change
{
	UpdateData(true);
	pDoc->Modify(this, listbox.GetCurSel());
	UpdateData(false);
	
	for (int pos = pDoc->MetroSys.stations.size() - 1; pos >= 0 ; pos--)
	{
		listbox.DeleteString(pos);
	}

	OnInitDialog();
}
