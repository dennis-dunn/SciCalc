// SciCalc.h : main header file for the SCICALC application
//

#if !defined(AFX_SCICALC_H__9A0F40FE_238E_4291_8CA5_CCA2C56FC6A7__INCLUDED_)
#define AFX_SCICALC_H__9A0F40FE_238E_4291_8CA5_CCA2C56FC6A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSciCalcApp:
// See SciCalc.cpp for the implementation of this class
//

class CSciCalcApp : public CWinApp
{
public:
	CSciCalcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSciCalcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSciCalcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCICALC_H__9A0F40FE_238E_4291_8CA5_CCA2C56FC6A7__INCLUDED_)
