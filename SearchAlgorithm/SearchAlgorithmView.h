// SearchAlgorithmView.h : interface of the CSearchAlgorithmView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEARCHALGORITHMVIEW_H__2DB68B6C_6A09_4276_ADF0_1078C49EA81E__INCLUDED_)
#define AFX_SEARCHALGORITHMVIEW_H__2DB68B6C_6A09_4276_ADF0_1078C49EA81E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSearchAlgorithmView : public CView
{
protected: // create from serialization only
	CSearchAlgorithmView();
	DECLARE_DYNCREATE(CSearchAlgorithmView)

// Attributes
public:
	CSearchAlgorithmDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchAlgorithmView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSearchAlgorithmView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSearchAlgorithmView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SearchAlgorithmView.cpp
inline CSearchAlgorithmDoc* CSearchAlgorithmView::GetDocument()
   { return (CSearchAlgorithmDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHALGORITHMVIEW_H__2DB68B6C_6A09_4276_ADF0_1078C49EA81E__INCLUDED_)
