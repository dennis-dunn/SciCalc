// SciCalcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SciCalc.h"
#include "SciCalcDlg.h"
#include "Math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSciCalcDlg dialog

CSciCalcDlg::CSciCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSciCalcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSciCalcDlg)
	m_strConsole = _T("");
	m_bShift = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSciCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSciCalcDlg)
	DDX_Control(pDX, IDC_SHIFT, m_ctlShift);
	DDX_Control(pDX, IDC_EQUALS, m_ctlEquals);
	DDX_Control(pDX, IDC_DELETE, m_ctlDel);
	DDX_Control(pDX, IDC_CP, m_ctlCP);
	DDX_Control(pDX, IDC_OP, m_ctlOP);
	DDX_Control(pDX, IDC_INVERSE, m_ctlInverse);
	DDX_Control(pDX, IDC_E, m_ctlPI);
	DDX_Control(pDX, IDC_SUBTRACT, m_ctlSubtract);
	DDX_Control(pDX, IDC_ADD, m_ctlAdd);
	DDX_Control(pDX, IDC_DIVIDE, m_ctlDivide);
	DDX_Control(pDX, IDC_MULT, m_ctlMult);
	DDX_Control(pDX, IDC_POWER, m_ctlPower);
	DDX_Control(pDX, IDC_CLEARALL, m_ctlClearAll);
	DDX_Control(pDX, IDC_BACKSPACE, m_ctlBack);
	DDX_Control(pDX, IDC_CONSOLE, m_ctlConsole);
	DDX_Control(pDX, IDC_COMMAND, m_ctlCommand);
	DDX_Text(pDX, IDC_COMMAND, m_strCommand);
	DDV_MaxChars(pDX, m_strCommand, 149);
	DDX_Text(pDX, IDC_CONSOLE, m_strConsole);
	DDX_Check(pDX, IDC_SHIFT, m_bShift);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSciCalcDlg, CDialog)
	//{{AFX_MSG_MAP(CSciCalcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, On1)
	ON_BN_CLICKED(IDC_2, On2)
	ON_BN_CLICKED(IDC_3, On3)
	ON_BN_CLICKED(IDC_4, On4)
	ON_BN_CLICKED(IDC_5, On5)
	ON_BN_CLICKED(IDC_6, On6)
	ON_BN_CLICKED(IDC_7, On7)
	ON_BN_CLICKED(IDC_8, On8)
	ON_BN_CLICKED(IDC_9, On9)
	ON_BN_CLICKED(IDC_0, On0)
	ON_BN_CLICKED(IDC_DECIMAL, OnDecimal)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_MULT, OnMult)
	ON_BN_CLICKED(IDC_SUBTRACT, OnSubtract)
	ON_BN_CLICKED(IDC_DIVIDE, OnDivide)
	ON_BN_CLICKED(IDC_CLEARALL, OnClearall)
	ON_BN_CLICKED(IDC_BACKSPACE, OnBackspace)
	ON_BN_CLICKED(IDC_HELP1, OnHelp1)
	ON_BN_CLICKED(IDC_SIN, OnSin)
	ON_BN_CLICKED(IDC_COS, OnCos)
	ON_BN_CLICKED(IDC_TAN, OnTan)
	ON_BN_CLICKED(IDC_LOG, OnLog)
	ON_BN_CLICKED(IDC_OP, OnOp)
	ON_BN_CLICKED(IDC_CP, OnCp)
	ON_BN_CLICKED(IDC_POWER, OnPower)
	ON_BN_CLICKED(IDC_E, OnE)
	ON_BN_CLICKED(IDC_CP2, OnSQUARE)
	ON_BN_CLICKED(IDC_SHIFT, OnShift)
	ON_BN_CLICKED(IDC_COPY, OnCopy)
	ON_BN_CLICKED(IDC_X, OnX)
	ON_BN_CLICKED(IDC_ENTER, OnEnter)
	ON_BN_CLICKED(IDC_EQUALS, OnEquals)
	ON_BN_CLICKED(IDC_LN, OnLn)
	ON_BN_CLICKED(IDC_OPTIONS, OnOptions)
	ON_BN_CLICKED(IDC_LAST, OnLast)
	ON_BN_CLICKED(IDC_INVERSE, OnInverse)
	ON_BN_CLICKED(IDC_ANS, OnAns)
	ON_EN_CHANGE(IDC_CONSOLE, OnChangeConsole)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_EN_CHANGE(IDC_COMMAND, OnChangeCommand)
	ON_BN_CLICKED(IDC_PASTE, OnPaste)
	ON_BN_CLICKED(IDC_GRAPH, OnGraph)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSciCalcDlg message handlers

