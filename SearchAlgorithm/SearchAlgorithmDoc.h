// SearchAlgorithmDoc.h : interface of the CSearchAlgorithmDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEARCHALGORITHMDOC_H__5840CC14_0A68_4B40_9A69_3DBBA5DF3997__INCLUDED_)
#define AFX_SEARCHALGORITHMDOC_H__5840CC14_0A68_4B40_9A69_3DBBA5DF3997__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSearchAlgorithmDoc : public CDocument
{
protected: // create from serialization only
	CSearchAlgorithmDoc();
	DECLARE_DYNCREATE(CSearchAlgorithmDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchAlgorithmDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSearchAlgorithmDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSearchAlgorithmDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHALGORITHMDOC_H__5840CC14_0A68_4B40_9A69_3DBBA5DF3997__INCLUDED_)
