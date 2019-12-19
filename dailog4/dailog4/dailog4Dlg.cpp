
// dailog4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "dailog4.h"
#include "dailog4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cdailog4Dlg dialog



Cdailog4Dlg::Cdailog4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cdailog4Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cdailog4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAME, edit_name);
	DDX_Control(pDX, IDC_EDIT_BIRTH, edit_birth);
	DDX_Control(pDX, IDC_COMBO_SEX, combo_sex);
	DDX_Control(pDX, IDC_EDIT_PHONE_NUMBER, edit_phone_number);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, edit_address);
	DDX_Control(pDX, IDC_LIST_INFOR, list_infor_);
}

BEGIN_MESSAGE_MAP(Cdailog4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &Cdailog4Dlg::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// Cdailog4Dlg message handlers

BOOL Cdailog4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	combo_sex.AddString(_T("Male"));
	combo_sex.AddString(_T("Female"));
	combo_sex.SetCurSel(0);

	// set line style
	list_infor_.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// set ten cho cot
	list_infor_.InsertColumn(0,_T("éÅñº"),LVCFMT_LEFT,150);
	list_infor_.InsertColumn(1,_T("ê∂îNåéì˙"),LVCFMT_LEFT,80);
	list_infor_.InsertColumn(2,_T("ê´ï "),LVCFMT_LEFT,80);
	list_infor_.InsertColumn(3,_T("ågë—ìdòb"),LVCFMT_LEFT,100);
	list_infor_.InsertColumn(4,_T("èZèä"),LVCFMT_LEFT,400);

	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cdailog4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cdailog4Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cdailog4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cdailog4Dlg::OnBnClickedButtonAdd()
{
	UpdateData(TRUE);
	
	CString student_name;
	edit_name.GetWindowTextW(student_name);

	CString student_birth;
	edit_birth.GetWindowTextW(student_birth);

	CString student_sex;
	int curren_sex = combo_sex.GetCurSel();
	combo_sex.GetLBText(curren_sex,student_sex);

	CString student_phone_number;
	edit_phone_number.GetWindowTextW(student_phone_number);

	CString student_address;
	edit_address.GetWindowTextW(student_address);

	list_infor_.InsertItem(0,student_name);
	list_infor_.SetItemText(0,1,student_birth);
	list_infor_.SetItemText(0,2,student_sex);
	list_infor_.SetItemText(0,3,student_phone_number);
	list_infor_.SetItemText(0,4,student_address);

	UpdateData(FALSE);


}