BOOL CSciCalcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	//Set the return string
	PI=3.14159265358979323846264338327950;//change 0 to a 1
	R[0] = 13;
	R[1] = 10;
	R[2] = '\0';
	m_iPrev = 0;
	m_iTPrev = 0;
	m_strPrev.Add("");
	m_dVer = 1.01;
	m_strLine[0]=0;
	m_strTemp.Format("SciCalc v%.2f",m_dVer);
	SetWindowText(m_strTemp);
	m_iAngle=1;//DEG
	CBitmap Bit;
	Bit.LoadBitmap(IDB_BACK);
	m_ctlBack.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_DEL);
	m_ctlDel.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_CLEARALL);
	m_ctlClearAll.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_ADD);
	m_ctlAdd.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_SUBTRACT);
	m_ctlSubtract.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_MULT);
	m_ctlMult.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_DIVIDE);
	m_ctlDivide.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_POWER);
	m_ctlPower.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_PI);
	m_ctlPI.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_INVERSE);
	m_ctlInverse.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_OP);
	m_ctlOP.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_CP);
	m_ctlCP.SetBitmap(Bit);
	Bit.Detach();
	Bit.LoadBitmap(IDB_EQUAL);
	m_ctlEquals.SetBitmap(Bit);
	Bit.Detach();

	for(int i = 0;i < 26;i++)
		m_dVar[i] = 0;

	m_dVal[0]=0;
	m_dAns = 0;
	m_dVar[4]=2.7182818281828182;//LN base e

	m_strConsole.Format("SciCalc    By: MasterHD@cox.net\r\nVer. %.2f  (C)2007\r\n\r\n", m_dVer);
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSciCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSciCalcDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSciCalcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSciCalcDlg::OnChangeConsole() 
{
	UpdateData(FALSE);
	m_ctlCommand.SetFocus();	
}

void CSciCalcDlg::OnEnter() 
{
	UpdateData(TRUE);
	//m_strLast = m_strCommand;
	//m_strConsole+=(m_strCommand+R);
	m_ctlConsole.SetWindowText(m_strConsole+m_strCommand+R+"="+Solve(m_strCommand)+R+R);
	//m_strConsole+=("="+Solve(m_strCommand)+R+R);
	m_iPrev = 1;
	m_strPrev.SetSize(m_iTPrev+1);
	m_strPrev.InsertAt(1,m_strCommand);//Add to front of list
	m_iTPrev++;
	if(m_iTPrev > 20)
		m_iTPrev = 20;

	m_strCommand = "";
	m_ctlCommand.SetWindowText("");
	//UpdateData(FALSE);
	m_ctlConsole.LineScroll(100);
}

