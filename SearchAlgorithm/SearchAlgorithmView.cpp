// SearchAlgorithmView.cpp : implementation of the CSearchAlgorithmView class
//

#include "stdafx.h"
#include "SearchAlgorithm.h"

#include "SearchAlgorithmDoc.h"
#include "SearchAlgorithmView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmView

IMPLEMENT_DYNCREATE(CSearchAlgorithmView, CView)

BEGIN_MESSAGE_MAP(CSearchAlgorithmView, CView)
	//{{AFX_MSG_MAP(CSearchAlgorithmView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmView construction/destruction

CSearchAlgorithmView::CSearchAlgorithmView()
{
	// TODO: add construction code here

}

CSearchAlgorithmView::~CSearchAlgorithmView()
{
}

BOOL CSearchAlgorithmView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmView drawing

void CSearchAlgorithmView::OnDraw(CDC* pDC)
{
	CSearchAlgorithmDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmView printing

BOOL CSearchAlgorithmView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSearchAlgorithmView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSearchAlgorithmView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmView diagnostics

#ifdef _DEBUG
void CSearchAlgorithmView::AssertValid() const
{
	CView::AssertValid();
}

void CSearchAlgorithmView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSearchAlgorithmDoc* CSearchAlgorithmView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSearchAlgorithmDoc)));
	return (CSearchAlgorithmDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmView message handlers
