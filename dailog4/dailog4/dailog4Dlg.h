
// dailog4Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// Cdailog4Dlg dialog
class Cdailog4Dlg : public CDialogEx
{
// Construction
public:
	Cdailog4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DAILOG4_DIALOG };

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
	CEdit edit_name;
	CEdit edit_birth;
	CComboBox combo_sex;
	CEdit edit_phone_number;
	CEdit edit_address;
	CListCtrl list_infor_;
public:
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnLvnItemchangedListInfor(NMHDR *pNMHDR, LRESULT *pResult);
};