int CSciCalcDlg::OnKey(CString strKey)
{
	UpdateData(TRUE);
	int first, last, cut;//find end selection
	m_ctlCommand.GetSel(first,last);
	cut = 0;
	if(first != last)//selected text
	{
		//DEBUG:
		/*CString strTemp;
		strTemp.Format("First %i Last %i",first, last);
		m_strCommand+=strTemp;*/
		cut = last-first;//Num of chars to erase
		m_strCommand.Delete(first, cut);
	}

	m_ctlCommand.GetSel(first, last);
	//m_strTemp.Format("Selection: %i - %i",first, last);
	//MessageBox(m_strTemp);
	cut = last-first;

	if((cut == 0) && (last == 0))//if first letter is an operator, add ANS to front
	{
		if((strKey.GetAt(0)=='-')||(strKey.GetAt(0)=='+')||(strKey.GetAt(0)=='*')||(strKey.GetAt(0)=='/')||(strKey.GetAt(0)=='^')||(strKey.GetAt(0)=='E')||(strKey.GetAt(0)=='²'))
		{
			m_strCommand.Insert(0,"ANS");
			first+=3;
			last+=3;
			m_ctlCommand.SetSel(3,3);//move cursor to end of inserted text
		}
	}
	m_strCommand.Insert(last-cut,strKey);
	m_ctlCommand.SetWindowText(m_strCommand);
	m_bShift=FALSE;
	m_ctlShift.SetCheck(m_bShift);
	//UpdateData(FALSE);
	m_ctlCommand.SetSel(last+strKey.GetLength()-cut,last+strKey.GetLength()-cut);//move cursor to end of inserted text
	return 0;
}

void CSciCalcDlg::On1() 
{
	OnKey("1");	
}

void CSciCalcDlg::On2() 
{
	OnKey("2");	
}

void CSciCalcDlg::On3() 
{
	OnKey("3");		
}

void CSciCalcDlg::On4()
{
	OnKey("4");	
}

void CSciCalcDlg::On5() 
{
	OnKey("5");	
}

void CSciCalcDlg::On6() 
{
	OnKey("6");	
}

void CSciCalcDlg::On7() 
{
	OnKey("7");	
}

void CSciCalcDlg::On8() 
{
	OnKey("8");	
}

void CSciCalcDlg::On9() 
{
	OnKey("9");	
}

void CSciCalcDlg::On0() 
{
	OnKey("0");	
}

void CSciCalcDlg::OnDecimal() 
{
	OnKey(".");
}

void CSciCalcDlg::OnAdd() 
{
	OnKey("+");
}

void CSciCalcDlg::OnMult() 
{
	OnKey("*");
}

void CSciCalcDlg::OnSubtract() 
{
	OnKey("-");
}

void CSciCalcDlg::OnDivide() 
{
	OnKey("/");
}

void CSciCalcDlg::OnSin() 
{
	if(!m_bShift)
		OnKey("SIN(");
	else
		OnKey("ASIN(");
}

void CSciCalcDlg::OnCos()
{
	if(!m_bShift)
		OnKey("COS(");
	else
		OnKey("ACOS(");
}

void CSciCalcDlg::OnTan()
{
	if(!m_bShift)
		OnKey("TAN(");
	else
		OnKey("ATAN(");
}

void CSciCalcDlg::OnLog()
{
	if(!m_bShift)
		OnKey("LOG(");
	else
		OnKey("10^(");
}

void CSciCalcDlg::OnLn() 
{
	if(!m_bShift)
		OnKey("LN(");
	else
		OnKey("e^(");
}

void CSciCalcDlg::OnOp() 
{
	if(!m_bShift)
		OnKey("(");
	else
		OnKey("[");
}

void CSciCalcDlg::OnCp() 
{
	if(!m_bShift)
		OnKey(")");
	else
		OnKey("]");
}

void CSciCalcDlg::OnPower() 
{
	if(!m_bShift)
		OnKey("^");
	else
		OnKey("E(");
}

void CSciCalcDlg::OnE() 
{
	if(!m_bShift)
		OnKey("PI");
	else
		OnKey("e");
}

void CSciCalcDlg::OnSQUARE() 
{
	if(!m_bShift)
		OnKey("²");
	else
		OnKey("SQRT(");
}

void CSciCalcDlg::OnX() 
{
	if(!m_bShift)
		OnKey("x");
	else
		OnKey("y");
}

void CSciCalcDlg::OnEquals() 
{
	OnKey("=");
}

void CSciCalcDlg::OnInverse() 
{
	if(!m_bShift)
		OnKey("^-1");
	else
		OnKey("!");
}

void CSciCalcDlg::OnAns() 
{
	if(!m_bShift)
		OnKey("ANS");
	else
		OnKey("");
}

