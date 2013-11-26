// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "SearchAlgorithm.h"
#include "GoldDlg.h"
#include "Dlg_Divide_Equal.h"
#include "Dlg_NewTon.h"
#include "Dlg_Parabolic.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_SEARCH_GOLD, OnSearchGold)
	ON_COMMAND(ID_SEARCH_DIVIDE_EQUAL, OnSearchDivideEqual)
	ON_COMMAND(ID_SEARCH_NEWTON, OnSearchNewton)
	ON_COMMAND(ID_SEARCH_PARABOLIC, OnSearchParabolic)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnSearchGold() 
{
	// TODO: Add your command handler code here
    
	//创建模态对话框
	//CGoldDlg goldDlg;
	//goldDlg.DoModal();

	//创建非模态对话框
	CGoldDlg* pGoldDlg = new CGoldDlg;
	pGoldDlg->Create(IDD_DIALOG_GOLD,this);
	pGoldDlg->ShowWindow(SW_SHOW);
}

void CMainFrame::OnSearchDivideEqual() 
{
	// TODO: Add your command handler code here
	//创建非模态对话框
	CDlg_Divide_Equal* pDivide_E_Dlg = new CDlg_Divide_Equal;
	pDivide_E_Dlg->Create(IDD_DIALOG_DIVIDE_EQUAL,this);
	pDivide_E_Dlg->ShowWindow(SW_SHOW);
}

void CMainFrame::OnSearchNewton() 
{
	// TODO: Add your command handler code here
	//创建非模态对话框
	CDlg_NewTon* pNewTon_Dlg = new CDlg_NewTon;
	pNewTon_Dlg->Create(IDD_DIALOG_NEWTON,this);
	pNewTon_Dlg->ShowWindow(SW_SHOW);
}

void CMainFrame::OnSearchParabolic() 
{
	// TODO: Add your command handler code here
	//创建非模态对话框
	CDlg_Parabolic* pParabolic_Dlg = new CDlg_Parabolic;
	pParabolic_Dlg->Create(IDD_DIALOG_PARABOLIC,this);
	pParabolic_Dlg->ShowWindow(SW_SHOW);
}
