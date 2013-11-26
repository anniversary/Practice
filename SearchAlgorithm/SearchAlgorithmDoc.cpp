// SearchAlgorithmDoc.cpp : implementation of the CSearchAlgorithmDoc class
//

#include "stdafx.h"
#include "SearchAlgorithm.h"

#include "SearchAlgorithmDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmDoc

IMPLEMENT_DYNCREATE(CSearchAlgorithmDoc, CDocument)

BEGIN_MESSAGE_MAP(CSearchAlgorithmDoc, CDocument)
	//{{AFX_MSG_MAP(CSearchAlgorithmDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmDoc construction/destruction

CSearchAlgorithmDoc::CSearchAlgorithmDoc()
{
	// TODO: add one-time construction code here

}

CSearchAlgorithmDoc::~CSearchAlgorithmDoc()
{
}

BOOL CSearchAlgorithmDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmDoc serialization

void CSearchAlgorithmDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmDoc diagnostics

#ifdef _DEBUG
void CSearchAlgorithmDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSearchAlgorithmDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmDoc commands