CString CSciCalcDlg::Solve(CString strEq)
{
	int max = strEq.GetLength();
	int power=1;
	//convert to number
	strcpy(m_strLine, LPCTSTR(strEq));
	strcpy(m_strLine2, LPCTSTR(strEq));

	for(int i=0;i<MAX;i++)
	{
		if(m_strLine[i] == ' ')
			MoveLeft(i);
		if((m_strLine[i]>=48)&&(m_strLine[i]<=57))
		{
			m_dVal[i] = m_strLine[i]-48;
			m_strLine[i]='#';
		}
	}
	//combine digits
	for(i=0;i<MAX;i++)
	{
		if((m_strLine[i]=='.')&&(m_strLine[i+1]=='#'))
		{
			//tenths
			m_dVal[i+1] = m_dVal[i+1]/(10);
			power=1;
			for(int j=(i+1);j<MAX;j++)
			{
				if(m_strLine[j+1]=='#')//more decimal places
				{
					power++;
					m_dVal[j] = m_dVal[j]+(m_dVal[j+1]/pow(10,power));
					MoveLeft(j+1);//erase current
					j--;
				}
				else
					break;
			}
			i++;//skip 2 spaces
		}
		else if((m_strLine[i]=='#')&&(m_strLine[i+1]=='#'))
		{
			m_dVal[i] = (m_dVal[i]*10)+m_dVal[i+1];
			MoveLeft(i+1);//erase current
			i--;
		}
	}
	//combine decimals
	for(i=0;i<MAX;i++)
	{
		if((m_strLine[i]=='#')&&(m_strLine[i+1]=='.')&&(m_strLine[i+2]=='#'))
		{
			m_dVal[i] = m_dVal[i]+m_dVal[i+2];
			MoveLeft(i+1,2);
		}
		if((m_strLine[i]=='.')&&(m_strLine[i+1]=='#'))//no pre-number
			MoveLeft(i);
	}

	//Variables
	for(i=0;i<MAX;i++)
	{
		if((m_strLine[i]=='A')&&(m_strLine[i+1]=='N')&&(m_strLine[i+2]=='S'))
		{//ANS
			m_strLine[i]='#';
			m_dVal[i]=m_dAns;
			MoveLeft(i+1,2);
		}
		else if((m_strLine[i]=='P')&&(m_strLine[i+1]=='I'))
		{//PI
			m_strLine[i]='#';
			//m_dVal[i] = 3.1415926535;
			
			//1.224606E-016
			//m_dVal[i]=3.1415926535897932384626433832795028841971693993751058209749445923;
			//
			m_dVal[i]=PI;
			MoveLeft(i+1);
		}
		else if(((m_strLine[i] >= 97)&&(m_strLine[i] <= 122)) || (m_strLine[i] == '#') || (m_strLine[i] == ')') || (m_strLine[i] == '}') || (m_strLine[i] == ']'))
		{//if letter a-z, '#', or A-Z (for functions)
			//Multiply Vars
			//If next char is a letter a-z, '#', or A-Z (for functions)
			if(m_strLine[i+1] == 'E')//EXPONENT EXCEPTION, don't add a '*'
				;
			else if(((m_strLine[i+1] >= 97)&&(m_strLine[i+1] <= 122)) || (m_strLine[i+1] == '#') || ((m_strLine[i+1] >= 65)&&(m_strLine[i+1] <= 90)) || (m_strLine[i+1] == '(') || (m_strLine[i+1] == '[') || (m_strLine[i+1] == '{'))
			{
				MoveRight(i+1);
				m_strLine[i+1]='*';
			}
			if((m_strLine[i] >= 97)&&(m_strLine[i] <= 122)&&(m_strLine[i+1] != '='))//Not being assigned
			{//a-z VARIABLES
				m_dVal[i]=m_dVar[m_strLine[i]-97];
				m_strLine[i]='#';
			}
		}
	}

	m_dAns = Sub(0);//order of operations
	if(((m_strLine[0]=='#')&&(m_strLine[1]==0))||((m_strLine[0]=='(')&&(m_strLine[1]=='#')&&(m_strLine[2]==0)))
	{
		if(((fabs(m_dAns) > 1000000)||(fabs(m_dAns) < 0.000001))&&(m_dAns != 0))
			strEq.Format("%E", m_dAns);
		else
			strEq.Format("%.14f", m_dAns);
	}
	else
		strEq.Format(" ERROR: Could not evaluate expression:%s%s", R,m_strLine);
	return strEq;
}

