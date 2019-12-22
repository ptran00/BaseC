
// dailog_loginDlg.h : header file
//

#pragma once
#include "afxwin.h"


// Cdailog_loginDlg dialog
class Cdailog_loginDlg : public CDialogEx
{
// Construction
public:
	Cdailog_loginDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DAILOG_LOGIN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
protected:
	CEdit edit_user_name;
	CEdit edit_password;
};
