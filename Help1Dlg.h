#if !defined(AFX_HELP1DLG_H__ECBFF4E0_6B5E_49F8_8FC3_C932352F3C53__INCLUDED_)
#define AFX_HELP1DLG_H__ECBFF4E0_6B5E_49F8_8FC3_C932352F3C53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Help1Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHelp1Dlg dialog

class CHelp1Dlg : public CDialog
{
// Construction
public:
	char R[3];
	CHelp1Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHelp1Dlg)
	enum { IDD = IDD_HELP };
	CString	m_strText;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHelp1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHelp1Dlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELP1DLG_H__ECBFF4E0_6B5E_49F8_8FC3_C932352F3C53__INCLUDED_)