double CSciCalcDlg::Sub(int start)
{
	//Evaluate and change the line expression starting at position "start" and
	//returns the answer calculated within the parenthesis

	//NOTE: The NEGATIVE operation must be called twice, once before the functions and once afterward.
	int i;

	//PARENTHESIS
	for(i = start;i < MAX;i++)
	{
		if((m_strLine[i] == '(')||(m_strLine[i] == '{')||(m_strLine[i] == '['))
			Sub(i+1);
		else if((m_strLine[i] == ')')||(m_strLine[i] == '}')||(m_strLine[i] == ']')||(m_strLine[i] == 0))
			break;//exit
	}

	//NEGATIVE
	/*for(i = start;i < MAX;i++)
	{
		if((m_strLine[i] == ')')||(m_strLine[i] == '}')||(m_strLine[i] == ']')||(m_strLine[i] == 0))
			break;//exit
		if(i==0)
		{
			if((m_strLine[i] == '-')&&(m_strLine[i+1] == '#'))
			{
				m_dVal[i+1]=-m_dVal[i+1];
				MoveLeft(i);
				i--;
			}
		}
		else if((m_strLine[i-1] != '#')&&(m_strLine[i] == '-')&&(m_strLine[i+1] == '#'))
		{
			m_dVal[i+1] = -m_dVal[i+1];
			MoveLeft(i);
			i--;
		}
	}*/

	//FUNCTIONS
	for(i=start;i<MAX;i++)
	{
		if((m_strLine[i]=='S')&&(m_strLine[i+1]=='I')&&(m_strLine[i+2]=='N')&&(m_strLine[i+3]=='#'))
		{//SIN
			if(m_iAngle==1)
				m_dVal[i+3] = m_dVal[i+3]*PI/180;
			
			/*if((m_dVal[i+3] == 0) || (m_dVal[i+3] == PI))
				m_dVal[i+3] = 0;
			else if(m_dVal[i+3] == PI/2)
				m_dVal[i+3] = 1;
			else if(m_dVal[i+3] == 3*PI/2)
				m_dVal[i+3] = -1;
			else*/
				m_dVal[i+3] = sin(m_dVal[i+3]);
			MoveLeft(i,3);
		}
		else if((m_strLine[i]=='A')&&(m_strLine[i+1]=='S')&&(m_strLine[i+2]=='I')&&(m_strLine[i+3]=='N')&&(m_strLine[i+4]=='#'))
		{//ASIN
			m_dVal[i+4]=asin(m_dVal[i+4])*(m_iAngle? 180/PI:1);
			MoveLeft(i,4);
		}
		else if((m_strLine[i]=='C')&&(m_strLine[i+1]=='O')&&(m_strLine[i+2]=='S')&&(m_strLine[i+3]=='#'))
		{//COS
			if(m_iAngle==1)
				m_dVal[i+3]=m_dVal[i+3]*PI/180;
			m_dVal[i+3]=cos(m_dVal[i+3]);
			MoveLeft(i,3);
		}
		else if((m_strLine[i]=='A')&&(m_strLine[i+1]=='C')&&(m_strLine[i+2]=='O')&&(m_strLine[i+3]=='S')&&(m_strLine[i+4]=='#'))
		{//ACOS
			m_dVal[i+4]=acos(m_dVal[i+4])*(m_iAngle? 180/PI:1);
			MoveLeft(i,4);
		}
		else if((m_strLine[i]=='T')&&(m_strLine[i+1]=='A')&&(m_strLine[i+2]=='N')&&(m_strLine[i+3]=='#'))
		{//TAN
			if(m_iAngle==1)
				m_dVal[i+3]=m_dVal[i+3]*PI/180;
			m_dVal[i+3]=tan(m_dVal[i+3]);
			MoveLeft(i,3);
		}
		else if((m_strLine[i]=='A')&&(m_strLine[i+1]=='T')&&(m_strLine[i+2]=='A')&&(m_strLine[i+3]=='N')&&(m_strLine[i+4]=='#'))
		{//ATAN
			m_dVal[i+4]=atan(m_dVal[i+4])*(m_iAngle? 180/PI:1);
			MoveLeft(i,4);
		}
		else if((m_strLine[i]=='L')&&(m_strLine[i+1]=='O')&&(m_strLine[i+2]=='G')&&(m_strLine[i+3]=='#'))
		{//LOG
			m_dVal[i+3]=log10(m_dVal[i+3]);
			MoveLeft(i,3);
		}
		else if((m_strLine[i]=='L')&&(m_strLine[i+1]=='N')&&(m_strLine[i+2]=='#'))
		{//LN
			m_dVal[i+2]=log(m_dVal[i+2]);
			MoveLeft(i,2);
		}
		else if((m_strLine[i]=='S')&&(m_strLine[i+1]=='Q')&&(m_strLine[i+2]=='R')&&(m_strLine[i+3]=='T')&&(m_strLine[i+4]=='#'))
		{//SQRT
			m_dVal[i+4]=sqrt(m_dVal[i+4]);
			MoveLeft(i, 4);
		}
		else if((m_strLine[i]=='#')&&(m_strLine[i+1]=='E'))
		{//Sci notation
			if(m_strLine[i+2]=='+')
				MoveLeft(i+2);//erase the plus sign if its there, 2E+3=2000
			if((m_strLine[i+2]=='-')&&(m_strLine[i+3]=='#'))
			{
				MoveLeft(i+2);//erase the minus sign if its there, 2E+3=2000
				m_dVal[i+2]*=-1;
			}
			if(m_strLine[i+2]=='#')
			{
				m_dVal[i] = m_dVal[i]*pow(10,m_dVal[i+2]);
				MoveLeft(i+1,2);
			}
		}
		else if((m_strLine[i]=='A')&&(m_strLine[i+1]=='B')&&(m_strLine[i+2]=='S')&&(m_strLine[i+3]=='#'))
		{//ABS
			m_dVal[i+3]=fabs(m_dVal[i+3]);
			MoveLeft(i,3);
		}
		else if((m_strLine[i]=='#')&&(m_strLine[i+1]=='!'))
		{//FACTORIAL
			int stop = int(m_dVal[i]);
			m_dVal[i] = 1;
			
			for(int j=1;j<=stop;j++)
				m_dVal[i] *= j;

			MoveLeft(i+1,1);
		}
	}

//(1.16*t)-(0.21*t^2)+(.24*t^3)
	//POWER
	for(i = start;i < MAX;i++)
	{
		if((m_strLine[i] == '(')||(m_strLine[i] == '{')||(m_strLine[i] == '['))
			Sub(i+1);
		else if((m_strLine[i] == ')')||(m_strLine[i] == '}')||(m_strLine[i] == ']')||(m_strLine[i] == 0))
			break;//exit

		if((m_strLine[i] == '#')&&(m_strLine[i+1] == '^')&&(m_strLine[i+2] == '#'))
		{//Power

			m_dVal[i]=pow(m_dVal[i],m_dVal[i+2]);
			MoveLeft(i+1,2);
			i--;
		}
		if((m_strLine[i] == '#')&&(m_strLine[i+1] == '^')&&(m_strLine[i+2] == '-')&&(m_strLine[i+3] == '#'))
		{//Negative Power FIX:?

			m_dVal[i]=pow(m_dVal[i],-1*m_dVal[i+3]);
			MoveLeft(i+1,3);
			i--;
		}
		else if((m_strLine[i] == '#')&&(m_strLine[i+1] == '²'))
		{//SQUARE
			m_dVal[i]=m_dVal[i]*m_dVal[i];
			MoveLeft(i+1);
		}
	}

	//NEGATIVE
	for(i = start;i < MAX;i++)
	{
		if((m_strLine[i] == ')')||(m_strLine[i] == '}')||(m_strLine[i] == ']')||(m_strLine[i] == 0))
			break;//exit
		if(i==0)
		{
			if((m_strLine[i] == '-')&&(m_strLine[i+1] == '#'))
			{
				m_dVal[i+1]=-m_dVal[i+1];
				MoveLeft(i);
				i--;
			}
		}
		else if((m_strLine[i-1] != '#')&&(m_strLine[i] == '-')&&(m_strLine[i+1] == '#'))
		{
			m_dVal[i+1] = -m_dVal[i+1];
			MoveLeft(i);
			i--;
		}
	}

	for(i = start;i < MAX;i++)
	{
		if((m_strLine[i] == ')')||(m_strLine[i] == '}')||(m_strLine[i] == ']')||(m_strLine[i] == 0))
			break;//exit

		else if((m_strLine[i] == '#')&&(m_strLine[i+1] == '*')&&(m_strLine[i+2] == '#'))
		{//Multiply
			m_dVal[i]*=m_dVal[i+2];
			MoveLeft(i+1,2);
			i--;
		}
		else if((m_strLine[i] == '#')&&(m_strLine[i+1] == '/')&&(m_strLine[i+2] == '#'))
		{//Divide
			if(m_dVal[i+2] == 0)//DIV BY 0
			{
				m_strLine[i+2] = '0';
				return 0;
			}
			m_dVal[i]/=m_dVal[i+2];
			MoveLeft(i+1,2);
			i--;
		}
	}

	for(i = start;i < MAX;i++)
	{
		if((m_strLine[i] == ')')||(m_strLine[i] == '}')||(m_strLine[i] == ']')||(m_strLine[i] == 0))
			break;//exit

		else if((m_strLine[i] == '#')&&(m_strLine[i+1] == '-')&&(m_strLine[i+2] == '#'))
		{//Subtract
			m_dVal[i]-=m_dVal[i+2];
			MoveLeft(i+1,2);
			i--;
		}
		else if((m_strLine[i] == '#')&&(m_strLine[i+1] == '+')&&(m_strLine[i+2] == '#'))
		{//Add
			m_dVal[i]+=m_dVal[i+2];
			MoveLeft(i+1,2);
			i--;
		}
	}
	if((m_strLine[i] == ')')||(m_strLine[i] == '}')||(m_strLine[i] == ']'))
	{//REMOVE BOTH Parenthesis (#)
		MoveLeft(i);
		MoveLeft(i-2);
	}

	//ASSIGN
	for(i = start;i < MAX;i++)
	{
		if((m_strLine[i] == ')')||(m_strLine[i] == '}')||(m_strLine[i] == ']')||(m_strLine[i] == 0))
			break;//exit

		if((m_strLine[i] >= 97)&&(m_strLine[i] <= 122)&&(m_strLine[i+1] == '=')&&(m_strLine[i+2] == '#'))
		{//Assign
			if(m_strLine[i]-97 != 4)//all ok except 'e'
			{
				m_dVar[m_strLine[i]-97]=m_dVal[i+2];
				MoveLeft(i,2);
			}
		}
	}
	return m_dVal[i-1];
}

