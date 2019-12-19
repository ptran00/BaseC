
// login_dailog.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clogin_dailogApp:
// See login_dailog.cpp for the implementation of this class
//

class Clogin_dailogApp : public CWinApp
{
public:
	Clogin_dailogApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Clogin_dailogApp theApp;