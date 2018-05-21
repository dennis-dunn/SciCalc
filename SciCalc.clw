; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSciCalcDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "SciCalc.h"

ClassCount=5
Class1=CSciCalcApp
Class2=CSciCalcDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_SCICALC_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CHelp1Dlg
Resource4=IDD_HELP
Class5=COptionsDlg
Resource5=IDD_OPTIONS

[CLS:CSciCalcApp]
Type=0
HeaderFile=SciCalc.h
ImplementationFile=SciCalc.cpp
Filter=N

[CLS:CSciCalcDlg]
Type=0
HeaderFile=SciCalcDlg.h
ImplementationFile=SciCalcDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMMAND

[CLS:CAboutDlg]
Type=0
HeaderFile=SciCalcDlg.h
ImplementationFile=SciCalcDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_SCICALC_DIALOG]
Type=1
Class=CSciCalcDlg
ControlCount=54
Control1=IDC_COMMAND,edit,1350631552
Control2=IDC_CONSOLE,edit,1352728644
Control3=IDC_1,button,1342242816
Control4=IDC_2,button,1342242816
Control5=IDC_3,button,1342242816
Control6=IDC_4,button,1342242816
Control7=IDC_5,button,1342242816
Control8=IDC_6,button,1342242816
Control9=IDC_7,button,1342242816
Control10=IDC_8,button,1342242816
Control11=IDC_9,button,1342242816
Control12=IDC_0,button,1342242816
Control13=IDC_DECIMAL,button,1342242816
Control14=IDC_ENTER,button,1342242817
Control15=IDC_ADD,button,1342242944
Control16=IDC_MULT,button,1342242944
Control17=IDC_SUBTRACT,button,1342242944
Control18=IDC_DIVIDE,button,1342242944
Control19=IDC_CLEARALL,button,1342242944
Control20=IDC_BACKSPACE,button,1342242944
Control21=IDC_HELP1,button,1342242816
Control22=IDC_POWER,button,1342242944
Control23=IDC_SHIFT,button,1342246915
Control24=IDC_SIN,button,1342242816
Control25=IDC_COS,button,1342242816
Control26=IDC_TAN,button,1342242816
Control27=IDC_LOG,button,1342242816
Control28=IDC_OP,button,1342242944
Control29=IDC_CP,button,1342242944
Control30=IDC_E,button,1342242944
Control31=IDC_CP2,button,1342242816
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC,static,1342308352
Control37=IDC_X,button,1342242816
Control38=IDC_COPY,button,1342242816
Control39=IDC_EQUALS,button,1342242944
Control40=IDC_STATIC,static,1342308352
Control41=IDC_STATIC,static,1342308352
Control42=IDC_LN,button,1342242816
Control43=IDC_STATIC,static,1342308352
Control44=IDC_STATIC,static,1342308352
Control45=IDC_OPTIONS,button,1342242816
Control46=IDC_INVERSE,button,1342242944
Control47=IDC_STATIC,static,1342308352
Control48=IDC_LAST,button,1342242816
Control49=IDC_STATIC,static,1342308352
Control50=IDC_STATIC,static,1342308352
Control51=IDC_ANS,button,1342242816
Control52=IDC_DELETE,button,1342242944
Control53=IDC_PASTE,button,1342242816
Control54=IDC_GRAPH,button,1342242816

[DLG:IDD_HELP]
Type=1
Class=CHelp1Dlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_TEXT,edit,1353779396

[CLS:CHelp1Dlg]
Type=0
HeaderFile=Help1Dlg.h
ImplementationFile=Help1Dlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TEXT
VirtualFilter=dWC

[DLG:IDD_OPTIONS]
Type=1
Class=COptionsDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_ANGLE1,button,1342308361
Control4=IDC_STATIC,button,1342177287
Control5=IDC_ANGLE2,button,1342177289

[CLS:COptionsDlg]
Type=0
HeaderFile=OptionsDlg.h
ImplementationFile=OptionsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_ANGLE1
VirtualFilter=dWC