int CSciCalcDlg::MoveLeft(int here, int step)
{
	for(int i = here;i < MAX-1;i++)
	{
		m_strLine[i]=m_strLine[i+step];
		m_strLine2[i]=m_strLine2[i+step];
		m_dVal[i]=m_dVal[i+step];
	}
	m_strLine2[MAX-step]=0;
	m_strLine[MAX-step]=0;
	m_dVal[MAX-step]=0;
	return 0;
}

int CSciCalcDlg::MoveRight(int here, int step)
{
	int iLen = strlen(m_strLine);
	if (iLen >= MAX-1)//can't make any longer
		return -1;
	for(int i = iLen-1;i >= here;i--)
	{
		m_strLine[i+step]=m_strLine[i];
		m_strLine2[i+step]=m_strLine2[i];
		m_dVal[i+step]=m_dVal[i];
	}
	m_strLine2[iLen+step]=0;
	m_strLine[iLen+step]=0;
	m_dVal[iLen+step]=0;
	return 0;
}

void CSciCalcDlg::UpdateData(BOOL bCase)
{
	//Calling this will reset the selection to 0 on any CEdit
	//override
	CDialog::UpdateData(bCase);
	//m_ctlConsole.SetSel(m_strConsole.GetLength()-10,-1, FALSE);
}

