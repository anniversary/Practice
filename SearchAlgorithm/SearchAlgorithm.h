// SearchAlgorithm.h : main header file for the SEARCHALGORITHM application
//

#if !defined(AFX_SEARCHALGORITHM_H__E34F0C22_70F1_45F5_9148_BC9E593217F2__INCLUDED_)
#define AFX_SEARCHALGORITHM_H__E34F0C22_70F1_45F5_9148_BC9E593217F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "GridCtrl_src\GridCtrl.h"
//#include "GridBtnCell_src\BtnDataBase.h"
/////////////////////////////////////////////////////////////////////////////
// CSearchAlgorithmApp:
// See SearchAlgorithm.cpp for the implementation of this class
//

class CSearchAlgorithmApp : public CWinApp
{
public:
	CSearchAlgorithmApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchAlgorithmApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSearchAlgorithmApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHALGORITHM_H__E34F0C22_70F1_45F5_9148_BC9E593217F2__INCLUDED_)
