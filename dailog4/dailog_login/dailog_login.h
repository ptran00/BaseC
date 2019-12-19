
// dailog_login.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cdailog_loginApp:
// See dailog_login.cpp for the implementation of this class
//

class Cdailog_loginApp : public CWinApp
{
public:
	Cdailog_loginApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cdailog_loginApp theApp;