void CSciCalcDlg::OnClearall() 
{
	m_ctlCommand.SetWindowText("");
	//UpdateData(FALSE);
}

void CSciCalcDlg::OnBackspace() 
{
	Erase(-1);
}

void CSciCalcDlg::OnDelete() 
{
	Erase(0);
}

void CSciCalcDlg::Erase(int here)
{
	int first, last, cut;
	m_ctlCommand.UpdateData(FALSE);
	m_ctlCommand.GetSel(first, last);

	//m_strTemp.Format("Selection: %i - %i",first, last);
	//MessageBox(m_strTemp);
	cut = last-first;

	if(cut == 0)//no selection
	{
		m_strCommand.Delete(first+here, 1);
		m_ctlCommand.SetWindowText(m_strCommand);
		//UpdateData(FALSE);
		m_ctlCommand.SetSel(first+here,first+here);
	}
	else
	{
		m_strCommand.Delete(first, cut);
		//UpdateData(FALSE);
		m_ctlCommand.SetWindowText(m_strCommand);
		m_ctlCommand.SetSel(first,first);
	}
}
void CSciCalcDlg::OnHelp1() 
{
	m_HelpDlg.DoModal();
}

void CSciCalcDlg::OnShift() 
{
	m_bShift=!m_bShift;
	m_ctlShift.SetCheck(m_bShift);
	//UpdateData(FALSE);
}

