// SciCalcDlg.h : header file
//

#if !defined(AFX_SCICALCDLG_H__D8FF78C0_E40D_4DDF_A6A2_F3347F86A1D7__INCLUDED_)
#define AFX_SCICALCDLG_H__D8FF78C0_E40D_4DDF_A6A2_F3347F86A1D7__INCLUDED_

#include "Help1Dlg.h"	// Added by ClassView
#include "OptionsDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSciCalcDlg dialog

class CSciCalcDlg : public CDialog
{
// Construction
public:
	CString m_strTemp;
	CStringArray m_strPrev;
	int m_iTPrev;	//total previous commands
	int m_iPrev;	//current previous string
	double PI;
	COptionsDlg m_OptionsDlg;
	int m_iAngle;
	void Erase(int here);
	CString m_strLast;
	CHelp1Dlg m_HelpDlg;
	double m_dVar[26];
	double m_dAns;
	void UpdateData(BOOL bCase);
	double m_dVer;
	int MoveRight(int here, int step=1);
	int MoveLeft(int here, int step=1);
	char m_strLine[150];
	char m_strLine2[150];
	double m_dVal[150];
	double Sub(int start);
	CString Solve(CString strEq);
	char R[3];
	int OnKey(CString);
	CSciCalcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSciCalcDlg)
	enum { IDD = IDD_SCICALC_DIALOG };
	CButton	m_ctlShift;
	CButton	m_ctlEquals;
	CButton	m_ctlDel;
	CButton	m_ctlCP;
	CButton	m_ctlOP;
	CButton	m_ctlInverse;
	CButton	m_ctlPI;
	CButton	m_ctlSubtract;
	CButton	m_ctlAdd;
	CButton	m_ctlDivide;
	CButton	m_ctlMult;
	CButton	m_ctlPower;
	CButton	m_ctlClearAll;
	CButton	m_ctlBack;
	CEdit	m_ctlConsole;
	CEdit	m_ctlCommand;
	CString	m_strCommand;
	CString	m_strConsole;
	BOOL	m_bShift;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSciCalcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSciCalcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void On1();
	afx_msg void On2();
	afx_msg void On3();
	afx_msg void On4();
	afx_msg void On5();
	afx_msg void On6();
	afx_msg void On7();
	afx_msg void On8();
	afx_msg void On9();
	afx_msg void On0();
	afx_msg void OnDecimal();
	afx_msg void OnAdd();
	afx_msg void OnMult();
	afx_msg void OnSubtract();
	afx_msg void OnDivide();
	afx_msg void OnClearall();
	afx_msg void OnBackspace();
	afx_msg void OnHelp1();
	afx_msg void OnSin();
	afx_msg void OnCos();
	afx_msg void OnTan();
	afx_msg void OnLog();
	afx_msg void OnOp();
	afx_msg void OnCp();
	afx_msg void OnPower();
	afx_msg void OnE();
	afx_msg void OnSQUARE();
	afx_msg void OnShift();
	afx_msg void OnCopy();
	afx_msg void OnX();
	afx_msg void OnEnter();
	afx_msg void OnEquals();
	afx_msg void OnLn();
	afx_msg void OnOptions();
	afx_msg void OnLast();
	afx_msg void OnInverse();
	afx_msg void OnAns();
	afx_msg void OnChangeConsole();
	afx_msg void OnDelete();
	afx_msg void OnChangeCommand();
	afx_msg void OnPaste();
	afx_msg void OnGraph();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCICALCDLG_H__D8FF78C0_E40D_4DDF_A6A2_F3347F86A1D7__INCLUDED_)
