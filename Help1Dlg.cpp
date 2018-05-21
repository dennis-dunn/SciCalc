// Help1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "SciCalc.h"
#include "Help1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelp1Dlg dialog


CHelp1Dlg::CHelp1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelp1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelp1Dlg)
	m_strText = _T("");
	//}}AFX_DATA_INIT
}


void CHelp1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelp1Dlg)
	DDX_Text(pDX, IDC_TEXT, m_strText);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelp1Dlg, CDialog)
	//{{AFX_MSG_MAP(CHelp1Dlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelp1Dlg message handlers

BOOL CHelp1Dlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CFile iniFile;	
	if(iniFile.Open("Help.txt",CFile::modeNoTruncate|CFile::modeRead|CFile::typeText))
	{
		char ch;
		int iLen = iniFile.GetLength();
		if(iLen == 0) return TRUE;

		CArchive* ar = new CArchive(&iniFile,CArchive::load);

		for(int i = 0;i < iLen;i++)
		{
			*ar >> ch;
			m_strText += ch;
		}
		delete ar;		
		iniFile.Close();
	}
	else
	{
		
		m_strText = "Help.txt file is missing, to read the Help file email me\nor run SciCalc with all of the files included in the same folder.";
		MessageBox(m_strText);
	}
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