void CSciCalcDlg::OnOptions() 
{
	// TODO: Add your control notification handler code here
	m_OptionsDlg.m_iAngle = m_iAngle;
	if(m_OptionsDlg.DoModal() == IDOK)
	{
		m_iAngle = m_OptionsDlg.m_iAngle;
		//0=RAD, 1=DEG
	}
}

void CSciCalcDlg::OnLast() 
{
	//Cycle through previously entered commands
	m_ctlCommand.SetSel(0, m_ctlCommand.GetWindowTextLength());
	m_ctlCommand.ReplaceSel(m_strPrev.GetAt(m_iPrev));
	m_iPrev++; 
	if(m_iPrev > m_iTPrev)
		m_iPrev = 0;
}

void CSciCalcDlg::OnChangeCommand() 
{
	UpdateData(TRUE);
	if(m_strCommand.GetLength() == 1)
	{
		char ch = m_strCommand.GetAt(0);
		if(ch == '*' || ch == '/' || ch == '+' || ch == '^' || ch == 'E' || ch == '²' || ch == '-')
		{
			m_strTemp.Format("ANS%c",ch);
			m_ctlCommand.SetWindowText(m_strTemp);
			m_ctlCommand.SetSel(4,4);
		}
	}
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
}

void CSciCalcDlg::OnCopy() 
{
	//UpdateData(TRUE);
	int first, last;

	m_ctlCommand.GetSel(first,last);//find selection

	if(last-first != 0)//something selected
		m_ctlCommand.Copy();
	else//nothing selected in command box
	{
		m_ctlConsole.GetSel(first,last);

		if(last-first != 0)//something selected in console box
			m_ctlConsole.Copy();
		else//nothing selected anywhere
		{
			CString temp;
			temp = m_strCommand;
			m_strCommand.Format("%.14f", m_dAns);
			m_ctlCommand.SetSel(0,m_strCommand.GetLength());
			m_ctlCommand.Copy();
			m_ctlCommand.SetWindowText(temp);
		}
	}
}

void CSciCalcDlg::OnPaste() 
{
	// TODO: Add your control notification handler code here
	m_ctlCommand.Paste();
}

void CSciCalcDlg::OnGraph() 
{
	// TODO: Add your control notification handler code here
	
}
